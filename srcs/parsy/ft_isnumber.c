/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:56:16 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/17 23:15:05 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

bool	ft_isnumber(char *str)
{
	for (int64_t i = 0; str[i]; i++) {
		if (ft_isdigit(str[i]) == false) {
			return (false);
		}
	}
	return (true);
}
