@echo off

echo Resetting network settings...
netsh winsock reset
netsh int ip reset
netsh advfirewall reset

echo Network settings reset complete.

pause