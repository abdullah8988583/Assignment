#include <stdio.h>
#include <stdlib.h>


void inputEmployees(int **ratings, int numEmployees, int numPeriods) {
    for (int i = 0; i < numEmployees; i++) {
        printf("Enter ratings for Employee %d:\n", i + 1);
        for (int j = 0; j < numPeriods; j++) {
            do {
                printf("Period %d (1-10): ", j + 1);
                scanf("%d", &ratings[i][j]);
                if (ratings[i][j] < 1 || ratings[i][j] > 10)
                    printf("Invalid rating. Please enter again.\n");
            } while (ratings[i][j] < 1 || ratings[i][j] > 10);
        }
    }
}


void displayPerformance(int **ratings, int numEmployees, int numPeriods) {
    printf("\nPerformance Ratings:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("Employee %d: ", i + 1);
        for (int j = 0; j < numPeriods; j++) {
            printf("%d ", ratings[i][j]);
        }
        printf("\n");
    }
}


int findEmployeeOfTheYear(int **ratings, int numEmployees, int numPeriods) {
    int bestEmployee = 0;
    double highestAvg = 0;

    for (int i = 0; i < numEmployees; i++) {
        int total = 0;
        for (int j = 0; j < numPeriods; j++) {
            total += ratings[i][j];
        }
        double avg = (double)total / numPeriods;
        if (avg > highestAvg) {
            highestAvg = avg;
            bestEmployee = i;
        }
    }
    return bestEmployee;
}


int findHighestRatedPeriod(int **ratings, int numEmployees, int numPeriods) {
    int bestPeriod = 0;
    double highestAvg = 0;

    for (int j = 0; j < numPeriods; j++) {
        int total = 0;
        for (int i = 0; i < numEmployees; i++) {
            total += ratings[i][j];
        }
        double avg = (double)total / numEmployees;
        if (avg > highestAvg) {
            highestAvg = avg;
            bestPeriod = j;
        }
    }
    return bestPeriod;
}


int findWorstPerformingEmployee(int **ratings, int numEmployees, int numPeriods) {
    int worstEmployee = 0;
    double lowestAvg = 11; 

    for (int i = 0; i < numEmployees; i++) {
        int total = 0;
        for (int j = 0; j < numPeriods; j++) {
            total += ratings[i][j];
        }
        double avg = (double)total / numPeriods;
        if (avg < lowestAvg) {
            lowestAvg = avg;
            worstEmployee = i;
        }
    }
    return worstEmployee;
}

int main() {
    int numEmployees, numPeriods;

    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);
    printf("Enter the number of evaluation periods: ");
    scanf("%d", &numPeriods);

    int **ratings = (int **)malloc(numEmployees * sizeof(int *));
    for (int i = 0; i < numEmployees; i++) {
        ratings[i] = (int *)malloc(numPeriods * sizeof(int));
    }

    inputEmployees(ratings, numEmployees, numPeriods);
    displayPerformance(ratings, numEmployees, numPeriods);

    int employeeOfTheYear = findEmployeeOfTheYear(ratings, numEmployees, numPeriods);
    printf("\nEmployee of the Year: Employee %d\n", employeeOfTheYear + 1);

    int highestRatedPeriod = findHighestRatedPeriod(ratings, numEmployees, numPeriods);
    printf("Highest Rated Period: Period %d\n", highestRatedPeriod + 1);

    int worstEmployee = findWorstPerformingEmployee(ratings, numEmployees, numPeriods);
    printf("Worst Performing Employee: Employee %d\n", worstEmployee + 1);

    for (int i = 0; i < numEmployees; i++) {
        free(ratings[i]);
    }
    free(ratings);
    return 0;
}
