#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

// Function declarations
void runCommand(const char* command);
void sfcScannow();
void scanHealth();
void checkHealth();
void restoreHealth();
void removeTemp();
void updateOs();
void diskCleanup();

int main() {
    cout << "Running sfc /scannow..." << endl;
    sfcScannow();

    cout << "\nRunning DISM ScanHealth..." << endl;
    scanHealth();

    cout << "\nRunning DISM CheckHealth..." << endl;
    checkHealth();

    cout << "\nRunning DISM RestoreHealth..." << endl;
    restoreHealth();

    cout << "\nRemoving temporary files..." << endl;
    removeTemp();

    cout << "\nUpdating the operating system..." << endl;
    updateOs();

    cout << "\nRunning Disk Cleanup..." << endl;
    diskCleanup();

    cout << "\nFinished optimizing the PC." << endl;
    return 0;
}

void runCommand(const char* command) {
    int result = system(command);
    if (result == 0) {
        cout << "Command executed successfully." << endl;
    } else {
        cout << "Command execution failed with error code: " << result << endl;
    }
}

void sfcScannow() {
    const char* command = "sfc /scannow";
    runCommand(command);
}

void scanHealth() {
    const char* command = "dism /Online /Cleanup-Image /ScanHealth";
    runCommand(command);
}

void checkHealth() {
    const char* command = "dism /Online /Cleanup-Image /CheckHealth";
    runCommand(command);
}

void restoreHealth() {
    const char* command = "dism /Online /Cleanup-Image /RestoreHealth";
    runCommand(command);
}

void removeTemp() {
    const char* command = "del /q /f /s %temp%\*";
    runCommand(command);
}

void updateOs() {
    const char* command = "sconfig";
    runCommand(command);
}

void diskCleanup() {
    const char* command = "cleanmgr /sagerun:1";
    runCommand(command);
}
