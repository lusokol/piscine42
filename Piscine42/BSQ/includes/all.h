/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:44:25 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/17 11:47:07 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H

# define ALL_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_list
{
	int				data;
	struct s_list	*next;
}				t_list;

typedef struct	s_map_info
{
	int			size;
	int			line_length;
	char		empty;
	char		obstacle;
	char		full;
	int			fd;
	t_list		first_line;
	int			**int_map;
}				t_map_info;

typedef	struct	s_biggest
{
	int			row;
	int			col;
	int			d;
}				t_biggest;

typedef	struct	s_index
{
	int			i;
	int			j;
	int			r;
	int			c;
	int			index;
	int			id;
	char		*str;
	int			str_length;
	int			legit;
}				t_index;

void			ft_strcat(char *dest, char *str);
void			copy_and_verify(char *dest, char *src);
int				ft_strlen(char *str);
int				map_helper(t_list	*first_line, char *buffer);
void			main_helper(int i);
t_biggest		*g_sqr;
t_map_info		*g_map_info;
t_index			*g_i;
int				min(int	a, int	b, int c);
t_list			*ft_create_elem(int data);
void			ft_list_push_back(t_list **first_line, int data);
void			ft_putstr(char *str);
int				ft_atoi(char *str, int	length);
void			print_t_map(int **map);
t_map_info		*save_info(char *info_arr);
int				map_reader(int fd, char *input);
void			check_biggest_square(int row, int col, int **int_map);
int				convert_map_the_rest(char *buffer, int **int_map);
void			convert_map_first_line(t_list *first_line, int **int_map);
int				validate_sym(char c);
void			free_everything(void);

#endif
