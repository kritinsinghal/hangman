/////////////////////////////////////////////////////////////////////////////
// INTEGRITY INSTRUCTIONS

// Explicitly state the level of collaboration on this question
// Examples:
//   * I discussed ideas with classmate(s) [include name(s)]
//   * I worked together with classmate(s) in the lab [include name(s)]
//   * Classmate [include name] helped me debug my code
//   * I consulted website [include url]
//   * None
// A "None" indicates you completed this question entirely by yourself
// (or with assistance from course staff)
/////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT:
// I received help from the following sources:

// None

// Name: Kritin Singhal  
// login ID: K4SINGHA
/////////////////////////////////////////////////////////////////////////////

#include <string.h>
#include "hangman-io.h"
#include "words.h"
#include "cs136.h"


// enter_letter(text,strike) prints the hangman, the letter prompt
//    and the text which the user has guessed.
void enter_letter(char *text, int strike) {
  print_hangman(strike);
  printf("%s",letter_prompt);
  printf("%s\n", text);
}

int main(void) {
  int game_number,word_count=0,strike=0,flag=0,x=0;
  char ch,res;
  ch=32;
  printf(enter_game_number,max_words);
  scanf("%d",&game_number);
  while((game_number<0)||(game_number>max_words)) {
    printf("%s",invalid_game_number);
    printf(enter_game_number,max_words);
    scanf("%d",&game_number);
  }
  const char *word=get_word(game_number);
  const char *word1=get_word(game_number);
  while(*word1) {
    word_count++;
    ++word1;
  }
  char text[50];
  char text1[50];
  for(int i=0;i<word_count;i++) {
    if(word[i]!=32) {
      text[i]=42;
    } else {
      text[i]=32;
    }
  }
  enter_letter(text,strike);
  while(strike<max_strikes) {
    flag=0;
    if(scanf(" %c",&ch)==1) {
      if((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) {
        for(int i=0;i<x;i++) {
          if((ch==text1[i])||((ch-32)==text1[i])) {
            if(ch<97) {
             printf(already_guessed_letter,ch); 
            } else {
             printf(already_guessed_letter,ch-32); 
            }
           flag=1;
         }
       }
       for(int i=0;i<word_count;i++) {
           if((ch==word[i])||((ch-32)==word[i])) {
             text[i]=word[i];
             flag=1;
          }
        }
        if(ch<97) {
          text1[x++]=ch;
        } else {
          text1[x++]=ch-32;
        }
      } else if(ch!=10) {
        printf(not_a_letter,ch);
        flag=1;
      } else {
        continue;
      }
    } else {
      continue;
    }
    if(flag==0) {
      strike++;
      if(ch<97) {
        printf(not_in_word,ch);
      } else {
        printf(not_in_word,(ch-32));
      }
      if(strike<max_strikes) {
        printf(not_last_guess,max_strikes-strike);
        enter_letter(text,strike);
      } else {
        print_hangman(strike);
        printf(game_over,word);
        printf("%s",play_again);
        while(true) {
          if((scanf(" %c",&res)==1)&&(res!=10)) {
            if(res=='N') {
              return 0;
            } else if(res=='Y') {
              main();
              return 0;
            } else {
              printf("%s",invalid_play_again_response);
              printf("%s",play_again);
            }
          }
        }
      }
    } else {
      if(strcmp(text,word)==0) {
        printf(congratulations,word);
        printf("%s",play_again);
        while(true) {
          if((scanf(" %c",&res)==1)&&(res!=10)) {
            if(res=='N') {
              return 0;
            } else if(res=='Y') {
              main();
              return 0;
            } else {
              printf("%s",invalid_play_again_response);
              printf("%s",play_again);
            }
          }
        }
      } else {
        enter_letter(text,strike);
      }
    }
  }
}



