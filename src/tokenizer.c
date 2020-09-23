#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
  printf("welcome tokenizer\n");

  char name[6] = " Hello";
  printf("%s",name);
  return 0;
}

//return true if c is space
int space_char(char c){
  if(c == ' ' || c == '\t'){
    return 1;
  }
  return 0;
}

//return true is c is not a space
int non_space_char(char c){
  if(c != ' ' && c != '\t'){
    return 1;
  }
  return 0;
}

//return a pointer to the first character of the next space-separated word in zero-terminator str. return 0 if str does not conatin any words
char *word_start(char *str){
  while(space_char(*str)){
    str++;
  }
  return str;
}

//return a pointer terminator char following *word
char *word_terminator(char *word){
  while(non_space_char(*word)){
    word++;
  }
  return word;
}

//count number of words in string
int count_words(char *str){
  int count = 0;
  str = word_start(str)
  while(*str){
    str = word_terminator(str);
    count++;
    str = word_start(str);
  }
  return count;
}

//return new zero-terminated string
char *copy_str(char *inStr, short len){
  char *copy = malloc(sizeof(char) * (len+1));
  int i;
  for(i = 0; i < len; i++){
    *(copy+i) = *(inStr+i);
  }
  *(copy+i) = '\0';
  return copy;
}

//return fresh allocated sero-terminated vector
char **tokenize(char* str){
  int wordCount = count_words(str);
  char **tokens = malloc((wordCount);
}

//print all tokens
void print_tokens(char **tokens){
  printf(" %s\n", tokens[0]);
  printf(" %s\n", tokens[1]);
  for(int i = 0; i < MAX; i++){
    if(tokens[i] == NULL){
       break;
    }else{
      printf("%s\n", tokens[i]);
    }
  }
}

//fress all tokens and the vector containing them
void free_tokens(char **tokens){
  printf("inside free\n");
  for(int i = 0; i <= MAX; i++){
    if(tokens[i] == NULL){
      free(tokens[i]);
      break;
    }else{
      free(tokens[i]);
      (*tokens)++;
    }
  }
  free(tokens);
}
