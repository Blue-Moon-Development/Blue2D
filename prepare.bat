@echo off

rem Copy assets to build directory
robocopy ./assets ./cmake-build-debug/app/assets /mir

rem robocopy returns non zero error code even when there is no real error
rem the following lets us return "errors" 1, 2, and 4 as 0

set/A errlev="%ERRORLEVEL% & 24"
exit/B %errlev%