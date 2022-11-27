#include <stdio.h>
#include <ctype.h>

int main()
{
    // decrypts with all possible keys (25)
    for (int key = 1; key < 26; key++)
    {
        // open the file
        FILE *fp = fopen("encryptedText.txt", "r");

        // Return if could not open file
        if (fp == NULL)
            return 0;
            
        do
        {
            // Taking input single character at a time
            char c = fgetc(fp);
            // lowers the char, ex "C" to "c"
            c = tolower(c);
            // Checking for end of file
            if (feof(fp))
                break;

            // checking if its a char between 'a' and 'z'
            if (c >= 'a' && c <= 'z')
            {
                c = (c - 'a' + key) % 26 + 'a';
            }
            // else if it's a symbol or anything that is not between a and z, it keeps it the same
            else
                c = c;

            printf("%c", c);
        } while (1);
        printf("\n------------------------\n");
        fclose(fp);
    }
    getch();
    return (0);
}