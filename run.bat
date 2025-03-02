@echo off
echo Launching program...

if exist out\program.exe (
    cd out
    program.exe
    cd ..
) else (
    echo Program not found. Build it first!
)

echo Run finished.
pause