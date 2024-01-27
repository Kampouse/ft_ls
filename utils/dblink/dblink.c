/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dblink.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:12:36 by jemartel          #+#    #+#             */
/*   Updated: 2022/06/06 12:55:09 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../Include/cube.h"
#include "stdio.h"
#include "stdlib.h"

t_tree	*node_init(void *content)
{
	t_tree	*link;

	link = (t_tree *)malloc(sizeof(*link));
	if (!link)
		return (NULL);
	link->content = content;
	link->left = NULL;
	link->right = NULL;
	return (link);
}

void	ft_lst_add_frontd(t_tree **currlist, t_tree *newnode)
{
	if (currlist)
	{
		if (*currlist)
			newnode->right = *currlist;
		*currlist = newnode;
	}
}

void	ft_lst_add_backd(t_tree **currlist, t_tree *node)
{
	t_tree	*last;

	if (currlist)
	{
		if (*currlist)
		{
			last = ft_lst_lastnode(*currlist);
			last->right = node;
			node->left = last;
		}
		else
			*currlist = node;
	}
}

void	ft_clearnode(t_tree *currlist, void (*del)(void *))
{
	if (currlist)
	{
		(*del)(currlist->content);
		free(currlist);
	}
}

void	ft_cleart_tree(t_tree **currlist, void (*del)(void *))
{
	t_tree	*iter;

	if (!del || !currlist || !*currlist)
		return ;
	while (currlist && *currlist)
	{
		iter = (*currlist)->right;
		*currlist = iter;
		ft_clearnode(*currlist, del);
	}
}
