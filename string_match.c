#include <stdio.h>

#define MAX 100

// Prototype
int StringMatch(char[], char[], char[], char[]);

// Main function
int main()
{
    char source[MAX] = {0}, pattern[MAX] = {0}, replace[MAX] = {0}, final[MAX] = {0};
    int found;

    printf("Enter Source String : \n");
    gets(source);
    printf("Enter Pattern String : \n");
    gets(pattern);
    printf("Enter Replace String : \n");
    gets(replace);
    found = StringMatch(source, pattern, replace, final);
    if (found == 1)
    {
        printf("The Final String is : \n");
        puts(final);
    }
    else
        printf("Search string Not Found\n");
    return 0;
}

// StringMatch function definition
int StringMatch(char source[], char pattern[], char replace[], char f[])
{
    int i, j, k, m, t; // i-index src, j-index pattern, k-index   replace, t-index final
    int found = 0;
    j = m = i = t = 0;
    while (source[i] != '\0')
    {
        if (source[m++] == pattern[j++]) // check for matching
        {
            if (pattern[j] == '\0') // pattern found
            {
                // copy replace string in final string
                for (k = 0; replace[k] != '\0'; k++, t++)
                    f[t] = replace[k];
                j = 0;
                i = m;
                found = 1;
            }
        }
        else // mismatch
        {
            f[t++] = source[i++];
            m = i;
            j = 0;
        }
    }
    return found;
}
