#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "projet.h"


int cesar_crypt (int decallage, char * texte)
{
  int i;
  size_t l;
  char alpha[26] = "abcdefghijklmnopqrstuvwxyz";

  for (l=0; l<strlen(texte); l++)
  {
    for (i=0; i<26; i++)
    {
      if (alpha[i] == * texte)
      {
	* texte = alpha[(i+decallage)%26];
	* texte++;
      }
    }
  }
  return 1;
}

int cesar_decrypt (int decallage, char *texte)
{
  int i;
  size_t l;
  char alpha[26] = "abcdefghijklmnopqrstuvwxyz";

  for (l=0; l<strlen(texte); l++)
  {
    for (i=0; i<26; i++)
    {
      if (alpha[i] == * texte)
      {
	* texte = alpha[(i-decallage)%26];
	* texte++;
      }
    }
  }
  return 1;
}
/*
int main()
{
  int decallage = 1;
  char texte[512] = "coucou";
  cesar_crypt(decallage,texte);
  printf("%s\n", texte);
  cesar_decrypt(decallage,texte);
  printf("%s\n", texte);	
  return 0;
}
*/
