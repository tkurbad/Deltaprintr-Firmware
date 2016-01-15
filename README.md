===============================
Deltaprintr 3D Printer Firmware
===============================

Based on Marlin, see README.orig.md.

This firmware includes all patches and fixes collected and created by user [johntron](https://github.com/johntron).
Thank you for the good work, John.

I added some fixes to have it compile in Arduino IDE 1.6+.

Build instructions (Gentoo Linux 64Bit)
=======================================

- As user `root`, install avrdude
```
mkdir -p /etc/portage/package.use
echo "dev-embedded/avrdude ftdi" >> /etc/portage/package.use/avrdude
emerge -NDuv avrdude
```
- Download Arduino IDE 1.6.7 for Linux 64 bits from https://www.arduino.cc/en/Main/Software
- Download the TeensyDuino Linux Installer (64 bit) from https://www.pjrc.com/teensy/td_download.html
- Download the Teensy udev rules from https://www.pjrc.com/teensy/49-teensy.rules
- As user `root`, copy the udev rules to /etc/udev/rules.d/
```
sudo cp 49-teensy.rules /etc/udev/rules.d/
```
- Create a working directory and untar `arduino-1.6.7.tar.xz`
```
mkdir -p ~/projects/deltaprintr
tar xpf arduino-1.6.7.tar.xz -C ~/projects/deltaprintr
```
- Replace the avrdude binary that came with the Arduino IDE
```
ln -sf /usr/bin/avrdude ~/projects/deltaprintr/arduino-1.6.7/hardware/tools/avr/bin/avrdude
rm -f ~/projects/deltaprintr/arduino-1.6.7/hardware/tools/avr/bin/avrdude_bin
```
- Launch the TeensyDuino installer (`teensyduino.64bit`) and choose `~/projects/deltaprintr/arduino-1.6.7` as installation directory
- Clone this repository
```
cd ~/projects/deltaprintr
git clone git@github.com:tkurbad/Deltaprintr-Firmware.git
```
- Connect your Deltaprintr via USB
- Make sure, the corresponding serial port device `/dev/ttyACM*` gets created
- Open `~/projects/deltaprintr/Deltaprintr-Firmware/Marlin/Marlin.ino` in the Arduino IDE
```
cd ~/projects/deltaprintr/arduino-1.6.7
./arduino ~/projects/deltaprintr/Deltaprintr-Firmware/Marlin/Marlin.ino
```
- In the Arduino IDE, choose 'Tools' &rarr; 'Board' &rarr; 'Arduino/Genuino Mega or Mega 2560'
- Choose the right Serial Port `/dev/ttyACM*`
- Add required libraries. In the Arduino IDE, choose 'Sketch' &rarr; 'Include library' &rarr; 'Manage libraries'.
Click on 'Time' &rarr; 'Install' and 'u8glib' &rarr; Install
- Choose 'Sketch' &rarr; 'Verify/Compile'
- There will be a compiler warning from `u8g_rot.c` that can be safely ignored (s. https://github.com/olikraus/u8glib/issues/366)
The last two lines of the output should look similar to:
```
Sketch uses 123,110 bytes (48%) of program storage space. Maximum is 253,952 bytes.
Global variables use 6,001 bytes (73%) of dynamic memory, leaving 2,191 bytes for local variables. Maximum is 8,192 bytes.
```
- Now you can choose 'Sketch' &rarr; 'Upload' to upload the firmware to your printer
