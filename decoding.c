#include <stdio.h> // for FILE handling

/*  Example:

    Download the file haystack.bin and find out the secret buried
    inside the file.

    Fibonacci: 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181...
*/

int main( )
{
    FILE *encoded;  // for handling the encoded .bin file
    int character;  // for character to be printed
    int first = 1;  // first Fibonacci number
    int second = 2; // second Fibonacci number
    int next_fibo;  // next Fibonacci number
    int size;       // for FILE size in bytes
    int i = 0;

    /* Open the encoded file for reading */
    encoded = fopen( "haystack.bin", "r" );

    /* Check if open fails */
    if ( NULL == encoded )
        {
        printf( " FILE open error!\n" );
        return 0;
        }
    else /* Get the file size for printing as an info */
        {
        printf( " FILE open ok.\n" );
        fseek( encoded, 0L, SEEK_END );
        size = ftell( encoded );
        rewind( encoded );
        printf( " FILE size: %d bytes.\n", size );
        }

    /* Get the first character */
    character = getc( encoded );

    /* Decode the Fibonecci secret from the FILE */
    while ( character != EOF )
        {
        /* Fibonecci = 0 when i = 0 */
        /* Fibonecci = 1 when i = 1 */
        if ( i <= 1 )
            {
            next_fibo = i;

            /* Print the character to the screen */
            putchar( character );

            if ( 1 == i ) 
                {
                /* Fibonacci == 1 must be printed twice */
                putchar( character );
                next_fibo = 2;
                }
            }
        else if ( i == next_fibo ) /* Fibonacci = (i-1) + (i-2) when i > 0 */
            {
            /* Calculate the next Fibonacci to be printed */
            next_fibo = first + second;
            /* Update the value of the second number */
            second = first + second;
            /* Update the value of the first number */
            first = second - first;
            /* Print the character to the screen */
            putchar( character );
            }

        /* Get the next character to be handled */
        character = getc( encoded );
        i++;
        }

    /* Check if EOF or Error */
    if ( feof( encoded ) )
        {
        printf( "\n End of FILE.\n" );
        }
    else
        {
        printf( "\n Error occured!\n" );
        }

    /* Close the encoded file */
    fclose( encoded );
    printf( " FILE closed.\n" );

    /* Secret solved: http://bit.ly/1x7owh1 */
    return 0; 
}
