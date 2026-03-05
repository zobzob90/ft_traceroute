/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:45:56 by eric              #+#    #+#             */
/*   Updated: 2026/03/05 09:23:18 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "traceroute.h"

int	parse_icmp(char *buf)
{
	struct ip	*ip_hdr;
	struct icmp	*icmp_hdr;
	
	ip_hdr = (struct ip *)buf;
	icmp_hdr = (struct icmp *)(buf + (ip_hdr->ip_hl * 4));
	if (icmp_hdr->icmp_type == ICMP_TIMXCEED)
		return (ICMP_TIMXCEED);
	if (icmp_hdr->icmp_type == ICMP_UNREACH)
		return (ICMP_UNREACH);
	return (-1);
}
