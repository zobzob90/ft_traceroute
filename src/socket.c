/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:46:02 by eric              #+#    #+#             */
/*   Updated: 2026/03/04 13:52:48 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "traceroute.h"

int	create_recv_socket(void)
{
	int sockfd;
	sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (sockfd < 0)
	{
		fprintf(stderr, "socket recv: %s\n", strerror(errno));
		return (-1);
	}
	return (sockfd);
}

int	create_send_socket(void)
{
	int sockfd;
	sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (sockfd < 0)
	{
		fprintf(stderr, "socket send: %s\n", strerror(errno));
	}
	return (sockfd)
}