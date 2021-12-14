/*
 * Copyright 2020 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <xrdc.h>

#define SP(X)		((X) << 9)
#define SU(X)		((X) << 6)
#define NP(X)		((X) << 3)
#define NU(X)		((X) << 0)

#define RWX		7
#define RW		6
#define R		4
#define X		1

struct xrdc_mda_config imx8ulp_mda[] = {
	{ 0, 7, MDA_SA_PT 	}, /* A core */
	{ 1, 1, MDA_SA_NS	}, /* DMA1 */
	{ 2, 1, MDA_SA_NS 	}, /* USB */
	{ 3, 1, MDA_SA_NS 	}, /* PXP-> .M10 */
	{ 4, 1, MDA_SA_NS 	}, /* ENET */
	{ 5, 1, MDA_SA_PT 	}, /* CAAM */
	{ 6, 1, MDA_SA_NS	}, /* USDHC0 */
	{ 7, 1, MDA_SA_NS 	}, /* USDHC1 */
	{ 8, 1, MDA_SA_NS	}, /* USDHC2 */
	{ 9, 2, MDA_SA_NS 	}, /* HIFI4 */
	{ 10, 3, MDA_SA_NS 	}, /* GPU3D */
	{ 11, 3, MDA_SA_NS 	}, /* GPU2D */
	{ 12, 3, MDA_SA_NS 	}, /* EPDC */
	{ 13, 3, MDA_SA_NS 	}, /* DCNano */
	{ 14, 3, MDA_SA_NS 	}, /* ISI */
	{ 15, 3, MDA_SA_NS 	}, /* PXP->NIC_LPAV.M0 */
	{ 16, 3, MDA_SA_NS 	}, /* DMA2 */
};

struct xrdc_mrc_config imx8ulp_mrc[] = {
	{ 0, 0, 0x0, 		0x30000, 	{0, 0, 0, 0, 0, 0, 0, 1}, {0xfff, 0} }, /* ROM1 */
	{ 1, 0, 0x60000000, 0x10000000, {1, 1, 0, 0, 1, 0, 1, 1}, {0xfff, 0} }, /* Flexspi2 */
	{ 2, 0, 0x22020000, 0x40000, 	{1, 1, 0, 0, 1, 0, 1, 1}, {0xfff, 0} }, /* SRAM2 */
	{ 3, 0, 0x22010000, 0x10000, 	{1, 1, 0, 0, 1, 0, 1, 1}, {0xfff, 0} }, /* SRAM0 */
	{ 4, 0, 0x80000000, 0x80000000, {1, 1, 0, 0, 1, 0, 1, 1}, {0xfff, 0} }, /* DRAM */
	{ 5, 0, 0x80000000, 0x80000000, {1, 1, 0, 0, 1, 0, 1, 1}, {0xfff, 0} }, /* DRAM */
	{ 6, 0, 0x80000000, 0x80000000, {1, 0, 0, 1, 0, 0, 1, 0}, {0xfff, 0} }, /* DRAM for LPAV and RTD*/
	{ 7, 0, 0x80000000, 0x10000000, {0, 0, 1, 0, 0, 0, 0, 0}, {0xfff, 0} }, /* DRAM for HIFI4 */
	{ 7, 1, 0x90000000, 0x10000000, {0, 0, 1, 0, 0, 0, 0, 0}, {0xfff, 0} }, /* DRAM for HIFI4 */
	{ 8, 0, 0x21000000, 0x10000, 	{1, 1, 1, 1, 1, 0, 1, 1}, {0xfff, 0} }, /* SRAM1 */
	{ 9, 0, 0x1ffc0000, 0xc0000, 	{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0} }, /* SSRAM for HIFI4 */
	{ 10, 0, 0x1ffc0000, 0xc0000, 	{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0} }, /* SSRAM for LPAV */
	{ 11, 0, 0x21170000, 0x10000, 	{0, 0, 1, 0, 0, 0, 0, 2}, {0xfff, SP(RW) | SU(RW) | NP(RW)} }, /* HIFI4 TCM */
	{ 11, 1, 0x21180000, 0x10000, 	{0, 0, 1, 0, 0, 0, 0, 2}, {SP(RW) | SU(RW) | NP(RW) | NU(RW), SP(RW) | SU(RW) | NP(RW)} }, /* HIFI4 TCM */
	{ 12, 0, 0x2d400000, 0x100000, 	{0, 0, 0, 0, 0, 0, 0, 1}, {SP(RW) | SU(RW) | NP(RW) | NU(RW), 0} }, /* GIC500 */
};

struct xrdc_pac_msc_config imx8ulp_pdac[] = {
	{ 0, PAC_SLOT_ALL, {0, 7, 0, 0, 0, 0, 0, 7} }, /* PAC0 */
	{ 0, 36, {0, 0, 0, 0, 0, 0, 7, 7} }, /* PAC0 slot 36 for CMC1 */
	{ 0, 41, {0, 0, 0, 0, 0, 0, 7, 7} }, /* PAC0 slot 41 for SIM_AD */
	{ 0, 47, {0, 0, 0, 0, 7, 0, 0, 7} }, /* PAC0 slot 47 for XRDC MGR*/
	{ 1, PAC_SLOT_ALL, {0, 7, 0, 0, 0, 0, 0, 7} }, /* PAC1 */
	{ 2, PAC_SLOT_ALL, {7, 0, 7, 7, 0, 0, 7, 7} }, /* PAC2 */
};

struct xrdc_pac_msc_config imx8ulp_msc[] = {
	{ 0, 0, {0, 0, 0, 0, 0, 0, 7, 7} }, /* MSC0 GPIOE */
	{ 0, 1, {0, 0, 0, 0, 0, 0, 0, 7} }, /* MSC0 GPIOF */
	{ 1, MSC_SLOT_ALL, {0, 0, 0, 0, 0, 0, 7, 7} }, /* MSC1 GPIOD */
	{ 2, MSC_SLOT_ALL, {0, 0, 0, 0, 0, 0, 7, 7} }, /* MSC2 GPU3D/2D/DCNANO/DDR registers */
};
