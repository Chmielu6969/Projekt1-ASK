# Reprezentacja danych w pamięci – INT, FLOAT, DOUBLE

## Opis projektu
Projekt przedstawia sposób przechowywania danych w pamięci komputera oraz operacje wykonywane na liczbach na poziomie binarnym. Program został napisany w języku C i pokazuje rzeczywistą reprezentację liczb całkowitych oraz zmiennoprzecinkowych w pamięci RAM.

## Zakres funkcjonalny programu
Program realizuje następujące zadania:

1. Drukowanie postaci bajtowej danych typu:
   - `int`
   - `float`
   - `double`

2. Drukowanie postaci binarnej powyższych typów danych (bit po bicie)

3. Prezentacja zasady wykonywania odejmowania w kodzie U2 (two’s complement)

4. Prezentacja konwersji:
   - FLOAT → DEC (odczyt wartości dziesiętnej z reprezentacji binarnej)
   - DEC → FLOAT (interpretacja surowych bitów jako liczby typu `float`)

## Zastosowane techniki
- dostęp do pamięci za pomocą wskaźników
- rzutowanie wskaźników (`type punning`)
- operacje bitowe (`~`, `+`, `>>`, `&`)
- reprezentacja liczb w kodzie uzupełnień do dwóch (U2)
- standard IEEE-754 dla liczb zmiennoprzecinkowych

## Struktura programu
Program składa się z następujących funkcji:

- `print_bytes()` – drukuje bajtową reprezentację zmiennej
- `print_bits()` – drukuje binarną reprezentację zmiennej
- `subtraction_U2()` – prezentuje odejmowanie w kodzie U2
- `float_conversion()` – pokazuje konwersję FLOAT ↔ DEC
- `main()` – funkcja główna programu

## Sposób kompilacji i uruchomienia

Kompilacja (GCC):
```bash
gcc main.c -o reprezentacja
```
