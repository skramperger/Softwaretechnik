//-----------------------------------------------------------------------
//Summe aller ungeraden Zahlen von 1 bis n

#include <stdio.h>

int main()
{
    unsigned int uiMaxAnzahl, uiFaktorial = 0, i;
    printf("Obere Grenze eingeben:");
    scanf("%u", &uiMaxAnzahl);

    if (uiMaxAnzahl >= 0){
            for (i=1;i<uiMaxAnzahl+1;i++)
    {
        if (i%2!=0){
            uiFaktorial += i;
        }
    }
    printf("%u", uiFaktorial);
    }
    else
    {
        printf("Bitte einen positiven Wert eingeben");
    }


    return 0;
}
//-----------------------------------------------------------------------
//Summe aller ungeraden Zahlen von 1 bis n - Aufgabe 2

#include <stdio.h>

int main()
{
    unsigned int uiGrenze, uiSchranke, uiFaktorial = 0, i;
    printf("Obere Grenze eingeben:");
    scanf("%u", &uiGrenze);
    printf("Schrank eingeben:");
    scanf("%u", &uiSchranke);
    
    if (uiGrenze >= 0){
        for (i =1; i<uiGrenze+1; i++){
            if (i%2!=0){
                if (uiFaktorial < uiSchranke){
                    uiFaktorial = uiFaktorial + i;
                }
                else
                {
                    break;
                }
            }
        }
    }
    else
    {
        printf("Bitte einen positiven Wert eingeben");
    }
    printf("%u", uiFaktorial);
    
    return 0;
    
}
//-----------------------------------------------------------------------
//Potenzzahl 1

#include <stdio.h>

int main()
{
    //uiNummer = a 
    //uiPotenz = n
    unsigned int uiNummer, uiPotenz, uiErgebnis = 1, i;
    printf("Nummer eingeben:");
    scanf("%u", &uiNummer);
    printf("Potenz eingeben:");
    scanf("%u", &uiPotenz);
    
    for (i=1; i<=uiPotenz; i++){
        
        uiErgebnis = uiErgebnis * uiNummer;
    }
    
    printf("%u", uiErgebnis);
    
    return 0;
    
}
//-----------------------------------------------------------------------
//Potenzzahl 2

#include <stdio.h>

int main()
{
    //uiNummer = a 
    //iPotenz = n
    int iPotenz;
    unsigned int uiNummer, uiErgebnis = 1, i;
    float flErgebnis1 = 1, flErgebnis2;
    printf("Nummer eingeben:");
    scanf("%u", &uiNummer);
    printf("Potenz eingeben:");
    scanf("%d", &iPotenz);
    
    //Wenn Hochzahl größer als 1 ist
    if (iPotenz > 0){
            for (i=1; i<=iPotenz; i++){
                flErgebnis1 = flErgebnis1 * uiNummer;
        }
        uiErgebnis = flErgebnis1;
        printf("%u", uiErgebnis);
    }
    //Für Hochzahlen unter 0 und genau 0
    else{
        if(iPotenz < 0){
            iPotenz = (iPotenz * -1);
            for (i=1; i<=iPotenz; i++){
                flErgebnis1 = flErgebnis1 * uiNummer;
            }
            flErgebnis2 = 1 / flErgebnis1;
            printf("%f", flErgebnis2);
        }
        else{
		printf("Error");
            }
        }
    }
    
    return 0;
    
}
//-----------------------------------------------------------------------
//Potenzzahl 3

#include <stdio.h>

int main()
{
    //uiNummer = a 
    //iPotenz = n
    int iPotenz;
    unsigned int uiNummer, uiErgebnis = 1, i;
    float flErgebnis1 = 1, flErgebnis2;
    printf("Nummer eingeben:");
    scanf("%u", &uiNummer);
    printf("Potenz eingeben:");
    scanf("%d", &iPotenz);
    
    //Wenn Hochzahl größer als 1 ist
    if (iPotenz > 0){
            for (i=1; i<=iPotenz; i++){
                flErgebnis1 = flErgebnis1 * uiNummer;
        }
        uiErgebnis = flErgebnis1;
        printf("%u", uiErgebnis);
    }
    //Für Hochzahlen unter 0 und genau 0
    else{
        if(iPotenz < 0){
            iPotenz = (iPotenz * -1);
            for (i=1; i<=iPotenz; i++){
                flErgebnis1 = flErgebnis1 * uiNummer;
            }
            flErgebnis2 = 1 / flErgebnis1;
            printf("%f", flErgebnis2);
        }
        else{
            if (iPotenz == 0){
                printf("Das Ergebnis ist 1!");
            }
            else{
                printf("Die Potenz ist keine Zahl!");
            }
        }
    }
    
    return 0;
    
}
//-----------------------------------------------------------------------
//Geschachtelte Schleifen

#include <stdio.h>

int main()
{
    unsigned int uiZahl1, uiZahl2, i, n, uiGesamt = 0;
    printf("Erste Zahl eingeben:");
    scanf("%u", &uiZahl1);
    printf("Zweite Zahl eingeben:");
    scanf("%u", &uiZahl2); 
    
    for (i=1; i<=uiZahl1; i++){
        for (n=1;n<=uiZahl2; n++){
            uiGesamt += 1;
        }
        
    }
    
    printf("Die Endzahl betraegt %u.", uiGesamt);
    return 0;
}
//-----------------------------------------------------------------------
