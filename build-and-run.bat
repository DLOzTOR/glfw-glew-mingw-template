@echo off
echo Starting build and run...

call build.bat
if %ERRORLEVEL% NEQ 0 (
    echo Build failed, stopping.
    pause
    exit /b %ERRORLEVEL%
)

call run.bat

echo Build and run completed.