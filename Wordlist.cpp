#include <stdio.h>
#include <string.h>

void generateCombinationsToFile(FILE *file, char charset[], int length, char current[], int index) {
    if (index == length) {
        current[length] = '\0';
        fprintf(file, "%s\n", current);
        return;
    }

    for (int i = 0; i < strlen(charset); i++) {
        current[index] = charset[i];
        generateCombinationsToFile(file, charset, length, current, index + 1);
    }
}

int main() {
    char charset[] = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123456789!@$%";
    int length = 6;

    char current[length + 1];
    FILE *file = fopen("combinations.txt", "w");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    generateCombinationsToFile(file, charset, length, current, 0);
    fclose(file);

    printf("Combinations written to 'combinations.txt'\n");

    return 0;
}
