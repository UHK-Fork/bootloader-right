> **DEPRECATION NOTICE:**

> This bootloader has been deprecated as a result of moving from Atmel AVR to the NXP Kinetis microcontrollers.

> You're welcome to check out the [new firmware](https://github.com/UltimateHackingKeyboard/firmware).

UHK right half bootloader
=========================

[![Changelog #186](https://img.shields.io/badge/changelog-%23186-lightgrey.svg)](https://changelog.com/186)

This is the bootloader of the right keyboard half of the [Ultimate Hacking Keyboard](https://UltimateHackingKeyboard.com).

`{ProgrammerName}` and `{ProgrammerPort}` are to be substituted with actual values below.

```bash
cd Bootloaders/CDC
make upload AVRDUDE_PROGRAMMER={ProgrammerName} AVRDUDE_PORT={ProgrammerPort}  # Build and upload the firmware.
make  fuses AVRDUDE_PROGRAMMER={ProgrammerName} AVRDUDE_PORT={ProgrammerPort}  # Set the fuses.
```

For the [AVR ISP mkII](http://www.bravekit.com/USB_AVR_ISP_AVRISP_mkII_programmer_PDI_TPI_ATxMega_Xmega) this translates to:

```bash
cd Bootloaders/CDC
make upload AVRDUDE_PROGRAMMER=avrispv2
make  fuses AVRDUDE_PROGRAMMER=avrispv2
```

Please note that the `fuses` makefile rule enables the BOOTRST fuse which jumps to the bootloader upon power up. The bootloader in turn jumps to the application by default unless an external reset has occurred. This makes USB enumeration fail right after uploading the bootloader because at that point the application is not uploaded yet. In order to be able to upload the application via the bootloader the GND and RESET pins of the ISP6 connector must be shorted, triggering the external reset condition, making the bootloader take over.

The LUFA CDC bootloader upon which this bootloader is based is licensed according to its own terms.  The modifications that were made upon the LUFA CDC bootloader are licensed under the [GPLv3](https://www.gnu.org/copyleft/gpl.html).
