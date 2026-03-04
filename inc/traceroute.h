/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traceroute.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:11:50 by eric              #+#    #+#             */
/*   Updated: 2026/03/04 13:54:00 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACEROUTE_H
#define TRACEROUTE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

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


/*UTILS*/
void	*ft_memset(void *ptr, int value, size_t len);

/*INIT*/
void	init_traceroute(t_traceroute *trace);

/*SOCKET*/
int		create_recv_socket(void);
int		create_send_socket(void);

#endif
