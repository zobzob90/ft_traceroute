/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traceroute.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:11:50 by eric              #+#    #+#             */
/*   Updated: 2026/03/04 14:55:10 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACEROUTE_H
#define TRACEROUTE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <netdb.h>

#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

typedef struct s_traceroute
{
	int						send_fd;
	int						recv_fd;
	
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
int		create_recv_socket(void); 								// -> socket RAW ICMP pour recevoir
int		create_send_socket(void); 								// -> socket UDP pour envoyer
int		resolve_host(t_traceroute* trace, char *hostname);		// -> resout le hostname en IP

#endif
