#include "fillit.h"

t_list	*ft_lstnew(void const *tet_piece)
{
	t_list	*link;

	if (!(link = (t_list*)malloc(sizeof(*link))))
		return (NULL);
	if (!content)
	{
		link->content = NULL;
		link->content_size = 0;
	}
	else
		list->content = tet_piece;
	link->next = NULL;
	return (link);
}

t_list	*ft_lstpush(t_list **alst, t_list *last, t_list *new_ele)
{

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
		if (!(piece = create_tet(buf, count)))
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
