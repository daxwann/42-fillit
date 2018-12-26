/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 12:50:49 by xwang             #+#    #+#             */
/*   Updated: 2018/12/26 12:50:52 by xwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_board bd;
	char	buf[20];
	t_list	*tetriminos;
	int		fd;

	if (argc != 2)
		return (display_usage_error(0));
	initialize_board(bd.board);
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		return (display_usage_error(1));
	tetriminos = create_list(fd, buf);
	if (!tetriminos)
		return (display_usage_error(1));
	bd.size = get_board_size(count_pieces(tetriminos));
	if (!solve(&bd, tetriminos))
		return (display_usage_error(1));
	print_board(bd.board, bd.size);
	return (0);
}
