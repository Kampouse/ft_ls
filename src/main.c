#include <stdio.h>
#include <dirent.h>
#include "../Include/cube.h"
#include <stdio.h>
#include <dirent.h>
#include <string.h>

void print_current_directory(char *rooted) {
    DIR *root;
    root = opendir(rooted);
    if (root) {
    ft_strjoin("rooted = %s\n", rooted);
        struct dirent *entry = readdir(root);
        while (entry != NULL) {
            if (entry->d_type == DT_DIR) {
                if (strcmp(entry->d_name, "..") != 0 && strcmp(entry->d_name, ".") != 0) {
                    char path[1024];
                    snprintf(path, sizeof(path), "%s/%s", rooted, entry->d_name);
                    printf("%s/\n", entry->d_name);
                    print_current_directory(path);
                }
            } else {
                printf("%s\t", entry->d_name);
            }
            entry = readdir(root);
        }
        closedir(root);
    }
}








int main( int argc, char *argv[]) {
  (void) argc;
  (void) argv;


// make a linked list of  all the directories and files in the current directory 
// if the  flag  is  -a  then  print  all  the  files  and  directories  in  the  current  directory
// if the  flag  is  -l  then  print  all  the  files  and  directories  in  the  current  directory  in  a  list  format
// if the  flag  is  -R  then  print  all  the  files  and  directories  in  the  current  directory  in  a  list  format  and  recursively  print  all  the  files  and  directories  in  the  subdirectories  of  the  current  directory
// if the  flag  is  -r  then  print  all  the  files  and  directories  in  the  current  directory  in  a  list  format  in  reverse  order
// if the  flag  is  -t  then  print  all  the  files  and  directories  in  the  current  directory  in  a  list  format  sorted  by  time  modified  (newest  first)
// if the  flag  is  -a  -l  then  print  all  the  files  and  directories  in  the  current  directory  in  a  list  format  including  the  hidden  files  and  directories
// if the  flag  is  -a  -R  then  print  all  the  files  and  directories  in  the  current  directory  in  a  list  format  including  the  hidden  files  and  directories  and  recursively  print  all  the  files  and  directories  in  the  subdirectories  of  the  current  directory


    //flag -l -R -a -r -t  
// check the  flags  and  print  the  files  and  directories  in  the  current  directory
// i want to  
    print_current_directory(".");


 

   




  }