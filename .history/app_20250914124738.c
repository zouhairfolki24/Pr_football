#include <stdio.h>

struct Joueur {
    int id;
    char nom[30], prenom[30];
    int numeroMaillot;
    char poste[30];
    int age, buts;
};

void affiche_menu() {
    printf("\n 1. Ajouter un joueur.\n 2. Afficher la liste de tous les joueurs.\n 3. Modifier un joueur.\n 4. Supprimer un joueur.\n 5. Rechercher un joueur.\n 6. Statistiques.\n 7. Quitter.\n");
}

void get_infos_joueur() {
    
}

int main() {

    affiche_menu();



    return 0;
}