#ifndef _BOOTLOADER_JUMP_H_
#define _BOOTLOADER_JUMP_H_

    /* Includes: */
        #include <avr/io.h>
        #include <avr/wdt.h>
        #include <LUFA/Drivers/USB/USB.h>
        #include "Descriptors.h"

    /* Macros: */
        #define MAGIC_BOOT_KEY            0xDC42ACCA
        #define FLASH_SIZE_BYTES          32768
        #define BOOTLOADER_SEC_SIZE_BYTES 4096
        #define BOOTLOADER_START_ADDRESS  (FLASH_SIZE_BYTES - BOOTLOADER_SEC_SIZE_BYTES)

        #define AGENT_COMMAND_REENUMERATE 0

    /* Type defines: */
        enum EnumerationMode_t {
            ENUMERATION_MODE_Keyboard    = 0, /**< Normal enumeration mode featuring a keyboard, a mouse and a generic HID interface */
            ENUMERATION_MODE_Bootloader  = 1, /**< Bootloader enumeration mode for upgrading the firmware of the right half */
            ENUMERATION_MODE_USBtoSerial = 2, /**< USBtoSerial enumeration mode for upgrading the firmware of the left half */
        };

        typedef struct {
          uint32_t MagicBootKey;
          uint8_t EnumerationMode;
        } wormhole_t;

    /* Function Prototypes: */
        void Bootloader_Jump_Check(void) ATTR_INIT_SECTION(3);
        void Reenumerate(uint8_t ReenumerateAs);
        void CatchReenumerateRequest(void);

#endif
