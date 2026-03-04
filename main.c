/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:45:39 by eric              #+#    #+#             */
/*   Updated: 2026/03/04 15:02:43 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "traceroute.h"

int main(int ac, char *av[])
{
	if (ac < 1)
	{
		printf("Wrong number of arguments");
		return (-1);
	}
	t_traceroute trace;
	
	init_traceroute(&trace);
	trace.recv_fd = create_recv_socket();
	if (trace.recv_fd < 0)
		return (1);
	trace.send_fd = create_send_socket();
	if (trace.send_fd < 0)
		return (1);
	while (1)
	{

	}
	return (0);
}
