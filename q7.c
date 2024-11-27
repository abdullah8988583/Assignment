#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inputEngagementMatrix(double **engagementMatrix, int numUsers, int numCategories) {
    for (int i = 0; i < numUsers; i++) {
        printf("Enter engagement scores for User %d:\n", i + 1);
        for (int j = 0; j < numCategories; j++) {
            printf("Category %d: ", j + 1);
            scanf("%lf", &engagementMatrix[i][j]);
        }
    }
}

void displayEngagementMatrix(double **engagementMatrix, int numUsers, int numCategories) {
    printf("\nEngagement Matrix:\n");
    for (int i = 0; i < numUsers; i++) {
        printf("User %d: ", i + 1);
        for (int j = 0; j < numCategories; j++) {
            printf("%.2f ", engagementMatrix[i][j]);
        }
        printf("\n");
    }
}

int findHighestEngagementCategory(double **engagementMatrix, int numUsers, int numCategories) {
    int highestCategory = 0;
    double maxAvg = 0;

    for (int j = 0; j < numCategories; j++) {
        double sum = 0;
        for (int i = 0; i < numUsers; i++) {
            sum += engagementMatrix[i][j];
        }
        double avg = sum / numUsers;
        if (avg > maxAvg) {
            maxAvg = avg;
            highestCategory = j;
        }
    }
    return highestCategory;
}

void inputDevicePreferences(double ***deviceMatrix, int numUsers, int numDevices) {
    for (int i = 0; i < numUsers; i++) {
        printf("Enter device preferences for User %d:\n", i + 1);
        for (int j = 0; j < numDevices; j++) {
            printf("Device %d - Resolution Preference (in px): ", j + 1);
            scanf("%lf", &deviceMatrix[i][j][0]); 
            printf("Playback History (minutes): ");
            scanf("%lf", &deviceMatrix[i][j][1]); 
            printf("Bandwidth Usage (MB): ");
            scanf("%lf", &deviceMatrix[i][j][2]); 
        }
    }
}

void displayDevicePreferences(double ***deviceMatrix, int numUsers, int numDevices) {
    printf("\nDevice Preferences:\n");
    for (int i = 0; i < numUsers; i++) {
        printf("User %d:\n", i + 1);
        for (int j = 0; j < numDevices; j++) {
            printf("  Device %d - Resolution: %.0fpx, Playback History: %.2f minutes, Bandwidth: %.2f MB\n", 
                   j + 1, deviceMatrix[i][j][0], deviceMatrix[i][j][1], deviceMatrix[i][j][2]);
        }
    }
}

void freeEngagementMatrix(double **engagementMatrix, int numUsers) {
    for (int i = 0; i < numUsers; i++) {
        free(engagementMatrix[i]);
    }
    free(engagementMatrix);
}

void freeDeviceMatrix(double ***deviceMatrix, int numUsers, int numDevices) {
    for (int i = 0; i < numUsers; i++) {
        for (int j = 0; j < numDevices; j++) {
            free(deviceMatrix[i][j]);
        }
        free(deviceMatrix[i]);
    }
    free(deviceMatrix);
}

int main() {
    int numUsers, numCategories, numDevices;

   
    printf("Enter the number of users: ");
    scanf("%d", &numUsers);
    printf("Enter the number of content categories: ");
    scanf("%d", &numCategories);
    printf("Enter the number of devices: ");
    scanf("%d", &numDevices);


    double **engagementMatrix = (double **)malloc(numUsers * sizeof(double *));
    for (int i = 0; i < numUsers; i++) {
        engagementMatrix[i] = (double *)malloc(numCategories * sizeof(double));
    }

    
    double ***deviceMatrix = (double ***)malloc(numUsers * sizeof(double **));
    for (int i = 0; i < numUsers; i++) {
        deviceMatrix[i] = (double **)malloc(numDevices * sizeof(double *));
        for (int j = 0; j < numDevices; j++) {
            deviceMatrix[i][j] = (double *)malloc(3 * sizeof(double)); 
        }
    }

    
    inputEngagementMatrix(engagementMatrix, numUsers, numCategories);
    displayEngagementMatrix(engagementMatrix, numUsers, numCategories);

    int highestCategory = findHighestEngagementCategory(engagementMatrix, numUsers, numCategories);
    printf("\nThe category with the highest average engagement is Category %d\n", highestCategory + 1);

    
    inputDevicePreferences(deviceMatrix, numUsers, numDevices);
    displayDevicePreferences(deviceMatrix, numUsers, numDevices);

    
    freeEngagementMatrix(engagementMatrix, numUsers);
    freeDeviceMatrix(deviceMatrix, numUsers, numDevices);

    return 0;
}
