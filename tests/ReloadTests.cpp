#include "_tests.h"
#include <HotConsts/HotConsts.h>
#include <iostream>
#include <fstream>

// Use backslashes in paths on Windows becaus'a fuckin' Microsoft
#ifdef _WIN32
#define TESTFILEDIR "ReloadTests\\"
#else
#define TESTFILEDIR "ReloadTests/"
#endif

// RELOAD TESTS

// Source code comment parsing
bool handleSingleLineComments()
{
	bool startsInMultiline = false;
	std::string beforeLine, afterLine;

	std::ifstream beforeFile(TESTFILEDIR "handleSingleLineComments_before.txt");
	std::ifstream afterFile(TESTFILEDIR "handleSingleLineComments_after.txt");
	if (beforeFile.is_open() && afterFile.is_open())
	{
		while (std::getline(beforeFile, beforeLine))
		{
			if (std::getline(afterFile, afterLine))
			{
				beforeLine = HotConsts::_stripComments(beforeLine, startsInMultiline);
				if (beforeLine != afterLine)
				{
					beforeFile.close();
					afterFile.close();
					return false;
				}
			}
			else
			{
				std::cout << "Number of lines in \"ReloadTests/handleSingleLineComments_before.txt\" and "
				"\"ReloadTests/handleSingleLineComments_after.txt\" differ." << std::endl;
				beforeFile.close();
				afterFile.close();
				return false;
			}
		}
	}
	else
	{
		std::cout << "Issue opening \"ReloadTests/handleSingleLineComments_before.txt\" or "
		"\"ReloadTests/handleSingleLineComments_after.txt\"" << std::endl;
		if (beforeFile.is_open())
			beforeFile.close();
		if (afterFile.is_open())
			afterFile.close();
		return false;
	}

	return true;
}

bool handleSingleLineCommentsInStrings()
{
	bool startsInMultiline = false;
	std::string beforeLine, afterLine;

	std::ifstream srcFile(TESTFILEDIR "handleSingleLineCommentsInStrings.txt");
	if (srcFile.is_open())
	{
		while (std::getline(srcFile, beforeLine))
		{
			afterLine = HotConsts::_stripComments(beforeLine, startsInMultiline);
			if (beforeLine != afterLine)
			{
				srcFile.close();
				return false;
			}
		}
	}
	else
	{
		std::cout << "Issue opening \"ReloadTests/handleSingleLineCommentsInStrings.txt\"." << std::endl;
		return false;
	}

	return true;
}

bool handleMultiLineComments()
{
	bool startsInMultiline = false;
	std::string beforeLine, afterLine;

	std::ifstream beforeFile(TESTFILEDIR "handleMultiLineComments_before.txt");
	std::ifstream afterFile(TESTFILEDIR "handleMultiLineComments_after.txt");
	if (beforeFile.is_open() && afterFile.is_open())
	{
		while (std::getline(beforeFile, beforeLine))
		{
			if (std::getline(afterFile, afterLine))
			{
				beforeLine = HotConsts::_stripComments(beforeLine, startsInMultiline);
				if (beforeLine != afterLine)
				{
					beforeFile.close();
					afterFile.close();
					return false;
				}
			}
			else
			{
				std::cout << "Number of lines in \"ReloadTests/handleMultiLineComments_before.txt\" and "
				"\"ReloadTests/handleMultiLineComments_after.txt\" differ." << std::endl;
				beforeFile.close();
				afterFile.close();
				return false;
			}
		}
	}
	else
	{
		std::cout << "Issue opening \"ReloadTests/handleMultiLineComments_before.txt\" or "
		"\"ReloadTests/handleMultiLineComments_after.txt\"" << std::endl;
		if (beforeFile.is_open())
			beforeFile.close();
		if (afterFile.is_open())
			afterFile.close();
		return false;
	}

	return true;
}

bool handleMultiLineCommentsInStrings()
{
	bool startsInMultiline = false;
	std::string beforeLine, afterLine;

	std::ifstream srcFile(TESTFILEDIR "handleMultiLineCommentsInStrings.txt");
	if (srcFile.is_open())
	{
		while (std::getline(srcFile, beforeLine))
		{
			afterLine = HotConsts::_stripComments(beforeLine, startsInMultiline);
			if (beforeLine != afterLine)
			{
				srcFile.close();
				return false;
			}
		}
	}
	else
	{
		std::cout << "Issue opening \"ReloadTests/handleMultiLineCommentsInStrings.txt\"." << std::endl;
		return false;
	}

	return true;
}

// Source code reload
bool reloadSimpleHC()
{
	const HotConsts::HC_Atomic<int>& reloadSimpleHC_testVal = HotConsts::_registerHotConst<int>(
		TESTFILEDIR "reloadSimpleHC.txt", "reloadSimpleHC_testVal", "int") = 1;
	HotConsts::_reloadSrcFile(TESTFILEDIR "reloadSimpleHC.txt");
	if (reloadSimpleHC_testVal == 100)
		return true;
	else
		return false;
}

bool reloadSingleHCWithTypeModifier()
{
	const HotConsts::HC_Atomic<unsigned int>& reloadSingleHCWithTypeModifier_testVal = HotConsts::_registerHotConst<unsigned int>(
		TESTFILEDIR "reloadSingleHCWithTypeModifier.txt", "reloadSingleHCWithTypeModifier_testVal", "unsigned int") = 1;
	HotConsts::_reloadSrcFile(TESTFILEDIR "reloadSingleHCWithTypeModifier.txt");
	if (reloadSingleHCWithTypeModifier_testVal == 100)
		return true;
	else
		return false;
}

bool reloadSingleHCWithLineBreaks()
{
	const HotConsts::HC_Atomic<int>& reloadSingleHCWithLineBreaks_testVal =
		HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadSingleHCWithLineBreaks.txt",
										  "reloadSingleHCWithLineBreaks_testVal", "int") = 1;
	HotConsts::_reloadSrcFile(TESTFILEDIR "reloadSingleHCWithLineBreaks.txt");
	if (reloadSingleHCWithLineBreaks_testVal == 100)
		return true;
	else
		return false;
}

bool reloadSingleHCWithTypeModifierAndLineBreaks()
{
	const HotConsts::HC_Atomic<int>& reloadSingleHCWithTypeModifierAndLineBreaks_testVal =
		HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadSingleHCWithTypeModifierAndLineBreaks.txt",
										  "reloadSingleHCWithTypeModifierAndLineBreaks_testVal", "unsigned int") = 1;
	HotConsts::_reloadSrcFile(TESTFILEDIR "reloadSingleHCWithTypeModifierAndLineBreaks.txt");
	if (reloadSingleHCWithTypeModifierAndLineBreaks_testVal == 100)
		return true;
	else
		return false;
}

bool reloadMultipleHCs()
{
	const HotConsts::HC_Atomic<int>& reloadMultipleHCs_testVal1 =
HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadMultipleHCs.txt",
								  "reloadMultipleHCs_testVal1", "int") = 1;
	const HotConsts::HC_Atomic<int>& reloadMultipleHCs_testVal2 =
HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadMultipleHCs.txt",
								  "reloadMultipleHCs_testVal2", "int") = 2;
	const HotConsts::HC_Atomic<int>& reloadMultipleHCs_testVal3 =
HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadMultipleHCs.txt",
								  "reloadMultipleHCs_testVal3", "int") = 3;

	HotConsts::_reloadSrcFile(TESTFILEDIR "reloadMultipleHCs.txt");
	if (reloadMultipleHCs_testVal1 == 100 &&
		reloadMultipleHCs_testVal2 == 200 &&
		reloadMultipleHCs_testVal3 == 300)
		return true;
	else
		return false;
}

bool reloadMutipleHCsSingleLine()
{
	const HotConsts::HC_Atomic<int>& reloadMultipleHCsSingleLine_testVal1 =
HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadMutipleHCsSingleLine.txt",
								  "reloadMultipleHCsSingleLine_testVal1", "int") = 1;
	const HotConsts::HC_Atomic<int>& reloadMultipleHCsSingleLine_testVal2 =
HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadMutipleHCsSingleLine.txt",
								  "reloadMultipleHCsSingleLine_testVal2", "int") = 2;
	const HotConsts::HC_Atomic<int>& reloadMultipleHCsSingleLine_testVal3 =
HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadMutipleHCsSingleLine.txt",
								  "reloadMultipleHCsSingleLine_testVal3", "int") = 3;

	HotConsts::_reloadSrcFile(TESTFILEDIR "reloadMutipleHCsSingleLine.txt");
	if (reloadMultipleHCsSingleLine_testVal1 == 100 &&
		reloadMultipleHCsSingleLine_testVal2 == 200 &&
		reloadMultipleHCsSingleLine_testVal3 == 300)
		return true;
	else
		return false;
}

bool reloadIgnoresMacroInStrings()
{
	const HotConsts::HC_Atomic<int>& reloadIgnoresMacroInStrings_testVal1 =
HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadIgnoresMacroInStrings.txt",
								  "reloadIgnoresMacroInStrings_testVal1", "int") = 100;
	HotConsts::_reloadSrcFile(TESTFILEDIR "reloadIgnoresMacroInStrings.txt");
	if (reloadIgnoresMacroInStrings_testVal1 == 100)
		return true;
	else
		return false;
}

bool reloadSkipsSymbolsContainingHC()
{
	const HotConsts::HC_Atomic<int>& reloadSkipsSymbolsContainingHC_testVal1 =
		HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadSkipsSymbolsContainingHC.txt",
										  "reloadSkipsSymbolsContainingHC_testVal1", "int") = 1;
	const HotConsts::HC_Atomic<int>& reloadSkipsSymbolsContainingHC_testVal2 =
		HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadSkipsSymbolsContainingHC.txt",
										  "reloadSkipsSymbolsContainingHC_testVal2", "int") = 2;
	const HotConsts::HC_Atomic<int>& reloadSkipsSymbolsContainingHC_testVal3 =
		HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadSkipsSymbolsContainingHC.txt",
										  "reloadSkipsSymbolsContainingHC_testVal3", "int") = 3;
	const HotConsts::HC_Atomic<int>& reloadSkipsSymbolsContainingHC_testVal4 =
		HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadSkipsSymbolsContainingHC.txt",
										  "reloadSkipsSymbolsContainingHC_testVal4", "int") = 4;
	const HotConsts::HC_Atomic<int>& reloadSkipsSymbolsContainingHC_testVal5 =
		HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadSkipsSymbolsContainingHC.txt",
										  "reloadSkipsSymbolsContainingHC_testVal5", "int") = 5;
	const HotConsts::HC_Atomic<int>& reloadSkipsSymbolsContainingHC_testVal6 =
		HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadSkipsSymbolsContainingHC.txt",
										  "reloadSkipsSymbolsContainingHC_testVal6", "int") = 6;
	const HotConsts::HC_Atomic<int>& reloadSkipsSymbolsContainingHC_testVal7 =
		HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadSkipsSymbolsContainingHC.txt",
										  "reloadSkipsSymbolsContainingHC_testVal7", "int") = 7;
	const HotConsts::HC_Atomic<int>& reloadSkipsSymbolsContainingHC_testVal8 =
		HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadSkipsSymbolsContainingHC.txt",
										  "reloadSkipsSymbolsContainingHC_testVal8", "int") = 8;
	const HotConsts::HC_Atomic<int>& reloadSkipsSymbolsContainingHC_testVal9 =
		HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadSkipsSymbolsContainingHC.txt",
										  "reloadSkipsSymbolsContainingHC_testVal9", "int") = 9;
	const HotConsts::HC_Atomic<int>& reloadSkipsSymbolsContainingHC_testVal10 =
		HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadSkipsSymbolsContainingHC.txt",
										  "reloadSkipsSymbolsContainingHC_testVal10", "int") = 10;

	HotConsts::_reloadSrcFile(TESTFILEDIR "reloadSkipsSymbolsContainingHC.txt");
	if (reloadSkipsSymbolsContainingHC_testVal1 == 1 &&
		reloadSkipsSymbolsContainingHC_testVal2 == 2 &&
		reloadSkipsSymbolsContainingHC_testVal3 == 3 &&
		reloadSkipsSymbolsContainingHC_testVal4 == 4 &&
		reloadSkipsSymbolsContainingHC_testVal5 == 5 &&
		reloadSkipsSymbolsContainingHC_testVal6 == 6 &&
		reloadSkipsSymbolsContainingHC_testVal7 == 7 &&
		reloadSkipsSymbolsContainingHC_testVal8 == 8 &&
		reloadSkipsSymbolsContainingHC_testVal9 == 9 &&
		reloadSkipsSymbolsContainingHC_testVal10 == 10)
		return true;
	else
		return false;
}

// Bad source code reload

bool reloadCatchesFileOpenFailure()
{
	HotConsts::_reloadSrcFile("NonexistentFolder/Nonexistentfile.bad");
	return true;
}

bool reloadHandlesBadParams()
{
	const HotConsts::HC_Atomic<int>& testConst =
		HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadHandlesBadParams.txt",
										  "testConst", "int") = 1;
	HotConsts::_reloadSrcFile(TESTFILEDIR "reloadHandlesBadParams.txt");
	if (testConst == 1)
		return true;
	else
		return false;
}

bool reloadHandlesBadAssignment()
{
	const HotConsts::HC_Atomic<int>& reloadHandlesBadAssignment_testVal1 =
		HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadHandlesBadAssignment.txt",
										  "reloadHandlesBadAssignment_testVal1", "int") = 1;
//    const HotConsts::HC_Atomic<int>& reloadHandlesBadAssignment_testVal2 =
//		HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadHandlesBadAssignment.txt",
//										  "reloadHandlesBadAssignment_testVal2", "int") = 2;
	const HotConsts::HC_Atomic<int>& reloadHandlesBadAssignment_testVal3 =
		HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadHandlesBadAssignment.txt",
										  "reloadHandlesBadAssignment_testVal3", "int") = 3;
	const HotConsts::HC_Atomic<int>& reloadHandlesBadAssignment_testVal4 =
		HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadHandlesBadAssignment.txt",
										  "reloadHandlesBadAssignment_testVal4", "int") = 4;
	const HotConsts::HC_Atomic<int>& reloadHandlesBadAssignment_testVal5 =
		HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadHandlesBadAssignment.txt",
										  "reloadHandlesBadAssignment_testVal5", "int") = 5;
	const HotConsts::HC_Atomic<int>& reloadHandlesBadAssignment_testVal6 =
		HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadHandlesBadAssignment.txt",
										  "reloadHandlesBadAssignment_testVal6", "int") = 6;

	HotConsts::_reloadSrcFile(TESTFILEDIR "reloadHandlesBadAssignment.txt");
	if (reloadHandlesBadAssignment_testVal1 == 1 &&
		// TODO: Avoid discarding line after a macro invocation that's missing a semicolon
//        reloadHandlesBadAssignment_testVal2 == 200 &&
		reloadHandlesBadAssignment_testVal3 == 3 &&
		reloadHandlesBadAssignment_testVal4 == 4 &&
		reloadHandlesBadAssignment_testVal5 == 5 &&
		reloadHandlesBadAssignment_testVal6 == 6)
		return true;
	else
		return false;
}

bool reloadHandlesNewParams()
{
	const HotConsts::HC_Atomic<int>& reloadHandlesNewParams_testVal1 =
		HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadHandlesNewParams.txt",
										  "reloadHandlesNewParams_testVal1", "int") = 1;
	const HotConsts::HC_Atomic<int>& reloadHandlesNewParams_testVal2 =
		HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadHandlesNewParams.txt",
										  "reloadHandlesNewParams_testVal2", "int") = 1;

	HotConsts::_reloadSrcFile(TESTFILEDIR "reloadHandlesNewParams.txt");
	if (reloadHandlesNewParams_testVal1 == 1 &&
		reloadHandlesNewParams_testVal2 == 200)
		return true;
	else
		return false;
}

bool reloadHandlesRedefinitions()
{
	const HotConsts::HC_Atomic<int>& reloadHandlesRedefinitions_testVal1 =
		HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadHandlesRedefinitions.txt",
										  "reloadHandlesRedefinitions_testVal1", "int") = 1;
	HotConsts::_reloadSrcFile(TESTFILEDIR "reloadHandlesRedefinitions.txt");
	if (reloadHandlesRedefinitions_testVal1 == 100)
		return true;
	else
		return false;
}

bool reloadHandlesEOF_awaitingLParentheses()
{
	const HotConsts::HC_Atomic<int>& reloadHandlesEOF_awaitingLParentheses_testVal1 =
		HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadHandlesEOF_awaitingLParentheses.txt",
										  "reloadHandlesEOF_awaitingLParentheses_testVal1", "int") = 1;
	HotConsts::_reloadSrcFile(TESTFILEDIR "reloadHandlesEOF_awaitingLParentheses.txt");
	if (reloadHandlesEOF_awaitingLParentheses_testVal1 == 1)
		return true;
	else
		return false;
}

bool reloadHandlesEOF_awaitingParam1()
{
	const HotConsts::HC_Atomic<int>& reloadHandlesEOF_awaitingParam1_testVal1 =
		HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadHandlesEOF_awaitingParam1.txt",
										  "reloadHandlesEOF_awaitingParam1_testVal1", "int") = 1;
	HotConsts::_reloadSrcFile(TESTFILEDIR "reloadHandlesEOF_awaitingParam1.txt");
	if (reloadHandlesEOF_awaitingParam1_testVal1 == 1)
		return true;
	else
		return false;
}

bool reloadHandlesEOF_awaitingComma()
{
	const HotConsts::HC_Atomic<int>& reloadHandlesEOF_awaitingComma_testVal1 =
		HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadHandlesEOF_awaitingComma.txt",
										  "reloadHandlesEOF_awaitingComma_testVal1", "int") = 1;
	HotConsts::_reloadSrcFile(TESTFILEDIR "reloadHandlesEOF_awaitingComma.txt");
	if (reloadHandlesEOF_awaitingComma_testVal1 == 1)
		return true;
	else
		return false;
}

bool reloadHandlesEOF_awaitingParam2()
{
	const HotConsts::HC_Atomic<int>& reloadHandlesEOF_awaitingParam2_testVal1 =
		HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadHandlesEOF_awaitingParam2.txt",
										  "reloadHandlesEOF_awaitingParam2_testVal1", "int") = 1;
	HotConsts::_reloadSrcFile(TESTFILEDIR "reloadHandlesEOF_awaitingParam2.txt");
	if (reloadHandlesEOF_awaitingParam2_testVal1 == 1)
		return true;
	else
		return false;
}

bool reloadHandlesEOF_awaitingRParentheses()
{
	const HotConsts::HC_Atomic<int>& reloadHandlesEOF_awaitingRParentheses_testVal1 =
		HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadHandlesEOF_awaitingRParentheses.txt",
										  "reloadHandlesEOF_awaitingRParentheses_testVal1", "int") = 1;
	HotConsts::_reloadSrcFile(TESTFILEDIR "reloadHandlesEOF_awaitingRParentheses.txt");
	if (reloadHandlesEOF_awaitingRParentheses_testVal1 == 1)
		return true;
	else
		return false;
}

bool reloadHandlesEOF_awaitingAssignmentOperator()
{
	const HotConsts::HC_Atomic<int>& reloadHandlesEOF_awaitingAssignmentOperator_testVal1 =
		HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadHandlesEOF_awaitingAssignmentOperator.txt",
										  "reloadHandlesEOF_awaitingAssignmentOperator_testVal1", "int") = 1;
	HotConsts::_reloadSrcFile(TESTFILEDIR "reloadHandlesEOF_awaitingAssignmentOperator.txt");
	if (reloadHandlesEOF_awaitingAssignmentOperator_testVal1 == 1)
		return true;
	else
		return false;
}

bool reloadHandlesEOF_awaitingSemicolon()
{
	const HotConsts::HC_Atomic<int>& reloadHandlesEOF_awaitingSemicolon_testVal1 =
		HotConsts::_registerHotConst<int>(TESTFILEDIR "reloadHandlesEOF_awaitingSemicolon.txt",
										  "reloadHandlesEOF_awaitingSemicolon_testVal1",
										  "int") = 1;
	HotConsts::_reloadSrcFile(TESTFILEDIR "reloadHandlesEOF_awaitingSemicolon.txt");
	if (reloadHandlesEOF_awaitingSemicolon_testVal1 == 1)
		return true;
	else
		return false;
}

bool fileChangeTriggersReload()
{
	std::ofstream srcFile(TESTFILEDIR "fileChangeTriggersReload.txt", std::ios_base::trunc);
	if (srcFile.is_open())
	{
		// First, set the source file to a "previous" state.
		srcFile << "#include <HotConsts/HotConsts.h>\n\nHC(int, fileChangeTriggersReload_testVal1) = 1;\n";
		srcFile.close();

		// Simulate a macro invocation from the test file.
		// Hack: The path to the file in this test must be a full path to work correctly on macOS.
		std::string thisDirectory;
#ifdef _WIN32
		thisDirectory = "ReloadTests\\fileChangeTriggersReload.txt";
#else
		std::string thisfile(__FILE__);
		auto postSlashPos = thisfile.rfind("ReloadTests.cpp");
		thisDirectory = thisfile.substr(0, postSlashPos) + "ReloadTests/fileChangeTriggersReload.txt";
#endif
		const HotConsts::HC_Atomic<int>& fileChangeTriggersReload_testVal1 =
			HotConsts::_registerHotConst<int>(thisDirectory.c_str(),
											  "fileChangeTriggersReload_testVal1",
											  "int") = 1;

		// After being registered, change the file to have a new value.
		srcFile.open(TESTFILEDIR "fileChangeTriggersReload.txt", std::ios_base::trunc);
		if (srcFile.is_open())
		{
			srcFile << "#include <HotConsts/HotConsts.h>\n\nHC(int, fileChangeTriggersReload_testVal1) = 100;\n";
			srcFile.close();

			std::this_thread::sleep_for(std::chrono::milliseconds(200)); //macOS reload latency is set to 100ms

			// See if new value has been loaded.
			// Sleep is to ensure asynchronous calls have time to complete.
			if (fileChangeTriggersReload_testVal1 == 100)
				return true;
			else
				return false;
		}
		else
		{
			std::cout << "Error reopening ReloadTests/fileChangeTriggersReload.txt." << std::endl;
			return false;
		}
	}
	else
	{
		std::cout << "Error opening ReloadTests/fileChangeTriggersReload.txt." << std::endl;
		return false;
	}

}
