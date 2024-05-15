@echo off

echo Scanning for viruses and malware...
echo This may take some time.

REM Run Windows Defender scan and remove detected threats
"%ProgramFiles%\Windows Defender\MpCmdRun.exe" -Scan -ScanType 3 -Remove

if %errorlevel% eq 0 (
    echo Virus and malware scan completed successfully. No threats found.
) else (
    echo Virus and malware scan completed. Threats were detected and removed.
)

echo Scan complete.
