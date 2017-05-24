/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 13:48:51 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/24 16:39:16 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
#include <dlfcn.h>
#ifndef CALL_TO_MALLOC_BEFORE_FAILURE
# define CALL_TO_MALLOC_BEFORE_FAILURE atoi(getenv("MALLOC_TEST"))
#endif

void *malloc(size_t size)
{
	static int	count = 0;
	void * (*real_malloc)(size_t);
	void	*address;
	char	desd;

	count++;
	ft_putstr("Malloc called : ");
	ft_putnbr(count);
	ft_putchar('\n');
	real_malloc = dlsym(RTLD_NEXT, "malloc");
	if (count < CALL_TO_MALLOC_BEFORE_FAILURE)
	address = real_malloc(size);
	else
		address = NULL;
	if (getenv("DEREF_MAL") != NULL)
		desd = *((char*)address);
	return (address);
}
