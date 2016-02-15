# MagzorI2C library for the Raspberry Pi.
A library which provides control for Magzor devices and additional devices.  
Visit http://magzor.com/magzor-unified-i2c-library for more information on this library.  
Visit http://www.magzor.com for more information and try out our MDP!  
##### Currently supports the following Raspberry Pi boards:
* Raspberry Pi Model A
* Raspberry Pi Model B rev 2
* Raspberry Pi Model A+
* Raspberry Pi Model B+
* Raspberry Pi 2 Model A
* Raspberry Pi 2 Model B
* Raspberry Pi Zero

## Prerequisites
* Raspbian
* wiringPi: http://wiringpi.com/download-and-install/

## Installation Instructions
1. Download the Zip folder. You can download this folder directly onto your Pi using a web-browser or download it to your system and transfer it to the Pi. For Windows users, WinSCP is a great tool for file management on a remote system.
2. Extract the contents onto the Raspberry Pi. While in a terminal on the Pi, you can navigate to the directory where the Zip folder is downloaded and extract the contents using the following command:```unzip libMagzorI2C.zip -d {target directory}```
3. Go into the folder that contains the *install* file:```cd {path from your current directory}/libMagzorI2C```  
Make sure you are in the folder or else the install script won't work.
4. Run the command: ```./install.sh```
You may have to run as root (use sudo before the command) and change the permission on this install file to use it by typing the following command into the terminal on your Pi: ```chmod 755 install.sh```

## Examples
Check out the examples folder for examples.
## License
GNU Lesser General Public License: http://www.gnu.org/licenses/lgpl-3.0.en.html
