#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Funkcja wypisuje bajtową reprezentację zmiennej

void print_bytes(void *ptr, size_t size)
{
  unsigned char *b = (unsigned char *)ptr;
  for (size_t i = 0; i < size; i++)
  {
    printf("%02X ", b[i]);
  }
  printf("\n");
}

// Funkcja wypisuje 32-bitową postać binarną liczby

void print_binary32(uint32_t v)
{
  for (int i = 31; i >= 0; i--)
  {
    printf("%d", (v >> i) & 1);
    if (i % 8 == 0)
      printf(" ");
  }
  printf("\n");
}

// Funkcja wypisuje 64-bitową postać binarną liczby

void print_binary64(uint64_t v)
{
  for (int i = 63; i >= 0; i--)
  {
    printf("%d", (v >> i) & 1);
    if (i % 8 == 0)
      printf(" ");
  }
  printf("\n");
}

// Prezentacja liczby typu int

void show_int(int x)
{
  printf("Podano liczbe typu int: %d\n", x);
  printf("Postac bajtowa:\n");
  print_bytes(&x, sizeof(int));
  printf("Postac binarna:\n");
  print_binary32((uint32_t)x);
}

// Prezentacja liczby typu float

void show_float(float x)
{
  uint32_t bits;
  memcpy(&bits, &x, sizeof(float));

  printf("Podano liczbe typu float: %f\n", x);
  printf("Postac bajtowa:\n");
  print_bytes(&x, sizeof(float));
  printf("Postac binarna:\n");
  print_binary32(bits);
}

// Prezentacja liczby typu double

void show_double(double x)
{
  uint64_t bits;
  memcpy(&bits, &x, sizeof(double));

  printf("Podano liczbe typu double: %lf\n", x);
  printf("Postac bajtowa:\n");
  print_bytes(&x, sizeof(double));
  printf("Postac binarna:\n");
  print_binary64(bits);
}

// Prezentacja odejmowania w kodzie U2

void show_u2(int a, int b)
{
  int neg_b = ~b + 1;
  int result = a + neg_b;

  printf("Odejmowanie w kodzie U2: %d - %d\n", a, b);

  printf("Liczba a:\n");
  print_binary32((uint32_t)a);

  printf("Liczba b:\n");
  print_binary32((uint32_t)b);

  printf("Liczba -b (U2):\n");
  print_binary32((uint32_t)neg_b);

  printf("Wynik a + (-b):\n");
  print_binary32((uint32_t)result);

  printf("Wynik dziesietny: %d\n", result);
}

// Konwersja float -> decimal

void float_to_decimal(float x)
{
  printf("Konwersja float -> decimal\n");
  printf("Wartosc: %f\n", x);
}

// Konwersja decimal -> float

void decimal_to_float(double x)
{
  float f = (float)x;
  uint32_t bits;
  memcpy(&bits, &f, sizeof(float));

  printf("Konwersja decimal -> float\n");
  printf("double: %lf\n", x);
  printf("float: %f\n", f);
  printf("Postac binarna float:\n");
  print_binary32(bits);
}

// Menu

void show_menu(void)
{
  printf("\n");
  printf("Wybierz opcje:\n");
  printf("1 - reprezentacja liczby typu int\n");
  printf("2 - reprezentacja liczby typu float\n");
  printf("3 - reprezentacja liczby typu double\n");
  printf("4 - odejmowanie w kodzie U2\n");
  printf("5 - konwersje float / decimal\n");
  printf("6 - wykonaj wszystkie operacje\n");
  printf("0 - zakoncz program\n");
}

// Main

int main()
{
  int choice;

  do
  {
    show_menu();
    printf("Twoj wybor: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
      int x;
      printf("Podaj liczbe typu int: ");
      scanf("%d", &x);
      printf("\n");
      show_int(x);
    }
    else if (choice == 2)
    {
      float x;
      printf("Podaj liczbe typu float: ");
      scanf("%f", &x);
      printf("\n");
      show_float(x);
    }
    else if (choice == 3)
    {
      double x;
      printf("Podaj liczbe typu double: ");
      scanf("%lf", &x);
      printf("\n");
      show_double(x);
    }
    else if (choice == 4)
    {
      int a, b;
      printf("Podaj dwie liczby typu int (a b): ");
      scanf("%d %d", &a, &b);
      printf("\n");
      show_u2(a, b);
    }
    else if (choice == 5)
    {
      float f;
      double d;
      printf("Podaj liczbe typu float: ");
      scanf("%f", &f);
      printf("\n");
      float_to_decimal(f);
      printf("\n");
      printf("Podaj liczbe typu decimal (double): ");
      scanf("%lf", &d);
      printf("\n");
      decimal_to_float(d);
    }
    else if (choice == 6)
    {
      double x;
      printf("Podaj jedna liczbe (zostanie uzyta we wszystkich operacjach): ");
      scanf("%lf", &x);

      printf("\n");
      show_int((int)x);

      printf("\n");
      show_float((float)x);

      printf("\n");
      show_double(x);

      printf("\n");
      show_u2((int)x, 1);

      printf("\n");
      float_to_decimal((float)x);

      printf("\n");
      decimal_to_float(x);
    }

  } while (choice != 0);

  return 0;
}