#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

void upperCaseKeyTransform(const char *key, char *upperCaseKey);
void cipherTransformation(char text[], int sizeOfText, char upperCaseKey[]);

int main(int argc, char const *argv[]) {
  setlocale(LC_ALL, "Portuguese_Brazil");

  if (argc != 2) {
    printf("Defina atrav�s da interface de linha de comando uma �nica chave para a cifra que contenha as 26 letras do alfabeto!");
    return 1;
  }

  int sizeOfKey = strlen(argv[1]);
  if (sizeOfKey != 26) {
    printf("Defina atrav�s da interface de linha de comando uma �nica chave para a cifra que contenha as 26 letras do alfabeto!");
    return 1;
  }

  for (int i = 0; i < 26; i++) {
    int charKey = (int) argv[1][i];
    if ( ( charKey <= 64 || charKey >= 123 ) || ( charKey >= 91 && charKey <= 96  ) ) {
      printf("Defina atrav�s da interface de linha de comando uma �nica chave para a cifra que contenha as 26 letras do alfabeto!");
      return 1;
    }
  }

  char upperCaseKey[26];
  upperCaseKeyTransform(argv[1], upperCaseKey);
  
  char text[1000];

  printf("Texto simples: ");
  fgets(text, sizeof(text), stdin);

  int sizeOfText = strlen(text) - 1;

  printf("Texto cifrado: ");
  cipherTransformation(text, sizeOfText, upperCaseKey);

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

void cipherTransformation(char text[], int sizeOfText, char upperCaseKey[]) {

  for (int i = 0; i < sizeOfText; i++) {
    int valueChar = (int) text[i];
    int letter;
    char valueKey;

    if ( valueChar >= 97 && valueChar <= 122 ) {
      letter = valueChar - 97;
      valueKey = upperCaseKey[letter] + 32;
      printf("%c", valueKey);
    } else if ( valueChar >= 65 && valueChar <= 90 ) {
      letter = valueChar - 65;
      valueKey = upperCaseKey[letter];
      printf("%c", valueKey);
    } else {
      printf("%c", valueChar);
    }
   
  }

}