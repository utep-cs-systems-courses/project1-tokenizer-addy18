#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

//return true if c is space
int space_char(char c){
  if(isspace(c)){
    return 1;
  }
  return 0;
}

//return true is c is not a space
int non_space_char(char c){
  if(!isspace(c)){
    return 1;
  }
  return 0;
}

//return a pointer to the first character of the next space-separated word in zero-terminator str. return 0 if str does not conatin any words
char word_start(char *str){
}

//return a pointer terminator char following *word
char *word_terminator(char *word){}

//count number of words in string
int count_words(char *str){}

//return new zero-terminated string
char *copy_str(cahr *inStr, short len){}

//return fresh allocated sero-terminated vector
char **tokenize(char* str){}

//print all tokens
void print_tokens(char **tokens){}

//fress all tokens and the vector containing them
void free_tokens(char **tokens){}
