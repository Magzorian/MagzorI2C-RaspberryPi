#!/usr/bin/env bash

if (( $EUID != 0 )); then
    echo "Please run as root."
    exit
fi

HEADER_DIR="/usr/local/include/MagzorI2C/"
LIB_DIR="/usr/local/lib/"
echo "Installing MagzorI2C library for the Raspberry Pi on your system."
echo "Ensure wiringPi is installed in order to utilized this library."
echo "Copying over library header files to: $HEADER_DIR ..."
mkdir -p $HEADER_DIR
\cp -vr include/* $HEADER_DIR
echo "Copying shared object files to: $LIB_DIR ..."
\cp -v lib/libMagzorI2C.so* $LIB_DIR
echo "Updating your ldconfig cache..."
sudo ldconfig
echo "...Done!"
