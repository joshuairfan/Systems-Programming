// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.



//

#include "pch.h"

#include <stdio.h>



int main()

{



	int low, high, middle, counter = 0;

	int found = 0;

	char input;

	int search_space;

	printf("Please enter the low bound \n");

	scanf_s("%d", &low);

	printf("Please enter the high bound \n");

	scanf_s("%d", &high);

	//counting the number of questions

	search_space = high - low;

	if (low > high)

	{

		printf("You are cheating!");

		return 0;

	}



	while (search_space != 0)

	{

		search_space = search_space / 2;

		counter++;

	}

	printf("I will guess your number in %d questions \n", counter + 1);

	counter = 0;

	while (low <= high)

	{

		middle = (high + low) / 2;

		counter++;

		printf("Press e if your number is equal to %d \n", middle);

		printf("Press g if your number is greater to %d \n", middle);

		printf("Press s if your number is smaller to %d \n", middle);

		scanf_s(" %c", &input);

		if (input == 'e')

		{

			found = 1;

			printf("I've done it \n");

			low = high + 1;

		}

		else

		{

			if (input == 'g')

				//shrink the search space

				low = middle + 1;

			else

				//shrink the search space

				high = middle - 1;

		}
	}
	if (found == 0) {

		printf("You liar! \n");

		return 0;

	}
printf("I guessed your number in %d questions \n", counter);
}