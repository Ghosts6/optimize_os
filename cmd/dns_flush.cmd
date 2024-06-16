@echo off

echo Flushing DNS resolver cache...

ipconfig /flushdns
ipconfig /registerdns
ipconfig /release
ipconfig /renew

echo DNS resolver cache flushed successfully.

echo DNS cache flush complete.

pause
