#include <stdio.h>
#include <string.h>

#define SIZE 4
#define EMPLOYED 16

typedef struct
{
	int id;
	char firstname[20];
	char surname[20];
	int line;
} Employee;

Employee team_A[SIZE];
Employee team_B[SIZE];
Employee team_C[SIZE];
Employee team_D[SIZE];



void DisplayList();

void CombineList(Employee [], int);

void SelectionSortSurname(Employee emp[]);

int main()
{
	DisplayList();

	SelectionSortSurname(&team_A[4]);
	
	return 0;
}

// Displays List of Employees before sort
void DisplayList()
{
	// TEAM A
	team_A[0].id = 101;
	strcpy(team_A[0].firstname, "Roxy");
	strcpy(team_A[0].surname, "Migurdia");
	team_A[0].line = 3;

	team_A[1].id = 102;
	strcpy(team_A[1].firstname, "Bishan");
	strcpy(team_A[1].surname, "Jesse");
	team_A[1].line = 3;

	team_A[2].id = 103;
	strcpy(team_A[2].firstname, "Marcelina");
	strcpy(team_A[2].surname, "Tivadar");
	team_A[2].line = 3;

	team_A[3].id = 104;
	strcpy(team_A[3].firstname, "Angelle");
	strcpy(team_A[3].surname, "Valkyrie");
	team_A[3].line = 3;




	// TEAM B
	team_B[0].id = 105;
	strcpy(team_B[0].firstname, "Anja");
	strcpy(team_B[0].surname, "Prokopios");
	team_B[0].line = 2;

	team_B[1].id = 106;
	strcpy(team_B[1].firstname, "Emilia");
	strcpy(team_B[1].surname, "Hannah");
	team_B[1].line = 2;

	team_B[2].id = 107;
	strcpy(team_B[2].firstname, "Granya");
	strcpy(team_B[2].surname, "Rukmini");
	team_B[2].line = 2;

	team_B[3].id = 108;
	strcpy(team_B[3].firstname, "Chestirad");
	strcpy(team_B[3].surname, "Erika");
	team_B[3].line = 2;




	// TEAM C
	team_C[0].id = 109;
	strcpy(team_C[0].firstname, "Ayaan");
	strcpy(team_C[0].surname, "Dariusz");
	team_C[0].line = 2;

	team_C[1].id = 110;
	strcpy(team_C[1].firstname, "Misa");
	strcpy(team_C[1].surname, "Imre");
	team_C[1].line = 1;

	team_C[2].id = 111;
	strcpy(team_C[2].firstname, "Ayomide");
	strcpy(team_C[2].surname, "Makoto");
	team_C[2].line = 3;

	team_C[3].id = 112;
	strcpy(team_C[3].firstname, "Rochus");
	strcpy(team_C[3].surname, "Koloman");
	team_C[3].line = 1;




	// TEAM D
	team_D[0].id = 113;
	strcpy(team_D[0].firstname, "Chikako");
	strcpy(team_D[0].surname, "Faelan");
	team_D[0].line = 1;

	team_D[1].id = 114;
	strcpy(team_D[1].firstname, "Vanda");
	strcpy(team_D[1].surname, "Kamal");
	team_D[1].line = 2;

	team_D[2].id = 115;
	strcpy(team_D[2].firstname, "Dmitrii");
	strcpy(team_D[2].surname, "Wulfrun");
	team_D[2].line = 1;

	team_D[3].id = 116;
	strcpy(team_D[3].firstname, "Dima");
	strcpy(team_D[3].surname, "Aristocles");
	team_D[3].line = 1;

	
	// Displaying Lists
	printf("\nTEAM A\n\nID\t    NAME\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d\t%s, %s\n", team_A[i].id, team_A[i].surname, team_A[i].firstname);
	}

	printf("\n\nTEAM B\n\nID\t    NAME\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d\t%s, %s\n", team_B[i].id, team_B[i].surname, team_B[i].firstname);
	}
	
	printf("\n\nTEAM C\n\nID\t    NAME\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d\t%s, %s\n", team_C[i].id, team_C[i].surname, team_C[i].firstname);
	}

	printf("\n\nTEAM D\n\nID\t    NAME\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d\t%s, %s\n", team_D[i].id, team_D[i].surname, team_D[i].firstname);
	}
}

void CombineList(Employee e[], int n)
{
	
}

void SelectionSortSurname(Employee emp[])
{

}