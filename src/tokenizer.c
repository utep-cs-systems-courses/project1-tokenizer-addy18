#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main(){
  char input[MAX];
  printf("welcome to tokenizer\nEnter a string\n");
  scanf("%[^\n]", &input);
  printf(input);

  char *toToken;
  toToken = input;
  printf("stored to pointer\n");

  char **tokens;
  tokens = tokenize(input);
  printf("tokenized\n");

  print_tokens(tokens);
  printf("finished printing\n");

  free_tokens(tokens);
  printf("free tokens\n");

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
  if(c != ' ' || c != '\t'){
    return 1;
  }
  return 0;
}

//return a pointer to the first character of the next space-separated word in zero-terminator str. return 0 if str does not conatin any words
char *word_start(char *str){
  int i = 0;
  while(space_char(str[i])){
    i++;
    return &str[i];
  }
}

//return a pointer terminator char following *word
char *word_terminator(char *word){
  int i = 0;
  while(non_space_char(word[i])){
    i++;
    return &word[i];
  }
}

//count number of words in string
int count_words(char *str){
  printf("word count\n");
  int count = 0;
  while(str != word_terminator(str)){
    count++;
  }
  return count;
}

//return new zero-terminated string
char *copy_str(char *inStr, short len){
  printf("copy string\n");
  char *outStr = malloc(len * sizeof(char));
  for(int i = 0; i <= len+1; i++){
    if(i == len+1){
      outStr[i] = '\0';
    }else {
      outStr[i] = inStr[i];
    }
  }
}

//return fresh allocated sero-terminated vector
char **tokenize(char* str){
  printf("tokenize\n");
  short wordCount = count_words(str);
  char *tokenWords[wordCount];
  short wordLength;
  char **tokens;
  char *starts;

  for(int i = 0; i < wordCount && str[i] != '\0'; i++){
    starts = word_start(str);
    printf("%s\n", starts);
    wordLength = 0;
    for(int j =0; j < MAX; j++){
      if(non_space_char(starts[j]) == 0){
	break;
      }else {
	wordLength++;
      }
   }
   printf("word length is %d \n", wordLength);
   tokenWords[i] = (copy_str(starts, wordLength));
   str = word_terminator(starts);
  }
  printf("finsihed tokenize\n");
  tokens = tokenWords;
  return tokens;
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
