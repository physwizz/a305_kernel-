/* x_tables module for setting the IPv4/IPv6 DSCP field
 *
 * (C) 2002 Harald Welte <laforge@gnumonks.org>
 * based on ipt_FTOS.c (C) 2000 by Matthew G. Marsh <mgm@paktronix.com>
 * This software is distributed under GNU GPL v2, 1991
 *
 * See RFC2474 for a description of the DSCP field within the IP Header.
 *
 * xt_DSCP.h,v 1.7 2002/03/14 12:03:13 laforge Exp
*/
#ifndef _XT_PRIO_TARGET_H
#define _XT_PRIO_TARGET_H
#include <linux/types.h>

/* target info */
struct xt_PRIO_info {
	__u32 prio;
};

#endif /* _XT_DSCP_TARGET_H */
