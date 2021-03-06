//
// Copyright (c) 2018 The nanoFramework project contributors
// Portions Copyright (c) Microsoft Corporation.  All rights reserved.
// See LICENSE file in the project root for full license information.
//

#include <stdint.h>
#include <ti/devices/cc32xx/inc/hw_memmap.h>
#include <ti/devices/cc32xx/driverlib/rom.h>
#include <ti/devices/cc32xx/driverlib/rom_map.h>
#include <ti/devices/cc32xx/driverlib/crc.h>

// strong implementation of this function specific to the TI Simple Link targets
unsigned int SUPPORT_ComputeCRC(const void* rgBlock, int nLength, unsigned int crc)
{
	MAP_CRCSeedSet(DTHE_BASE, crc);

	crc = MAP_CRCDataProcess(DTHE_BASE, rgBlock, nLength, CRC_CFG_SIZE_8BIT);

    return crc;
};
