#!/usr/bin/env bash

if (( $EUID != 0 )); then
    echo "Please run as root."
    exit
fi

HEADER_DIR="/usr/local/include/MagzorI2C/"
LIB_FILE="/usr/local/lib/libMagzorI2C.so"
echo "Uninstalling MagzorI2C library for the Raspberry Pi on your system."
echo "Deleting the library header files from: $HEADER_DIR ..."
\rm -rf $HEADER_DIR
echo "Deleting shared object files from: $LIB_FILE ..."
\rm $LIB_FILE
echo "Updating your ldconfig cache..."
sudo ldconfig
echo "...Done!"
