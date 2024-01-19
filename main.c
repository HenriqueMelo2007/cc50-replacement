#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

char* lowerCaseKeyTransform (char key[]);
void cipherTransformation (char text[]);

int main(int argc, char const *argv[])
{
  setlocale(LC_ALL, "Portuguese_Brazil");

  if ( argc != 2 ) {
    printf("Defina através da interface de linha de comando uma única chave para a cifra que contenha as 26 letras do alfabeto!");
    return 1;
  }

  int sizeOfKey = strlen(argv[1]);
  if ( sizeOfKey != 26 ) {
    printf("Defina através da interface de linha de comando uma única chave para a cifra que contenha as 26 letras do alfabeto!");
    return 1;
  }

  char lowerCaseKey[26] = lowerCaseKeyTransform(argv[1]);
  char text[1000];

  printf("Texto simples: ");
  fgets(text, sizeof(text), stdin);


  return 0;
}

char* lowerCaseKeyTransform (char key[]) {}

void cipherTransformation (char text[]) {}