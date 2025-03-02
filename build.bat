@echo off
echo Building project...

cmake -G "MinGW Makefiles" -S . -B out
if %ERRORLEVEL% NEQ 0 (
    echo CMake configuration failed.
    exit /b %ERRORLEVEL%
)

mingw32-make -C out
if %ERRORLEVEL% NEQ 0 (
    echo Build failed.
    exit /b %ERRORLEVEL%
)

echo Build completed.