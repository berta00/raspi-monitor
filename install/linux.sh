
// raspi-monitor auto installation script

if ls /bin/raspi-monitor; then
    echo "already installed"
elseßß
    mv ./../bin/raspi-monitor /bin/raspi-monitor
    echo "installed"
fi

echo "bye!"