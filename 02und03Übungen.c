//------------------------------------------------------------------------------------------------
// Ermitteln der Diagonale eines Quadrats

#include <stdio.h>

int main()
{
    double dblSeitenlaenge;
    printf("Seitelaenge eingeben:");
    scanf("%lf", &dblSeitenlaenge);
    
    printf("Die Diagonale beträgt %lf." , dblSeitenlaenge*1.41);
    
    return 0;
}

//------------------------------------------------------------------------------------------------
// Ermitteln des durchschnittlichen Benzinverbrauchs

#include <stdio.h>

int main()
{
    float flLiter, flKilometer;
    printf("Bitte Liter eingeben:");
    scanf("%f", &flLiter);
    printf("Bitte Kilometer eingeben:");
    scanf("%f", &flKilometer);
    printf("Der durchschnittliche Verbrauch in Liter pro 100 Kilometer betraegt: %f", flLiter / flKilometer * 100);

    return 0;
}

//------------------------------------------------------------------------------------------------
// Ermitteln von Kugeldaten

#include <stdio.h>

int main()
{
    float flRadius, flPI = 3.1415926;
    printf("Radius eingeben:");
    scanf("%f", &flRadius);
    printf("Die Oberflaeche betraegt %f und das Volumen betragt %f", 4*flRadius*flRadius*flPI, 4*flRadius*flRadius*flRadius*flPI/3);
    
    return 0;
}

//------------------------------------------------------------------------------------------------
// Ermitteln des Bruttopreises

#include <stdio.h>

int main()
{
    unsigned int uiAnzahl1, uiAnzahl2;
    float fNetto1, fNetto2, fNettogesamtpreis;
    
    printf("Erste Anzahl eingeben:");
    scanf("%ui", &uiAnzahl1);
    printf("Ersten Nettopreis eingeben:");
    scanf("%f", &fNetto1);
    
    printf("Zweite Anzahl eingeben:");
    scanf("%ui", &uiAnzahl2);
    printf("Zweiten Nettopreis eingeben:");
    scanf("%f", &fNetto2);
    
    fNettogesamtpreis = (uiAnzahl1*fNetto1)+(uiAnzahl2*fNetto2);
    printf("Der Nettogesamtpreis ist %.2f, der Mehrwertsteuerbetrag ist %.2f und der Bruttogesamtpreis ist %.2f",fNettogesamtpreis, fNettogesamtpreis*0.2, fNettogesamtpreis*1.2);
    
    return 0;
}

//------------------------------------------------------------------------------------------------
// Rabatt

#include <stdio.h>

int main()
{
    unsigned int uiAnzahl;
    float fPreis = 29.99;
    printf("Stueckzahl angeben:");
    scanf("%ui", &uiAnzahl);
    if (uiAnzahl > 10) 
    {
        printf("Der Gesamtpreis ist %.2f, der Rabatt ist %.2f und der Gesamtpreis mit Rabatt ist %.2f.", fPreis * uiAnzahl, fPreis * uiAnzahl * 0.05, fPreis * uiAnzahl * 0.95);
    }    
    else 
    {
        printf("Der Gesamtpreis ist %.2f.", fPreis * uiAnzahl);
    }    
        
    return 0;
}

//------------------------------------------------------------------------------------------------
// Tintenverbrauch

#include <stdio.h>

int main()
{

    unsigned int uiSeitenAnzahl;
    
    printf("Anzahl der Seiten eingeben:");
    scanf("%ui", &uiSeitenAnzahl);
    
    if (uiSeitenAnzahl * 0.5 > 300) {
        printf("Es muss Tinte nachbestellt werden!");
    }
    
    return 0;
}

//------------------------------------------------------------------------------------------------
// Erbschaft

#include <stdio.h>

int main()
{

    unsigned int uiAnzahl;
    float fProzent;
    printf("Anzahl der Kinder eingeben:");
    scanf("%ui", &uiAnzahl);
    
    if (uiAnzahl > 0) {
        fProzent = 60.0 / uiAnzahl;
        printf("Der Ehepartner bekommt 40 Prozent und die Kinder bekommen jeweils %.1f Prozent des Erbes.", fProzent);
    }
    else {
        printf("Der Eherpartner bekommt die vollen 100 Prozent.");
    }
    
    return 0;
}

//------------------------------------------------------------------------------------------------
// Fliesen

#include <stdio.h>

int main()
{
    unsigned int uiAnzahl, uiPakete;
    float fLaenge, fBreite, fFlaeche;
    
    printf("Laenge eingeben:");
    scanf("%f", &fLaenge);
    printf("Breite eingeben:");
    scanf("%f", &fBreite);

    fFlaeche = fBreite * fLaenge;
    if (fFlaeche < 10) {
        fFlaeche = fFlaeche*1.1;
        uiAnzahl = (fFlaeche+0.5) * 1.5;
    }
    else {
        fFlaeche = fFlaeche * 1.05;
        uiAnzahl = (fFlaeche+0.5) * 1.5;
    }
    uiPakete = uiAnzahl;                    //um auf einen Integer Datentypen zu kommen
    printf("Die Flaeche ist %.2f und die Anzahl der Fliesenpakete ist %u.", fFlaeche, uiPakete);
    return 0;
}
//------------------------------------------------------------------------------------------------
