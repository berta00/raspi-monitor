# raspi-monitor auto installation script

if ls /bin/raspi-monitor; then
    git stash
    git pull
    # compile for linux
    gcc ./../source/raspi-monitor.c -w -o ./../bin/raspi-monitor
    # move to /bin directoryß
    sudo mv ./../bin/raspi-monitor /bin/raspi-monitor
    echo "installed and updated"
    
else
    # compile for linux
    gcc ./../source/raspi-monitor.c -w -o ./../bin/raspi-monitor
    # move to /bin directory
    sudo mv ./../bin/raspi-monitor /bin/raspi-monitor
    echo "installed"
fi

echo "bye!"
