/*
	Algorithm Design & Problem Solving CMPU1001 - Assignment 2022

	Author: Onting Leung (C21308733)  
	Date: 21/04/22
*/

#include <stdio.h>
#include <string.h>

#define SIZE 4
#define EMPLOYED 16

typedef struct 
{
	int id;
	int cert;
} Certs;

typedef struct
{
	char firstname[20];
	char surname[20];
	int line;
	Certs emp;
} Employee;


Employee team_A[SIZE];
Employee team_B[SIZE];
Employee team_C[SIZE];
Employee team_D[SIZE];
Employee fullList[EMPLOYED];
Employee fullTemp[EMPLOYED];



void DisplayTeamList();
void DisplayFullList();
void CombineList();
int binarySearch(Employee [], Employee, int, int);
void insertionSort(Employee [], int);
void merge(Employee [], Employee [], int, int, int);
void mergeSort(Employee [], Employee [], int, int, int);
void cert123();
void employeeSearch();



int main()
{

	int quit = 0, yes;
/* START OF TEAM LISTS */

	// TEAM A
	strcpy(team_A[0].firstname, "Roxy");
	strcpy(team_A[0].surname, "Migurdia");
	team_A[0].line = 3;

	strcpy(team_A[1].firstname, "Bishan");
	strcpy(team_A[1].surname, "Jesse");
	team_A[1].line = 3;

	strcpy(team_A[2].firstname, "Marcelina");
	strcpy(team_A[2].surname, "Tivadar");
	team_A[2].line = 3;

	strcpy(team_A[3].firstname, "Angelle");
	strcpy(team_A[3].surname, "Valkyrie");
	team_A[3].line = 3;

	
	// TEAM B
	strcpy(team_B[0].firstname, "Anja");
	strcpy(team_B[0].surname, "Prokopios");
	team_B[0].line = 2;

	strcpy(team_B[1].firstname, "Emilia");
	strcpy(team_B[1].surname, "Hannah");
	team_B[1].line = 2;

	strcpy(team_B[2].firstname, "Granya");
	strcpy(team_B[2].surname, "Rukmini");
	team_B[2].line = 2;

	strcpy(team_B[3].firstname, "Chestirad");
	strcpy(team_B[3].surname, "Erika");
	team_B[3].line = 2;


	// TEAM C
	strcpy(team_C[0].firstname, "Ayaan");
	strcpy(team_C[0].surname, "Dariusz");
	team_C[0].line = 2;

	strcpy(team_C[1].firstname, "Misa");
	strcpy(team_C[1].surname, "Imre");
	team_C[1].line = 1;

	strcpy(team_C[2].firstname, "Ayomide");
	strcpy(team_C[2].surname, "Makoto");
	team_C[2].line = 3;

	strcpy(team_C[3].firstname, "Rochus");
	strcpy(team_C[3].surname, "Koloman");
	team_C[3].line = 1;

	
	// TEAM D
	strcpy(team_D[0].firstname, "Chikako");
	strcpy(team_D[0].surname, "Faelan");
	team_D[0].line = 1;

	strcpy(team_D[1].firstname, "Vanda");
	strcpy(team_D[1].surname, "Kamal");
	team_D[1].line = 2;

	strcpy(team_D[2].firstname, "Dmitrii");
	strcpy(team_D[2].surname, "Wulfrun");
	team_D[2].line = 1;

	strcpy(team_D[3].firstname, "Dima");
	strcpy(team_D[3].surname, "Aristocles");
	team_D[3].line = 1;

/* END OF TEAM LISTS */


/* START OF CERTS AND ID'S */

	// TEAM A
	team_A[0].emp.id = 101;
	team_A[0].emp.cert = 123;
	team_A[1].emp.id = 102;
	team_A[1].emp.cert = 123;
	team_A[2].emp.id = 103;
	team_A[2].emp.cert = 123;
	team_A[3].emp.id = 104;
	team_A[3].emp.cert = 123;

	// TEAM B
	team_B[0].emp.id = 105;
	team_B[0].emp.cert = 120;
	team_B[1].emp.id = 106;
	team_B[1].emp.cert = 120;
	team_B[2].emp.id = 107;
	team_B[2].emp.cert = 120;
	team_B[3].emp.id = 108;
	team_B[3].emp.cert = 120;

	// TEAM C
	team_C[0].emp.id = 109;
	team_C[0].emp.cert = 120;
	team_C[1].emp.id = 110;
	team_C[1].emp.cert = 100;
	team_C[2].emp.id = 111;
	team_C[2].emp.cert = 123;
	team_C[3].emp.id = 112;
	team_C[3].emp.cert = 100;

	// TEAM D
	team_D[0].emp.id = 113;
	team_D[0].emp.cert = 100;
	team_D[1].emp.id = 114;
	team_D[1].emp.cert = 120;
	team_D[2].emp.id = 115;
	team_D[2].emp.cert = 100;
	team_D[3].emp.id = 116;
	team_D[3].emp.cert = 100;

/* ENF OF CERTS AND ID'S */

	printf("\n\nPress any key to Display the 4 separate list of teams:\n");
	getchar();

	DisplayTeamList();

	printf("\n\nPress any key to Combine and Sort:\n");
	getchar();

	CombineList();
	mergeSort(fullList, fullTemp, 0, EMPLOYED, 4);

	DisplayFullList();

	printf("\n\nPress any key to Display employees certified to work on all lines\n");
	getchar();

	cert123();

	while (quit == 0)
	{
		employeeSearch();
		printf("\n\nWould you like to search again?\n\nPress [1] if yes or any other key to exit:\n");
		scanf("%d", &yes);

		while (getchar() != '\n');

		if (yes == 1)
			employeeSearch();
		else
			quit = 1;
	}

	return 0;
}


// Displays List of Employees before sort
void DisplayTeamList()
{
	// Displaying Lists
	printf("\nTEAM A\n\nID\t    NAME\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d\t%s, %s\n", team_A[i].emp.id, team_A[i].surname, team_A[i].firstname);
	}

	printf("\n\nTEAM B\n\nID\t    NAME\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d\t%s, %s\n", team_B[i].emp.id, team_B[i].surname, team_B[i].firstname);
	}
	
	printf("\n\nTEAM C\n\nID\t    NAME\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d\t%s, %s\n", team_C[i].emp.id, team_C[i].surname, team_C[i].firstname);
	}

	printf("\n\nTEAM D\n\nID\t    NAME\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d\t%s, %s\n", team_D[i].emp.id, team_D[i].surname, team_D[i].firstname);
	}
}

int binarySearch(Employee emp[], Employee item, int low, int high)
{
	while (low <= high)
	{
		int mid = (low + (high -low) / 2);
		if (strcmp(item.surname, emp[mid].surname) == 0)
			return mid + 1;
		else if (strcmp(item.surname, emp[mid].surname) > 0)
			low = mid + 1;
		else
			high = mid - 1;
	}

	return low;
}

void insertionSort(Employee emp[], int length)
{
	int i, loc, j;
	Employee selected;

	for (i = 1; i < length; i++)
	{
		j = i - 1;
		selected = emp[i];

		// find location where selected should be inserted
		loc = binarySearch(emp, selected, 0, j);

		// move all elements after location to create space
		while (j >= loc)
		{
			emp[j + 1] = emp[j];
			j--;
		}
		emp[j + 1] = selected;
	}
}

void DisplayFullList()
{
	printf("\n\nFull List\n\nID\t    NAME\n");
	for (int i = 0; i < EMPLOYED; i++)
	{
		printf("%d\t%s, %s\n", fullList[i].emp.id, fullList[i].surname, fullList[i].firstname);
	}
}

void merge(Employee emp[], Employee temp[], int l, int m, int r)
{
	int i = l;
	int j = m + 1;
	int k = l;
	while ((i <= m) && (j <= r))
	{
		if (strcmp(emp[i].surname, emp[j].surname) < 0)
		{
			temp[k] = emp[i];
			i++;
		}
		else
		{
			temp[k] = emp[j];
			j++;
		}
		k++;
	}

	while (j <= r)
	{
		temp[k] = emp [j];
		j++;
		k++;
	}

	while (i <= m)
	{
		temp[k] = emp [i];
		i++;
		k++;
	}
	
	for (i = l; i <= r; i++)
	{
		emp[i] = temp[i];
	}
}

void mergeSort(Employee emp[], Employee temp[], int l, int r, int threshold)
{
	if (l < r)
	{
		if ((r - l) <= threshold)
			insertionSort(emp, r);
		else
		{
			int m = (l + r) / 2;
			mergeSort(emp, temp, l, m, threshold);
			mergeSort(emp, temp, m + 1, r, threshold);
			merge(emp, temp, l, m, r);
		}
	}
}

void CombineList()
{
	for(int i = 0; i < SIZE; i++)
	{
		fullList[i] = team_A[i];
		fullList[i + SIZE] = team_B[i];
		fullList[i + (SIZE * 2)] = team_C[i];
		fullList[i + (SIZE * 3)] = team_D[i];
	}
} 

void cert123()
{
	printf("\nCertified 123 Employees\n\n");
	printf("CERT\t   NAME\n");
	for (int i = 0; i < EMPLOYED; i++)
	{
		if (fullList[i].emp.cert == 123)
			printf("%d\t%s, %s\n", fullList[i].emp.cert, fullList[i].surname, fullList[i].firstname);
	}
}

void employeeSearch()
{
	char s[20];
	int i;

	printf("\nEnter Employee surname to search: ");
	scanf("%s", s);

	for (i = 0; i < EMPLOYED; i++)
	{
		if (!strcmp(s, fullList[i].surname))
			break;
	}

	if (i != EMPLOYED)
		printf("\nDetails on %s\n\nID: %d\nCERT: %d\nNAME: %s, %s\nLINE: %d\n\n", s, fullList[i].emp.id, fullList[i].emp.cert, fullList[i].surname, fullList[i].firstname, fullList[i].line);
	else
		printf("\n%s is not present in Employee List", s);
}