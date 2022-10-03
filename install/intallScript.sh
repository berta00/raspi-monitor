# build in raspiban
gcc ../source/raspi-monitor.c -w -o ../bin/raspi-monitor

# copy binary in /bin directory
cp ../bin/raspi-monitor /bin/raspi-monitor

echo "binary compiled and moved to /bin directory"

