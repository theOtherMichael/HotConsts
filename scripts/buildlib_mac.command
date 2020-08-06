#!/bin/bash
cd "`dirname "$0"`"
cd ".."
# Add user permission to execute premake
chmod u+x scripts/premake/premake5
# Invoke the premake build script
scripts/premake/premake5 xcode4

read -s -n 1 -p "Press any key to continue . . ."
echo ""
