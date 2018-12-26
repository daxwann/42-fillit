/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 12:51:47 by xwang             #+#    #+#             */
/*   Updated: 2018/12/26 13:14:52 by xwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*ft_lstnew(void *tet_piece)
{
	t_list	*link;

	if (!(link = (t_list*)malloc(sizeof(*link))))
		return (NULL);
	if (!tet_piece)
	{
		link->content = NULL;
		link->content_size = 0;
	}
	else
		link->content = tet_piece;
	link->next = NULL;
	return (link);
}

t_list	*ft_lstpush(t_list **head, t_list *last, t_list *new_ele)
{
	if (!head || !new_ele)
		return (NULL);
	if (!last)
	{
		(*head)->next = new_ele;
		last = (*head)->next;
	}
	else
	{
		last->next = new_ele;
		last = last->next;
	}
	return (last);
}

t_list	*create_list(int fd, char *buf)
{
	t_tet	*piece;
	t_list	*head;
	t_list	*last;
	int		count;
	int		no_newline;

	count = 0;
	no_newline = 0;
	head = NULL;
	last = NULL;
	while (!no_newline)
	{
		if (read(fd, buf, 20) != 20)
			return (NULL);
		if (!(piece = check_tet(buf, count)))
			return (NULL);
		if (!head)
			head = ft_lstnew(piece);
		else
			last = ft_lstpush(&head, last, ft_lstnew(piece));
		if (!read(fd, buf, 1))
			no_newline = 1;
		count++;
	}
	return (head);
}
