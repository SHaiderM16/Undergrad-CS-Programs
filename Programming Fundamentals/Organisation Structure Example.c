#include <stdio.h>
#include <string.h>

struct Organisation
{
    char organisation_name[100];
    char organisation_number[100];
    struct Employee
    {
        int employee_id;
        char name[100];
        int salary;
    } emp;

} org;

int main()
{
    int sizeOrganisation = sizeof(struct Organisation);

    strcpy(org.organisation_name, "NU-Fast");
    strcpy(org.organisation_number, "NUFAST123ABC");
    org.emp.employee_id = 127;
    strcpy(org.emp.name, "Linus Sebastian");
    org.emp.salary = 400000;

    printf("The size of structure organisation : %d\n", sizeOrganisation);
    printf("Organisation Name : %s\n", org.organisation_name);
    printf("Organisation Number : %s\n", org.organisation_number);
    printf("Employee id : %d\n", org.emp.employee_id);
    printf("Employee name : %s\n", org.emp.name);
    printf("Employee Salary : %d\n", org.emp.salary);
}