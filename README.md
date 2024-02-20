![baner](https://github.com/Ghosts6/Local-website/blob/main/img/Baner.png)

# optimize

Inside this repo i place two c++ file to optimize linux and windows os,with help of this file you can optimize your system and make it faster just remind that for using this file you need admin access for windows you need run it as administrator and for linux you need password cuz command run on sudo and for compile codes  you can use this commands 'gpp -o optimize optimize.cpp' or 'g++ -o optimize optimize.cpp' and then you can run it

# 💻windows:

For windows we use command like sfc ,dism ,del , sconfig and cleanmgr to scan and fix problem and also update os and near them we will remove temp file to optimize system
```cpp
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
```

# 🖥️Linux:

Here we have c++ code that i write to optimize linux distribtions include debian ,redhat and arch,inside code we have method to decarle distro and run update command for that distro
```cpp
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// distribution type
enum DistributionType {
    DEBIAN,
    ARCH,
    REDHAT,
    UNKNOWN
};

// Function declarations
void runCommand(const char* command);
DistributionType getDistributionType();

int main() {
    DistributionType targetDistribution = getDistributionType();

    const char* updateCommand;
    const char* upgradeCommand;
    const char* autoremoveCommand;

    switch (targetDistribution) {
        case DEBIAN:
            updateCommand = "sudo apt update";
            upgradeCommand = "sudo apt upgrade -y";
            autoremoveCommand = "sudo apt autoremove -y";
            break;

        case ARCH:
            updateCommand = "sudo pacman -Sy";
            upgradeCommand = "sudo pacman -Syu --noconfirm";
            autoremoveCommand = "sudo pacman -Rns $(pacman -Qtdq) --noconfirm";
            break;

        case REDHAT:
            updateCommand = "sudo yum update -y";
            upgradeCommand = "sudo yum upgrade -y";
            autoremoveCommand = "sudo yum autoremove -y";
            break;

        default:
            cerr << "Unsupported or unidentified distribution" << endl;
            return 1;
    }

    cout << "Updating the system..." << endl;
    runCommand(updateCommand);

    cout << "\nUpgrading the system..." << endl;
    runCommand(upgradeCommand);

    cout << "\nPerforming autoremove..." << endl;
    runCommand(autoremoveCommand);

    cout << "\nFinished updating and optimizing the system." << endl;
    return 0;
}

void runCommand(const char* command) {
    int result = system(command);
    if (result == 0) {
        cout << "Command executed successfully." << endl;
    } else {
        cerr << "Command execution failed with error code: " << result << endl;
    }
}

DistributionType getDistributionType() {
    const char* lsbReleaseCommand = "lsb_release -a";
    FILE* pipe = popen(lsbReleaseCommand, "r");

    if (pipe) {
        char buffer[128];
        std::string result = "";
        while (!feof(pipe)) {
            if (fgets(buffer, 128, pipe) != nullptr)
                result += buffer;
        }
        pclose(pipe);

        // Check if the result contains "Ubuntu"
        if (result.find("Ubuntu") != std::string::npos) {
            return DEBIAN;
        }

        // Check if the result contains "Arch"
        if (result.find("Arch") != std::string::npos) {
            return ARCH;
        }

        // Check if the result contains "Red Hat" or "CentOS" or "Fedora"
        if (result.find("Red Hat") != std::string::npos || result.find("CentOS") != std::string::npos || result.find("Fedora") != std::string::npos) {
            return REDHAT;
        }
    }

    return UNKNOWN;
}
```
