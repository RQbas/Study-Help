
/* 
Anagrams. The user enters a string. Write a program that checks a (given) dictionary for occurrences of anagrams of this string. For example, ANGLE and GALEN are anagrams.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string>
#pragma warning(disable:4996)

int check_anagram(char a[], char b[])
{
   int first[26] = {0}, second[26] = {0}, c = 0;

   while (a[c] != '\0')
   {
      first[a[c]-'a']++;
      c++;
   }

   c = 0;

   while (b[c] != '\0')
   {
      second[b[c]-'a']++;
      c++;
   }

   for (c = 0; c < 26; c++)
   {
      if (first[c] != second[c])
         return 0;
   }

   return 1;
}


int main()
{

        int word_max_lenght =30;
        int conv;
			char *a1 = (char *)malloc(word_max_lenght*sizeof(char));
			char *a2 = (char *)malloc(word_max_lenght*sizeof(char));
			int *asciitable_dc = (int *)malloc(word_max_lenght*sizeof(int));
    printf("Enter string\n");
        scanf("%s", a1);
int k=0;





    printf("These are anagrams:\n");

	FILE * fp = fopen("dictionary.txt", "r");
        if (fp == NULL)
	{
		printf("Something is wrong with file. Please correct data.");
		return -1;
	}
else
    {
    int check;
    while ((check = fgetc(fp)) != EOF)
			{
				if (check == '\n')
				{
					 fgets(a2, word_max_lenght, fp);
                            while (a2[k] != '\0') //till wordlist[k] is not equal end
                                {
                                asciitable_dc[k] = a2[k];// filling asciitable with data from wordlist
                                k++;
                                }
                                k=0;
                    if(asciitable_dc[0]>64&&asciitable_dc[0]<91)
                        asciitable_dc[0]=asciitable_dc[0]+32;
                        a2[0]=asciitable_dc[0];
					 if ( check_anagram(a1, a2))
                     {
                         printf("%s\n", a2);
                     }



				}
			}

   system ("pause");
   return 0;


}
}


