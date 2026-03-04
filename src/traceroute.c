/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traceroute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:09:51 by eric              #+#    #+#             */
/*   Updated: 2026/03/04 14:48:26 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "traceroute.h"

int	resolve_host(t_traceroute* trace, char *hostname)
{
	struct addrinfo	hints;
	struct addrinfo	*res;
	int				ret;

	ft_memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_DGRAM;

	ret = getaddrinfo(hostname, NULL, &hints, &res);
	if (ret != 0)
	{
		fprint(stderr, "getaddrinfo: %s", gai_strerror(ret));
		return (-1);
	}
	trace->dest = *(struct sockaddr_in *)res->ai_addr;
	freeaddrinfo(res);
	return (0);
}

