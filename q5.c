#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initializeInventory(char ***inventory, int numSpecies, int *numSupplies) {
    for (int i = 0; i < numSpecies; i++) {
        inventory[i] = NULL;
        numSupplies[i] = 0;
    }
}

void addSupplies(char ***inventory, int *numSupplies, int speciesIndex) {
    printf("Enter the number of supplies for species %d: ", speciesIndex + 1);
    scanf("%d", &numSupplies[speciesIndex]);

    inventory[speciesIndex] = (char **)malloc(numSupplies[speciesIndex] * sizeof(char *));
    for (int i = 0; i < numSupplies[speciesIndex]; i++) {
        inventory[speciesIndex][i] = (char *)malloc(50 * sizeof(char));
        printf("Enter supply %d: ", i + 1);
        scanf(" %[^\n]", inventory[speciesIndex][i]);
    }
}

void updateSupply(char ***inventory, int speciesIndex, int supplyIndex) {
    printf("Enter the new name for supply %d of species %d: ", supplyIndex + 1, speciesIndex + 1);
    scanf(" %[^\n]", inventory[speciesIndex][supplyIndex]);
}

void removeSpecies(char ***inventory, int *numSupplies, int speciesIndex, int *numSpecies) {
    for (int i = 0; i < numSupplies[speciesIndex]; i++) {
        free(inventory[speciesIndex][i]);
    }
    free(inventory[speciesIndex]);

    for (int i = speciesIndex; i < *numSpecies - 1; i++) {
        inventory[i] = inventory[i + 1];
        numSupplies[i] = numSupplies[i + 1];
    }
    (*numSpecies)--;
}

void displayInventory(char ***inventory, int *numSupplies, int numSpecies) {
    printf("\nCurrent Inventory:\n");
    for (int i = 0; i < numSpecies; i++) {
        printf("Species %d:\n", i + 1);
        for (int j = 0; j < numSupplies[i]; j++) {
            printf("  - %s\n", inventory[i][j]);
        }
    }
}

int main() {
    int numSpecies;
    printf("Enter the number of species: ");
    scanf("%d", &numSpecies);

    char ***inventory = (char ***)malloc(numSpecies * sizeof(char **));
    int *numSupplies = (int *)malloc(numSpecies * sizeof(int));
    initializeInventory(inventory, numSpecies, numSupplies);

    int choice, speciesIndex, supplyIndex;
    do {
        printf("\nMenu:\n");
        printf("1. Add Supplies\n");
        printf("2. Update Supply\n");
        printf("3. Remove Species\n");
        printf("4. Display Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the species index to add supplies (1 to %d): ", numSpecies);
                scanf("%d", &speciesIndex);
                addSupplies(inventory, numSupplies, speciesIndex - 1);
                break;
            case 2:
                printf("Enter the species index to update supply (1 to %d): ", numSpecies);
                scanf("%d", &speciesIndex);
                printf("Enter the supply index to update: ");
                scanf("%d", &supplyIndex);
                updateSupply(inventory, speciesIndex - 1, supplyIndex - 1);
                break;
            case 3:
                printf("Enter the species index to remove (1 to %d): ", numSpecies);
                scanf("%d", &speciesIndex);
                removeSpecies(inventory, numSupplies, speciesIndex - 1, &numSpecies);
                break;
            case 4:
                displayInventory(inventory, numSupplies, numSpecies);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    for (int i = 0; i < numSpecies; i++) {
        for (int j = 0; j < numSupplies[i]; j++) {
            free(inventory[i][j]);
        }
        free(inventory[i]);
    }
    free(inventory);
    free(numSupplies);

    return 0;
}
