#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int indexOf (char* string, char key);
int convert_to_dec (int from, char* data, char* ref);

int main () {
  char ref[] = "0123456789ABCDEF";
  char input[256], output[256];
  int inbase10, fbase, tbase;

  printf("Enter input number: ");
  scanf("%s", input);
  printf("Enter input base: ");
  scanf("%d", &fbase);
  printf("Enter target base: ");
  scanf("%d", &tbase);

  if (fbase != 10) {
    inbase10 = convert_to_dec(fbase, input, ref);
  } else {
    inbase10 = atoi(input);
  }

  if (tbase == 10) {
    printf("Result: %d\nDONE!\n", inbase10);
    return 0;
  }

  int divi = inbase10;
  int k = 0;
  while (divi > 0) {
    int odivi = divi;
    int rem = divi % tbase;
    output[k] = ref[rem];
    divi = (divi - rem) / tbase;
    printf("%d / %d = %d \t\t R: %d\n", odivi, tbase, divi, rem);
    k++;
  }
  output[k] = '\0';

  printf("\nReminders in base%d: %s\n", tbase, output);

  k--;
  printf("Result: ");
  for(; k >= 0; k--) printf("%c", output[k]);
  printf("\nDONE!\n");

  return 0;
}

int convert_to_dec (int from, char* data, char* ref) {
  int decs[strlen(data)];
  int inplen = strlen(data) - 1;
  int decsum = 0;
  
  int i = inplen;
  for (; i >= 0; i--) {
    int r = inplen - i;
    int d = indexOf(ref, data[r]);
    int dec = d * pow(from, i);
    decs[r] = dec;
    decsum += dec;
    printf("%d x %d^%d = %d\n", d, from, i, dec);
  }

  printf("%d ", decs[0]);
  for (unsigned int j = 1; j < strlen(data); j++) printf("+ %d ", decs[j]);
  printf("= %d\n\n", decsum);

  return decsum;
}

int indexOf (char* string, char key) {
  char* x = strchr(string, key);
  if (x == NULL) {
    printf("INVALID CHARACTER %c\n", key);
    exit(EXIT_FAILURE);
  }
  return x - string;
}