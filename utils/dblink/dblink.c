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

// this  is unssafe because it  not bound the size of the string
int fr_strcmp(const char *str1, const char *str2) {
  while (*str1 && *str2 && *str1 == *str2) {
    str1++;
    str2++;
  }
  return ((unsigned char)*str1 - (unsigned char)*str2);
}

t_dlist *node_init(void *content) {
  t_dlist *link;

  link = (t_dlist *)malloc(sizeof(*link));
  if (!link)
    return (NULL);
  link->content = content;
  link->prev = NULL;
  link->next = NULL;
  return (link);
}

void ft_lst_add_frontd(t_dlist **currlist, t_dlist *newnode) {
  if (currlist) {
    if (*currlist)
      newnode->next = *currlist;
    *currlist = newnode;
  }
}

void ft_lst_add_backd(t_dlist **currlist, t_dlist *node) {
  t_dlist *last;

  if (currlist) {
    if (*currlist) {
      last = ft_lst_lastnode(*currlist);
      last->next = node;
      node->prev = last;
    } else
      *currlist = node;
  }
}

void ft_clearnode(t_dlist *currlist, void (*del)(void *)) {
  if (currlist) {
    (*del)(currlist->content);
    free(currlist);
  }
}

void ft_cleart_dlist(t_dlist **currlist, void (*del)(void *)) {
  t_dlist *iter;

  if (!del || !currlist || !*currlist)
    return;
  while (currlist && *currlist) {
    iter = (*currlist)->next;
    *currlist = iter;
    ft_clearnode(*currlist, del);
  }
}

t_dlist *split(t_dlist *head) {
  t_dlist *fast = head;
  t_dlist *slow = head;
  while (fast->next && fast->next->next) {
    fast = fast->next->next;
    slow = slow->next;
  }
  t_dlist *temp = slow->next;
  slow->next = NULL;
  return temp;
}

// Function to merge two sorted lists

t_dlist *ft_lst_merge(t_dlist *first, t_dlist *second) {
  if (!first)
    return second;
  if (!second)
    return first;

  if (fr_strcmp(first->content, second->content) < 0) {
    first->next = ft_lst_merge(first->next, second);
    if (first->next)
      first->next->prev = first;
    first->prev = NULL;
    return first;
  } else {
    second->next = ft_lst_merge(first, second->next);
    if (second->next)
      second->next->prev = second;
    second->prev = NULL;
    return second;
  }
}

// Recursive merge sort function
t_dlist *ft_mergeSort(t_dlist *head) {
  if (!head || !head->next)
    return head;
  t_dlist *second = split(head);

  head = ft_mergeSort(head);
  second = ft_mergeSort(second);

  return ft_lst_merge(head, second);
}

// print  the list from  the  first  to the last  element
void ft_lst_print(t_dlist *currlist) {
  t_dlist *temp;
  while (currlist) {
    printf("%s  ", (char *)currlist->content);
    free(currlist->content);
    currlist->content = NULL;
    temp = currlist;
    currlist = currlist->next;
    free(temp);
    temp = NULL;
  }
}
