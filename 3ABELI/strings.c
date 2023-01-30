//---------------------------------------------------------------------------------------------------
// Ausgabe von Hexadezimal Werten der Eingabe
#include <stdio.h>
#include <string.h>

int main()
{
    char Name[100];
    char Vorname[100], Nachname[100];
    int i;
    
    printf("Bitte Name eingeben: ");
    gets(Name);
    
    for (i=0; i < strlen(Name); i++)
    {
        printf("%c ", Name[i]);
        printf("%x\n", Name[i]);

    }
    

    return 0;
}

//---------------------------------------------------------------------------------------------------
// Eingabe von Strings mit Nachnamen und Vornamen Trennung
#include <stdio.h>
#include <string.h>

int main()
{
    unsigned char Name[100];
    unsigned char Vorname[100], Nachname[100];
    int i;
    
    printf("Bitte Name eingeben: ");
    gets(Name);
    
    Vorname[0] = 0;
    Nachname[0] = 0;
    for (i=0; i < strlen(Name); i++)
    {
        if (Name[i] == 0x20)
        {
            Name[i] = 0;
            strcpy(Vorname, Name);
            Name[i] = 0x20;
            strcpy(Nachname, &Name[i+1]);
            break;
        }
    }
    if (i == strlen(Name))
    {
        printf("Keine gültige Eingabe!");
    }
    else
    {
        printf("Vorname: %s\nNachname: %s", &Vorname, &Nachname);
    }
    return 0;
}
//---------------------------------------------------------------------------------------------------
// Abfrage von String oder Zahl

#include <stdio.h>

int main()
{
    char Eingabe[100];
    int ZahlEingabe, Anzahl;
    
    do
    {
        printf("Bitte Zahl eingeben:");
        gets(Eingabe);
        
        
        Anzahl = sscanf(Eingabe, "%d", &ZahlEingabe);
        if (Anzahl == 0)
        {
            printf("Ungültige Eingabe!\n");
        }
        else
        {
            break;
        } 
    } while(1);

    printf("Die Zahl ist %d", ZahlEingabe);
    return 0;
}
//---------------------------------------------------------------------------------
