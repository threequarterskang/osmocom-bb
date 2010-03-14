/*
 * (C) 2010 by Andreas Eversberg <jolly@eversberg.eu>
 *
 * All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

/* collection of system information of the current cell */

/* frequency mask flags of frequency type */
#define	FREQ_TYPE_SERV	(1 << 0)
#define	FREQ_TYPE_NCELL	(1 << 1)

/* structure of one frequency */
struct gsm_sysinfo_freq {
	/* if the frequency included in the sysinfo */
	uint8_t	mask;
	/* the power measured as real value */
	int8_t	rxlev;
	...
};

/* structure of all received system informations */
struct gsm_sysinfo {
	struct	gsm_sysinfo_freq	freq[1024];

	/* serving cell */
	uint8_t				max_retrans; /* decoded */
	uint8_t				tx_integer; /* decoded */
	uint8_t				reest_denied; /* 1 = denied */
	uint8_t				cell_barred; /* 1 = barred */
	uint8_t				class_barr[16]; /* 10 is emergency */

	/* neighbor cell */
	uint8_t				nb_ext_ind;
	uint8_t				nb_ba_ind;
	uint8_t				nb_multi_rep; /* see GSM 05.08 8.4.3 */
	uint8_t				nb_ncc_permitted;
	uint8_t				nb_max_retrans; /* decoded */
	uint8_t				nb_tx_integer; /* decoded */
	uint8_t				nb_reest_denied; /* 1 = denied */
	uint8_t				nb_cell_barred; /* 1 = barred */
	uint8_t				nb_class_barr[16]; /* 10 is emergency */


	...
};
