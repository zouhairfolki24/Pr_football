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

    for (int i = 0; i < 20; i++) {

        if (strcmp(pChoix[i])) {
            printf("\n%c\n", pChoix[i]);
        }

    }

    return 0;
}