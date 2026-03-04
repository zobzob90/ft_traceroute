/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traceroute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:09:51 by eric              #+#    #+#             */
/*   Updated: 2026/03/04 16:25:44 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "traceroute.h"

void	send_probe(t_traceroute *trace)
{
	setsockopt(trace->send_fd, IPPROTO_IP, IP_TTL, &trace->ttl, sizeof(trace->ttl));
	trace->dest.sin_port = htons(33434 + trace->sequence);
	gettimeofday(&trace->start, NULL);
	sendto(trace->send_fd, NULL, 0, 0, (struct sockadd *)&trace->dest, sizeof(trace->dest));
	trace->sequence++;
}

void	wait_response()
{
	
}

void	print_hop()
{

}

void	run_traceroute(t_traceroute *trace)
{
	
}
