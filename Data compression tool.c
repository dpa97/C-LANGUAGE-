
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Run-Length Encoding: Compression
void compressRLE(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (!in || !out) {
        printf("Error: Cannot open file.\n");
        return;
    }

    char prev = fgetc(in), curr;
    int count = 1;

    while ((curr = fgetc(in)) != EOF) {
        if (curr == prev) {
            count++;
        } else {
            fprintf(out, "%c%d", prev, count);
            prev = curr;
            count = 1;
        }
    }

    if (prev != EOF)
        fprintf(out, "%c%d", prev, count);  // write last sequence

    fclose(in);
    fclose(out);
    printf("✅ Compression complete: %s\n", outputFile);
}

// Run-Length Decoding: Decompression
void decompressRLE(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (!in || !out) {
        printf("Error: Cannot open file.\n");
        return;
    }

    char ch;
    int count;

    while ((ch = fgetc(in)) != EOF) {
        if (isalpha(ch) || ispunct(ch) || ch == ' ') {
            fscanf(in, "%d", &count);
            for (int i = 0; i < count; i++)
                fputc(ch, out);
        }
    }

    fclose(in);
    fclose(out);
    printf("✅ Decompression complete: %s\n", outputFile);
}

// Main menu
int main() {
    int choice;

    while (1) {
        printf("\n=== RLE Compression Tool ===\n");
        printf("1. Compress (input.txt → compressed.txt)\n");
        printf("2. Decompress (compressed.txt → decompressed.txt)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                compressRLE("input.txt", "compressed.txt");
                break;
            case 2:
                decompressRLE("compressed.txt", "decompressed.txt");
                break;
            case 3:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
