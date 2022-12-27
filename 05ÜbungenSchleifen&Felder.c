//----------------------------------------------------------------------------------------------
// Temperaturtabelle 

#include <stdio.h>

double CelsiusInFahrenheit(double CelsiusWert)
{
    return ((CelsiusWert* 9 / 5) + 32);
}

int main()
{
    int i;
    for (i=0; i<=100; i+=5)
    {
        printf("%d Grad Celsius sind %.0f Grad Fahrenheit\n",i , CelsiusInFahrenheit(i));
    }
    return 0;
}
//----------------------------------------------------------------------------------------------
// Schülergrößen

#include <stdio.h>

int main()
{
    double SchuelerGroessen[10];
    size_t n = sizeof(SchuelerGroessen)/sizeof(SchuelerGroessen[0]);
    
    int i;
    for (i=0; i<n; i++)
    {
        printf("Größe des %dten Schülers in Zentimeter eingeben: ", (i+1));
        scanf("%lf", &SchuelerGroessen[i]);
    }
    
    double GroesseGesamt = 0;
    double DurchschnittsGroesse = 0;
    for(i=0; i<n; i++)
    {
        GroesseGesamt += SchuelerGroessen[i];
    }
    DurchschnittsGroesse = GroesseGesamt / n;
    
    double GroessterSchueler = SchuelerGroessen[0];
    for (i=0; i<n; i++)
    {
        if (SchuelerGroessen[i] > GroessterSchueler)
        {
            GroessterSchueler = SchuelerGroessen[i];
        }
    }
    
    double KleinsterSchueler = SchuelerGroessen[0];
    for (i=0; i<n; i++)
    {
        if (SchuelerGroessen[i] < KleinsterSchueler)
        {
            KleinsterSchueler = SchuelerGroessen[i];
        }
    }
    
    printf("Die Durchschnittsgröße aller Schüler beträgt %.2lf Meter.\n", (DurchschnittsGroesse/100));
    printf("Der größte Schüler ist %.2lf Meter groß.\n", (GroessterSchueler/100));
    printf("Der kleinste Schüler ist %.2lf Meter groß.", (KleinsterSchueler/100));
    
    return 0;
}
//----------------------------------------------------------------------------------------------
// Transistor Messungen

#include <stdio.h>

int main()
{
    double Strom[10]={0.001,0.001,0.001,0.005,0.02,0.05,0.1,0.3,0.5,0.7};
    double Spannung[10]={0.1,0.2,0.3,0.4,0.5,0.6,0.65,0.7,0.75, 0.9};
    
    double StromwertErreicht = 0; 
    double DazugehoerigeSpannung = 0;
    size_t n = sizeof(Strom)/sizeof(Strom[0]);  //Berechnung für Länge des Feldes
    
    int i;
    for (i=0; i<n; i++)
    {
        if (Strom[i] > 0.08)
        {
            StromwertErreicht = Strom[i];
            DazugehoerigeSpannung = Spannung[i];
            break;
        }
    }
    
    double SpannungErreicht = 0;
    double DazugehoerigerStrom = 0;
    for (i=0; i<n; i++)
    {
        if (Spannung[i] > 0.6)
        {
            SpannungErreicht = Spannung[i];
            DazugehoerigerStrom = Strom[i];
            break;
        }
    }

    printf("Der erste Stromwert über 0.08A ist bei: %.2lf Ampere und %.2lf Volt.\n", StromwertErreicht, DazugehoerigeSpannung);
    printf("Der erste Spannungswert über 0.6V ist bei: %.2lf Volt und %.2lf Ampere.\n", SpannungErreicht, DazugehoerigerStrom);

    double Widerstand[10];
    for (i=0; i<n; i++)
    {
        Widerstand[i] = Spannung[i] / Strom[i];
        printf("Der %dte Widerstand besitzt %.2lf Ohm.\n", i+1, Widerstand[i]);
    }
    
    return 0;
}
//----------------------------------------------------------------------------------------------
// Quadratzahlen

#include <stdio.h>

int main()
{
    
    unsigned int QuadratzahlenFeld[100];
    unsigned int SummeQuadratzahlen = 0;
    double Durchschnittswert = 0;
    
    size_t n = sizeof(QuadratzahlenFeld)/sizeof(QuadratzahlenFeld[0]);  //Berechnung für Länge des Feldes
    int i;
    for(i=0; i<n; i++)
    {
        QuadratzahlenFeld[i] = i*i;
        printf("%u\n", QuadratzahlenFeld[i]);
        SummeQuadratzahlen += QuadratzahlenFeld[i];
    }
    
    Durchschnittswert = (double)SummeQuadratzahlen / (double)n;
    
    unsigned int HoeherAlsDurchschnitt = QuadratzahlenFeld[0];
    unsigned int Stelle = 0;
    for(i=0; i<n; i++)
    {
        if (QuadratzahlenFeld[i] > Durchschnittswert)
        {
            HoeherAlsDurchschnitt = QuadratzahlenFeld[i];
            Stelle = i;
            break;
        }
    }
    
    printf("Die Summe aller Feldelemente ist %u.\n", SummeQuadratzahlen);
    printf("Der Durchschnittswert ist %.1lf.\n", Durchschnittswert);
    printf("Der erste Wert über dem Durchschnitt ist %u an %uter Stelle.", HoeherAlsDurchschnitt, Stelle);
    
    return 0;
}
//----------------------------------------------------------------------------------------------
