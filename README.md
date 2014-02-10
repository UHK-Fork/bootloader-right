UHK right half bootloader
=========================

This is the bootloader of the right keyboard half of the Ultimate Hacking Keyboard.

`{ProgrammerName}` and `{ProgrammerPort}` are to be substituted with actual values below.

```bash
cd Bootloaders/CDC
make avrdude AVRDUDE_PROGRAMMER={ProgrammerName} AVRDUDE_PORT={ProgrammerPort}  # Build and upload the firmware.
make fuses AVRDUDE_PROGRAMMER={ProgrammerName} AVRDUDE_PORT={ProgrammerPort}    # Set the fuses.
```

The LUFA CDC bootloader upon which this bootloader is based is licenced according to its own terms.  The modifications that were made upon the LUFA CDC bootloader are licenced under the [GPLv3](https://www.gnu.org/copyleft/gpl.html).
