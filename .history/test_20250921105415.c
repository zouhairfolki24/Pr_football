#include <stdio.h>

printf("\nEntrez votre choix: ");
        fgets(choix, sizeof(choix), stdin);
        choix[strcspn(choix, "\n")] = 0;

int main() {


    return 0;
}