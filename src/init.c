/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:24:15 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/16 15:40:51 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"
#include <stdlib.h>

int ft_isspace(char c) {
  if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
    return (1);
  return (0);
}

// check if the string startt with a - and that there is a char after  the -
int is_flag(char *str) {
  // check the len  of the string
  if (ft_strlen(str) == 1)
    return (0);
  if (str[0] == '-' && str[1] != '\0')
    return (1);
  return (0);
}

// get me the number of fags so i can  take the correct agrs for th dir
int get_flag_counter(char **str, int argc) {

  // check ift there no flag
  if (argc == 1) {
    return 1;
  }

  int count = 0;
  int i = 0;
  while (count < argc) {
    if (is_flag(str[i]) == 1) {
      count++;
    } else {
      return count;
    }
  }

  return count;
}

// take all the argument and join    the flags into one string and return it the
// flag is not valid return the current string
char *get_current_flag_string(int argc, char *argv[]) {

  int i = 1;
  char *flag = ft_strdup("");
  char *temp;
  if (argc == 1) {

    free(flag);

    return NULL;
  }

  while (i < argc) {
    if (is_flag(argv[i]) == 1) {
      temp = ft_strjoin(flag, argv[i]);
      free(flag);
      flag = temp;
    } else {
      return (flag);
    }
    i++;
  }
  return (flag);
}

t_flag *get_flaggy(char *str) {
  int i;
  i = 0;
  t_flag *flag = malloc(sizeof(t_flag));
  flag->l_flag = 0;
  flag->R_flag = 0;
  flag->a_flag = 0;
  flag->r_flag = 0;
  flag->t_flag = 0;
  flag->invalid_flag = 0;
  if (!str) {
    return (flag);
  }
  if (ft_strlen(str) == 1 && str[0] == '-') {
    return (flag);
  }
  while (str[i] != '\0') {
    if (ft_isspace(str[i]) == 0 || (str[i] == '-' && i == 0)) {
      i++;
    }
    if (str[i] == '-' && i != 1) {
      return (NULL);
    } else if (str[i] == 'l') {
      flag->l_flag = 1;
      printf("flag l\n");
    } else if (str[i] == 'R') {
      flag->R_flag = 1;
      // printf("flag R\n");
    } else if (str[i] == 'a') {
      flag->a_flag = 1;
    } else if (str[i] == 'r') {

      flag->r_flag = 1;
      printf("flag r\n");
    } else if (str[i] == 't') {
      flag->t_flag = 1;
      printf("flag t\n");
    } else {
      flag->invalid_flag = 1;
      return (flag);
    }
    i++;
  }
  return (flag);
}

t_flag *setup_args(int argc, char *argv[]) {
  (void)argc;
  (void)argv;
  // extract the flag  from argv and return it
  int i = 1;
  //  check if the first argument is a flag
  t_flag *flag = get_flaggy(argv[1]);
  (void)flag;
  while (argv[i] != NULL) {

    printf("argv[%d] : %s\n", i, argv[i]);
    i++;
  }

  return (0);
}
