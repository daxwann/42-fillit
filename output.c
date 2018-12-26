/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 12:51:08 by xwang             #+#    #+#             */
/*   Updated: 2018/12/26 12:51:14 by xwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(const char *str)
{
	size_t len;

	if (!str)
		return ;
	len = ft_strlen(str);
	write(1, str, len);
}

int		display_usage_error(int error_code)
{
	if (error_code == 0)
		ft_putstr("usage: ./fillit [file_name]\n");
	else if (error_code == 1)
		ft_putstr("error\n");
	return (0);
}
