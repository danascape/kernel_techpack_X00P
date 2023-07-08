/*****************************************************************************
	Copyright(c) 2017 FCI Inc. All Rights Reserved

	File name : fc8350_tun_table.c

	Description : source of FC8350 tuner driver

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

	History :
	----------------------------------------------------------------------
******************************************************************************/
#include "fci_types.h"

u32 ch_mode_saw[121][11] = {
	{0x00, 0x11, 0x12, 0x11d, 0x11f, 0x11e, 0x120, 0x121, 0x123, 0x122,
		0x124},
	{90000, 0x04, 0xc0, 0x7f, 0x7f, 0x81, 0x81, 0x91, 0x91, 0x75, 0x75},
	{96000, 0x04, 0xc0, 0x80, 0x80, 0x80, 0x80, 0x91, 0x91, 0x75, 0x75},
	{102000, 0x04, 0xc0, 0x80, 0x80, 0x80, 0x80, 0x91, 0x91, 0x75, 0x75},
	{108000, 0x04, 0xc0, 0x81, 0x81, 0x80, 0x80, 0x91, 0x91, 0x75, 0x75},
	{114000, 0x04, 0xc0, 0x81, 0x81, 0x80, 0x80, 0x91, 0x91, 0x76, 0x76},
	{120000, 0x04, 0xc0, 0x81, 0x81, 0x80, 0x80, 0x90, 0x90, 0x76, 0x76},
	{126000, 0x04, 0xc0, 0x82, 0x82, 0x80, 0x80, 0x8f, 0x8f, 0x77, 0x77},
	{132000, 0x04, 0xc0, 0x81, 0x81, 0x81, 0x81, 0x8f, 0x8f, 0x77, 0x77},
	{138000, 0x04, 0xc0, 0x82, 0x82, 0x81, 0x81, 0x90, 0x90, 0x76, 0x76},
	{144000, 0x04, 0xc0, 0x82, 0x82, 0x81, 0x81, 0x8f, 0x8f, 0x78, 0x78},
	{150000, 0x04, 0xc0, 0x83, 0x83, 0x83, 0x83, 0x8f, 0x8f, 0x77, 0x77},
	{156000, 0x04, 0xc0, 0x82, 0x82, 0x83, 0x83, 0x90, 0x90, 0x77, 0x77},
	{164000, 0x04, 0xc0, 0x84, 0x84, 0x83, 0x83, 0x90, 0x90, 0x76, 0x76},
	{170000, 0x04, 0xc0, 0x83, 0x83, 0x83, 0x83, 0x90, 0x90, 0x77, 0x77},
	{176000, 0x04, 0xc0, 0x83, 0x83, 0x83, 0x83, 0x91, 0x91, 0x77, 0x77},
	{182000, 0x04, 0xc0, 0x83, 0x83, 0x84, 0x84, 0x91, 0x91, 0x77, 0x77},
	{188000, 0x04, 0xc0, 0x84, 0x84, 0x84, 0x84, 0x92, 0x92, 0x77, 0x77},
	{192000, 0x04, 0xc0, 0x84, 0x84, 0x84, 0x84, 0x92, 0x92, 0x77, 0x77},
	{198000, 0x04, 0xc0, 0x7d, 0x7d, 0x81, 0x81, 0x90, 0x90, 0x72, 0x72},
	{204000, 0x04, 0xc0, 0x7d, 0x7d, 0x81, 0x81, 0x91, 0x91, 0x72, 0x72},
	{210000, 0x04, 0xc0, 0x7d, 0x7d, 0x81, 0x81, 0x92, 0x92, 0x73, 0x73},
	{216000, 0x04, 0xc0, 0x7d, 0x7d, 0x82, 0x82, 0x92, 0x92, 0x72, 0x72},
	{222000, 0x04, 0xc0, 0x7e, 0x7e, 0x82, 0x82, 0x92, 0x92, 0x72, 0x72},
	{228000, 0x04, 0x00, 0x7f, 0x7f, 0x81, 0x81, 0x94, 0x94, 0x72, 0x72},
	{234000, 0x04, 0x00, 0x7d, 0x7d, 0x7f, 0x7f, 0x95, 0x95, 0x71, 0x71},
	{240000, 0x04, 0x00, 0x9d, 0x9d, 0xac, 0xac, 0x8f, 0x8f, 0x76, 0x76},
	{246000, 0x04, 0x00, 0x77, 0x77, 0x89, 0x89, 0x87, 0x87, 0x7b, 0x7b},
	{252000, 0x04, 0x00, 0x80, 0x80, 0x80, 0x80, 0x92, 0x92, 0x74, 0x74},
	{258000, 0x04, 0x00, 0x7f, 0x7f, 0x81, 0x81, 0x95, 0x95, 0x72, 0x72},
	{264000, 0x04, 0x00, 0x7f, 0x7f, 0x7e, 0x7e, 0x97, 0x97, 0x71, 0x71},
	{270000, 0x04, 0x00, 0x82, 0x82, 0x71, 0x71, 0x9e, 0x9e, 0x64, 0x64},
	{276000, 0x04, 0x00, 0xac, 0xac, 0x91, 0x91, 0xad, 0xad, 0x95, 0x95},
	{282000, 0x04, 0x00, 0x7e, 0x7e, 0x82, 0x82, 0x8f, 0x8f, 0x73, 0x73},
	{288000, 0x04, 0x00, 0x80, 0x80, 0x82, 0x82, 0x92, 0x92, 0x75, 0x75},
	{294000, 0x04, 0x00, 0x81, 0x81, 0x80, 0x80, 0x94, 0x94, 0x74, 0x74},
	{300000, 0x04, 0x00, 0x84, 0x84, 0x80, 0x80, 0x95, 0x95, 0x73, 0x73},
	{306000, 0x04, 0x00, 0x80, 0x80, 0x7e, 0x7e, 0x97, 0x97, 0x73, 0x73},
	{312000, 0x04, 0x00, 0x82, 0x82, 0x7e, 0x7e, 0x98, 0x98, 0x71, 0x71},
	{318000, 0x04, 0x00, 0x82, 0x82, 0x7a, 0x7a, 0x99, 0x99, 0x72, 0x72},
	{324000, 0x04, 0x00, 0x83, 0x83, 0x7a, 0x7a, 0x97, 0x97, 0x72, 0x72},
	{330000, 0x04, 0x00, 0x86, 0x86, 0x78, 0x78, 0x9a, 0x9a, 0x71, 0x71},
	{336000, 0x04, 0x00, 0x82, 0x82, 0x73, 0x73, 0x9a, 0x9a, 0x6a, 0x6a},
	{342000, 0x04, 0x00, 0x85, 0x85, 0x79, 0x79, 0x95, 0x95, 0x70, 0x70},
	{348000, 0x04, 0x00, 0x84, 0x84, 0x6f, 0x6f, 0x98, 0x98, 0x65, 0x65},
	{354000, 0x04, 0x00, 0x8e, 0x8e, 0x79, 0x79, 0x8b, 0x8b, 0x63, 0x63},
	{360000, 0x04, 0x00, 0x8c, 0x8c, 0x8a, 0x8a, 0x9e, 0x9e, 0x68, 0x68},
	{366000, 0x04, 0x00, 0x83, 0x83, 0x77, 0x77, 0x9a, 0x9a, 0x6e, 0x6e},
	{372000, 0x04, 0x00, 0x8b, 0x8b, 0x7f, 0x7f, 0xa4, 0xa4, 0x87, 0x87},
	{378000, 0x04, 0x00, 0x8f, 0x8f, 0x76, 0x76, 0x79, 0x79, 0x84, 0x84},
	{384000, 0x04, 0x00, 0x5a, 0x5a, 0x76, 0x76, 0x8d, 0x8d, 0x85, 0x85},
	{390000, 0x04, 0x00, 0x94, 0x94, 0xac, 0xac, 0x58, 0x58, 0x8b, 0x8b},
	{396000, 0x02, 0x00, 0x9b, 0x9b, 0x9a, 0x9a, 0x82, 0x82, 0x99, 0x99},
	{402000, 0x02, 0x00, 0xa6, 0xa6, 0x7e, 0x7e, 0x8b, 0x8b, 0x67, 0x67},
	{408000, 0x02, 0x00, 0x84, 0x84, 0x8c, 0x8c, 0x8d, 0x8d, 0xad, 0xad},
	{414000, 0x02, 0x00, 0x8c, 0x8c, 0x66, 0x66, 0x88, 0x88, 0x96, 0x96},
	{420000, 0x02, 0x00, 0x88, 0x88, 0x83, 0x83, 0x67, 0x67, 0x97, 0x97},
	{426000, 0x02, 0x00, 0x6b, 0x6b, 0x81, 0x81, 0x5f, 0x5f, 0x9b, 0x9b},
	{432000, 0x02, 0x00, 0x6d, 0x6d, 0x74, 0x74, 0x63, 0x63, 0x99, 0x99},
	{438000, 0x02, 0x00, 0x8a, 0x8a, 0x89, 0x89, 0x83, 0x83, 0x73, 0x73},
	{444000, 0x02, 0x00, 0x98, 0x98, 0x7a, 0x7a, 0xa5, 0xa5, 0x9b, 0x9b},
	{450000, 0x02, 0x00, 0x74, 0x74, 0x93, 0x93, 0x84, 0x84, 0x87, 0x87},
	{456000, 0x02, 0x00, 0x94, 0x94, 0xa4, 0xa4, 0x6f, 0x6f, 0x7f, 0x7f},
	{462000, 0x02, 0x00, 0xac, 0xac, 0x64, 0x64, 0x88, 0x88, 0x60, 0x60},
	{470000, 0x02, 0x00, 0x63, 0x63, 0x7c, 0x7c, 0x76, 0x76, 0x86, 0x86},
	{476000, 0x02, 0x00, 0x60, 0x60, 0x9b, 0x9b, 0x8d, 0x8d, 0xa2, 0xa2},
	{482000, 0x02, 0x00, 0xc9, 0xc9, 0x0e, 0x0e, 0x6d, 0x6d, 0x20, 0x20},
	{488000, 0x02, 0x00, 0xb2, 0xb2, 0x15, 0x15, 0x55, 0x55, 0x50, 0x50},
	{494000, 0x02, 0x00, 0x93, 0x93, 0x78, 0x78, 0x80, 0x80, 0x86, 0x86},
	{500000, 0x02, 0x00, 0x61, 0x61, 0x92, 0x92, 0x77, 0x77, 0x6b, 0x6b},
	{506000, 0x02, 0x00, 0x97, 0x97, 0x77, 0x77, 0x69, 0x69, 0x68, 0x68},
	{512000, 0x02, 0x00, 0x6a, 0x6a, 0x74, 0x74, 0x9d, 0x9d, 0x65, 0x65},
	{518000, 0x02, 0x00, 0x5e, 0x5e, 0x76, 0x76, 0x81, 0x81, 0x5c, 0x5c},
	{524000, 0x02, 0x00, 0x58, 0x58, 0x9c, 0x9c, 0x89, 0x89, 0x65, 0x65},
	{530000, 0x02, 0x00, 0x79, 0x79, 0x8f, 0x8f, 0x62, 0x62, 0x8c, 0x8c},
	{536000, 0x02, 0x00, 0x77, 0x77, 0x82, 0x82, 0x9a, 0x9a, 0x8f, 0x8f},
	{542000, 0x02, 0x00, 0x67, 0x67, 0x9f, 0x9f, 0x5d, 0x5d, 0x8b, 0x8b},
	{548000, 0x02, 0x00, 0x8c, 0x8c, 0x72, 0x72, 0x84, 0x84, 0xaa, 0xaa},
	{554000, 0x02, 0x00, 0xb2, 0xb2, 0x15, 0x15, 0x55, 0x55, 0x50, 0x50},
	{560000, 0x02, 0x00, 0x88, 0x88, 0x92, 0x92, 0x68, 0x68, 0x69, 0x69},
	{566000, 0x02, 0x00, 0x66, 0x66, 0x63, 0x63, 0x8e, 0x8e, 0x72, 0x72},
	{572000, 0x02, 0x00, 0x75, 0x75, 0x8b, 0x8b, 0xab, 0xab, 0x74, 0x74},
	{578000, 0x01, 0x00, 0x6e, 0x6e, 0x6c, 0x6c, 0x6c, 0x6c, 0x9a, 0x9a},
	{584000, 0x01, 0x00, 0x9f, 0x9f, 0x83, 0x83, 0xa2, 0xa2, 0x7f, 0x7f},
	{590000, 0x01, 0x00, 0x91, 0x91, 0x93, 0x93, 0x5c, 0x5c, 0x9d, 0x9d},
	{596000, 0x01, 0x00, 0x87, 0x87, 0x9b, 0x9b, 0x98, 0x98, 0x98, 0x98},
	{602000, 0x01, 0x00, 0x81, 0x81, 0x20, 0x20, 0x50, 0x50, 0x50, 0x50},
	{608000, 0x01, 0x00, 0x94, 0x94, 0x76, 0x76, 0x5a, 0x5a, 0x75, 0x75},
	{614000, 0x01, 0x00, 0x7f, 0x7f, 0x7f, 0x7f, 0x7a, 0x7a, 0x9f, 0x9f},
	{620000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{626000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{632000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{638000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{644000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{650000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{656000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{662000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{668000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{674000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{680000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{686000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{692000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{698000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{704000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{710000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{716000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{722000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{728000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{734000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{740000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{746000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{752000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{758000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{764000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{770000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{776000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{782000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{788000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{794000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{800000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{806000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60}
};

u32 ch_mode_nosaw[121][11] = {
	{0x00, 0x11, 0x12, 0x11d, 0x11f, 0x11e, 0x120, 0x121, 0x123, 0x122,
		0x124},
	{90000, 0x04, 0xc0, 0x81, 0x81, 0x80, 0x80, 0x92, 0x92, 0x74, 0x74},
	{96000, 0x04, 0xc0, 0x81, 0x81, 0x80, 0x80, 0x93, 0x93, 0x75, 0x75},
	{102000, 0x04, 0xc0, 0x81, 0x81, 0x80, 0x80, 0x93, 0x93, 0x75, 0x75},
	{108000, 0x04, 0xc0, 0x82, 0x82, 0x80, 0x80, 0x93, 0x93, 0x75, 0x75},
	{114000, 0x04, 0xc0, 0x82, 0x82, 0x80, 0x80, 0x93, 0x93, 0x75, 0x75},
	{120000, 0x04, 0xc0, 0x82, 0x82, 0x80, 0x80, 0x93, 0x93, 0x76, 0x76},
	{126000, 0x04, 0xc0, 0x82, 0x82, 0x80, 0x80, 0x93, 0x93, 0x75, 0x75},
	{132000, 0x04, 0xc0, 0x83, 0x83, 0x80, 0x80, 0x93, 0x93, 0x76, 0x76},
	{138000, 0x04, 0xc0, 0x83, 0x83, 0x80, 0x80, 0x93, 0x93, 0x75, 0x75},
	{144000, 0x04, 0xc0, 0x84, 0x84, 0x80, 0x80, 0x94, 0x94, 0x75, 0x75},
	{150000, 0x04, 0xc0, 0x84, 0x84, 0x80, 0x80, 0x94, 0x94, 0x75, 0x75},
	{156000, 0x04, 0xc0, 0x84, 0x84, 0x81, 0x81, 0x94, 0x94, 0x75, 0x75},
	{164000, 0x04, 0xc0, 0x85, 0x85, 0x81, 0x81, 0x94, 0x94, 0x75, 0x75},
	{170000, 0x04, 0xc0, 0x85, 0x85, 0x81, 0x81, 0x95, 0x95, 0x75, 0x75},
	{176000, 0x04, 0xc0, 0x86, 0x86, 0x81, 0x81, 0x95, 0x95, 0x75, 0x75},
	{182000, 0x04, 0xc0, 0x86, 0x86, 0x82, 0x82, 0x95, 0x95, 0x75, 0x75},
	{188000, 0x04, 0xc0, 0x87, 0x87, 0x82, 0x82, 0x95, 0x95, 0x75, 0x75},
	{192000, 0x04, 0xc0, 0x87, 0x87, 0x82, 0x82, 0x95, 0x95, 0x75, 0x75},
	{198000, 0x04, 0xc0, 0x82, 0x82, 0x7e, 0x7e, 0x96, 0x96, 0x70, 0x70},
	{204000, 0x04, 0xc0, 0x83, 0x83, 0x80, 0x80, 0x96, 0x96, 0x70, 0x70},
	{210000, 0x04, 0xc0, 0x83, 0x83, 0x80, 0x80, 0x97, 0x97, 0x70, 0x70},
	{216000, 0x04, 0xc0, 0x83, 0x83, 0x80, 0x80, 0x97, 0x97, 0x70, 0x70},
	{222000, 0x04, 0xc0, 0x83, 0x83, 0x80, 0x80, 0x96, 0x96, 0x70, 0x70},
	{228000, 0x04, 0x00, 0x83, 0x83, 0x80, 0x80, 0x97, 0x97, 0x70, 0x70},
	{234000, 0x04, 0x00, 0x83, 0x83, 0x80, 0x80, 0x97, 0x97, 0x70, 0x70},
	{240000, 0x04, 0x00, 0x83, 0x83, 0x80, 0x80, 0x97, 0x97, 0x70, 0x70},
	{246000, 0x04, 0x00, 0x84, 0x84, 0x80, 0x80, 0x97, 0x97, 0x70, 0x70},
	{252000, 0x04, 0x00, 0x85, 0x85, 0x80, 0x80, 0x96, 0x96, 0x6f, 0x6f},
	{258000, 0x04, 0x00, 0x85, 0x85, 0x80, 0x80, 0x97, 0x97, 0x6f, 0x6f},
	{264000, 0x04, 0x00, 0x85, 0x85, 0x80, 0x80, 0x97, 0x97, 0x6f, 0x6f},
	{270000, 0x04, 0x00, 0x85, 0x85, 0x80, 0x80, 0x97, 0x97, 0x6f, 0x6f},
	{276000, 0x04, 0x00, 0x85, 0x85, 0x80, 0x80, 0x98, 0x98, 0x6e, 0x6e},
	{282000, 0x04, 0x00, 0x86, 0x86, 0x80, 0x80, 0x97, 0x97, 0x6f, 0x6f},
	{288000, 0x04, 0x00, 0x86, 0x86, 0x80, 0x80, 0x98, 0x98, 0x6e, 0x6e},
	{294000, 0x04, 0x00, 0x86, 0x86, 0x80, 0x80, 0x98, 0x98, 0x6e, 0x6e},
	{300000, 0x04, 0x00, 0x87, 0x87, 0x80, 0x80, 0x98, 0x98, 0x6d, 0x6d},
	{306000, 0x04, 0x00, 0x88, 0x88, 0x80, 0x80, 0x98, 0x98, 0x6d, 0x6d},
	{312000, 0x04, 0x00, 0x87, 0x87, 0x80, 0x80, 0x98, 0x98, 0x6d, 0x6d},
	{318000, 0x04, 0x00, 0x88, 0x88, 0x80, 0x80, 0x98, 0x98, 0x6d, 0x6d},
	{324000, 0x04, 0x00, 0x87, 0x87, 0x80, 0x80, 0x98, 0x98, 0x6c, 0x6c},
	{330000, 0x04, 0x00, 0x87, 0x87, 0x80, 0x80, 0x98, 0x98, 0x6c, 0x6c},
	{336000, 0x04, 0x00, 0x87, 0x87, 0x81, 0x81, 0x98, 0x98, 0x6d, 0x6d},
	{342000, 0x04, 0x00, 0x8b, 0x8b, 0x80, 0x80, 0x98, 0x98, 0x6d, 0x6d},
	{348000, 0x04, 0x00, 0x87, 0x87, 0x7f, 0x7f, 0x9a, 0x9a, 0x6d, 0x6d},
	{354000, 0x04, 0x00, 0x88, 0x88, 0x7f, 0x7f, 0x9b, 0x9b, 0x6b, 0x6b},
	{360000, 0x04, 0x00, 0x89, 0x89, 0x82, 0x82, 0x98, 0x98, 0x6b, 0x6b},
	{366000, 0x04, 0x00, 0x88, 0x88, 0x81, 0x81, 0x9c, 0x9c, 0x6a, 0x6a},
	{372000, 0x04, 0x00, 0x8a, 0x8a, 0x80, 0x80, 0x93, 0x93, 0x6d, 0x6d},
	{378000, 0x04, 0x00, 0x87, 0x87, 0x80, 0x80, 0x95, 0x95, 0x6a, 0x6a},
	{384000, 0x04, 0x00, 0x8a, 0x8a, 0x83, 0x83, 0x96, 0x96, 0x6d, 0x6d},
	{390000, 0x04, 0x00, 0x8b, 0x8b, 0x83, 0x83, 0x97, 0x97, 0x69, 0x69},
	{396000, 0x02, 0x00, 0x8b, 0x8b, 0x88, 0x88, 0x98, 0x98, 0x6b, 0x6b},
	{402000, 0x02, 0x00, 0x89, 0x89, 0x81, 0x81, 0x97, 0x97, 0x69, 0x69},
	{408000, 0x02, 0x00, 0x8a, 0x8a, 0x81, 0x81, 0x97, 0x97, 0x69, 0x69},
	{414000, 0x02, 0x00, 0x8a, 0x8a, 0x81, 0x81, 0x98, 0x98, 0x68, 0x68},
	{420000, 0x02, 0x00, 0x8b, 0x8b, 0x81, 0x81, 0x98, 0x98, 0x67, 0x67},
	{426000, 0x02, 0x00, 0x8b, 0x8b, 0x81, 0x81, 0x98, 0x98, 0x66, 0x66},
	{432000, 0x02, 0x00, 0x8c, 0x8c, 0x81, 0x81, 0x99, 0x99, 0x66, 0x66},
	{438000, 0x02, 0x00, 0x8d, 0x8d, 0x81, 0x81, 0x9a, 0x9a, 0x66, 0x66},
	{444000, 0x02, 0x00, 0x8d, 0x8d, 0x81, 0x81, 0x9b, 0x9b, 0x67, 0x67},
	{450000, 0x02, 0x00, 0x8d, 0x8d, 0x81, 0x81, 0x9b, 0x9b, 0x67, 0x67},
	{456000, 0x02, 0x00, 0x8e, 0x8e, 0x81, 0x81, 0x9a, 0x9a, 0x66, 0x66},
	{462000, 0x02, 0x00, 0x8e, 0x8e, 0x81, 0x81, 0x9a, 0x9a, 0x67, 0x67},
	{470000, 0x02, 0x00, 0x8d, 0x8d, 0x84, 0x84, 0x9e, 0x9e, 0x68, 0x68},
	{476000, 0x02, 0x00, 0x8f, 0x8f, 0x85, 0x85, 0x9e, 0x9e, 0x68, 0x68},
	{482000, 0x02, 0x00, 0x89, 0x88, 0x80, 0x81, 0x94, 0x94, 0x76, 0x76},
	{488000, 0x02, 0x00, 0x86, 0x8a, 0x80, 0x80, 0x94, 0x92, 0x78, 0x76},
	{494000, 0x02, 0x00, 0x8f, 0x8f, 0x86, 0x86, 0x9d, 0x9d, 0x67, 0x67},
	{500000, 0x02, 0x00, 0x8f, 0x8f, 0x87, 0x87, 0x9b, 0x9b, 0x67, 0x67},
	{506000, 0x02, 0x00, 0x8f, 0x8f, 0x87, 0x87, 0x9e, 0x9e, 0x66, 0x66},
	{512000, 0x02, 0x00, 0x8f, 0x8f, 0x85, 0x85, 0x9e, 0x9e, 0x65, 0x65},
	{518000, 0x02, 0x00, 0x90, 0x90, 0x86, 0x86, 0x9b, 0x9b, 0x68, 0x68},
	{524000, 0x02, 0x00, 0x8f, 0x8f, 0x87, 0x87, 0x9d, 0x9d, 0x64, 0x64},
	{530000, 0x02, 0x00, 0x90, 0x90, 0x85, 0x85, 0x9c, 0x9c, 0x62, 0x62},
	{536000, 0x02, 0x00, 0x93, 0x93, 0x84, 0x84, 0x9b, 0x9b, 0x66, 0x66},
	{542000, 0x02, 0x00, 0x8e, 0x8e, 0x8a, 0x8a, 0x9a, 0x9a, 0x67, 0x67},
	{548000, 0x02, 0x00, 0x8d, 0x8d, 0x87, 0x87, 0x9b, 0x9b, 0x67, 0x67},
	{554000, 0x02, 0x00, 0x89, 0x86, 0x7a, 0x80, 0x8e, 0x8b, 0x6f, 0x71},
	{560000, 0x02, 0x00, 0x8e, 0x8e, 0x8b, 0x8b, 0x9c, 0x9c, 0x65, 0x65},
	{566000, 0x02, 0x00, 0x93, 0x93, 0x88, 0x88, 0x9f, 0x9f, 0x69, 0x69},
	{572000, 0x02, 0x00, 0x8d, 0x8d, 0x89, 0x89, 0x9a, 0x9a, 0x5d, 0x5d},
	{578000, 0x01, 0x00, 0x96, 0x96, 0x84, 0x84, 0xa2, 0xa2, 0x63, 0x63},
	{584000, 0x01, 0x00, 0x90, 0x90, 0x89, 0x89, 0xa0, 0xa0, 0x67, 0x67},
	{590000, 0x01, 0x00, 0x8b, 0x8b, 0x8d, 0x8d, 0x9e, 0x9e, 0x62, 0x62},
	{596000, 0x01, 0x00, 0x96, 0x96, 0x86, 0x86, 0x9d, 0x9d, 0x69, 0x69},
	{602000, 0x01, 0x00, 0x86, 0x86, 0x7b, 0x7d, 0x8d, 0x81, 0x70, 0x68},
	{608000, 0x01, 0x00, 0x8e, 0x8e, 0x8f, 0x8f, 0x9c, 0x9c, 0x5d, 0x5d},
	{614000, 0x01, 0x00, 0x98, 0x98, 0x85, 0x85, 0x94, 0x94, 0x64, 0x64},
	{620000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{626000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{632000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{638000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{644000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{650000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{656000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{662000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{668000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{674000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{680000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{686000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{692000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{698000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{704000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{710000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{716000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{722000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{728000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{734000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{740000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{746000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{752000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{758000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{764000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{770000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{776000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{782000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{788000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{794000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{800000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60},
	{806000, 0x01, 0x00, 0x1e, 0x52, 0x1e, 0x52, 0x60, 0x60, 0x60, 0x60}
};
