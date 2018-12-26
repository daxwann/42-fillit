#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>

typedef struct		s_board
{
	char			board[104][104];
	int				size;
}					t_board;

typedef struct		s_list
{
	struct s_list	*next;
	void			*content;
	int				content_size;
}					t_list;

typedef struct		s_tet
{
	int				row;
	int				col;
	char			letter;
	char			shape[4][4];
}					t_tet;

typedef struct		s_piece
{
	int				num;
	int				connection;
	int				left;
	int				top;
}					t_piece;

// output
void				ft_putchar(char c);
size_t				ft_strlen(const char *str);
void				ft_putstr(const char *str);
int					display_usage_error(int error_code);
// list
t_list				*ft_lstnew(void const *tet_piece);
void				ft_lstadd(t_list **alst, t_list *new_ele);
t_list				*create_list(int fd, char *buf);



#endif
