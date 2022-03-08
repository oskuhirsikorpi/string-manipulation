#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STRING_MAX 300

void display_menu(void);
char ask_command(void);
void read_string(char s[]);
void print_string(char s[]);
int count_vowels(char s[]);
int count_consonants(char s[]);
void to_lower(char s[]);
void to_upper(char s[]);
void read_file(char s[]);
void write_file(char s[]);

int main(void)
{
  char string[STRING_MAX] = "Hello World!";

  display_menu();

  while (1)
  {
    char valinta = ask_command();

    switch (valinta)
    {
    case 'A':
      printf("String has %d vowels\n\n", count_vowels(string));
      break;

    case 'B':
      printf("String has %d consonants\n\n", count_consonants(string));
      break;

    case 'C':
      to_upper(string);
      printf("%s\n\n", string);
      break;

    case 'D':
      to_lower(string);
      printf("%s\n\n", string);
      break;

    case 'E':
      print_string(string);
      break;

    case 'F':
      read_string(string);
      break;

    case 'G':
      read_file(string);
      break;

    case 'H':
      write_file(string);
      break;

    case 'M':
      display_menu();
      break;

    case 'X':
      exit(0);
    }
  }
}

void display_menu(void)
{
  printf("\n\nA) Count the number of vowels in the string\n");
  printf("B) Count the number of consonants in the string\n");
  printf("C) Convert the string to uppercase\n");
  printf("D) Convert the string to lowercase\n");
  printf("E) Display the current string\n");
  printf("F) Enter another string\n");
  printf("G) Read string from file\n");
  printf("H) Write string to file\n");
  printf("\nM) Display this menu\n");
  printf("X) Exit the program\n");
}

char ask_command()
{

  char s[250];
  while (1)
  {
    printf("\nEnter command: ");
    fgets(s, 250, stdin);
    for (int i = 0; s[i] != '\0'; i++)
    {
      s[i] = toupper(s[i]);
    }
    if (s[0] == 'A' || s[0] == 'B' || s[0] == 'C' || s[0] == 'D' || s[0] == 'E' || s[0] == 'F' || s[0] == 'G' || s[0] == 'H' || s[0] == 'M' || s[0] == 'X')
    {
      break;
    }
    else
    {
      printf("Invalid input\n");
    }
  }
  return s[0];
}

int count_vowels(char s[])
{
  int pituus = strlen(s);
  int vokaalit = 0;
  for (int i = 0; i < pituus; i++)
  {
    s[i] = toupper(s[i]);
    if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y')
    {
      vokaalit++;
    }
  }
  return vokaalit;
}

int count_consonants(char s[])
{
  int pituus = strlen(s);
  int konsonantit = 0;
  for (int i = 0; i < pituus; i++)
  {
    s[i] = toupper(s[i]);
    if (s[i] >= 65 && s[i] <= 90)
    {
      if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y')
      {
      }
      else
      {
        konsonantit++;
      }
    }
  }
  return konsonantit;
}

void to_upper(char str[])
{
  int pituus = strlen(str);
  for (int i = 0; i < pituus; i++)
    if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
    {
      str[i] = toupper(str[i]);
    }
}

void to_lower(char str[])
{
  int pituus = strlen(str);
  for (int i = 0; i < pituus; i++)
  {
    str[i] = tolower(str[i]);
  }
}

void print_string(char str[])
{
  printf("%s\n\n", str);
}

void read_string(char str[])
{
  char s[STRING_MAX];
  printf("\n\nGive string: ");
  fgets(str, STRING_MAX, stdin);
  printf("%s\n", str);
}

void read_file(char s[])
{
  char line[255];

  FILE *fpointer = fopen("text.txt", "r");

  fgets(line, 255, fpointer);
  puts(line);

  fclose(fpointer);
}

void write_file(char s[])
{
  char line[255];

  FILE *fpointer = fopen("text.txt", "w");
  printf("\n\nWrite something: \n");
  fgets(line, 255, stdin);
  fprintf(fpointer, "%s\n", line);
  fclose(fpointer);
}