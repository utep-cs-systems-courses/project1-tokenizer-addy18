#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define limit2 10

//initialize list to keep history
List* init_history(){
  List *list = malloc(sizeof(List));
  list->root = NULL;
  return list;
}

//adds string to the history list
void add_history(List *list, char *str){
  int len = len_word(str);
  int count = 2;

  if(list->root == NULL){
    char *string_copy = copy_str(str, len);
    Item *newNode = (Item*) malloc (sizeof(Item));
    newNode->str = string_copy;
    newNode->id = 1;
    newNode->next = NULL;
    list->root = newNode;
  }else{
    Item *current;
    current = (list->root);
    while(current->next != NULL){
      current = current->next;
      ++count;
    }
    char *string_copy = copy_str(str,len);
    current->next = (Item*)malloc(sizeof(Item));
    current->next->id = count;
    current->next->str= string_copy;
    current->next->next = NULL;
  }
}

//retrieve the string stored in the node where Item -> id == id
char *get_history(List *list, int id){
  char *history;
  if(list->root == NULL)
    printf("List is empty");
  else{
    Item *current;
    current = (list->root);
    while(current != NULL){
      if(current->id == id){
	history = current ->str;
	return history;
      }
      current = current -> next;
    }
  }
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
  Item *next;
  
  while(traversal != NULL){
    next = traversal ->next;
    free(traversal ->str);
    free(traversal);
    traversal = next;
  }
  free(list);
}

int get_input(){
  int user_input = 0;
  int count = 0;

  while(user_input >= 0){
    printf("select an option\n");
    printf("1. search for input\n");
    printf("2. print user history\n");
    printf("3. quit\n");

    scanf("%d\n", &user_input);
    
  }
  return user_input;
}

char *search_history(List *list, char *str){
  char input[limit2];
  int is_exclam,  int_conv, i;
  int num_words = count_words(str);
  char *found_str;

  while(is_exclam == 0){
    printf("enter '!(the number of string youd like to find)'\n");
    fgets(input, limit2, stdin);
    printf("\n");

    if(input[0] == '!')
      is_exclam = 1;
  }
  for(i = 1; input[i] >= '0' && input[i] <= '9'; i++)
    int_conv = 10*int_conv + (input[i] - '0');

  if(int_conv > 0 && int_conv <= num_words)
    found_str = get_history(list, int_conv);
  else{
    printf("that string is not in history\n");
    found_str = NULL;
  }
  return found_str;
}

void history_UI(List *list, char *str){
  char *search_node;
  int user_input, search, print, quit;
  user_input = get_input();
  printf("\n");

  if(user_input == 3)
    printf("goodbye");
    
  while(user_input != 3){
    if(user_input == 1){
      search_node = search_history(list, str);
      if(search_node != NULL){
	printf("the string found in history");
	printf("->");
	printf("%s\n", search_node);
      }
    }else {
      print_history(list);
      printf("\n");
    }
    user_input = get_input();
    printf("\n");

    if(user_input == 3)
      break;
  }
}
	
