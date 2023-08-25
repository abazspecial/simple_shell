


#include "shell.h"


/**

 * checkMode - returns true if shell is interactive mode
 * @s: address of a structure
 * Return: 1 if interactive mode, 0 otherwise

 */

int checkMode(s_t *s)

{

        return (isatty(STDIN_FILENO) && s->readfd <= 2);

}


/**

 * isDelimeter - checks if character is a delimeter or not
 * @x: char to check
 * @d: is a delimeter string

 * Return: 1 if true, 0 if false

 */

int isDelimeter(char x, char *d)

{

        while (*d)

                if (*d++ == x)

                        return (1);

        return (0);

}


/**

 * is_Alpha - checks for an alphabetic character
 * @x: The character input
 * Return: 1 if x is alphabetic
 */


int is_Alpha(int x)

{

        if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))

                return (1);

        else

                return (0);

}


/**

 * string_int  - converts a string to an integer
 * @p: the string to be converted
 * Return: 0 if no numbers in string, convert
 */


int string_int (char *p)

{

        int k, s = 1, f = 0, output;

        unsigned int result = 0;


        for (k = 0; p[k] != '\0' && f != 2; k++)

        {

                if (p[k] == '-')

                        s *= -1;


                if (p[k] >= '0' && p[k] <= '9')

                {

                        f = 1;

                        result *= 10;

                        result += (p[k] - '0');

                }

                else if (f == 1)

                        f = 2;

        }


        if (s == -1)

                output = -result;

        else

                output = result;


        return (output);

}



