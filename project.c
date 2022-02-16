#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STRING_MAX 500

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

int main()
{
  char string[STRING_MAX] = "Hello World!";
  display_menu();

  char valinta = ask_command();

  switch (valinta)
  {
  case 'A':
    // count_vowels(string);
    printf("\n\nString has %d vowels\n\n", count_vowels(string));
    main();
    break;
  case 'B':
    // count_consonants(string);
    printf("\n\nString has %d consonants\n\n", count_consonants(string));
    break;
  /*case 'C':
    printf("%s", to_upper(string));
    break;
     case 'D':
       to_lower();
       break;
     case 'E':
       print_string(string);
       break;
     case 'F':
       read_string(string[STR_MAX]);
       break;
     case 'G':
       read_file();
       break;
     case 'H':
       write_file();
       break;
     case 'M':
       display_menu();
       break;
     case 'X':
       exit(0);
     default:
       printf("\n INCORRECT CHARACTER \n");
       break;*/
  }
}

char ask_command(void)
{
  char s[2];
  printf("Enter command: ");
  fgets(s, 2, stdin);
  for (int i = 0; s[i]; i++)
  {
    s[i] = toupper(s[i]);
  }
  // printf("%s", s);
  return s[0];
}

void display_menu(void)
{
  printf("A) Count the number of vowels in the string\n");
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

void print_string(char s[])
{
  printf("\nassdddd");
}

int count_vowels(char s[])
{
  int pituus = strlen(s);
  int x = 0;
  for (int i = 0; i < pituus; i++)
  {
    s[i] = toupper(s[i]);
    if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y')
    {
      x++;
    }
  }
  return x;
}

int count_consonants(char s[])
{
  int pituus = strlen(s);
  int x = 0;
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
        x++;
      }
    }
  }
  return x;
}

/* void to_upper(char s[])
{
  char neg = strupr(s);
  return neg;
}*/
