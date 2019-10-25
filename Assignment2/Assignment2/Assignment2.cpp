// Assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*

Joshua Irfan

dynamic array
*/

#include "pch.h"

#include <stdio.h>

#include<stdlib.h>

void array_accommodation(int *a, int size);

void printarray(int *a, int size);
void printarraybackwards(int *a, int size);

void bubble_sort(int *a, int size);

void find_min(int *a, int size);

void linear_search(int *a, int size);

void binary_search(int *a, int size);

void printrec(int *a, int size, int index);
void printrecbackwards(int *a, int size, int index);

void recursivelinearsearchshell(int * a, int size);
int recursivelinearsearchstep(int * a, int size, int index, int target);


void counting(int *a, int size);

//rec linear search

//fin max

//print array forward recursively

//print array backwards recursively

//printrecbackwards

//print non-recursively backwards

//linear search recursive





int main()

{

	int *a;

	int size;

	int i;

	int min;

	printf("How many numbers do you want to enter \n");

	scanf_s("%d", &size);

	a = (int*)calloc(size, sizeof(int));

	array_accommodation(a, size);

	find_min(a, size);

	printarray(a, size);

	printarraybackwards(a, size);

	linear_search(a, size);

	bubble_sort(a, size);

	binary_search(a, size);
	
	printf("Printing array forward recursively \n");

	printrec(a, size, 0);
	
	printf("Printing array backwards recursively \n");

	printrecbackwards(a, size, 0);

	recursivelinearsearchshell(a, size);

}

void array_accommodation(int *a, int size)

{

	int i;

	printf("Please enter %d numbers \n", size);

	for (i = 0; i < size; i++)

		scanf_s("%d", &a[i]);

}

void printarray(int *a, int size)

{

	int i;

	printf("Printing your array \n");

	for (i = 0; i < size; i++)

		printf("%d \n", a[i]);

}

void printarraybackwards(int *a, int size)
{
	int i;

	printf("Printing your array backwards \n");

	for (i = size - 1; i >= 0; i--)
		printf("%d \n", a[i]);
}

void bubble_sort(int *a, int size)

{

	int i, j;

	int temp;

	for (j = 0; j < size - 1; j++)

		for (i = 0; i < size - 1; i++)

			if (a[i] > a[i + 1])

			{

				temp = a[i];

				a[i] = a[i + 1];

				a[i + 1] = temp;

			}

	printf("\n Now array is sorted! \n");

	printarray(a, size);

}

void find_min(int *a, int size)

{

	int i;

	int min = a[0];

	for (i = 0; i < size; i++)

		if (a[i] < min)

			min = a[i];

	printf("minimal number is %d \n", min);

}

void linear_search(int *a, int size)

{

	int i;

	int target;

	int found = 0;

	printf("\n Let's perform linear search \n");

	printf("Please enter a target number to search for \n");

	scanf_s("%d", &target);

	for (i = 0; i < size && found != 1 ; i++)

		if (a[i] == target)

			found = 1 ;

	if (found == 1 )

		printf("Your target is found \n");

	else

		printf("Your target is NOT found \n");

}

void binary_search(int *a, int size)

{

	int low, high, middle;

	int i;

	int target;

	int found = 0;

	printf("\n Let's perform binary search, sorting array first /n");

	bubble_sort(a, size);

	printf("Please enter a target number to search for \n");

	scanf_s("%d", &target);

	low = 0;

	high = size - 1;

	while (low <= high && found != 1)

	{

		middle = (high + low) / 2;

		if (target == a[middle])

			found = 1;

		else

		{

			if (target > a[middle])

				low = middle + 1;

			else

				high = middle - 1;

		}

	}

	if (found == 1 )

		printf("Your target is found \n");

	else

		printf("Your target is NOT found \n");


}

void printrec(int *a, int size, int index)

{

	printf("%d \n", a[index]);

	if (index != size - 1)

	{

		printrec(a, size, index + 1);

	}

}

void printrecbackwards(int *a, int size, int index)
{
	if (index != size - 1)
	{
		printrecbackwards(a, size, index + 1);

	}
	printf("%d \n", a[index]);
}

void counting(int *a, int size)

{

	int i, max;

	int *c;

	int csize;

	max = a[0];

	for (i = 0; i < size - 1; i++)

		if (a[i] > max)

			max = a[i];

	printf("%d \n", max);

	csize = max + 1;

	c = (int*)calloc(csize, sizeof(int));

	for (i = 0; i < csize; i++)

		c[i] = 0;

	for (i = 0; i < size; i++)

	{

		c[a[i]]++;

	}



	//search

	printf("Printing original array sorted using counting array \n");

		for (i = 0; i < csize; i++)

		{

			while (c[i] != 0)

			{

				printf("%d \n", i);

				c[i]--;

			}



		}
		

}
void recursivelinearsearchshell(int * a, int size)
{
	int target = 0;
	int flag = 0;

	printf("What is your target number? \n");

	scanf_s("%d", &target);

	flag = recursivelinearsearchstep(a, size, 0, target);

	if (flag == 1)
	{
		printf("Your number has been found! \n");
	}
	else
	{
		printf("Your number has NOT been found! \n");
	}

}





int recursivelinearsearchstep(int * a, int size, int index, int target)
{
	if (index == size)
	{
		return 0;
	}
	else if (a[index] == target)
	{
		return 1;
	}
	else
	{
		return recursivelinearsearchstep(a, size, index + 1, target);
	}
}

