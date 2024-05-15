@echo off

echo Checking system files integrity...
sfc /scannow
if %errorlevel% neq 0 (
    echo Error: System file integrity check failed.
    goto :eof
)
echo SFC scan completed.

echo Checking system health...
DISM /Online /Cleanup-Image /ScanHealth
DISM /Online /Cleanup-Image /CheckHealth
DISM /Online /Cleanup-Image /RestoreHealth
if %errorlevel% neq 0 (
    echo Error: System health check or restoration failed.
    goto :eof
)
echo System health check and restoration completed successfully.

echo System update complete.

echo Do you want to reboot your system now? (Y/N)
set /p choice=
if /i "%choice%"=="Y" (
    shutdown /r /t 0
) else (
    echo Please reboot your system to apply changes.
)
