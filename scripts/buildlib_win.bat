@echo off
pushd %~dp0\..\tests
CALL ..\scripts\premake\premake5.exe vs2019
popd
PAUSE