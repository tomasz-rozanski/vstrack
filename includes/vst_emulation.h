#ifndef _VST_EMULATION_H
#define _VST_EMULATION_H

// The formula:
// PSX_TO_EMU = PSX_OFFSET - EMU_OFFSET + EMU_BASE_ADDRESS
// EMU_OFFSET = PSX_OFFSET + EMU_BASE_ADDRESS - PSX_TO_EMU
// PSX_OFFSET = PSX_TO_EMU + EMU_OFFSET - EMU_BASE_ADDRESS

#define PSX_TO_EPSXE_1925 0x7F974960
#define PSX_TO_EPSXE_2050 0x7F57DFE0

#define PSX_TO_BIZHAWK_2320 0x7FEE2780
#define PSX_TO_BIZHAWK_2410 0x7FCF2070

#endif
