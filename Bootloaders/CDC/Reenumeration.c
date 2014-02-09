/** \file
 *
 *  Bootloader jump functions, taken from the LUFA documentation.
 */

#include "Reenumeration.h"

wormhole_t *Wormhole ATTR_NO_INIT;
bool ShouldReenumerate = false;

void Bootloader_Jump_Check(void)
{
    SP -= sizeof(wormhole_t);
    Wormhole = (wormhole_t*)(SP + 1);

    // If the reset source was the bootloader and the key is correct, clear it and jump to the bootloader
    if ((MCUSR & (1 << WDRF)) && (Wormhole->MagicBootKey == MAGIC_BOOT_KEY)) {
        Wormhole->MagicBootKey = 0;
        ((void (*)(void))0x0000)();
    }
}

void Reenumerate(uint8_t NewEnumerationMode)
{
    // If USB is used, detach from the bus and reset it
    USB_Disable();

    // Disable all interrupts
    cli();

    // Wait two seconds for the USB detachment to register on the host
    Delay_MS(2000);

    // Set the bootloader key to the magic value and force a reset
    Wormhole->EnumerationMode = NewEnumerationMode;
    Wormhole->MagicBootKey = MAGIC_BOOT_KEY;
    wdt_enable(WDTO_250MS);
    for (;;);
}

void CatchReenumerateRequest()
{
    if (!(Endpoint_IsSETUPReceived())) {
        return;
    }

    if (USB_ControlRequest.wIndex != INTERFACE_ID_CDC_CCI) {
        return;
    }

    if (USB_ControlRequest.bRequest != HID_REQ_SetReport) {
        return;
    }

    if (USB_ControlRequest.bmRequestType != (REQDIR_HOSTTODEVICE | REQTYPE_CLASS | REQREC_INTERFACE)) {
        return;
    }

    uint16_t ReportSize = USB_ControlRequest.wLength;
    uint8_t  ReportData[ReportSize];

    Endpoint_ClearSETUP();
    Endpoint_Read_Control_Stream_LE(ReportData, ReportSize);
    Endpoint_ClearIN();

    uint8_t Command = ReportData[0];
    if (Command != AGENT_COMMAND_REENUMERATE) {
        return;
    }

    uint8_t NewEnumerationMode = ReportData[1];
    Wormhole->EnumerationMode = NewEnumerationMode;
    ShouldReenumerate = true;
}
