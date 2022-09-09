#include <stdio.h>
#include <conio.h>
#include <string.h>

struct Student
{
    int roll;
    char name[25];
};

// Call by reference
void updateStudentInfo(struct Student* std){
    strcpy((*std).name, "Foo");
    std->roll = 35;
}

// call by value
void printStudentInfo(struct Student std){
    printf("Name: %s; Roll: %d\n", std.name, std.roll);
}

int main()
{
    struct Student std1;
    struct Student std2 = {30, "Imran"};

    updateStudentInfo(&std1);
    printStudentInfo(std1);
    printStudentInfo(std2);

    getch();
    return 0;
}
