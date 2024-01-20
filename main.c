#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

void upperCaseKeyTransform(const char *key, char *upperCaseKey);
void cipherTransformation(char text[], int sizeOfText);

int main(int argc, char const *argv[]) {
  setlocale(LC_ALL, "Portuguese_Brazil");

  if (argc != 2) {
    printf("Defina através da interface de linha de comando uma única chave para a cifra que contenha as 26 letras do alfabeto!");
    return 1;
  }

  int sizeOfKey = strlen(argv[1]);
  if (sizeOfKey != 26) {
    printf("Defina através da interface de linha de comando uma única chave para a cifra que contenha as 26 letras do alfabeto!");
    return 1;
  }

  char upperCaseKey[26];
  upperCaseKeyTransform(argv[1], upperCaseKey);
  
  char text[1000];

  printf("Texto simples: ");
  fgets(text, sizeof(text), stdin);

  int sizeOfText = strlen(text) - 1;

  printf("Texto cifrado: ");
  cipherTransformation(text, sizeOfText);

  return 0;
}

void upperCaseKeyTransform(const char *key, char *upperCaseKey) {

  for (int i = 0; i < 26; i++) {
    if (key[i] >= 'a' && key[i] <= 'z') {
      char upperCaseChar = key[i] - 32;
      upperCaseKey[i] = upperCaseChar;
    } else {
      upperCaseKey[i] = key[i];
    }
  }

  upperCaseKey[26] = '\0';
}

void cipherTransformation(char text[], int sizeOfText) {}