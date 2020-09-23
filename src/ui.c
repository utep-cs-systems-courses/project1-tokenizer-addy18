#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.c"
#include "history.c"

#define limit 50 //limit how many characters can be entered

int main(){
  //call tokenizer
  char user_input[limit];
  printf("enter a string:");
  fgets(user_input, limit, stdin);
  char *str = user_input;
  printf("%s", word_terminator(str));
  char **token = tokenize(str);
  print_tokens(token);
  free_tokens(token);
  printf("\n");

  //history calls
  char *temp = str;
  List *strings;
  strings = init_history();
  int num_words = count_words(str);
  
  for(int i = 0; i < num_words; i++){
    add_history(strings, temp);
    temp = word_terminator(temp);
    temp = word_start(temp);
  }
  // hisotry_UI(strings, str); 
  free_history(strings);
  

  return 0;
}
  
