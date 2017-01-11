#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projet.h"


char* traduc (char* message)
{
  char * msg = malloc(512 * sizeof(char));
  int longueurChaine;
  int posChaine;
  int compteur;
  char * temp;
  
  longueurChaine = strlen(message);

  for (compteur=0; compteur<longueurChaine; compteur++)
  {
    char lettre;
    lettre = message[compteur];

    switch(lettre)
    {
      case ' ':
        temp = "3";
        strcat(msg,temp);
        break;
      case 'a':
        temp = "012";
        strcat(msg,temp);;
        break;
      case 'b':
        temp = "10002";
        strcat(msg,temp);
        break;
      case 'c':
        temp = "10102";
        strcat(msg,temp);
        break;
      case 'd':
        temp = "1002";
        strcat(msg,temp);
        break;
      case 'e':
        temp = "02";
        strcat(msg,temp);
        break;
      case 'f':
        temp = "00102";
        strcat(msg,temp);
        break;
      case 'g':
        temp = "1102";
        strcat(msg,temp);
        break;
      case 'h':
        temp = "00002";
        strcat(msg,temp);
        break;
      case 'i':
        temp = "002";
        strcat(msg,temp);
        break;
      case 'j':
        temp = "01112";
        strcat(msg,temp);
        break;
      case 'k':
        temp = "1012";
        strcat(msg,temp);
        break;
      case 'l':
        temp = "01002";
        strcat(msg,temp);
        break;
      case 'm':
        temp = "112";
        strcat(msg,temp);
        break;
      case 'n':
        temp = "102";
        strcat(msg,temp);
        break;
      case 'o':
        temp = "1112";
        strcat(msg,temp);
        break;
      case 'p':
        temp = "01102";
        strcat(msg,temp);
        break;
      case 'q':
        temp = "11012";
        strcat(msg,temp);
        break;
      case 'r':
        temp = "0102";
        strcat(msg,temp);
        break;
      case 's':
        temp = "0002";
        strcat(msg,temp);
        break;
      case 't':
        temp = "12";
        strcat(msg,temp);
        break;
      case 'u':
        temp = "0012";
        strcat(msg,temp);
        break;
      case 'v':
        temp = "00012";
        strcat(msg,temp);
        break;
      case 'w':
        temp = "0112";
        strcat(msg,temp);
        break;
      case 'x':
        temp = "10012";
        strcat(msg,temp);
        break;
      case 'y':
        temp = "10112";
        strcat(msg,temp);
        break;
      case 'z':
        temp = "11002";
        strcat(msg,temp);
        break;
      case '1':
        temp = "011112";
        strcat(msg,temp);
        break;
      case '2':
        temp = "001112";
        strcat(msg,temp);
        break;
      case '3':
        temp = "000112";
        strcat(msg,temp);
        break;
      case '4':
        temp = "000012";
        strcat(msg,temp);
        break;
      case '5':
        temp = "000002";
        strcat(msg,temp);
        break;
      case '6':
        temp = "100002";
        strcat(msg,temp);
        break;
      case '7':
        temp = "110002";
        strcat(msg,temp);
        break;
      case '8':
        temp = "111002";
        strcat(msg,temp);
        break;
      case '9':
        temp = "111102";
        strcat(msg,temp);
        break;
      case '0':
        temp = "111112";
        strcat(msg,temp);
        break;
      default:
       printf("Cette lettre n'est pas reconnue");
       break;
    }
  }
  

  return msg;
}
/*
int main()
{
    char * message= "guillaume";
    char * msg;

    msg = traduc(message);
    printf("%s\n", msg);
    return 0;
}
*/
