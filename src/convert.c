// preprocessor directives
#include "../include/convert.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

// definition of all the functions declared in convert.h and called in main.c
int otherToDecimal(int radix, char *other)
{
  if (isRadix(other, radix))
  {
    // Formula = sum of (other[i] * radix^n) [n=position from right starting at 0]
    int result = 0;
    // Ensure element 0 aligns with position from the right
    char *reversed = reverse(other);

    int length = strlen(other);

    for (int i = 0; i < length; i++)
    {
      if (reversed[i] >= 'A' && reversed[i] <= 'F')
      {
        result += (reversed[i] - 'A' + 10) * (int)pow(radix, i);
      }
      else if (reversed[i] >= '0' && reversed[i] <= '9')
      {
        result += (reversed[i] - '0') * (int)pow(radix, i);
      }
      else
      {
        // Returns 0 if the user inputs invalid chars for their number
        return 0;
      }
    }
    // Freeing reversed as it is no longer needed since our converted decimal is
    // stored in result
    free(reversed);

    return result;
  }
  else
  {
    // Returns 0 if other is not of base radix
    return 0;
  }
}

char *decimalToOther(int dnumber, int radix)
{
  int remainder;
  int numberOfDigits = 0;
  int buffer = dnumber;

  // Special case for 0
  if (dnumber == 0)
  {
    numberOfDigits = 1;
  }
  else
  {
    do
    {
      dnumber = dnumber / radix;
      numberOfDigits++;
    } while (dnumber > 0);
  }

  // Dynamically allocating memory, factoring in space for null
  // terminator
  char *converted = malloc((numberOfDigits + 1) * sizeof(char));

  if (converted == NULL)
  {
    printf("Memory allocation failed.");
  }
  else
  {
    // Special case for 0
    if (dnumber == 0)
    {
      converted[0] = '0';
    }
    else
    {
      for (int i = 0; buffer > 0; i++)
      {
        remainder = buffer % radix;
        buffer = buffer / radix;

        // Using the ASCII table to map digits to chars
        if (remainder < 10)
        {
          converted[i] = '0' + remainder;
        }
        else
        {
          converted[i] = 'A' + (remainder - 10);
        }
      }
    }
    converted[numberOfDigits] = '\0';

    char *result = reverse(converted);
    // no longer need memory for converted
    free(converted);

    return result;
  }
}

char *reverse(char *other)
{
  int length = strlen(other);
  char *reversed = malloc((length + 1) * sizeof(char));

  if (reversed == NULL)
  {
    printf("Memory allocation failed.");
  }

  else
  {
    for (int i = 0; i < length; i++)
    {
      reversed[i] = other[length - i - 1];
    }

    // null-terminating the c string
    reversed[length] = '\0';

    return reversed;
  }
}

int isRadix(char *other, int radix)
{
  const char *allDigits =
      "0123456789ABCDEF";         // All possible digits up to base 16
  char possibleDigits[radix + 1]; // Stores all possible digits for a given

  // Copying up to n = radix elements from allDigits
  strncpy(possibleDigits, allDigits, radix);
  possibleDigits[radix] = '\0';

  char *result; // Stores the result of strchr()

  int length = strlen(other);

  for (int i = 0; i < length; i++)
  {
    // Comparing the string against all possible digits for a given radix
    result = strchr(possibleDigits, other[i]);

    // If strchr is NULL at any point then return 0
    if (!result)
    {
      return 0;
    }
  }
  return 1;
}
