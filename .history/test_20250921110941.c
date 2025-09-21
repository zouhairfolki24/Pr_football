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
    int len_string = sizeof(pChoix) / sizeof(pChoix[0]);

    for (int i = 0; i < 20; i++) {
        if (pChoix[i] != '\n') {
            printf("\n'%c'\n", pChoix[i]);
        }
    }

    return 0;
}