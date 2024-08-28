#!/bin/bash

fix_missing() {
    echo "Updating package lists and fixing missing dependencies..."
    sudo apt-get update --fix-missing
}

fix_broken_packages() {
    echo "Fixing broken packages..."
    sudo apt-get install -f
}

reconfigure_packages() {
    echo "Reconfiguring all packages..."
    sudo dpkg --configure -a
}

clean_package_cache() {
    echo "Cleaning up package cache..."
    sudo apt-get clean
}

autoremove_packages() {
    echo "Removing unnecessary packages..."
    sudo apt-get autoremove
}

autoclean_package_cache() {
    echo "Removing old downloaded package files..."
    sudo apt-get autoclean
}

update_and_upgrade() {
    echo "Updating and upgrading the system..."
    sudo apt-get update && sudo apt-get upgrade -y
}

fix_corrupted_dpkg() {
    echo "Attempting to fix corrupted dpkg status..."
    sudo mv /var/lib/dpkg/status /var/lib/dpkg/status.old
    sudo cp /var/lib/dpkg/status-old /var/lib/dpkg/status
}

fix_missing
fix_broken_packages
reconfigure_packages
clean_package_cache
autoremove_packages
autoclean_package_cache
update_and_upgrade
fix_corrupted_dpkg

echo "All tasks completed. Your system should be fixed now!"
