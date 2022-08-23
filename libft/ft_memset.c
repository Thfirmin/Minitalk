/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:22:24 by thfirmin          #+#    #+#             */
/*   Updated: 2022/08/06 02:40:34 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//write a byte to n byte string

void	*ft_memset(void *b, int c, size_t len)
{
	int	i;
	if (!b)
		return (0);
	i = 0;
	while (len--)
		*(unsigned char *)(b + i++) = c;
	return (b);
}
