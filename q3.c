#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int validateEmail(char *email) {
    int atCount = 0, dotAfterAt = 0, atPosition = -1;
    int length = strlen(email);

    if (length == 0) return 0;

    for (int i = 0; i < length; i++) {
        if (email[i] == '@') {
            atCount++;
            atPosition = i;
        } else if (email[i] == '.' && atPosition != -1 && i > atPosition) {
            dotAfterAt = 1;
        }
    }

    return (atCount == 1 && dotAfterAt);
}

int main() {
    char *email;
    int size;

    printf("Enter the size of the email: ");
    scanf("%d", &size);

    email = (char *)malloc(size * sizeof(char));
    if (!email) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the email address: ");
    scanf(" %[^\n]", email);

    if (validateEmail(email))
        printf("Valid Email\n");
    else
        printf("Invalid Email\n");

    free(email);
    return 0;
}
