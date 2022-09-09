/*
	author: M Saifur Rahman
	last modified: December 12, 2020
    
    Solution to the sessional problem titled "Word Frequency"
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct keyword
{
    char word[20 + 1];
    int freq;
} words[100];

int main()
{
    FILE *fpPara = NULL;
    FILE *fpKeyword = NULL;
    FILE *fpFreq = NULL;

    int nKeywords = 0, i;

    fpPara = fopen("paragraph.txt", "r");
    fpKeyword = fopen("keywords.txt", "r");
    fpFreq = fopen("freq.txt", "w");

    while (1)
    {
        fscanf(fpKeyword, "%s", words[nKeywords].word);
        if (feof(fpKeyword))
            break;

        words[nKeywords++].freq = 0;
    }
    fclose(fpKeyword);

    while (1)
    {
        char str[256];
        int len;
        fscanf(fpPara, "%s", str);
        if (feof(fpPara))
            break;

        str[0] = tolower(str[0]);
        len = strlen(str);
        if (ispunct(str[len - 1]))
            str[len - 1] = '\0';

        for (i = 0; i < nKeywords; i++)
        {
            if (0 == strcmp(str, words[i].word))
                words[i].freq++;
        }
    }
    fclose(fpPara);

    for (i = 0; i < nKeywords; i++)
        fprintf(fpFreq, "%s %d\n", words[i].word, words[i].freq);
    fclose(fpKeyword);

    return 0;
}
