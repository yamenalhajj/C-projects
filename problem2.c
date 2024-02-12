#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int LineNumber;

    scanf("%d", &LineNumber);

    char CheckWord[100];

    FILE* readFile;

    readFile = fopen("words.txt", "r");
    if (readFile == NULL) {
        printf("File not found");
        exit(1);
    }

    char word[100];
    char buffer[100];
    for (int i = 1; i <= 9; i++) {
        if (fgets(buffer, sizeof(buffer), readFile) != NULL) {
            if (i == LineNumber) {
                char charecter;
                charecter = buffer[1];
                printf("%c\n", charecter);
                int ASCII = 0;
                ASCII = charecter - 48;
                int realNUM = ASCII;

                while ((charecter = buffer[ASCII + 2]) != '\n' && (charecter = buffer[ASCII + 2]) != EOF) {
                    printf("%c", buffer[ASCII + 2]);
                    ASCII++;
                }
                printf("\n");
                int index = 0;
                for (int i = 2; i < 2 + realNUM; i++) {
                    word[index] = buffer[i];
                    index++;
                }

                int wordLength = strlen(word);
                scanf("%s", CheckWord);
                int checkwordLength = strlen(CheckWord);
                if (wordLength == checkwordLength) {
                    for (int q = 0; q < wordLength; q++) {
                        if (CheckWord[q] == word[q])
                            continue;
                        else {
                            printf("Wrong answer");
                            return 0;
                        }
                    }
                    printf("Correct answer.");
                    return 0;
                } else {
                    for (int q = 0; q < wordLength; q++) {
                        if (CheckWord[q] == word[q])
                            continue;
                        else {
                            printf("Wrong answer.");
                            exit(1);
                        }
                    }
                    printf("Wrong number of characters.");
                    exit(1);
                }
            }
        }
    }

    fclose(readFile);

    return 0;
}

