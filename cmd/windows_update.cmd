@echo off

echo Updating Windows...
powershell -command "Install-Module PSWindowsUpdate -Force -SkipPublisherCheck"
powershell -command "Import-Module PSWindowsUpdate; Get-WindowsUpdate -Install -AcceptAll -AutoReboot"

echo Windows update complete.

pause