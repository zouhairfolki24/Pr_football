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

    for (int i = 0; pChoix[i] != '\0'; i++) {
        printf("%c", pChoix[i]);
    }

    char * pChoix_2 = get_choix_user()

    return 0;
}