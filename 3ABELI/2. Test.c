//------------------------------------------------------------------------------------------------------
// Beispiel 1

// Berechne die Summe der ungeraden Zahlen von 95 bis 181.

#include <stdio.h>

int BerechneSumme(int Start, int Ende)
{
    int i, Summe = 0;
    for (i=Start; i<Ende; i++)
    {
        Summe += i;
    }

    return Summe;
}

int main()
{
    printf("Die Summe von den zusammengezählten Zahlen von 95 bis 181 ist: %d.", BerechneSumme(95, 181));

    return 0;
}
//------------------------------------------------------------------------------------------------------
// Beispiel 2

// Der Verkaufspreis eines Christbaums berechnet sich nach folgender Tabelle:
// Baeume unter 1.3 Meter Groesse kosten 26 EUR.
// Baeume unter 1.7 Meter Groesse kosten 43 EUR.
// Baeume unter 2.1 Meter Groesse kosten 55 EUR.
// noch groessere Baeume kosten 68 EUR.
// Schreibe eine Funktion, die den Preis eines Christbaums auf Grund seiner Groesse bestimmt.
// Lies im Hauptprogramm die Groesse des Christbaums ein.
// Bestimme den Verkaufspreis mit Hilfe deiner Funktion und gib diesen aus.


#include <stdio.h>

double BerechneVerkaufpreis(double Baumgroesse)
{
    if(Baumgroesse < 1.3)                       {return 26;}
    if(Baumgroesse < 1.7 && Baumgroesse >= 1.3) {return 43;}
    if(Baumgroesse < 2.1 && Baumgroesse >= 1.7) {return 55;}
    if(Baumgroesse > 2.1)                       {return 68;}

}

int main()
{
    double Baumhoehe;

    printf("Baumhöhe eingeben: ");
    scanf("%lf", &Baumhoehe);
    printf("Der Baum mit einer Höhe von %.2lf Meter kostet %.2lf Euro.", Baumhoehe, BerechneVerkaufpreis(Baumhoehe));

    return 0;
}
//------------------------------------------------------------------------------------------------------
// Beispiel 3

// Gegeben ist ein Feld mit 31 Luftfeuchtigkeitswerten eines Monats:
// unsigned int uiHumidity[31] = { 71, 66, 68, 34, 41, 47, 27, 87, 63, 32, 51, 64, 89, 32, 15, 25, 86, 25, 21, 34, 65, 52, 65, 87, 53, 81, 35, 20, 81, 17,  35 };
// 1. Bestimme den durchschnittlichen Feuchtigkeitswert und gib diesen aus.
// 2. Bestimme die Anzahl der Tage, an denen der Wert groesser als der Durchschnitt ist.
// 3. Bestimme den niedrigsten Feuchtigkeitswert und gib diesen aus.

#include <stdio.h>

int main()
{   
    unsigned int uiHumidity[31] = { 71, 66, 68, 34, 41, 47, 27, 87, 63, 32, 51, 64, 89, 32, 15, 25, 86, 25, 21, 34, 65, 52, 65, 87, 53, 81, 35, 20, 81, 17, 35};
    double HumiditySumme = 0;
    double HumidityDurchschnitt = 0;
    unsigned int AnzahlTageGroesserDurchschnitt = 0;
    int NiedrigsterWert = uiHumidity[0];
    
    int i;
    for (i=0; i<31; i++)
    {
        HumiditySumme += uiHumidity[i];
    }
    
    HumidityDurchschnitt = HumiditySumme / 31;
    
    for (i=0; i<31; i++)
    {
        if (uiHumidity[i] > HumidityDurchschnitt)
        {
            AnzahlTageGroesserDurchschnitt++;
        }
        
        if (uiHumidity[i] < NiedrigsterWert)
        {
            NiedrigsterWert = uiHumidity[i];
        }
    }
    
    
    printf("Durchschnitt: %.2lf\n", HumidityDurchschnitt);
    printf("Anzahl der Tage die größer als der Durchschnitt sind: %u\n", AnzahlTageGroesserDurchschnitt);
    printf("Niedrigster Wert in der Tabelle: %d", NiedrigsterWert);
    return 0;
}
//------------------------------------------------------------------------------------------------------
