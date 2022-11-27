#include <stdio.h>
#include <ctype.h>

int main()
{
    // open the file
    FILE *fp = fopen("sampleText.txt", "r");

    int key=25;
    //input
    /*printf("Enter the key: ");
    scanf("%d", & key);
    //if key isn't between 1 and 25 then sets key to 25
    if(key<1 || key>25)
        key=25;*/

    // Return if could not open file
    if (fp == NULL)
        return 0;
    printf("Encrypted Message: ");
    do
    {
        // Taking input single character at a time
        char c = fgetc(fp);
        //lowers the char, ex "C" to "c"
        c = tolower(c);
        // Checking for end of file
        if (feof(fp))
            break;
        
        //checking if its a char between 'a' and 'z'
        if (c >= 'a' && c <= 'z'){
            c = (c - 'a' + key) % 26 + 'a';
        }
        //else if it's a symbol or anything that is not between a and z, it keeps it the same
        else
            c=c;
            
        printf("%c", c);
    } while (1);

    fclose(fp);
    getch();
    return (0);
}