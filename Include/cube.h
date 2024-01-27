/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:33:18 by jemartel          #+#    #+#             */
/*   Updated: 2023/06/10 21:16:09 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  CUBE_H
# define  CUBE_H
# define TWO_PI			6.28318530
# define PI				3.14159265359
# define HEIGHT			900
# define WIDTH			1400

# include "stdio.h"
# include "stdlib.h"
# include "../utils/get_next_line.h"
# include "../utils/libft/libft.h"
# include "stdbool.h"
# include "math.h"
#include <dirent.h>
typedef struct t_tree
{

	struct t_tree	*node;
	 
	void			*content;
	struct t_tree	*left ;
	struct t_tree	*right;
}					t_tree;







t_tree		*ft_lst_lastnode(t_tree *currlist);
t_tree		*ft_lst_firstnode(t_tree *currlist);
t_tree		*ft_lst_prevnode(t_tree *currlist);
t_tree		*ft_lst_nextnode(t_tree *currlist);
t_tree		*node_init(void *content);

#endif 
