/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traceroute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:09:51 by eric              #+#    #+#             */
/*   Updated: 2026/03/05 09:58:55 by eric             ###   ########.fr       */
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

int	wait_response(t_traceroute *trace, struct sockaddr_in *recv_addr, char *buf)
{
	fd_set			fds;
	struct timeval	timeout;
	socklen_t		addr_len;

	FD_ZERO(&fds);
	FD_SET(trace->recv_fd, &fds);
	timeout.tv_sec = 3;
	timeout.tv_usec = 0;
	if (select(trace->recv_fd + 1, &fds, NULL, NULL, &timeout) <= 0)
		return (-1);
	addr_len = sizeof(*recv_addr);
	recvfrom(trace->recv_fd, buf, 512, 0, (struct sockaddr *)recv_addr, &addr_len);
	gettimeofday(&trace->end, NULL);
	return (parse_icmp(buf));
}

void	print_hop(int ttl, struct sockaddr_in *recv_addr, t_traceroute *trace)
{
	char	host[NI_MAXHOST];
	double	rtt;

	rtt	= calc_rtt(trace);
	getnameinfo((struct sockaddr *)recv_addr, sizeof(*recv_addr), host, sizeof(host), 0, 0);
	printf(" %2d %s (%s) %.3f ms ", ttl, host, inet_ntoa(recv_addr->sin_addr), rtt);
}

void	print_timeout(void)
{
	printf("* ");
}

void	run_traceroute(t_traceroute *trace)
{
	struct sockaddr_in	recv_addr;
	char				buf[512];
	int					probe;
	int					ret;
	int					done;
	
	done = 0;
	printf("traceroute to %s, %d hops max\n", inet_ntoa(trace->dest.sin_addr), trace->max_ttl);
	while (trace->ttl <= trace->max_ttl && !done)
	{
		printf(" %2d ", trace->ttl);
		probe = 0;
		while (probe < trace->probes_per_ttl)
		{
			send_probe(trace);
			ret = wait_response(trace, &recv_addr, buf);
			if (ret == -1)
				print_timeout();
			else
			{
				print_hop(trace, &recv_addr, buf);
				if (ret == ICMP_UNREACH)
					done = 1;
			}
			probe++;
		}
		printf("\n");
		trace->ttl++;
	}
}
