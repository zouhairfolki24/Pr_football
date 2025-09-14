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
    strcpy(joueur.nom, nom);

    printf("\nPrenom: ");
    fgets(prenom, sizeof(prenom), stdin);
    strcpy(joueur.prenom, prenom);
    
    printf("\nNumero Maillot: ");
    scanf("%d", &numeroMaillot);
    joueur.numeroMaillot = numeroMaillot;
    
    printf("\nPoste (gardien / defenseur / milieu / attaquant): ");
    fgets(poste, sizeof(poste), stdin);
    strcpy(joueur.poste, poste);
    
    printf("\nAge: ");
    scanf("%d", &age);    
    joueur.age = age;

    printf("\nButs: ");
    scanf("%d", &buts);
    joueur.buts = buts;

    return joueur;
}

int main() {

    affiche_menu();

    struct Joueur joueur = get_infos_joueur();

    printf("\nNom: , Prenom")

    return 0;
}