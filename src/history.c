#include <stdio.h>
#include <stdlib.h>
#include "history.h"

//initialize list to keep history
List* init_history(){
  List *list = malloc(sizeof(List));
  list->root = NULL;
  return list;
}

//adds string to the history list
void add_history(List *list, char *str){
  Item* item = malloc(sizeof(Item));
  item -> str = str;
  if(list -> root == NULL){
    item -> id =1;
    list -> root = item;
    return;
  }
  Item *traversal = list -> root;
  int newId = 2;
  while(traversal ->next != NULL){
    newId = 1 + traversal->next->id;
    traversal = traversal->next;
  }
  item->id = newId;
  item->next = NULL;
  traversal->next = item;
}

//retrieve the string stored in the node where Item -> id == id
char *get_history(List *list, int id){
  Item *traversal = list->root;
  while(traversal->next != NULL){
    if(id == traversal->id){
      return traversal->str;
    }
    traversal = traversal -> next;
  }
  return("String not found");
}

// print the entire contents of the list
void print_history(List *list){
  Item *traversal = list->root;
  while(traversal->next != NULL){
    printf("\n%s", traversal->str);
    traversal = traversal->next;
  }
  printf("\n%s", traversal->str);
}

//free the history list and the string it references
void free_history(List *list){
  Item *traversal = list->root;
  Item *deletionTarget = NULL;
  while(traversal->next != NULL){
    free(traversal->str);
    deletionTarget = traversal;
    traversal = traversal->next;
    free(deletionTarget);
  }
  free(traversal->str);
  free(traversal);
  free(list);
}
