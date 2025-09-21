#include <stdio.h>

char * get_choix_user() {

    char choix[20];

    printf("\nEntrez votre choix: ");
    fgets(choix, sizeof(choix), stdin);
    choix[strcspn(choix, "\n")] = 0;

    return choix;

}

int main() {

    char * pChoix = get_choix_user();

    printf({})

    return 0;
}