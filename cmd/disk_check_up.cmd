@echo off

echo Optimizing and boosting system performance...
echo This may take some time.

REM Clear temporary files
echo Clearing temporary files...
del /q "%temp%\*" >nul 2>&1
echo Temporary files cleared successfully.

REM Run Disk Cleanup
echo Running Disk Cleanup...
cleanmgr /sagerun:1 >nul 2>&1
echo Disk Cleanup completed.

REM Run Disk Defragmentation
echo Running Disk Defragmentation...
defrag C: /v >nul 2>&1
echo Disk Defragmentation completed.

REM Run Check Disk
echo Running Check Disk...
chkdsk C: /f /r /x
echo Check Disk completed.

REM Run System File Cleanup
echo Running System File Cleanup...
sfc /scannow >nul 2>&1
echo System File Cleanup completed.

echo System optimization complete.

pause