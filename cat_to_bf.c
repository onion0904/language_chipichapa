#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");
    char tokenA[6], tokenB[6];

    if (!file) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    while (fscanf(file, "%s%s", tokenA, tokenB) != EOF) {
        if (strcmp(tokenA, "chipi") == 0 && strcmp(tokenB, "chipi") == 0)
            printf(">");
        if (strcmp(tokenA, "chapa") == 0 && strcmp(tokenB, "chapa") == 0)
            printf("<");
        if (strcmp(tokenA, "dubi") == 0 && strcmp(tokenB, "dubi") == 0)
            printf("+");
        if (strcmp(tokenA, "daba") == 0 && strcmp(tokenB, "daba") == 0)
            printf("-");
        if (strcmp(tokenA, "boom") == 0 && strcmp(tokenB, "boom") == 0)
            printf(",");
        if (strcmp(tokenA, "chipi") == 0 && strcmp(tokenB, "chapa") == 0)
            printf(".");
        if (strcmp(tokenA, "dubi") == 0 && strcmp(tokenB, "daba") == 0)
            printf("[");
        if (strcmp(tokenA, "happy") == 0 && strcmp(tokenB, "happy") == 0)
            printf("]");
    }

    fclose(file);
    return 0;
}
