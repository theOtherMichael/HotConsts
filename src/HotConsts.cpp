#include "HotConsts/HotConsts.h"
#include <fstream>

namespace HotConsts
{

std::map<hcSrcOrigin, std::tuple<std::string, hcReloadFn, unsigned int>>& _getReloadMap()
{
	static auto instance = 
		new std::map<hcSrcOrigin, std::tuple<std::string, hcReloadFn, unsigned int>>();
	return *instance;
}

// TODO: Get rid of all the string allocations.
std::string _stripComments(std::string srcLine, bool& startsInMultiline)
{
	size_t searchPos;

	if (!startsInMultiline)
	{
		// Handle single line comments "//"
		searchPos = srcLine.find("//");
		if (searchPos != std::string::npos)
		{
			// Confirm the "//" isn't in a string literal.
			bool inStringLiteral = false;
			size_t quotePos = srcLine.find('\"');
			while (quotePos < searchPos)
			{
				if (quotePos > 0)
				{
					// Confirm the quote isn't part of an escape sequence.
					if (srcLine.at(quotePos - 1) != '\\')
						inStringLiteral = !inStringLiteral;
				}
				else
					inStringLiteral = !inStringLiteral;
				
				quotePos = srcLine.find('\"', ++quotePos);
			}
			
			if (!inStringLiteral)
			{
				srcLine.resize(searchPos);
				if(srcLine.empty())
					return srcLine;
			}
		}

		// Handle multi-line comment openings "/*"
		searchPos = srcLine.find("/*");
		if (searchPos != std::string::npos)
		{
			// Confirm the "/*" isn't in a string literal.
			bool inStringLiteral = false;
			size_t quotePos = srcLine.find('\"');
			while (quotePos < searchPos)
			{
				if (quotePos > 0)
				{
					// Confirm the quote isn't part of an escape sequence.
					if (srcLine.at(quotePos - 1) != '\\')
						inStringLiteral = !inStringLiteral;
				}
				else
					inStringLiteral = !inStringLiteral;
				
				quotePos = srcLine.find('\"', ++quotePos);
			}
			
			if (!inStringLiteral)
			{
				startsInMultiline = true;
				
				// remove "/*" from the line.
				srcLine.erase(searchPos, 2);
				
				// handle the rest of the line.
				if (!srcLine.empty())
				{
					std::string backOfLine = srcLine.substr(searchPos);
					srcLine.resize(searchPos);
					return srcLine + _stripComments(backOfLine, startsInMultiline);
				}
			}
			
			return srcLine;
		}
		else
			return srcLine; // No comment was detected, so return the whole line.
	}
	else
	{
		// Handle multi-line comment endings "*/"
		searchPos = srcLine.find("*/");
		if (searchPos != std::string::npos)
		{
			startsInMultiline = false;

			// clear everything though "*/"
			srcLine.erase(0, searchPos + 2);
			
			// check the rest of the line for comments
			if (!srcLine.empty())
				return _stripComments(srcLine, startsInMultiline);
			else
				return srcLine;
		}
		else
			return std::string(); // No end to comment detected, return empty string.
	}
}

enum class parserState
{
	awaitingMacro,
	awaitingLParentheses,
	awaitingParam1,
	awaitingParam2,
	awaitingRParentheses,
	awaitingAssignmentOperator,
	awaitingSemicolon
};

void _reloadSrcFile(const std::string& filename)
{
	std::ifstream srcFile(filename);

	std::vector<std::string> reloadedHCNames;
	int repeatCount = 0;
	
	while (repeatCount < 5)
	{
		if (srcFile.is_open())
		{
			std::string srcLine, carryover, HCTypeStr, HCNameStr;
			int lineNumber = 0, macroLine;
			bool inMultilineComment = false; // tracks whether line start is within /**/ block.
			bool isNonModifierIdentified = false; // used when parsing first parameter of HC macro.
			std::string_view term; // also used when parsing the first parameter of the HC macro.

			size_t searchPos1, searchPos2;

			// reload function stuff
			std::string registeredTypeStrName;
			hcReloadFn reloadFn;
			unsigned int valueIndex;

			parserState currentState = parserState::awaitingMacro;

			while (std::getline(srcFile, srcLine))
			{
				lineNumber++;
				srcLine = _stripComments(srcLine, inMultilineComment);

				searchPos1 = 0;
				searchPos2 = 0;
				bool stillParsingLine = true;
				while (stillParsingLine)
				{
					stillParsingLine = true;

					switch (currentState)
					{
					case parserState::awaitingMacro:
						searchPos1 = srcLine.find("HC", searchPos1);
						if (searchPos1 != std::string::npos)
						{
							// Check that the preceding character isn't a-z, A-Z, 0-9, or _.
							if (searchPos1 > 0)
							{
								if ((srcLine.at(searchPos1 - 1) >= 'a' && srcLine.at(searchPos1 - 1) <= 'z') ||
									(srcLine.at(searchPos1 - 1) >= 'A' && srcLine.at(searchPos1 - 1) <= 'Z') ||
									(srcLine.at(searchPos1 - 1) >= '0' && srcLine.at(searchPos1 - 1) <= '9') ||
									srcLine.at(searchPos1 - 1) == '_')
								{
									searchPos1 += 2;
								}
								else
									goto outerElse;
							}
							else
							{
							outerElse:;

								// Check that this isn't part of a string literal.
								bool inStringLiteral = false;
								searchPos2 = srcLine.find('\"');
								while (searchPos2 < searchPos1)
								{
									// Confirm the quote isn't part of an escape sequence.
									if (searchPos2 > 0)
									{
										if (srcLine.at(searchPos2 - 1) != '\\')
											inStringLiteral = !inStringLiteral;
									}
									else
										inStringLiteral = !inStringLiteral;

									searchPos2 = srcLine.find('\"', ++searchPos2);
								}

								if (!inStringLiteral)
								{
									currentState = parserState::awaitingLParentheses;
									macroLine = lineNumber;
								}

								searchPos1 += 2; // move past "HC"
							}
						}
						else
							stillParsingLine = false;
						break;

					case parserState::awaitingLParentheses:
						// Position 1 starts as the first character after "HC".
						searchPos2 = srcLine.find('(', searchPos1);
						if (searchPos2 != std::string::npos)
						{
							// Check that there's only whitespace between "HC" and "(".
							if (srcLine.find_first_not_of(" \t", searchPos1) < searchPos2)
								currentState = parserState::awaitingMacro;
							else
							{
								currentState = parserState::awaitingParam1;
								searchPos1 = searchPos2 + 1; // Continue search after "(".
							}
						}
						else
						{
							// If the rest of the line isn't whitespace, this can't be an "HC" macro.
							if (srcLine.find_first_not_of(" \t", searchPos1) != std::string::npos)
								currentState = parserState::awaitingMacro;

							stillParsingLine = false;
						}
						break;

					case parserState::awaitingParam1:
						// Position 1 starts as the first character after "(".

						searchPos1 = srcLine.find_first_not_of(" \t", searchPos1);
						if (searchPos1 != std::string::npos)
						{
							if (srcLine.at(searchPos1) == ',')
							{
								// This is the comma following the parameter.  Strip the last space from HCTypeStr, then move on if it's valid.
								if (HCTypeStr.empty())
								{
									std::cout << "Hot Constants:  Reload Failure: Macro invocation is missing its first parameter."
										"\n                File: " << filename << ", Line: " << macroLine << std::endl;
									isNonModifierIdentified = false;
									currentState = parserState::awaitingMacro;
								}
								else
								{
									HCTypeStr.resize(HCTypeStr.size() - 1); //strip the trailing space
									searchPos1++; //move past the comma
									isNonModifierIdentified = false;
									currentState = parserState::awaitingParam2;
								}
							}
							else
							{
								// This might be a type.
								searchPos2 = srcLine.find_first_of(", \t", searchPos1);
								if (searchPos2 != std::string::npos)
								{
									term = std::string_view(srcLine.c_str() + searchPos1, searchPos2 - searchPos1);
								}
								else
								{
									term = std::string_view(srcLine.c_str() + searchPos1);
									stillParsingLine = false;
								}

								// If this is a modifier, append it to HCTypeStr.  Else, we append only if it's the first typename.
								if (term == "signed" || term == "unsigned" || term == "short" || term == "long")
								{
									HCTypeStr.append(term);
									HCTypeStr.append(" ");
									searchPos1 = searchPos2;
								}
								else
								{
									if (isNonModifierIdentified)
									{
										std::cout << "Hot Constants:  Reload Failure: Invalid first parameter in macro invocation."
											"\n                File: " << filename << ", Line: " << macroLine << std::endl;
										HCTypeStr.clear();
										currentState = parserState::awaitingMacro;
									}
									else
									{
										isNonModifierIdentified = true;
										HCTypeStr.append(term);
										HCTypeStr.append(" ");
										searchPos1 = searchPos2;
									}
								}
							}
						}
						else
						{
							// We've encountered a blank line after "(": continue with the next one.
							stillParsingLine = false;
						}
						break;

					case parserState::awaitingParam2:
						// Position 1 starts as the first character after ",".

						// Whatever's next on the line is assumed to be a parameter.
						searchPos1 = srcLine.find_first_not_of(" \t", searchPos1);
						if (searchPos1 != std::string::npos)
						{
							searchPos2 = srcLine.find_first_of("); \t", searchPos1);
							if (searchPos2 != std::string::npos)
								HCNameStr = srcLine.substr(searchPos1, searchPos2 - searchPos1);
							else
								HCNameStr = srcLine.substr(searchPos1);

							if (HCNameStr.empty())
							{
								std::cout << "Hot Constants:  Reload Failure: Macro invocation is missing its second parameter."
									"\n                File: " << filename << ", Line: " << macroLine << std::endl;
								HCTypeStr.clear();
								currentState = parserState::awaitingMacro;
							}
							else
							{
								currentState = parserState::awaitingRParentheses;
								searchPos1 = searchPos2;
							}
						}
						else
						{
							// Parameter must be on next line.
							stillParsingLine = false;
						}
						break;

					case parserState::awaitingRParentheses:
						// Position 1 should be the first thing after parameter 2.

						searchPos2 = srcLine.find(')', searchPos1);
						if (searchPos2 > srcLine.find_first_not_of(" \t", searchPos1))
						{
							// The first thing on this line isn't ")".
							std::cout << "Hot Constants:  Reload Failure: \')\' not found after second parameter of macro invocation."
								"\n                File: " << filename << ", Line: " << macroLine << std::endl;
							HCTypeStr.clear();
							currentState = parserState::awaitingMacro;
						}
						else
						{
							// If nothing is on the line at all, we continue looking for the ')' on the next line.
							if (searchPos2 == std::string::npos)
							{
								searchPos1 = 0;
								stillParsingLine = false;
							}
							else
							{
								currentState = parserState::awaitingAssignmentOperator;

								// Check whether this is a valid macro before moving on.
								try
								{
									std::tie(registeredTypeStrName, reloadFn, valueIndex) = _getReloadMap().at(std::pair(filename, HCNameStr));
									// If the above statement didn't throw, this is assumed to be one of the registered constants.

									if (std::find(reloadedHCNames.begin(), reloadedHCNames.end(), HCNameStr) != reloadedHCNames.end())
									{
										std::cout << "Hot Constants:  Error: Redefinition of constant \"" << HCNameStr << "\".  "
											"Modified code may not compile.  Value will reflect first found definition in file."
											"\n                File: " << filename << ", Line: " << macroLine << std::endl;
										HCTypeStr.clear();
										currentState = parserState::awaitingMacro;
									}
									else
										reloadedHCNames.emplace_back(HCNameStr);
								}
								catch (const std::out_of_range& e)
								{
									std::cout << "Hot Constants:  Warning: Encountered unregistered value \"" << HCNameStr << "\" in source.  "
										"The application will not reflect new or renamed values until it is recompiled.  "
										"\n                File: " << filename << ", Line: " << macroLine << std::endl;
									HCTypeStr.clear();
									currentState = parserState::awaitingMacro;
								}

								searchPos1 = searchPos2 + 1; //move past the ')'.
							}
						}
						break;

					case parserState::awaitingAssignmentOperator:
						// Position 1 should be the first thing after ')'.

						searchPos2 = srcLine.find('=', searchPos1);
						if (searchPos2 != srcLine.find_first_not_of(" \t", searchPos1))
						{
							// the first thing on this line isn't a '=', so we've got an HC() missing an assignment.
							std::cout << "Hot Constants:  Reload Failure: \'=\' not found after macro invocation.\n                "
								"Value: " << HCNameStr << ", File: " << filename << "Line: " << macroLine << std::endl;
							HCTypeStr.clear();
							currentState = parserState::awaitingMacro;
						}
						else
						{
							// If nothing is on the line at all, we continue looking for the '=' on the next line.
							if (searchPos2 == std::string::npos)
							{
								searchPos1 = 0;
								stillParsingLine = false;
							}
							else
							{
								if (searchPos2 < srcLine.length() - 1)
								{
									if (srcLine.at(searchPos2 + 1) == '=')
									{
										std::cout << "Hot Constants:  Reload Failure: \"==\" encountered after macro invocation.  "
											"Did you mean to use \'=\'?\n                Value: \"" << HCNameStr << "\", File: " << filename
											<< ", Line: " << macroLine << std::endl;
										HCTypeStr.clear();
										currentState = parserState::awaitingMacro;
										searchPos1 = searchPos2 + 2; //move past the "==".
									}
									else
									{
										currentState = parserState::awaitingSemicolon;
										searchPos1 = searchPos2 + 1; //move past the '='.
									}

								}
								else
								{
									currentState = parserState::awaitingSemicolon;
									searchPos1 = searchPos2 + 1; //move past the '='.
								}
							}
						}
						break;

					case parserState::awaitingSemicolon:
						// Position 1 should be the first thing after the assignment operator.

						searchPos2 = srcLine.find(';', searchPos1);
						if (searchPos2 != std::string::npos)
						{
							carryover += srcLine.substr(searchPos1, searchPos2 - searchPos1);

							// Warn if type differs
							if (registeredTypeStrName != HCTypeStr)
							{
								std::cout << "Hot Constants:  Warning: \"" << HCNameStr << "\" was changed from type \"" <<
									registeredTypeStrName << "\" to type \"" << HCTypeStr << "\" in source.  "
									"The application will not reflect the new type until it is recompiled.\n                "
									"File: " << filename << ", Line: " << macroLine << std::endl;
							}

							if (carryover.find_first_not_of(" /r") != std::string::npos)
							{
								// Finally call reload function.
								if (reloadFn(carryover, valueIndex))
								{
									std::cout << "Hot Constants:  \"" << HCNameStr << "\" successfully reloaded!" << std::endl;
								}
								else
								{
									std::cout << "                Reload Failure: \"" << HCNameStr << "\" was not reloaded due to an issue "
										"evaluating its assignment.\n                File: " << filename << ", Line: " << macroLine << std::endl;
								}
							}
							else
							{
								std::cout << "Hot Constants:  Reload Failure: Expression not found after macro invocation.\n                "
									"Value: \"" << HCNameStr << "\", File: " << filename << ", Line: " << macroLine << std::endl;
							}
							carryover.clear();
							HCTypeStr.clear();
							currentState = parserState::awaitingMacro;
							searchPos1 = searchPos2 + 1; // move past ';'.
						}
						else
						{
							carryover += srcLine.substr(searchPos1);
							searchPos1 = 0;
							stillParsingLine = false;
						}
					}
				}
			}

			if (currentState != parserState::awaitingMacro)
			{
				std::cout << "Hot Constants:  Reload Failure: EOF reached before end of macro invocation."
					"\n                File: " << filename << ", Line: " << macroLine << std::endl;
			}

			srcFile.close();

			break;
		}
		else
		{
			std::cout << "Hot Constants:  Reload failure: \"" << filename <<
				"\" failed to open.  Reattempting in 500ms." << std::endl;
			repeatCount++;
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			srcFile.open(filename);
		}
	}

	if (repeatCount >= 5)
	{
		std::cout << "Hot Constants:  \"" << filename << "\" still fails to "
			"open 2.5 seconds after save.  Reload aborted." << std::endl;
	}
}

}
