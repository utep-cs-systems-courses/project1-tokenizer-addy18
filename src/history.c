#include <stdio.h>
#include <stdlib.h>
#include "history.h"

//initialize list to keep history
List *init_history(){}

//adds string to the history list
void add_history(List *list, char *str){}

//retrieve the string stored in the node where Item -> id == id
char *get_history(List *list, int id){}

// print the entire contents of the list
void print_history(List *list){}

//free the history list and the string it references
void free_history(List *list){}
