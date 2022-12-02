//--------------------------------------------------------------------------------------------------------------------------------------------------
//Programme vom 28.11.2022

// Felder mit Temperatureingabe

#include <stdio.h>

int main()
{
    float fltTemperatur[7], fltMittlereTemperatur=0;
    unsigned int uiZaehler;
    
    for (uiZaehler=0; uiZaehler<7;uiZaehler++){
        printf("Bitte den %u. Wert eingeben: ", uiZaehler+1);
        scanf("%f", &fltTemperatur[uiZaehler]);
    }
    
    
    for(uiZaehler=0; uiZaehler<7; uiZaehler++){
        fltMittlereTemperatur += fltTemperatur[uiZaehler];
    }
    
    fltMittlereTemperatur = fltMittlereTemperatur / 7;
    printf("Die Durchschnittstemperatur beträgt: %.1f Grad Celsius", fltMittlereTemperatur);

    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------
// Felder mit Temperatureingabe + Niederster/Höchster/Mittel Wertausgabe

#include <stdio.h>

int main()
{
    float fltTemperatur[7], fltMittlereTemperatur=0, fltMaxTemperatur, fltMinTemperatur;
    unsigned int uiZaehler;
    
    for (uiZaehler=0; uiZaehler<7;uiZaehler++){
        printf("Bitte den %u. Wert eingeben: ", uiZaehler+1);
        scanf("%f", &fltTemperatur[uiZaehler]);
    }

    
    for (uiZaehler=0; uiZaehler<7; uiZaehler++){
        fltMittlereTemperatur += fltTemperatur[uiZaehler];
    }
    fltMittlereTemperatur = fltMittlereTemperatur / 7;
    
    fltMaxTemperatur = fltTemperatur[0];            //ersten Wert aus dem Feld nehmen für Begrenzung!
    for (uiZaehler=0; uiZaehler<7; uiZaehler++){
        if (fltTemperatur[uiZaehler] > fltMaxTemperatur){
            fltMaxTemperatur = fltTemperatur[uiZaehler];
        }
    }
    
    fltMinTemperatur = fltTemperatur[0];            //ersten Wert aus dem Feld nehmen für Begrenzung!
    for (uiZaehler=0; uiZaehler<7; uiZaehler++){
        if (fltTemperatur[uiZaehler] < fltMinTemperatur){
            fltMinTemperatur = fltTemperatur[uiZaehler];
        }
    }
    
    printf("Die Durchschnittstemperatur beträgt %.1f Grad Celsius.\n", fltMittlereTemperatur);
    printf("Die höchste Temperatur beträgt %.1f Grad Celsius.\n", fltMaxTemperatur);
    printf("Die niedrigste Temperatur beträgt %.1f Grad Celsius.", fltMinTemperatur);
    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------
// Felder mit Temperaturausgabe + Nieder/Höchst/Mittelwertausgabe und Wochentagermittlung über einen Switch Case

#include <stdio.h>

int main()
{
    float fltTemperatur[7], fltMittlereTemperatur=0, fltMaxTemperatur, fltMinTemperatur;
    unsigned int uiZaehler, uiMaxTag, uiMinTag;
    char *chWochentagNieder, *chWochentagHoch;
    
    for (uiZaehler=0; uiZaehler<7;uiZaehler++){
        printf("Bitte den %u. Wert eingeben: ", uiZaehler+1);
        scanf("%f", &fltTemperatur[uiZaehler]);
    }


    for (uiZaehler=0; uiZaehler<7; uiZaehler++){
        fltMittlereTemperatur += fltTemperatur[uiZaehler];
    }
    fltMittlereTemperatur = fltMittlereTemperatur / 7;
    
    fltMaxTemperatur = fltTemperatur[0];            //ersten Wert aus dem Feld nehmen für Begrenzung!
    uiMaxTag = 0;
    for (uiZaehler=0; uiZaehler<7; uiZaehler++){
        if (fltTemperatur[uiZaehler] > fltMaxTemperatur){
            fltMaxTemperatur = fltTemperatur[uiZaehler];
            uiMaxTag = uiZaehler;
        }
    }
    
    fltMinTemperatur = fltTemperatur[0];            //ersten Wert aus dem Feld nehmen für Begrenzung!
    uiMinTag = 0;
    for (uiZaehler=0; uiZaehler<7; uiZaehler++){
        if (fltTemperatur[uiZaehler] < fltMinTemperatur){
            fltMinTemperatur = fltTemperatur[uiZaehler];
            uiMinTag = uiZaehler;
        }
    }
    
    
    switch (uiMinTag){
        case 0: 
            chWochentagNieder = "Montag";
            break;
        case 1: 
            chWochentagNieder = "Dienstag";
            break;
        case 2: 
            chWochentagNieder = "Mittwoch";
            break;
        case 3: 
            chWochentagNieder = "Donnerstag";
            break;
        case 4: 
            chWochentagNieder = "Freitag";
            break;
        case 5: 
            chWochentagNieder = "Samstag";
            break;
        case 6: 
            chWochentagNieder = "Sonntag";
            break;
        default:
            break;
        break;
    }
    switch (uiMaxTag){
        case 0: 
            chWochentagHoch = "Montag";
            break;
        case 1: 
            chWochentagHoch = "Dienstag";
            break;
        case 2: 
            chWochentagHoch = "Mittwoch";
            break;
        case 3: 
            chWochentagHoch = "Donnerstag";
            break;
        case 4: 
            chWochentagHoch = "Freitag";
            break;
        case 5: 
            chWochentagHoch = "Samstag";
            break;
        case 6: 
            chWochentagHoch = "Sonntag";
            break;
        default:
            break;
        break;
    }
    
    printf("Die Durchschnittstemperatur beträgt %.1f Grad Celsius.\n", fltMittlereTemperatur);
    printf("Die höchste Temperatur in der Woche beträgt %.1f Grad Celsius und ist am %s.\n", fltMaxTemperatur, chWochentagHoch);
    printf("Die niedrigste Temperatur in der Woche beträgt %.1f Grad Celsius und ist am %s.", fltMinTemperatur, chWochentagNieder);
    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------
