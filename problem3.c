#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float midX(float x1, float x2);
float midY(float y1, float y2);

int main()
{
    FILE *forRead;
    FILE *forWrite;

    forRead = fopen("Info.txt", "r");
    forWrite = fopen("Results.txt", "w");

    if (forRead == NULL)
    {
        printf("File not Found");
        exit(1);
    }

    float firstXaccs, firstYaccs, secondXaccs, secondYaccs;
    float SUMX, SUMY;
    float SUBX, SUBY;
    float dist;

    fprintf(forWrite, "Dist\tMidX\tMidY\n");

    while (fscanf(forRead, "%f%f%f%f", &firstXaccs, &firstYaccs, &secondXaccs, &secondYaccs) == 4)
    {
        SUMX = midX(firstXaccs, secondXaccs);
        SUMY = midY(firstYaccs, secondYaccs);
        SUBX = pow((firstXaccs - secondXaccs), 2);
        SUBY = pow((firstYaccs - secondYaccs), 2);

        dist = sqrt(SUBX + SUBY);

        fprintf(forWrite, "%0.2f\t%0.2f\t%0.2f\n", dist, SUMX, SUMY);
    }

    fclose(forRead);
    fclose(forWrite);

    return 0;
}

float midX(float x1, float x2)
{
    float mid = (x1 + x2) / 2;
    return mid;
}

float midY(float y1, float y2)
{
    float mid = (y1 + y2) / 2;
    return mid;
}
