#define _CRT_SECURE_NO_WARNINGS 1
#include "stdio.h"
#include "conio.h"
#include "stdbool.h"
#include "string.h"

int main()
{
    FILE* fp, *fpout;
    char scBuffer[100], scFilename[200];
    int siZaehler, siFilenummer = 0;
    char *scStart = "Daten;";

    fp = fopen("COM5:", "r");
    if (fp == NULL)
    {
        printf("serielle Schnittstelle nicht aufmachbar");
    }
    else
    {
        setvbuf(fp, NULL, _IONBF, 0);
        while (1)
        {
            sprintf(scFilename, "C:\\TEMP\\ergebnis%d.csv", siFilenummer++);
            fpout = fopen(scFilename, "w");
            for (siZaehler = 0; siZaehler < 200; siZaehler++)
            {
                fgets(scBuffer, 100, fp);
                printf(".");
                if (siZaehler > 0)
                {
                    if (strncmp(scBuffer, scStart, strlen(scStart)) == 0)
                        fprintf(fpout, "%s", scBuffer);
                }
            }
            fclose(fpout);
        }
        fclose(fp);
    }

    printf("fertig");
    _getch();
}
