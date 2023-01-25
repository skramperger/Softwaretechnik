#include <stdio.h>

int main()
{
    int variable1, variable2;
    int *ein_pointer;
    ein_pointer = NULL;
    ein_pointer = &variable1;
    variable1 = 5;
    variable2 = 12;
    printf("Pointer zeigt auf: %d\n", *ein_pointer);
    printf("Variable1: %d, Variable2: %d\n", variable1, variable2);

    ein_pointer = &variable1; // Pointer zeigt auf variable1
    *ein_pointer = 6; // jetzt enthält variable1 den Wert 6
    printf("Variable1: %d, Variable2: %d\n", variable1, variable2);

    variable1 = variable1 + 1; // jetzt enthält variable1 den Wert 7
    *ein_pointer = *ein_pointer + 1; // jetzt enthält variable1 den Wert 8
    printf("Variable1: %d, Variable2: %d\n", variable1, variable2);

    ein_pointer = &variable2; // Pointer zeigt auf variable2
    *ein_pointer = *ein_pointer + 1; // jetzt enthält variable2 den Wert 13
    printf("Variable1: %d, Variable2: %d\n", variable1, variable2);

    return 0;
}
