#!/bin/sh

./bin/set_max1932 192.168.10.16 255
sleep 10
./bin/set_max1932 192.168.10.16 210
sleep 10
./bin/set_max1932 192.168.10.16 180
sleep 10
./bin/set_max1932 192.168.10.16 150
sleep 10
./bin/set_max1932 192.168.10.16 120
sleep 10
./bin/set_max1932 192.168.10.16 90
sleep 10
./bin/set_max1932 192.168.10.16 60
sleep 10
./bin/set_max1932 192.168.10.16 28

echo "Finish startup_max1932.sh"
