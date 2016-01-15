===============================
Deltaprintr 3D Printer Firmware
===============================

Based on Marlin, see README.orig.md.

This firmware includes all patches and fixes collected and created by user @johntron.
Thank you for the good work, John.

I added some fixes to have it compile in Arduino IDE 1.6+.

Build instructions (Gentoo Linux 64Bit)
=======================================

1. As user `root`, install avrdude
```
mkdir -p /etc/portage/package.use
echo "dev-embedded/avrdude ftdi" >> /etc/portage/package.use/avrdude
emerge -NDuv avrdude
```
2.1. Download Arduino IDE 1.6.7 for Linux 64 bits from https://www.arduino.cc/en/Main/Software
2.2. Download the TeensyDuino Linux Installer (64 bit) from https://www.pjrc.com/teensy/td_download.html
2.3. Download the Teensy udev rules from https://www.pjrc.com/teensy/49-teensy.rules
3. As user `root`, copy the udev rules to /etc/udev/rules.d/
```
sudo cp 49-teensy.rules /etc/udev/rules.d/
```
4. Create a working directory and untar `arduino-1.6.7.tar.xz`
```
mkdir -p ~/projects/deltaprintr
tar xpf arduino-1.6.7.tar.xz -C ~/projects/deltaprintr
```
5. Replace the avrdude binary that came with the Arduino IDE
```
ln -sf /usr/bin/avrdude ~/projects/deltaprintr/arduino-1.6.7/hardware/tools/avr/bin/avrdude
rm -f ~/projects/deltaprintr/arduino-1.6.7/hardware/tools/avr/bin/avrdude_bin
```
6. Launch the TeensyDuino installer (`teensyduino.64bit`) and choose `~/projects/deltaprintr/arduino-1.6.7` as installation directory
7.1. Clone this repository
```
cd ~/projects/deltaprintr
git clone git@github.com:tkurbad/Deltaprintr-Firmware.git
```
7.2. Connect your Deltaprintr via USB
7.3. Make sure, the corresponding serial port device `/dev/ttyACM*` gets created
7.4. Open `~/projects/deltaprintr/Deltaprintr-Firmware/Marlin/Marlin.ino` in the Arduino IDE
```
cd ~/projects/deltaprintr/arduino-1.6.7
./arduino ~/projects/deltaprintr/Deltaprintr-Firmware/Marlin/Marlin.ino
```
7.5. In the Arduino IDE, choose 'Tools' -> 'Board' -> 'Arduino/Genuino Mega or Mega 2560'
7.6. Choose the right Serial Port
7.7. Add required libraries. In the Arduino IDE, choose 'Sketch' -> 'Include library' -> 'Manage libraries'.
Click on 'Time' -> 'Install' and 'u8glib' -> Install
8.1 Choose 'Sketch' -> 'Verify/Compile'
8.2. There will be a compiler warning from `u8g_rot.c` that can be safely ignored (s. https://github.com/olikraus/u8glib/issues/366)
The last two lines of the output should look similar to:
```
Sketch uses 123,110 bytes (48%) of program storage space. Maximum is 253,952 bytes.
Global variables use 6,001 bytes (73%) of dynamic memory, leaving 2,191 bytes for local variables. Maximum is 8,192 bytes.
```
8.3. Now you can choose 'Sketch' -> 'Upload' to upload the firmware to your printer
