#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  setlocale(LC_ALL, "Portuguese_Brazil");

  printf("Oi");


  return 0;
}