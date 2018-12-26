/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 12:38:19 by xwang             #+#    #+#             */
/*   Updated: 2018/12/26 12:38:22 by xwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_board_size(int pieces)
{
	int b_size;

	b_size = 2;
	while ((b_size * b_size) < (pieces * 4))
		b_size++;
	return (b_size);
}

void	initialize_board(char board[104][104])
{
	int row;
	int col;

	row = 0;
	while (row < 104)
	{
		col = 0;
		while (col < 104)
		{
			board[row][col] = 0;
			col++;
		}
		row++;
	}
}

void	print_board(char board[104][104], int size)
{
	int row;
	int col;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			if (board[row][col])
				ft_putchar(board[row][col]);
			else
				ft_putchar('.');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
