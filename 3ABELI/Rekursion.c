//---------------------------------------------------------------------------------------------------------------------------------------
// Rekursion für die Summe aller Zahlen n
#include <stdio.h>

unsigned long ulSummeAllerZahlen(unsigned long ulGrenze)
{
    unsigned long ulErgebnis;
    
    if (ulGrenze == 0)
    {
        return (0);
    }
    ulErgebnis = ulGrenze + ulSummeAllerZahlen(ulGrenze -1);
    return (ulErgebnis);
}


int main()
{
    printf("Summe der Zahlen ist: %lu.", ulSummeAllerZahlen(5));
    return 0;
}
//---------------------------------------------------------------------------------------------------------------------------------------
// Labyrinth Path Finder mit eigenem Feld
// Programm von Erwin Unger (Professor an der HTL Bulme)

#include <stdio.h>

#define SIZE_X 10 
#define SIZE_Y 6 

char laby[SIZE_Y][SIZE_X] =
{
    '+','+','+','+','Z','+','+','+','+','+',
    '+',' ',' ',' ',' ',' ',' ',' ',' ','+',
    '+',' ','+','+',' ','+','+','+',' ','+',
    '+',' ','+','+',' ',' ',' ','+',' ','+',
    '+',' ',' ',' ',' ','+',' ',' ',' ','+',
    '+','+','S','+','+','+','+','+','+','+'
};

void print_laby()
{
    int i,j;
    for (i=0;i<SIZE_Y;i++)
    {
        for (j=0;j<SIZE_X;j++)
            printf("%c",laby[i][j]);
        printf("\n");
    }
    printf("\n");
}

void walk_laby(int x, int y)
{
    if (laby[x][y] == 'Z') print_laby();
    if (laby[x][y] != ' ') return;
    laby[x][y] = '^';
    walk_laby(x-1,y);
    laby[x][y] = '>';
    walk_laby(x,y+1);
    laby[x][y] = '<';
    walk_laby(x,y-1);
    laby[x][y] = 'v';
    walk_laby(x+1,y);
    laby[x][y] = ' ';
}

int main()
{
    int i,j;

    print_laby();
    for (i=0;i<SIZE_Y;i++)
    {
        for (j=0;j<SIZE_X;j++)
            if (laby[i][j] == 'S') break;
        if (laby[i][j] == 'S') break;
    }
    walk_laby(i-1,j);    
    return 0;
}
//---------------------------------------------------------------------------------------------------------------------------------------
