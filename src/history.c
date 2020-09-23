#include <stdio.h>
#include <stdlib.h>
#include "history.h"

int main(){
  return 0;
}

//initialize list to keep history
List* init_history(){
  List *list = malloc(sizeof(List));
  list->root = NULL;
  return list;
}

//adds string to the history list
void add_history(List *list, char *str){
  Item* item = malloc(sizeof(List));
  Item* lastItem = list;

  if(list == 0){
    list = item;
    return;
  }

  item -> root = str;
  lastItem -> next = 0;

  while(lastItem -> next != 0){
    lastItem -> next = item;
  }
}
//retrieve the string stored in the node where Item -> id == id
//char *get_history(List *list, int id){}

// print the entire contents of the list
//void print_history(List *list){}

//free the history list and the string it references
//void free_history(List *list){}
