/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 13:48:51 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/24 15:26:33 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <dlfcn.h>

void *malloc(size_t size)
{
	static int	count = 0;
	void * (*real_malloc)(size_t);

	count++;
	ft_putstr("Malloc called : ");
	ft_putnbr(count);
	ft_putchar('\n');
	real_malloc = dlsym(RTLD_NEXT, "malloc");
	if (count < 100)
	return real_malloc(size);
	else
		return (NULL);
}
