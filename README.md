UHK right half bootloader
=========================

This is the bootloader of the right keyboard half of the [Ultimate Hacking Keyboard](https://UltimateHackingKeyboard.com).

`{ProgrammerName}` and `{ProgrammerPort}` are to be substituted with actual values below.

```bash
cd Bootloaders/CDC
make upload AVRDUDE_PROGRAMMER={ProgrammerName} AVRDUDE_PORT={ProgrammerPort}  # Build and upload the firmware.
make  fuses AVRDUDE_PROGRAMMER={ProgrammerName} AVRDUDE_PORT={ProgrammerPort}  # Set the fuses.
```

For the [AVR ISP mkII](http://www.bravekit.com/USB_AVR_ISP_AVRISP_mkII_programmer_PDI_TPI_ATxMega_Xmega) this is:

```bash
cd Bootloaders/CDC
make upload AVRDUDE_PROGRAMMER=avrispv2
make  fuses AVRDUDE_PROGRAMMER=avrispv2
```

The LUFA CDC bootloader upon which this bootloader is based is licensed according to its own terms.  The modifications that were made upon the LUFA CDC bootloader are licensed under the [GPLv3](https://www.gnu.org/copyleft/gpl.html).
