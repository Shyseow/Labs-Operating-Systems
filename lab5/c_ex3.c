#include <stdio.h>	// for printf
#include <stdlib.h>	// for exit
#include <string.h>

struct Student {
	char *name; // point to a name string
	int id; // student number
	char enroll; // enrollment option: D or X
};

void getStudent(struct Student *);
void printStudent(struct Student);

int main(void)
{
struct Student john;
getStudent (&john);
printStudent(john);
exit(0);
}

void getStudent(struct Student *s)
{
	printf("Type the name of the student: ");
	s->name = malloc(100); // assume name has less than 100 letters
	fgets(s->name, 100, stdin);

	int n;
	n = strlen (s->name);
	
	if(s->name[n-1] == '\n')
{	
	s->name[n-1] = '\0';
}

printf("Type the student number: ");
scanf("%d", &(s->id));
getchar();
printf("Type the student enrollment option (D or X): ");
scanf("%c",&(s->enroll));
}

void printStudent(struct Student s)
{
printf("Student name: %s\n", s.name);
printf("Student number: %d\n", s.id);
printf("Student enrollment option: %c\n", s.enroll);
return;
}