#include <stdio.h>
#include <string.h>

char * get_choix_user() {

    static char choix[20];

    printf("\nEntrez votre choix: ");
    fgets(choix, sizeof(choix), stdin);
    choix[strcspn(choix, "\n")] = 0;

    return choix;

}

int main() {

    char choix[20];
    char choix_ajoute[20];

    strcpy(choix, )

    return 0;
}