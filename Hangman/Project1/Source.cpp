#include <stdio.h>
#include <string.h>

#include <stdlib.h>
#include <ctype.h> 

#include <ctime>
#pragma warning(disable:4996) 





int main()
{

	FILE *fp;
	fp = fopen("words.txt", "r"); //loading file
	int store[27]; //used for showing used letters


	if (fp == NULL)
	{
		printf("Something is wrong with file. Please correct data.");
		return -1;
	}
	else
	{	
		int playernumb = 0;   //number of players
		printf("Welcome in Hangman game. Please tell, how many players?\n\t\t 1 - Single player (word from dictionary)\n\t\t 2 - Two players (word made up by opponent)\n\t\t");
		scanf("%d", &playernumb);
		if (playernumb==1)
		{srand(time(NULL));
			int Lnumber = 1;
			int check;
			while ((check = fgetc(fp)) != EOF)
			{
				if (check == '\n')
				{
					Lnumber = Lnumber + 1;   //getting number of lines
				}
			}
			int randnumber; //pseudo random number
			for (int p = 0; p < 15; p++)
			{
				randnumber = (rand() % Lnumber) + 1; //it is in loop to generate number correctly (every new use of programm was changing number for about 50 ~~)
			}
			rewind(fp);
			Lnumber = 1;
			int word_max_lenght = 50;
			char *wordlist = (char *)malloc(word_max_lenght*sizeof(char)); //alocating memory for word
			while ((check = fgetc(fp)) != EOF)
			{
				if (check == '\n')
				{
					Lnumber = Lnumber + 1;
					if (Lnumber == randnumber)
					{
						fgets(wordlist, word_max_lenght, fp); //getting line with number(randnumber) and putting it into wordlist array)
					}
				}
			}
			int k = 0; //variable used in while loop
			int letternumb = 0;
			int *asciitable = (int *)malloc(word_max_lenght*sizeof(int)); //allocating memory for ascii table from wordlist
			int mode = 0;
			while (wordlist[k] != '\0') //till wordlist[k] is not equal end
			{
				//use printf to show word from list
				//printf("%c", wordlist[k]);
				letternumb++; //increasing number of letters
				asciitable[k] = wordlist[k];// filling asciitable with data from wordlist
				k++;
			}


			int *outputascii = (int *)malloc(letternumb); //allocating memory for array with user answers
			for (int i = 0; i < letternumb; i++)
			{
				outputascii[i] = 95; // filling user answers with '_' 
				//printf("%d ", outputascii[i]);
				//printf("%d ", asciitable[i]); //if you want to check 
			}
			printf("\n");
			char *user_input = (char *)malloc(letternumb + 9); //alocating memory for user input
			int *user_ascii_input = (int *)malloc(letternumb + 9); //memory for user input in ascii. 
			//TO be honest I've been trying with getchar but it was giving me doubled input, I don't know why, therefore I chose this method because it works

			int chancechecker1 = 0; //variable checking chances
			int prevcheck = 0; //previous check
			int empcheck = letternumb; //checker '_'
			int chance = 6; //chance (tries)
			char *answer = (char *)malloc(sizeof(char));//alocating memory for user answer Hard/Easy

			printf("Choose difficulty of game: Hard/Easy\n");
			scanf("%s", answer);
			if (strncmp(answer, "Hard", 3) == 0) //if he wrote Hard
			{
				mode = 1;
				chance = 6;
				printf("You chose hard game mode. Only 6 chances. Give first letter: \n");
			}
			if (strncmp(answer, "Easy", 3) == 0) //if he wrote Easy
			{
				mode = 2;
				chance = 10;
				printf("You chose easy game mode. Till 10 chances. Give first letter: \n");
			}

			int z = 0;


			//Main game
			for (int i = 0; i < 27; i++)
				store[i] = 0; //filling table of used letters with 0 (no letter was used for now)


			for (int x = 0; x < (letternumb + 11)*letternumb; x++) //loop which creates game
			{
				if (mode == 1) //if it is hard game
				{
					switch (chance) //for every chance it "draws" hangman in different states
					{
					case 6:
						printf("\n      \n        \n        \n\n________\n");
						break;
					case 5:
						printf("\n      \n        \n|        \n|\n________\n");
						break;
					case 4:
						printf("\n|      \n|        \n|        \n|\n________\n");
						break;
					case 3:
						printf("________\n|      \n|        \n|        \n|\n________\n");
						break;
					case 2:
						printf("________\n|     o\n|        \n|        \n|\n________\n");
						break;
					case 1:
						printf("________\n|     o\n|    /|\\ \n|        \n|\n________\n");
						break;


					}
				}

				if (mode == 2) //same goes for easy mode
				{
					switch (chance)
					{
					case 10:
						printf("\n     \n    \n    \n\n________\n");
						break;
					case 9:
						printf("\n     \n     \n|     \n|\n________\n");
						break;
					case 8:
						printf("\n|     \n|     \n|     \n|\n________\n");
						break;
					case 7:
						printf("____    \n|     \n|     \n|     \n|\n________\n");
						break;
					case 6:
						printf("________\n|     \n|     \n|     \n|\n________\n");
						break;
					case 5:
						printf("________\n|     o\n|     \n|     \n|\n________\n");
						break;
					case 4:
						printf("________\n|     o\n|     | \n|     \n|\n________\n");
						break;
					case 3:
						printf("________\n|     o\n|     |\\  \n|     \n|\n________\n");
						break;
					case 2:
						printf("________\n|     o\n|    /|\\ \n|     \n|\n________\n");
						break;
					case 1:
						printf("________\n|     o\n|    /|\\ \n|      \\ \n|\n________\n");
						break;

					}
				}




				for (int i = 0; i < letternumb - 1; i++)
				{
					if (outputascii[i] == 95)
						prevcheck++; //checking how many _ are in table before putting letter from scanf
				}


			{
				scanf("%s", user_input);
				user_ascii_input[0] = user_input[0]; //getting letter from user and putting it into "convertible" 
				printf("\n");
				for (int i = 0; i < 27; i++)
				{
					if (store[i] == 1) //used letter
						if (user_ascii_input[0] == i + 97)
						{
						memset(user_input, 0, strlen(user_input));
						printf("Already used letter. Give another one: \n"); //case when u write same letter as it was used
						scanf("%s", user_input);
						user_ascii_input[0] = user_input[0];
						printf("\n");
						}
				}
				store[user_ascii_input[0] - 97] = 1;
			}

				for (int i = 0; i < letternumb - 1; i++)
				{

					if ((asciitable[i] == user_input[0]) || ((asciitable[i] + 32) == user_input[0])) //checking if it is great letter or normal
					{
						outputascii[i] = user_ascii_input[0]; //filling answer array
					}
					printf("%c ", outputascii[i]); //printing answer array
				}


				for (int i = 0; i < letternumb - 1; i++)
				{
					if (outputascii[i] != 95)
					{
						empcheck--; //if place in array is not _ then empcheck decreases
					}
					else
					{
						chancechecker1++; //else variable chancechecker (used to create chances)
						if (prevcheck == chancechecker1) //if previous state in answer array is same as before, then answer was wrong -> chance decreases
						{
							chance--;
						}

					}

				}


				printf("\tThere are (%d) chances left. Choose letter wisely.\n", chance);
				if (chance == 0)
				{

					system("cls");
					printf("You lost after %d tries\n", x + 1);
					printf("________\n|     o\n|    /|\\ \n|    / \\ \n|\n________\n");
					printf("Word: ");
					while (wordlist[z] != '\0')
					{
						printf("%c", wordlist[z]);
						z++;
					}
					printf("\n");
					break;//screen when game is lost
				}
				if (empcheck == 0)
				{
					system("cls");
					printf("You won in %d tries\n", x + 1); //screen when you win
					break;
				}
				prevcheck = 0;
				chancechecker1 = 0;

				empcheck = letternumb - 1;
				printf("Already used letters :");
				for (int i = 0; i < 27; i++)
				{
					if (store[i] != 0)
						printf(" %c ", i + 97);
				}//printing already used letters
				printf("\n Enter letter:\n");

				memset(user_input, 0, strlen(user_input));
			}


			system("pause");
			
		} //second mode - similar but instead of looking for in dictionary, opponent inputs word
		if (playernumb == 2)
		{
			srand(time(NULL));
			int Lnumber = 1;

			
			
			int word_max_lenght = 50;
			char *wordlist = (char *)malloc(word_max_lenght*sizeof(char));
			printf("Enter a word for opponent:\n\t");
			scanf("%s", wordlist);
			system("cls");
			int k = 0;
			int letternumb = 0;
			int *asciitable = (int *)malloc(word_max_lenght*sizeof(int));
			int mode = 0;
			int z = 0;
			while (wordlist[k] != '\0')
			{
				//use printf to show word from list
				//printf("%c", wordlist[k]);
				letternumb++;
				asciitable[k] = wordlist[k];
				k++;
			}
			//printf("%d", letternumb);

			int *outputascii = (int *)malloc(letternumb);
			for (int i = 0; i < letternumb; i++)
			{
				outputascii[i] = 95;
				//printf("%d ", outputascii[i]);
				//printf("%d ", asciitable[i]);
			}
			printf("\n");
			char *user_input = (char *)malloc(letternumb + 9);
			int *user_ascii_input = (int *)malloc(letternumb + 9);

			int chancechecker1 = 0;
			int prevcheck = 0;
			int empcheck = letternumb;
			int chance = 6;
			char *answer = (char *)malloc(sizeof(char));

			printf("Choose difficulty of game: Hard/Easy\n");
			scanf("%s", answer);
			if (strncmp(answer, "Hard", 3) == 0)
			{
				mode = 1;
				chance = 6;
				printf("You chose hard game mode. Only 6 chances. Give first letter: \n");
			}
			if (strncmp(answer, "Easy", 3) == 0)
			{
				mode = 2;
				chance = 10;
				printf("You chose easy game mode. Till 10 chances. Give first letter: \n");
			}




			//Main game
			for (int i = 0; i < 27; i++)
				store[i] = 0;


			for (int x = 0; x < (letternumb + 11)*letternumb; x++)
			{
				if (mode == 1)
				{
					switch (chance)
					{
					case 6:
						printf("\n      \n        \n        \n\n________\n");
						break;
					case 5:
						printf("\n      \n        \n|        \n|\n________\n");
						break;
					case 4:
						printf("\n|      \n|        \n|        \n|\n________\n");
						break;
					case 3:
						printf("________\n|      \n|        \n|        \n|\n________\n");
						break;
					case 2:
						printf("________\n|     o\n|        \n|        \n|\n________\n");
						break;
					case 1:
						printf("________\n|     o\n|    /|\\ \n|        \n|\n________\n");
						break;


					}
				}

				if (mode == 2)
				{
					switch (chance)
					{
					case 10:
						printf("\n     \n    \n    \n\n________\n");
						break;
					case 9:
						printf("\n     \n     \n|     \n|\n________\n");
						break;
					case 8:
						printf("\n|     \n|     \n|     \n|\n________\n");
						break;
					case 7:
						printf("____    \n|     \n|     \n|     \n|\n________\n");
						break;
					case 6:
						printf("________\n|     \n|     \n|     \n|\n________\n");
						break;
					case 5:
						printf("________\n|     o\n|     \n|     \n|\n________\n");
						break;
					case 4:
						printf("________\n|     o\n|     | \n|     \n|\n________\n");
						break;
					case 3:
						printf("________\n|     o\n|     |\\  \n|     \n|\n________\n");
						break;
					case 2:
						printf("________\n|     o\n|    /|\\ \n|     \n|\n________\n");
						break;
					case 1:
						printf("________\n|     o\n|    /|\\ \n|      \\ \n|\n________\n");
						break;

					}
				}




				for (int i = 0; i < letternumb; i++)
				{
					if (outputascii[i] == 95)
						prevcheck++; //checking how many _ are in table before putting letter from scanf
				}


			{
				scanf("%s", user_input);
				user_ascii_input[0] = user_input[0];
				printf("\n");
				for (int i = 0; i < 27; i++)
				{
					if (store[i] == 1)
						if (user_ascii_input[0] == i + 97)
						{
						memset(user_input, 0, strlen(user_input));
						printf("Already used letter. Give another one: \n");
						scanf("%s", user_input);
						user_ascii_input[0] = user_input[0];
						printf("\n");
						}
				}
				store[user_ascii_input[0] - 97] = 1;
			}

				for (int i = 0; i < letternumb; i++)
				{

					if ((asciitable[i] == user_input[0]) || ((asciitable[i] + 32) == user_input[0]))
					{
						outputascii[i] = user_ascii_input[0];
					}
					printf("%c ", outputascii[i]);
				}


				for (int i = 0; i < letternumb; i++)
				{
					if (outputascii[i] != 95)
					{
						empcheck--;
					}
					else
					{
						chancechecker1++;
						if (prevcheck == chancechecker1)
						{
							chance--;
						}

					}

				}


				printf("\tThere are (%d) chances left. Choose letter wisely.\n", chance);
				if (chance == 0)
				{

					system("cls");
					printf("You lost after %d tries\n", x + 1);
					printf("________\n|     o\n|    /|\\ \n|    / \\ \n|\n________\n");
					printf("Word: ");
					while (wordlist[z] != '\0')
					{
						printf("%c", wordlist[z]);
						z++;
					}

					printf("\n");
							break;
				}
				if (empcheck == 0)
				{
					system("cls");
					printf("You won in %d tries\n", x + 1);
					break;
				}
				prevcheck = 0;
				chancechecker1 = 0;

				empcheck = letternumb;
				printf("Already used letters :");
				for (int i = 0; i < 27; i++)
				{
					if (store[i] != 0)
						printf(" %c ", i + 97);
				}
				printf("\n Enter letter:\n");

				memset(user_input, 0, strlen(user_input));
			}


			system("pause");
		}




	}
	fclose(fp);

	getchar();
	return 0;
}
