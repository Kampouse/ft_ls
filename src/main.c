#include "../Include/cube.h"
#include <dirent.h>
#include <stdio.h>
#include <string.h>

void print_current_directory(char *rooted, t_flag *flaggy) {
  DIR *root;
  char *path;
  root = opendir(rooted);
  (void)flaggy;
  t_dlist *lst = NULL;
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

          char *temp = ft_strjoin(rooted, "/");
          path = ft_strjoin(temp, entry->d_name);
          free(temp);
          printf("%s/\t", entry->d_name);
          ft_lst_add_backd(&lst, node_init(path));
          // print_current_directory(path, flaggy);
        }
      } else {
        printf("%s\t\t", entry->d_name);
      }
      entry = readdir(root);
    }
    printf("\n");
    closedir(root);
    while (lst != NULL && flaggy && flaggy->R_flag == 1) {
      printf("%s->:\n", (char *)lst->content);
      print_current_directory(lst->content, flaggy);
      lst = lst->next;
    }
    if (lst != NULL &&  flaggy && flaggy->R_flag == 1 ) {
      ft_cleart_dlist(&lst, free);
    }
  }
}

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;

  t_flag *flaggy = NULL;

  flaggy = get_flaggy(argv[1]);
  if (argc == 1) {
    print_current_directory(".", flaggy);
  } else if (argc == 2) {

    if (flaggy == NULL) {
      printf("flaggy is null\n");
      return (0);
    }
    print_current_directory(".", flaggy);
  } else {
    printf("error\n");
  }
  free(flaggy);

  // make a linked list of  all the directories and files in the current
  // directory if the  flag  is  -a  then  print  all  the  files  and
  // directories  in  the  current  directory if the  flag  is  -l  then print
  // all  the  files  and  directories  in  the  current  directory  in  a
  // list format if the  flag  is  -R  then  print  all  the  files  and
  // directories in  the  current  directory  in  a  list  format  and
  // recursively  print all  the  files  and  directories  in  the
  // subdirectories  of  the current directory if the  flag  is  -r  then
  // print  all  the  files  and directories  in  the  current  directory  in
  // a  list  format  in  reverse order if the  flag  is  -t  then  print  all
  // the  files  and  directories in  the  current  directory  in  a  list
  // format  sorted  by  time modified (newest  first) if the  flag  is  -a -l
  // then  print  all  the  files  and directories  in  the  current directory
  // in  a  list  format  including the  hidden  files  and  directories if
  // the  flag  is  -a  -R  then  print all  the  files  and  directories  in
  // the  current  directory  in  a  list format  including  the  hidden files
  // and  directories  and  recursively print  all  the  files  and
  // directories  in  the  subdirectories  of  the current  directory

  // flag -l -R -a -r -t
  // check the  flags  and  print  the  files  and  directories  in  the
  // current directory i want to print_current_directory(".");
}
