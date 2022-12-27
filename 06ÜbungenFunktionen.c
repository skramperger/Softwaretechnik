//-------------------------------------------------------------------------------------------------------
// Umrechnen von Grad Celsius in Grad Fahrenheit
#include <stdio.h>

double CelsiusInFahrenheit(double CelsiusWert)
{
    return (CelsiusWert*1.8+32);
}

int main()
{
    double CelsiusEingabe;
    printf("Grad Celsius eingeben: ");
    scanf("%lf", &CelsiusEingabe);
    printf("%.2lf Grad Celsius sind %.2lf Grad Fahrenheit.", CelsiusEingabe, CelsiusInFahrenheit(CelsiusEingabe));
    return 0;
}
//-------------------------------------------------------------------------------------------------------
// Umrechnen von Grad Fahrenheit in Grad Celsius
#include <stdio.h>

double FahrenheitInCelsius(double FahrenheitWert)
{
    return ((FahrenheitWert-32)/1.8);
}

int main()
{
    double FahrenheitEingabe;
    printf("Grad Fahrenheit eingeben: ");
    scanf("%lf", &FahrenheitEingabe);
    printf("%.2lf Grad Fahrenheit sind %.2lf Grad Celsius.", FahrenheitEingabe, FahrenheitInCelsius(FahrenheitEingabe));
    return 0;
}
//-------------------------------------------------------------------------------------------------------
// Umrechnen von Längeneinheit Seemeilen in Kilometer
#include <stdio.h>

double SeemeilenInKilometer(double SeemeilenWert)
{
    return (SeemeilenWert*1.852);
}

int main()
{
    double SeemeilenEingabe;
    printf("Seemeilen eingeben: ");
    scanf("%lf", &SeemeilenEingabe);
    printf("%.2lf Seemeilen sind %.2lf Kilometer.", SeemeilenEingabe, SeemeilenInKilometer(SeemeilenEingabe));
    return 0;
}
//-------------------------------------------------------------------------------------------------------
// Umrechnen von Längeneinheit Kilometer in Seemeilen
#include <stdio.h>

double KilometerInSeemeilen(double KilometerWert)
{
    return (KilometerWert/1.852);
}

int main()
{
    double KilometerEingabe;
    printf("Kilometer eingeben: ");
    scanf("%lf", &KilometerEingabe);
    printf("%.2lf Kilometer sind %.2lf Seemeilen.", KilometerEingabe, KilometerInSeemeilen(KilometerEingabe));
    return 0;
}
//-------------------------------------------------------------------------------------------------------
// Ermitteln der Note
#include <stdio.h>

int Notenberechnung(int Punkte)
{
    if (Punkte > 42 && Punkte < 49){return 1;}
    if (Punkte > 36 && Punkte < 43){return 2;}
    if (Punkte > 30 && Punkte < 37 ){return 3;}
    if (Punkte > 23 && Punkte < 31){return 4;}
    if (Punkte >= 0 && Punkte < 24){return 5;}
    else {return 0;}
}

int main()
{   
    int Punktezahl;
    printf("Punktezahl eingeben: ");
    scanf("%d", &Punktezahl);
    if (Punktezahl >= 0 && Punktezahl <= 48)
    {
        printf("Note ist %d.", Notenberechnung(Punktezahl));
    }
    else
    {
        printf("Ungültige Punkteanzahl!");
    }
    return 0;
}
//-------------------------------------------------------------------------------------------------------
// Fläche Rechteck
#include <stdio.h>

double FlaecheRechteckBerechnen(double Laenge, double Breite)
{
    return (Laenge*Breite);
}

int main()
{   
    double LaengenEingabe, BreitenEingabe;
    printf("Länge in Meter eingeben: ");
    scanf("%lf", &LaengenEingabe);
    printf("Breite in Meter eingeben: ");
    scanf("%lf", &BreitenEingabe);
    
    printf("Die Fläche des Rechtecks beträgt %.2lf Quadratmeter.", FlaecheRechteckBerechnen(LaengenEingabe, BreitenEingabe));
    
    return 0;
}
//-------------------------------------------------------------------------------------------------------
