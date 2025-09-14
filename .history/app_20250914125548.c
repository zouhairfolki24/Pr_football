#include <stdio.h>
#include <string.h>

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

struct Joueur get_infos_joueur() {
    
    struct Joueur joueur;
    char nom, prenom, poste;
    int numeroMaillot, age, buts;

    printf("\nNom: ");
    fgets(nom, sizeof(nom), stdin);
    strcpy(joueur.nom, nom)

    printf("\nPrenom: ");
    fgets(prenom, sizeof(prenom), stdin);
    
    printf("\nNumero Maillot: ");
    scanf("%d", &numeroMaillot);
    
    printf("\nPoste (gardien / defenseur / milieu / attaquant): ");
    fgets(poste, sizeof(poste), stdin);    
    
    printf("\nAge: ");
    scanf("%d", &age);    

    printf("\nButs: ");
    scanf("%d", &buts);

    

}

int main() {

    affiche_menu();



    return 0;
}