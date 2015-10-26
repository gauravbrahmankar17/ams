#include<stdio.h>
#include<stdlib.h>
/*switch (key) {
		case 'a' : keychar="a" ; break; case 'b' : keychar="b" ; break; case 'c' : keychar="c" ; break; case 'd' : keychar="d" ; break; case 'e' : keychar="e" ; break; case 'f' : keychar="f" ; 			break; case 'g' : keychar="g" ; break; case 'h' : keychar="h" ; break; case 'i' : keychar="i" ; break; case 'j' : keychar="j" ; break; case 'k' : keychar="k" ; break; case 'l' : 			keychar="l" ; break; case 'm' : keychar="m" ;case 'n' : keychar="n" ;case 'o' : keychar="o" ; break; case 'p' : keychar="p" ; break; case 'q' : keychar="q" ; break; case 'r' : 		keychar="r" ; break; case 's' : keychar="s" ; break; 			case 't' : keychar="t" ; break; case 'u' : keychar="u" ; break; case 'v' : keychar="v"; break; case 'w' : 			keychar="w" ; break; case 'x' : keychar="x" ; break;case 'y' : keychar="y" ; 			break;case 'z' : keychar="z" ; break;case '0' : keychar="0" ; break; case '1' : 		keychar="1" ; break; case '2' : keychar="2" ; break; case '3' : keychar="3" ; break; case '4' : 		keychar="4" ; break;case '5' : keychar="5" ; break;case '6' : 			keychar="6" ; break;case '7' : keychar="7" ; break;case '8' : keychar="8" ; break;case '9' : keychar="9" ; break;
 	}*/
typedef struct signup {
	char *firstname; char *surname;
	char *email; int password; int confirmpassword; 
} signup;
//------------------------------=
char* scan()
{
	char ch;
	int size =10;
    	int index=0;
    	char* buffer = NULL;
 	buffer = malloc(size);
    	while ((ch = getchar()) != '\n') {
        	buffer[index++] = ch;
        	if( index == size ) {
            		size += size;
            		buffer = realloc(buffer, size);
        	}
    	}
    	buffer[index++] = '\0';
    	if (index < size) 
        	buffer = realloc(buffer, index);

    	return buffer;
}
//------------------------------=
char* itoa(int num, char* str, int base)
{
    int i = 0;
    int isNegative =0;
 
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
 
    // In standard itoa(), negative numbers are handled only with 
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = 1;
        num = -num;
    }
 
    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }
 
    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';
 
    str[i] = '\0'; // Append string terminator
 
    // Reverse the string
    
 
    return str;
}
//------------------------------=
int main() {	
	char* str;int a=66;
	str=itoa(a,str, 10);
	printf("%s", str);
	return 0;
}
