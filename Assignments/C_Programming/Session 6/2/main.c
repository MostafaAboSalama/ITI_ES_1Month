#include <stdio.h>
#include <string.h>

struct Employee
{
    char name[50];
    int id;
    union
    {
        float salary;
        char department[50];
    } info;
    int type; // 0 for salary, 1 for department
};

void addEmployee(struct Employee employees[], int *count);
void displayEmployees(struct Employee employees[], int count);
void findEmployee(struct Employee employees[], int count, int id);
void updateSalary(struct Employee employees[], int count, int id, float newSalary);
void listByDepartment(struct Employee employees[], int count, const char *department);

int main() {
    struct Employee employees[100];
    int count = 0;
    addEmployee(employees, &count);
    displayEmployees(employees, count);
    return 0;
}

void addEmployee(struct Employee employees[], int *count)
{
    struct Employee emp;
    printf("Enter name: ");
    scanf("%s", emp.name);
    printf("Enter ID: ");
    scanf("%d", &emp.id);
    printf("Enter type (0 for salary, 1 for department): ");
    scanf("%d", &emp.type);
    if (emp.type == 0)
    {
        printf("Enter salary: ");
        scanf("%f", &emp.info.salary);
    } else
    {
        printf("Enter department: ");
        scanf("%s", emp.info.department);
    }
    employees[*count] = emp;
    (*count)++;
}

void displayEmployees(struct Employee employees[], int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("Name: %s, ID: %d, ", employees[i].name, employees[i].id);
        if (employees[i].type == 0)
            printf("Salary: %.2f\n", employees[i].info.salary);
        else
            printf("Department: %s\n", employees[i].info.department);

    }
}

void findEmployee(struct Employee employees[], int count, int id)
{
    for (int i = 0; i < count; i++)
    {
        if (employees[i].id == id)
        {
            printf("Name: %s, ID: %d, ", employees[i].name, employees[i].id);
            if (employees[i].type == 0)
                printf("Salary: %.2f\n", employees[i].info.salary);
            else
                printf("Department: %s\n", employees[i].info.department);

            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

void updateSalary(struct Employee employees[], int count, int id, float newSalary)
{
    for (int i = 0; i < count; i++)
    {
        if (employees[i].id == id && employees[i].type == 0)
        {
            employees[i].info.salary = newSalary;
            printf("Salary updated.\n");
            return;
        }
    }
    printf("Employee with ID %d not found or not of type salary.\n", id);
}

void listByDepartment(struct Employee employees[], int count, const char *department)
{
    for (int i = 0; i < count; i++)
    {
        if (employees[i].type == 1 && strcmp(employees[i].info.department, department) == 0)
            printf("Name: %s, ID: %d, Department: %s\n", employees[i].name, employees[i].id, employees[i].info.department);
    }
}
