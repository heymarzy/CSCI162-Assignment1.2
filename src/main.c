/*
NUMBER CONVERSION
Convert any radix input to unsigned integer or unsigned integer to
any other radix chosen by the user
Emphasis on binary decimal octal and hexadecimal
@ author Kawal Jeet
*/
// preprocessor directives here
// includes and defines
#include "../include/convert.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Driver program
int main()
{
  const int BUFFER_SIZE = 100;

  int userNumber, userRadix;
  int choice = 0;
  char otherNumber[BUFFER_SIZE];

  do
  {
    printf("1 :Convert unsigned integer to any Other Radix (binary 2, Octal 8, "
           "Hexadecimal 16).\n"
           "2 :Convert From any Radix (binary 2, Octal 8, Hexadecimal 16) to "
           "unsigned integer number.\n");

    scanf("%d", &choice);
  } while (choice < 1 || choice > 2);

  switch (choice)
  {

  case 1:
    // code to ask user to input unsigned decimal number and radix to which
    // it is to be converted.
    // Call decimalToOther(decimalNumber, radix) which returns
    // decimal number converted to that radix
    // display the result

    printf("Please input an unsigned decimal number: ");
    scanf("%d", &userNumber);

    printf("\nNow please enter the radix to which %d is to be converted to: ",
           userNumber);
    scanf("%d", &userRadix);

    char *convertedDecimal = decimalToOther(userNumber, userRadix);

    int length = strlen(convertedDecimal);

    printf("Your number converted to radix %d: ", userRadix);
    for (int i = 0; i < length; i++)
    {
      printf("%c", convertedDecimal[i]);
    }

    // No longer needed after printing
    free(convertedDecimal);

    break;

  case 2:
    // code to ask user to input what is to be converted to decimal
    // and radix of the input.
    // Check if the input is of radix user is asking for isRadix(inputString,
    // radix) Call otherToDecimal(radix, inputString) which returns unsigned
    // decimal number display the result
    printf("Please input a number (binary, octal, or hex): ");
    // Ensuring the input does not exceed the BUFFER_SIZE - 1 for null
    // terminator
    scanf("%99s", otherNumber);

    printf("\nNow please enter the radix of %s: ", otherNumber);
    scanf("%d", &userRadix);

    int convertedOther = otherToDecimal(userRadix, otherNumber);
    if (convertedOther)
    {
      printf("\nYour number converted to decimal is: %d", convertedOther);
    }
    else
    {
      printf("Sorry, there is no valid conversion with %s and %d.", otherNumber,
             userRadix);
    }

    break;
  }

  return 0;
}
