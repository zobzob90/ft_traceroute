/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:46:10 by eric              #+#    #+#             */
/*   Updated: 2026/03/04 13:38:15 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "traceroute.h"

void	*ft_memset(void *ptr, int value, size_t len)
{
	if (ptr == NULL)
		return (NULL);
	size_t i = 0;
	unsigned char *p = (unsigned char *) ptr;
	while (i < len)
	{
		p[i] = (unsigned char) value;
		i++;
	}
	return (ptr);
}
