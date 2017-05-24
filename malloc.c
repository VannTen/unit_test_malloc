/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 13:48:51 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/24 15:40:40 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <dlfcn.h>
#ifndef CALL_TO_MALLOC_BEFORE_FAILURE
# define CALL_TO_MALLOC_BEFORE_FAILURE 100
#endif

void *malloc(size_t size)
{
	static int	count = 0;
	void * (*real_malloc)(size_t);

	count++;
	ft_putstr("Malloc called : ");
	ft_putnbr(count);
	ft_putchar('\n');
	real_malloc = dlsym(RTLD_NEXT, "malloc");
	if (count < CALL_TO_MALLOC_BEFORE_FAILURE)
	return real_malloc(size);
	else
		return (NULL);
}
