//-----------------------------------------------------------------------------
// Notes:
//   - Funktion → Methode
//   - Variable → Eigenschaft
//   - *pointer zeigt auf den Wert der in Pointer steht
//   -  pointer zeigt auf Adresse

#include <stdio.h>

int main()
{
    char eingabe[80];
    char *pointer;
    
    eingabe[0] = 'h';
    pointer = eingabe;
    
    printf("Wert von eingabe_0: %c\n", eingabe[0]);
    printf("Adresse von pointer: %p\n", pointer);
    pointer++;
    printf("Adresse von pointer: %p\n", pointer);
    printf("Wert an der Stelle des Pointers: %x\n", *pointer);
    printf("Wert an der Stelle des Pointers: %c\n", *eingabe);
    
    return 0;
}
//-----------------------------------------------------------------------------

#include <iostream>
#include <math.h>

class Kreis {
private:
    float radius;
public:
    Kreis(int a) {  // Konstruktor
        if (a>0)
            radius = a;
    }
    float Umfang() {
        return 2*3.1415*radius;
    }
};

using namespace std;

int main()
{
    Kreis myKreis(2);
    Kreis secondKreis(10);
    cout<<"Umfang: "<<myKreis.Umfang() << endl;
    cout<<"Umfang: "<<secondKreis.Umfang() << endl;    
    return 0;
}
//-----------------------------------------------------------------------------
