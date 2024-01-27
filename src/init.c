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

t_flag *get_flaggy(char *str) {
  int i = 0;
  t_flag *flag = malloc(sizeof(t_flag));

  flag->l_flag = 0;
  flag->R_flag = 0;
  flag->a_flag = 0;
  flag->r_flag = 0;
  flag->t_flag = 0;

  if (!str) {
    return (flag);
  }

  if (ft_strlen(str) == 1 && str[0] == '-') {
    return (flag);
  }
  while (str[i] != '\0') {
    if (str[i] == '-' && i == 0) {
      i++;
      continue;
    } else if (str[i] == '-' && i != 1) {
      printf(" hello %s\n", str);
      return (NULL);
    } else if (str[i] == 'l') {
      flag->l_flag = 1;
      printf("flag l\n");
    } else if (str[i] == 'R') {
      flag->R_flag = 1;
      printf("flag R\n");
    } else if (str[i] == 'a') {

      flag->a_flag = 1;
      printf("flag a\n");
    } else if (str[i] == 'r') {

      flag->r_flag = 1;
      printf("flag r\n");
    } else if (str[i] == 't') {
      flag->t_flag = 1;
      printf("flag t\n");
    } else {
      printf("str[i] : %c\n", str[i]);
      printf("flag error\n");
      free(flag);
      return (NULL);
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
