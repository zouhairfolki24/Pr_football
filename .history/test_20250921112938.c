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

    char * pChoix = get_choix_user();
    char * pChoix_ajoute = get_char_choix_user();
    
    printf("\n%s\n", pChoix);
    printf("\n\n");

    return 0;
}