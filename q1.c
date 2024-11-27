#include <stdio.h>
#include <string.h>

typedef struct {
    int employeeCode;
    char employeeName[50];
    char dateOfJoining[11];
} Employee;

void inputEmployees(Employee employees[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter details for Employee %d:\n", i + 1);
        printf("Employee Code: ");
        scanf("%d", &employees[i].employeeCode);
        printf("Employee Name: ");
        scanf(" %[^\n]", employees[i].employeeName);
        printf("Date of Joining (DD/MM/YYYY): ");
        scanf("%s", employees[i].dateOfJoining);
    }
}

void checkTenure(Employee employees[], int size) {
    int currentDay, currentMonth, currentYear, count = 0;
    printf("Enter the current date (DD MM YYYY): ");
    scanf("%d %d %d", &currentDay, &currentMonth, &currentYear);

    printf("\nEmployees with tenure of more than 3 years:\n");
    for (int i = 0; i < size; i++) {
        int joinDay, joinMonth, joinYear;
        sscanf(employees[i].dateOfJoining, "%d/%d/%d", &joinDay, &joinMonth, &joinYear);
        int tenureYears = currentYear - joinYear - 
            (currentMonth < joinMonth || (currentMonth == joinMonth && currentDay < joinDay));
        if (tenureYears > 3) {
            count++;
            printf("Employee Code: %d, Name: %s, Tenure: %d years\n",
                   employees[i].employeeCode, employees[i].employeeName, tenureYears);
        }
    }
    printf("Total Employees with tenure > 3 years: %d\n", count);
}

int main() {
    Employee employees[4];
    inputEmployees(employees, 4);
    checkTenure(employees, 4);
    return 0;
}
