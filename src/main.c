#include "../Include/cube.h"
#include <dirent.h>
#include <stdio.h>
#include <string.h>

void print_current_directory(char *rooted, t_flag *flaggy) {
  DIR *root;
  char *path;
  char *temp;
  root = opendir(rooted);
  (void)flaggy;
  t_dlist *lst = NULL;
  t_dlist *temp_lst = NULL;
  if (root) {
    struct dirent *entry = readdir(root);
    if (entry == NULL) {
      return;
    }

    while (entry != NULL) {

      if (entry->d_type == DT_DIR) {

        if (strcmp(entry->d_name, "..") != 0 &&
            strcmp(entry->d_name, ".") != 0) {
          if (entry->d_name[0] == '.' && flaggy->a_flag == 0) {
            entry = readdir(root);
            continue;
          }

          temp = ft_strjoin(rooted, "/");
          path = ft_strjoin(temp, entry->d_name);

					free(temp);
          printf("%s \n -> ", path);

          // printf("%s->", path);
          ft_lst_add_backd(&lst, node_init(path));
					//free(path);
          //ft_lst_add_backd(&temp_lst, node_init(ft_strdup(entry->d_name)));
          if (flaggy->R_flag == 1) {
            // print_current_directory(path, flaggy);
          }
        }
      } else {

        if (entry->d_name[0] == '.' && flaggy->a_flag == 1) {

          struct stat fileInfo;
          t_dlist *temp = node_init(ft_strdup(entry->d_name));
          // do  a stat on the file and add it to the list
          if (stat(temp->content, &fileInfo) == 0) {
            //printf("fileInfo.st_size %lld %s\n", fileInfo.st_size,
              //     entry->d_name);
            //temp->creation_date = fileInfo.st_birthtime;
            ft_lst_add_backd(&temp_lst, temp);
          }
        } else if (entry->d_name[0] != '.') {

          ft_lst_add_backd(&temp_lst, node_init(ft_strdup(entry->d_name)));
        }
      }
      entry = readdir(root);
    }
    temp_lst = ft_mergeSort(temp_lst);
    lst = ft_mergeSort(lst);
    // apply_stat(temp_lst, temp);
    ft_lst_print(temp_lst);
    // printf("\n");
    closedir(root);
    while (lst != NULL && flaggy) {
      //     printf("%s->:\n", (char *)lst->content);
      temp_lst = lst;
      if (flaggy->R_flag == 1) {
        print_current_directory(lst->content, flaggy);
      }

       free(lst->content);
      lst = lst->next;
       free(temp_lst);
    }
    if (lst != NULL && flaggy && flaggy->R_flag == 1) {
      ft_cleart_dlist(&lst, free);
    }
     //free(temp);
  }
}

// check if the  the thing  look like a flag

int display_flaggy(t_flag *flaggy) {

  if (flaggy == NULL) {
    printf("flaggy is null\n");
    return (0);
  }
  printf("flaggy->a_flag:%d\n", flaggy->a_flag);
  printf("flaggy->R_flag:%d\n", flaggy->R_flag);
  printf("flaggy->r_flag:%d\n", flaggy->r_flag);
  printf("flaggy->t_flag:%d\n", flaggy->t_flag);
  printf("flaggy->l_flag:%d\n", flaggy->l_flag);

  return (0);
}

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;
  t_flag *flaggy = NULL;
  char *temp = NULL;
  temp = get_current_flag_string(argc, argv);
  int len = get_flag_counter(argv, argc);
  // printf("temp:%s\n", temp);
  (void)len;
  flaggy = get_flaggy(temp);
  free(temp);
  if (flaggy->invalid_flag == 1) {
    printf("invalid flag\n");
    free(flaggy);
    return (0);
  }
  // display_flaggy(flaggy);

  print_current_directory(".", flaggy);
  free(flaggy);
}
