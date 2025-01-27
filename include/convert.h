#define SIZE 33 
//define SIZE of memeory allocated as 33, 32 for storing binary 1 or 0 and space for '\0'

/*
Parameters-
radix: radix of the number entered
other : number to be converetd to unsigned integer
Function takes the radix and the number to be converted to and converst to decimal
oToDecimal(2, "10001011") return 139
oToDecimal(16,"8B") return 139
oToDecimal(8, "213") return 139
*/
int otherToDecimal(int radix, char *other);

/*
Parameters-
radix: radix to which the number is to be converted
dnumber : unsigned integer number to be converetd to radix
Function takes a decimal number and the radix to which it is to be converted
decimalToO(139, 2) return 10001011
decimalToO(139, 16) return 8B
decimalToO(139, 8) return 213
*/
char* decimalToOther(int dnumber, int radix);

/*
Paramter:
other: string to be reveresed
Takes a string and reverses it
reverse("10001011") returns 11010001
reverse("112") returns 211
reverse("4321B") returns B1234
*/
char* reverse(char *other);

/*
Parameters-
radix: radix of the number
other : a number whose radix is to be checked 
Function checks if the string other is of the passed radix
Return 1 if the radix is correct and 0 otherwise
isRadix("1B11110", 2) return 0
isRadix("4571230", 8) returns 1
isRadix("6789334", 8) return 0
isRadix("567829", 10) returns 1
isRadix("678B334", 10) returns 0
isRadix("56H7829", 16) returns 0
isRadix("678B334", 16) returns 1
*/
int isRadix(char *other, int radix);


