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

#ifndef CUBE_H
#define CUBE_H
#define TWO_PI 6.28318530
#define PI 3.14159265359
#define HEIGHT 900
#define WIDTH 1400

#include "../utils/get_next_line.h"
#include "../utils/libft/libft.h"
#include "math.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include <dirent.h>

typedef struct t_dlist {
  void *content;
  time_t creation_date;
  struct t_dlist *next;
  struct t_dlist *prev;
} t_dlist;

typedef struct s_flag {
  char **args;
  int R_flag;
  int r_flag;
  int l_flag;
  int a_flag;
  int t_flag;
  int invalid_flag;
} t_flag;

int is_flag(char *str);
int get_flag_counter(char **str, int argc);

void apply_stat(t_dlist *head,char *root);
t_flag *get_flaggy(char *str);
char *get_current_flag_string(int argc, char *argv[]);
void ft_lst_print(t_dlist *currlist);

int ft_lst_lenght(t_dlist *currlist);
t_dlist *ft_mergeSort(t_dlist *head);
t_dlist *ft_lst_lastnode(t_dlist *currlist);
t_dlist *ft_lst_firstnode(t_dlist *currlist);
t_dlist *ft_lst_prevnode(t_dlist *currlist);
t_dlist *ft_lst_nextnode(t_dlist *currlist);
t_dlist *node_init(void *content);
void ft_lst_add_frontd(t_dlist **currlist, t_dlist *newnode);
void ft_lst_add_backd(t_dlist **currlist, t_dlist *node);

void ft_cleart_dlist(t_dlist **currlist, void (*del)(void *));
t_dlist *node_init(void *content);

#endif
