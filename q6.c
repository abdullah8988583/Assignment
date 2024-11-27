#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures
typedef struct {
    char cropType[50];
    char growthStage[50];
    float expectedYield;
} Crop;

typedef struct {
    char equipmentName[50];
    int operationalStatus; // 1 = Active, 0 = Inactive
    float fuelLevel; // Percentage
} Equipment;

typedef struct {
    float pHLevel;
    float soilNutrients;
    float pestActivity;
} Sensor;

typedef struct {
    float gpsCoordinates[2]; // Latitude and Longitude
    float soilHealth;
    float moistureLevel;
    Crop *crops;
    int numCrops;
    Equipment *equipment;
    int numEquipment;
    Sensor *sensors;
    int numSensors;
} Field;

typedef struct {
    Field *fields;
    int numFields;
} RegionalHub;

// Input functions
void inputField(Field *field) {
    printf("Enter GPS Coordinates (Latitude Longitude): ");
    scanf("%f %f", &field->gpsCoordinates[0], &field->gpsCoordinates[1]);

    printf("Enter Soil Health Metric: ");
    scanf("%f", &field->soilHealth);

    printf("Enter Moisture Level: ");
    scanf("%f", &field->moistureLevel);

    printf("Enter the number of crops: ");
    scanf("%d", &field->numCrops);
    field->crops = (Crop *)malloc(field->numCrops * sizeof(Crop));
    for (int i = 0; i < field->numCrops; i++) {
        printf("Enter Crop %d Type: ", i + 1);
        scanf(" %[^\n]", field->crops[i].cropType);
        printf("Enter Growth Stage: ");
        scanf(" %[^\n]", field->crops[i].growthStage);
        printf("Enter Expected Yield: ");
        scanf("%f", &field->crops[i].expectedYield);
    }

    printf("Enter the number of equipment: ");
    scanf("%d", &field->numEquipment);
    field->equipment = (Equipment *)malloc(field->numEquipment * sizeof(Equipment));
    for (int i = 0; i < field->numEquipment; i++) {
        printf("Enter Equipment %d Name: ", i + 1);
        scanf(" %[^\n]", field->equipment[i].equipmentName);
        printf("Enter Operational Status (1 = Active, 0 = Inactive): ");
        scanf("%d", &field->equipment[i].operationalStatus);
        printf("Enter Fuel Level (%%): ");
        scanf("%f", &field->equipment[i].fuelLevel);
    }

    printf("Enter the number of sensors: ");
    scanf("%d", &field->numSensors);
    field->sensors = (Sensor *)malloc(field->numSensors * sizeof(Sensor));
    for (int i = 0; i < field->numSensors; i++) {
        printf("Enter Sensor %d Data - pH Level: ", i + 1);
        scanf("%f", &field->sensors[i].pHLevel);
        printf("Soil Nutrients: ");
        scanf("%f", &field->sensors[i].soilNutrients);
        printf("Pest Activity: ");
        scanf("%f", &field->sensors[i].pestActivity);
    }
}

void inputRegionalHub(RegionalHub *hub) {
    printf("Enter the number of fields in the regional hub: ");
    scanf("%d", &hub->numFields);
    hub->fields = (Field *)malloc(hub->numFields * sizeof(Field));
    for (int i = 0; i < hub->numFields; i++) {
        printf("\nInput details for Field %d:\n", i + 1);
        inputField(&hub->fields[i]);
    }
}

// Display functions
void displayField(Field *field) {
    printf("\nField GPS Coordinates: (%f, %f)\n", field->gpsCoordinates[0], field->gpsCoordinates[1]);
    printf("Soil Health: %f, Moisture Level: %f\n", field->soilHealth, field->moistureLevel);

    printf("Crops:\n");
    for (int i = 0; i < field->numCrops; i++) {
        printf("  Crop %d - Type: %s, Growth Stage: %s, Expected Yield: %.2f\n", 
               i + 1, field->crops[i].cropType, field->crops[i].growthStage, field->crops[i].expectedYield);
    }

    printf("Equipment:\n");
    for (int i = 0; i < field->numEquipment; i++) {
        printf("  Equipment %d - Name: %s, Status: %s, Fuel Level: %.2f%%\n", 
               i + 1, field->equipment[i].equipmentName, 
               field->equipment[i].operationalStatus ? "Active" : "Inactive", field->equipment[i].fuelLevel);
    }

    printf("Sensors:\n");
    for (int i = 0; i < field->numSensors; i++) {
        printf("  Sensor %d - pH Level: %.2f, Soil Nutrients: %.2f, Pest Activity: %.2f\n", 
               i + 1, field->sensors[i].pHLevel, field->sensors[i].soilNutrients, field->sensors[i].pestActivity);
    }
}

void displayRegionalHub(RegionalHub *hub) {
    for (int i = 0; i < hub->numFields; i++) {
        printf("\nDetails of Field %d:\n", i + 1);
        displayField(&hub->fields[i]);
    }
}

// Free memory
void freeField(Field *field) {
    free(field->crops);
    free(field->equipment);
    free(field->sensors);
}

void freeRegionalHub(RegionalHub *hub) {
    for (int i = 0; i < hub->numFields; i++) {
        freeField(&hub->fields[i]);
    }
    free(hub->fields);
}

int main() {
    RegionalHub hub;

    inputRegionalHub(&hub);
    displayRegionalHub(&hub);
    freeRegionalHub(&hub);

    return 0;
}
