@echo off
echo Launching program...

if exist out\build\program.exe (
    cd out\build
    program.exe
    cd ..
) else (
    echo Program not found. Build it first!
)

echo Run finished.
pause