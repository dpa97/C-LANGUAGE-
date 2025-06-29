#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char data[100];

    // 1. CREATE and WRITE to a file
    file = fopen("example.txt", "w"); // Opens file in write mode
    if (file == NULL) {
        printf("Error creating file.\n");
        return 1;
    }

    printf("Enter some text to write into the file: ");
    fgets(data, sizeof(data), stdin); // Get input from user
    fputs(data, file); // Write input to file

    fclose(file); // Close the file
    printf("Data written to file successfully.\n");

    // 2. READ from the file
    file = fopen("example.txt", "r"); // Opens file in read mode
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }

    printf("\nReading data from file:\n");
    while (fgets(data, sizeof(data), file) != NULL) {
        printf("%s", data); // Print the content read
    }

    fclose(file); // Close the file

    // 3. APPEND data to the file
    file = fopen("example.txt", "a"); // Opens file in append mode
    if (file == NULL) {
        printf("Error opening file for appending.\n");
        return 1;
    }

    printf("\nEnter some text to append to the file: ");
    fgets(data, sizeof(data), stdin); // Get input from user
    fputs(data, file); // Append input to file

    fclose(file); // Close the file
    printf("Data appended to file successfully.\n");

    // 4. Final READ to show complete content
    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file for final read.\n");
        return 1;
    }

    printf("\nFinal content of the file:\n");
    while (fgets(data, sizeof(data), file) != NULL) {
        printf("%s", data);
    }

    fclose(file);
    return 0;
}
