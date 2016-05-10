#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#pragma warning(disable:4996)  //to avoid visual studio problems about unsafe functions

int **PathTable; //Global declared because is needed in FWPath procedure

int LineCounter(FILE *Filename, int NLines) //As name says, this is function for counting lines in file
{
	int Checker1;   //Needed variable which could  compare signs in ASCII
	while ((Checker1 = fgetc(Filename)) != EOF) //Checking Till End
	{
		if (Checker1 == '\n') // New line found
		{
			NLines = NLines + 1; //increasing variable everytime it finds new line
		}
	}
	
	return NLines; //function returns number of lines
}

void FWPath(int i, int j) //It should have found order of path (using recurection) but it has memory crash but i wont hide it as a comment
{
	if (i == j) printf("%d  ", i);
	else if (PathTable[i][j] == 0) printf("No Path");	//No path while there is 0 in PathTable
	else
	{
		FWPath(i, PathTable[i][j]);
		printf("%d  ", j);
	}
}
	
int main()
{

	FILE *fp;
	fp = fopen("city.txt", "r");  //creating pointer and assigning it to file city in reading mode
	if (fp == NULL)		//condition checking if stream isn't empty
	{ 
		printf("Something is wrong with file. Please correct data."); //if stream is empty program won't start compiling code
		return -1;			
	}
	else
	{

		// GETTING NUMBER OF LINES (LINE COUNTER)
		int NumberOfLines = 1;
		NumberOfLines = LineCounter(fp, NumberOfLines);//Using created function to count number of lines
		printf("Number Of Lines in file :%d\n", NumberOfLines);
		//Refreshing fp after last initation
		rewind(fp);
		//Another part of variables
		int infinity = INT_MAX; //Will be used in filling matrices
		int MAX_NAME_LEN = 30; //Used to limit memory needed in allocation
		//Taking one line (First Line)
		int NumbCities;
		fscanf(fp, "%d", &NumbCities);
		printf("Number of city declared :%d\n\n", NumbCities); //showing if number of city is correct by printing it

		int **FloydTable;	//Creating dynamic two dimensial array used to make floyd warshall algorithm on it
		FloydTable = (int **)malloc(NumbCities * sizeof(int*));
		for (int i = 0; i < NumbCities; i++)	//allocating memory for every array
		{
			FloydTable[i] = (int *)malloc(NumbCities * sizeof(int));
		}

		PathTable = (int **)malloc(NumbCities * sizeof(int*));//Creating dynamic two dimensial array used to carry out path ('next move)
		for (int i = 0; i < NumbCities; i++)
		{
			PathTable[i] = (int *)malloc(NumbCities * sizeof(int)); //allocating memory for it
		}


		//Filling FloydTable
		for (int k = 0; k < NumbCities; k++)
		{

			for (int j = 0; j < NumbCities; j++)
			{
				if (k == j)
				{
					FloydTable[k][j] = 0;// We fill diagonal with zeros (because distance between a_1 and a_1 is 0
				}
				else
				{
					FloydTable[k][j] = infinity; //For now we assume there is no other connections between cities, so I fill them as an infinity
				}


			}
		}
		//Filling PathTable
		for (int i = 0; i < NumbCities; i++)
		{

			for (int j = 0; j < NumbCities; j++)
			{
				PathTable[i][j] = 0; //Assume that there are no connections available -> 0
			}

		}





		


		//Time for getting city names from file into arrays
		char **dynCNames;
		dynCNames = (char **)malloc(NumbCities * sizeof(char*));//Also here, we allocate memory for it , two dimensional char array)
		for (int i = 0; i < NumbCities; i++)
		{
			dynCNames[i] = (char *)malloc(MAX_NAME_LEN * sizeof(char));

		}
		//Getting combination of cities and distances between them into array
		char **dynCDist;
		dynCDist = (char **)malloc((NumbCities*NumbCities) * sizeof(char*));
		for (int i = 0; i < NumbCities*NumbCities; i++)
		{
			dynCDist[i] = (char *)malloc(MAX_NAME_LEN * sizeof(char)); //allocating memory

		}

		//Taking City Names 
		const size_t line_size = 300;
		char *line = (char *)malloc(100);


	
		printf("LIST OF DECLARED CITIES\n");
		int counter = 1; //Used to get only city names, it is counter of lines to know, what we're getting - only city names, or distance combinations
		while (!feof(fp))
		{
			while (fgets(line, line_size, fp) != NULL)//Taking lane from file to buffer line
			{
				if (counter >= 2 && counter <= NumbCities + 1)
				{
					strcpy(dynCNames[counter - 2], line);//copying from buffer to array with city names
					printf("%s", dynCNames[counter - 2]);
					counter++;//increasing counter to move to another line

				}
				else
				{
					if (counter > NumbCities)//counter is bigger than number of cities so we move to combinations
					{
						strcpy(dynCDist[counter - (NumbCities + 1)], line);//copying from buffer to array with whole combinations
						counter++;
					}
					else
						counter++; //it is used only in first step, to avoid putting first line into array

				}
			}
		}

		printf("\n\n");


		char FirstCChecker[20];   //Used as a buffer for first city name
		char SecondCChecker[20];	//Used as a buffer for second city name
		int DistanceValue;		//Used as a buffer for distance between mentioned first and second city
		//Dividing Cities&Distance combinations
		for (int k = 1; k < NumberOfLines - (NumbCities); k++)
		{

			sscanf(dynCDist[k], "%s %s %d", FirstCChecker, SecondCChecker, &DistanceValue);// sscanf used to partialy divide array dynCDist

			for (int i = 0; i < NumbCities; i++)
			{
				if (strncmp(FirstCChecker, dynCNames[i], strlen(FirstCChecker)) == 0)//We check if first buffer is same as one element of dynCNames for length of first buffer
					for (int j = 0; j < NumbCities; j++) //if and only if upper condition is satisfied
					{
					if (strncmp(SecondCChecker, dynCNames[j], strlen(SecondCChecker)) == 0)//we do the same but with second buffer
					{
						FloydTable[i][j] = DistanceValue;//if every condition was satisfied so put in floydtable at position [i][j] value of distance buffer
					}
					}
			}
			memset(FirstCChecker, 0, strlen(FirstCChecker));//reseting 1st buffer
			memset(SecondCChecker, 0, strlen(SecondCChecker));//reseting second buffer
		}//there is no need to reset DistanceValue because it is integer and it can be overwritten
		//Filling PathTable
		for (int k = 1; k < NumberOfLines - (NumbCities); k++)
		{

			sscanf(dynCDist[k], "%s %s %d", FirstCChecker, SecondCChecker, &DistanceValue);

			for (int i = 0; i < NumbCities; i++)
			{
				if (strncmp(FirstCChecker, dynCNames[i], strlen(FirstCChecker)) == 0) //Same as in filling FloydTable
					for (int j = 0; j < NumbCities; j++)
					{
					if (strncmp(SecondCChecker, dynCNames[j], strlen(SecondCChecker)) == 0)//Same as in filling FloydTable
					{
						PathTable[i][j]=j+1; //Whole procedure is to fulfill PathTable with possible connections
					}
					}
			}
			memset(FirstCChecker, 0, strlen(FirstCChecker));
			memset(SecondCChecker, 0, strlen(SecondCChecker));//Again cleaning buffers in every loop transition- I will use them later too
		}
		//Floyd Warshall Algorithm
		for (int k = 0; k < NumbCities; k++)
		{
			for (int i = 0; i < NumbCities; i++)
			{
				for (int j = 0; j < NumbCities; j++)
				{
					if (FloydTable[i][k] == infinity || FloydTable[k][j] == infinity)continue; //Operations on places with infinity
					if (FloydTable[i][j] > FloydTable[i][k] + FloydTable[k][j]) //If distance from i to j is bigger than distances from i to k and from k to j then 
						//we overwrite dist[i][j] as a sum of these 2 distances
					{
						FloydTable[i][j] = FloydTable[i][k] + FloydTable[k][j];
						PathTable[i][j] = PathTable[i][k]; //to avoid zeros, doing changes in pathtable
					}
				}
			}
		}
		/*printf("RESULTS BELOW CITY COMBINATION\n"); 
		for (int i = 0; i < NumbCities; i++)
		{
			for (int j = 0; j < NumbCities; j++)
			{
				//printf("%d  ", i);// I used them to check if answers were correct. (To avoid big names I've just used numbers)
			//	printf("%d  ", j);

				printf("%s", dynCNames[i]); //printing name of city which is in table with i index
				printf("%s", dynCNames[j]);// same for j
				if (FloydTable[i][j] == infinity)//
				{
					printf("No path\n");
				}
				else
				{
					printf("%d\n", FloydTable[i][j]);
				}
				printf("\n");
			}
		}
		*/// These loops were used to write combination of cities + their distances, no needed but I will keep them in code


		/* I WILL LEAVE IT IN SOURCE CODE JUST IN CASE SOMEONE WILL WANT TO SEE MATRIX
		for (int i = 0; i<NumbCities; i++)
		{

		for (int j = 0; j < NumbCities; j++)
		{
		printf("%d\t", FloydTable[i][j]);

		}
		printf("\n");
		}
		printf("\n\n");
		*/
		//PART WHEN WE GET DATA FROM USER TO OUTPUT NEEDED DISTANCE
		// I can use same char 'buffers' like FirstCChecker because they were erased in last invocation in for loop
		// So there is no need to create another buffer-like table
		int test = 1; //This is variable that is changed during while loop (used to hold loop - possibility to ask for other distances)
		char *statement = (char *)malloc(sizeof(char));//Statement will be the input from user if he wants to continue looking for.
		while (test)// test=1 so loop is always realised till test = 0
		{
			printf("Please write down name of first city then press enter\n");
			scanf("%s", FirstCChecker);//Getting first buffer

			printf("Please write down name of second city then press enter\n");
			scanf("%s", SecondCChecker);//Getting second buffer
			for (int i = 0; i < NumbCities; i++)
			{
				if (strncmp(FirstCChecker, dynCNames[i], strlen(FirstCChecker)) == 0)//If first buffer is same as name of city
					for (int j = 0; j < NumbCities; j++)
					{
					if (strncmp(SecondCChecker, dynCNames[j], strlen(SecondCChecker)) == 0)//if second buffer is same as name of city
					{
						printf("Distance : %d\n", FloydTable[i][j]); //we get distance value for buffer1 and buffer2
						printf("Intermediate city (Next in way) :\t");
						if (PathTable[i][j] == i+1) //if next city is same city as first one (moving from a to b through a)
						{
							printf("No intermediate cities\n\n");//It makes no sense, so there is no intermediate city
						}
						else
						{
							if (PathTable[i][j] != 0) //we don't need same cities
							{
								printf("%s\n", dynCNames[PathTable[i][j] - 1]);//
								printf("Distance to intermediate city :\t\t");
								printf("%d\n\n", FloydTable[i][PathTable[i][j] - 1]); //Taking distance from FloydTable with coordinates : i and intermediate city

							}
							else
								printf("No intermediate cities\n");
						}
					}
					}
			}
			

			printf("Do you want to try other cities? \n\tYes/No\n"); //Condition to continue checking values


			scanf("%s", statement);
			if (strncmp(statement, "Yes", 1) == 0)
			{
				memset(statement, 0, strlen(statement));
				continue;
			}
			if (strncmp(statement, "No", 1) == 0)
			{
				memset(statement, 0, strlen(statement));
				test = 0;
			}
			memset(statement, 0, strlen(statement));
			memset(FirstCChecker, 0, strlen(FirstCChecker));
			memset(SecondCChecker, 0, strlen(SecondCChecker));
			
		}
	}




	
	
	fclose(fp);

	getchar();
	return 0;
}
