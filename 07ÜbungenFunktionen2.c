//-------------------------------------------------------------------------------------------------------
//Größter gemeinsamer Teiler

#include <stdio.h>

unsigned int BerechneGGT(int Zahl1, int Zahl2)
{
    unsigned int GrosseZahl, KleineZahl;
    
    GrosseZahl = 0;
    KleineZahl = 0;
    if (Zahl1 == Zahl2){return Zahl1;}
    if (Zahl1 > Zahl2)
    {
        GrosseZahl = Zahl1;
        KleineZahl = Zahl2;
    }
    if (Zahl2 > Zahl1)
    {
        GrosseZahl = Zahl2;
        KleineZahl = Zahl1;
    }
    
    if (GrosseZahl % KleineZahl == 0)
    {
        return (KleineZahl);
    }
    
    unsigned int GroessterGemeinsamerTeiler, Rest, DivisionsErgebnis;
    while (Rest != 0)
    {
        if (GrosseZahl % KleineZahl == 0){Rest = 0; return KleineZahl;}
        else
        {
            Rest = GrosseZahl % KleineZahl;
            GrosseZahl = KleineZahl;
            KleineZahl = Rest;
        }
    }
}

int main()
{   
    unsigned int ErsteZahl, ZweiteZahl;
    printf("Erste Zahl: ");
    scanf("%u", &ErsteZahl);
    printf("Zweite Zahl: ");
    scanf("%u", &ZweiteZahl);
    
    printf("Der größte gemeinsame Teiler ist %u.", BerechneGGT(ErsteZahl, ZweiteZahl));
    
    return 0;
}
//-------------------------------------------------------------------------------------------------------
// Kleinstes gemeinsames Vielfaches
#include <stdio.h>

unsigned int BerechneGGT(int Zahl1, int Zahl2)
{
    unsigned int GrosseZahl, KleineZahl;
    
    GrosseZahl = 0;
    KleineZahl = 0;
    if (Zahl1 == Zahl2){return Zahl1;}
    if (Zahl1 > Zahl2)
    {
        GrosseZahl = Zahl1;
        KleineZahl = Zahl2;
    }
    if (Zahl2 > Zahl1)
    {
        GrosseZahl = Zahl2;
        KleineZahl = Zahl1;
    }
    
    if (GrosseZahl % KleineZahl == 0)
    {
        return (KleineZahl);
    }
    
    unsigned int GroessterGemeinsamerTeiler, Rest, DivisionsErgebnis;
    while (Rest != 0)
    {
        if (GrosseZahl % KleineZahl == 0){Rest = 0; return KleineZahl;}
        else
        {
            Rest = GrosseZahl % KleineZahl;
            GrosseZahl = KleineZahl;
            KleineZahl = Rest;
        }
    }
}

int main()
{   
    unsigned int ErsteZahl, ZweiteZahl;
    printf("Erste Zahl: ");
    scanf("%u", &ErsteZahl);
    printf("Zweite Zahl: ");
    scanf("%u", &ZweiteZahl);
    
    printf("Das kleinste gemeinsame Vielfache ist %u.", (ErsteZahl * ZweiteZahl /BerechneGGT(ErsteZahl, ZweiteZahl)));
    
    return 0;
}
//-------------------------------------------------------------------------------------------------------
// Umsätze einer Firma
#include <stdio.h>

int main()
{
    double Umsatz[7];
    char* Wochentag[7] = {"Montag", "Dienstag", "Mittwoch", "Dienstag", "Freitag", "Samstag", "Sonntag"};
    
    int i;
    for (i=0; i<7; i++)
    {
        printf("Umsatz in Euro für %s eingeben: ", Wochentag[i]);
        scanf("%lf", &Umsatz[i]);
    }
    
    double GroessterUmsatz = Umsatz[0];
    double GeringsterUmsatz = Umsatz[0];
    char* GroessterTag = Wochentag[0];
    char* GeringsterTag = Wochentag[0];
    
    for (i=0; i<7; i++)
    {
        if (GroessterUmsatz < Umsatz[i]){GroessterUmsatz = Umsatz[i];GroessterTag = Wochentag[i];}
        if (GeringsterUmsatz > Umsatz[i]){GeringsterUmsatz = Umsatz[i];GeringsterTag = Wochentag[i];}
    }
    printf("Der größte Umsatz beträgt %.2lf€ und war am %s.\n", GroessterUmsatz, GroessterTag);
    printf("Der geringste Umsatz beträgt %.2lf€ und war am %s.\n", GeringsterUmsatz, GeringsterTag);
    
    return 0;
}
//-------------------------------------------------------------------------------------------------------
