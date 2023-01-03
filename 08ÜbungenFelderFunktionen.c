//---------------------------------------------------------------------------------------------------------------
// Ostereier
#include <stdio.h>

int EierProStunde (int PersonNummer)
{
    int Personen[3] = {5, 7, 9};
    if (PersonNummer > 3 || PersonNummer < 1){return 0;}
    else
    {
        return (Personen[PersonNummer-1]);
    }
}

int main()
{
    printf("Ingesamt werden %d Eier bemalt.", ((3*EierProStunde(1))+(4*EierProStunde(2))+(2*EierProStunde(3))));
    return 0;
}
//---------------------------------------------------------------------------------------------------------------
// Pi näherungsweise berechnen
#include <stdio.h>
#include <math.h>

double PiStelleBerechnen(int Stellen)
{
    return (pow((-1), Stellen) / (2* Stellen -1));
}

int main()
{
    double PiSumme = 0;
    
    int i;
    for (i=1; i<10000; i++)
    {
        PiSumme += PiStelleBerechnen(i);
    }
    
    printf("Pi: %lf", -(PiSumme*4));
}
//---------------------------------------------------------------------------------------------------------------
// Primzahlen
#include <stdio.h>

int main()
{
    int i, number, count, min, max, ArrayCount;
    
    printf("Start und Endzahl eingeben: ");
    scanf("%d %d", &min, &max);
    number = min;
    int Primzahlen[(max-min)];
    
    ArrayCount = 0;
   
    while(number <= max)
    {
        count = 0; 
        i=2;
        while(i <= number/2)
        {
            if(number%i == 0)
            {
                count++;
                break;
            }
            i++;
        }
        if(count == 0 && number != 1)
        {
            Primzahlen[ArrayCount] = number;
            ArrayCount += 1;
        }
        number++;
    }
    
    
    for(i=ArrayCount; i<(max-min); i++)
    {
        Primzahlen[i] = 0;
    }
    
    printf("Alle Primzahlen von %d bis %d sind: | ", min, max);
    for (i=0; i<(max-min); i++)
    {
        if(Primzahlen[i] !=0)
        {
            printf("%d | ", Primzahlen[i]);
        }
    }
    
    return 0;
}
//---------------------------------------------------------------------------------------------------------------
