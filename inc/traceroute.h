/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traceroute.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:11:50 by eric              #+#    #+#             */
/*   Updated: 2026/03/03 16:38:11 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACEROUTE_H
#define TRACEROUTE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

typedef struct s_traceroute
{
	int						sockfd;
	struct	sockaddr_in		dest;
	
	int						ttl;
	int						max_ttl;
	int						probes_per_ttl;

	int						sequence;
	pid_t					pid;
	
	struct timeval			start;
	struct timeval			end;
	
} t_traceroute;

#endif
