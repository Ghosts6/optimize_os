import subprocess
import platform
import os
from datetime import datetime

def run_command(command):
    process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
    output, error = process.communicate()
    return output.decode(), error.decode()

def system_info():
    system_info = {
        "Date": str(datetime.now()),
        "Platform": platform.system(),
        "Release": platform.release(),
        "Version": platform.version(),
        "Architecture": platform.architecture(),
        "Processor": platform.processor(),
    }
    return system_info

def log_data(log_data):
    with open("log.txt", "a") as log_file:
        for key, value in log_data.items():
            log_file.write(f"{key}: {value}\n")
        log_file.write("\n")

def main():
    distro_info, _ = run_command("lsb_release -a")
    print("Distro Info:")
    print(distro_info)

    system_info = system_info()
    print("\nSystem Info:")
    for key, value in system_info.items():
        print(f"{key}: {value}")

    log_data(system_info)

    distro_info_lower = distro_info.lower()
    
    if "debian" in distro_info_lower or "ubuntu" in distro_info_lower or "mint" in distro_info_lower:
        print("\nRunning commands for Debian-based system:")
        run_command("sudo apt update && sudo apt upgrade -y && sudo apt autoremove -y")

    elif "redhat" in distro_info_lower or "centos" in distro_info_lower:
        print("\nRunning commands for Red Hat-based system:")
        run_command("sudo yum update -y && sudo yum upgrade -y && sudo yum autoremove -y")

    elif "arch" in distro_info_lower:
        print("\nRunning commands for Arch Linux:")
        run_command("sudo pacman -Syu --noconfirm")

    else:
        print("\nError,unsupported os.")

if __name__ == "__main__":
    main()

