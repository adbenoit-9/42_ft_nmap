/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 16:41:55 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/07 19:17:21 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(void *ptr, size_t newsize)
{
	char	*newptr;
	size_t	size;

	if (ptr == NULL)
		return (malloc(newsize));
	size = ft_strlen((char *)ptr);
	if (newsize <= size)
		return (ptr);
	newptr = malloc(newsize);
	ft_memcpy(newptr, ptr, size);
	free(ptr);
	ptr = NULL;
	return (newptr);
}
