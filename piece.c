/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 12:51:57 by xwang             #+#    #+#             */
/*   Updated: 2018/12/26 12:52:00 by xwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_pieces(t_list *tetriminos)
{
	int count;

	count = 0;
	while (tetriminos)
	{
		count++;
		tetriminos = tetriminos->next;
	}
	return (count);
}

void	initialize_piece(t_piece *piece)
{
	piece->num = 0;
	piece->connection = 0;
	piece->left = 4;
	piece->top = 4;
}

int		count_connections(char *str, int position)
{
	int count;

	count = 0;
	if (position % 5 > 0 && str[position - 1] == '#')
		count++;
	if (position % 5 < 4 && str[position + 1] == '#')
		count++;
	if (position / 5 > 0 && str[position - 5] == '#')
		count++;
	if (position / 5 < 4 && str[position + 5] == '#')
		count++;
	return (count);
}

void	modify_piece(t_piece *piece, char *str, int row, int pos)
{
	if (row < piece->top)
		piece->top = row;
	if (pos % 5 < piece->left)
		piece->left = pos % 5;
	piece->connection += count_connections(str, pos);
	piece->num += 1;
}
