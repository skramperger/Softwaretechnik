//---------------------------------------------------------------------------------------------------------------------------------------
// 1. Beispiel

// Editiere das Projekt mit dem Namen 'Aufgabe1'.
// Kopiere diesen Text ganz an den Anfang der Datei Quelle.c.
// Pro Stockwerk darf ein Haus maximal 4 Meter Höhe haben, dazu kommen 3 Meter Höhe für einen Keller.
// Lass die Anzahl der Stockwerke eines Hauses mittels scanf eingeben, und berechne daraus die maximale Bauhöhe.
// Gib diese aus. Der minimale Abstand von der Grundstücksgrenze ergibt sich als 5 Meter für das erste Stockwerk,
// plus 1.50 Meter pro weiterem Stockwerk. Gib diesen Minimalabstand ebenfalls aus.
// Das fertige Programm wird zusammen mit den anderen Beispielen abgegeben.


#include <stdio.h>

int main()
{
    //3m für Keller, 4m pro Stockwerk
    //max Bauhöhe ist 4m * Anzahl Stockwerke + 3m für Keller
    //min Bauabstand ist 5m + 1.5m * Anzahl Stockwerke -1
    unsigned int uiAnzahl;
    float fltMaxHoehe = 0, fltMinAbstand = 0;
    
    printf("Anzahl der Stockwerke eingeben:");
    scanf("%u", &uiAnzahl);
    
    if (uiAnzahl > 1){
        fltMaxHoehe = uiAnzahl * 4 + 3;
    }
    else 
    {
        fltMaxHoehe = 7;
    }
    
    if (uiAnzahl > 1){
        fltMinAbstand = 5 + ((uiAnzahl-1) * 1.5);
    }
    else
    {
        fltMinAbstand = 5;
    }
    
    
    printf("Die maximale Bauhöhe ist %.1f Meter.\n", fltMaxHoehe);
    printf("Die minimale Bauhöhe ist %.1f Meter.", fltMinAbstand);
    
    

    return 0;
}
//---------------------------------------------------------------------------------------------------------------------------------------
// 2. Beispiel

// Editiere das Projekt mit dem Namen 'Aufgabe2'.
// Kopiere diesen Text ganz an den Anfang der Datei Quelle.c.
// Das Programm soll aus einer gegebenen Menge an Laugenstangen (in Kilogramm) sowie dem Gesamtpreis der Laugenstangen
// den Preis pro Kilogramm Laugenstangen berechnen. Lies dazu das Gewicht in Kilogramm sowie den Gesamtpreis in EUR ein.
// Berechne daraus den Preis pro Kilogramm und gib diesen aus.
// Wenn der Preis pro Kilogramm Laugenstangen grösser oder gleich 12.58 EUR ist, gib eine Warnung aus, dass der Preis der Laugenstangen sehr hoch ist!
// Das fertige Programm wird zusammen mit den anderen Beispielen abgegeben.


#include <stdio.h>

int main()
{
    
    float fltKilogramm, fltGesamtpreis, fltPreisProKilo;
    
    printf("Das Gewicht in Kilogramm eingeben:");
    scanf("%f", &fltKilogramm);
    printf("Den Gesamtpreis in Euro eingeben:");
    scanf("%f", &fltGesamtpreis);
    
    fltPreisProKilo = fltGesamtpreis / fltKilogramm;
    printf("Der Preis pro Kilogramm beträgt:%.2f€.\n", fltPreisProKilo);
    if (fltPreisProKilo >= 12.58){
        printf("Der Preis der Laugenstangen ist sehr hoch.");
    }

    return 0;
}
//---------------------------------------------------------------------------------------------------------------------------------------
// 3. Beispiel

// Editiere das Projekt mit dem Namen 'Aufgabe3'.
// Kopiere diesen Text ganz an den Anfang der Datei Quelle.c.
// Berechne die Summe der ungeraden Zahlen von 95 bis 182.
// Das fertige Programm wird zusammen mit den anderen Beispielen abgegeben.


#include <stdio.h>

int main()
{
    
    unsigned int uiSumme = 0, i;
    
        for (i = 95; i <= 182; i++){
            if(i%2!= 0){
                uiSumme = uiSumme + i;
            }
        }
    
    printf("%u", uiSumme);
    
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------------------
