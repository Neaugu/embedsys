#!/bin/bash

export LED=117
#create access functions /sys/class/gpio/gpio$LED/
echo $LED > /sys/class/gpio/export
echo out > /sys/class/gpio/gpio$LED/direction

# we test the led by turning it on
echo 1 > /sys/class/gpio/gpio$LED/value






