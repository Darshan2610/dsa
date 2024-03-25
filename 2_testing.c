#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 20

int stringmatch(char[], char[], char[], char[]);

int main (){
    char s[max]={0}, p[max]={0}, r[max]={0}, f[max]={0};
    printf("enter source:\n");
    gets(s);
    printf("enter pattern:\n");
    gets(p);
    printf("enter replacing:\n");
    gets(r);
    int flag = stringmatch(s, p ,r,f);
    if(flag == -1){
        printf("no match found\n");
    }else{
        printf("final string: \n");
        puts(f);
    }
    
    return 0;
}

int stringmatch(char s[], char p[], char r[], char f[])
{
    int sindex, pindex, rindex, findex, m;
    sindex = m = pindex = findex = 0;
    int found = 0;
    while (s[sindex] != '\0'){
        if (s[m++] == p[pindex++])
        {
            if (p[pindex] == '\0')
            {
                    for (rindex = 0;r[rindex]!= '\0';rindex++,findex++)
                        f[findex] = r[rindex];
                pindex = 0;
                sindex = m;
                found = 1;
            }
        }
        else{
            f[findex++] = s[sindex++];
            m = sindex;
            pindex = 0;
        }
    }
    return found;
}

// int stringMatch(char source[], char pattern[], char replace[], char final[])
// {
//     int sourceIndex = 0, patternIndex = 0, replaceIndex = 0, finalIndex = 0; // Indices for source, pattern, replace, final
//     int found = 0;

//     while (source[sourceIndex] != '\0'){
//         if (source[sourceIndex++] == pattern[patternIndex++]) {
//             if (pattern[patternIndex] == '\0') // Pattern found
//             {
//                 // Copy replace string into final string
//                 while (replace[replaceIndex] != '\0')
//                 {
//                     final[finalIndex++] = replace[replaceIndex++];
//                 }
//                 patternIndex = 0;
//                 sourceIndex = replaceIndex;
//                 found = 1;
//             }
//         }
//         else // Mismatch
//         {
//             final[finalIndex++] = source[sourceIndex++];
//             patternIndex = 0;
//             replaceIndex = sourceIndex;
//         }
//     }
//     return found;
// }