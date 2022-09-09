#include <stdio.h>
#include <string.h>

typedef struct {
    int roll;
    char name[6];
    double gpa;
} Student;

typedef struct {
    Student std[50];
    int nStudents;
    char teacher[25+1];
} Class;

void printStudent(Student std) {
    printf("%s %d %f\n", std.name, std.roll, std.gpa);
}

void printClass(Class cls) {
    printf("Teacher: %s\n", cls.teacher);
    printf("No. of students: %d\n", cls.nStudents);
    for (int i = 0; i < cls.nStudents; i++)
        printStudent(cls.std[i]);
}

/*
    In c++ ;
    The readStudent function can have reference parameter)

    void readStudent(Student& pStd) {
        scanf("%s%d%lf", pStd.name, &pStd.roll, &pStd.gpa);
    }

    in the main function we can just write 
            readStudent(cls.std[i]) ;
*/

void readStudent(Student* pStd) {
    scanf("%s%d%lf", pStd->name, &pStd->roll, &pStd->gpa);
}

int main()
{
    Class cls;
    int i;

    cls.nStudents = 2;
    strcpy(cls.teacher, "Teacher");
    for (i = 0; i < cls.nStudents; i++) {
        readStudent(&cls.std[i]);
    }

    printClass(cls);

    return 0;
}
