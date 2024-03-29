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
