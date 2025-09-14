#include <stdio.h>
#include <string.h>

struct Joueur {
    int id;
    char nom[30], prenom[30];
    int numeroMaillot;
    char poste[30];
    int age, buts;
};

struct Joueur equipe[100];
int id = 1;

void affiche_menu() {
    printf("\n 1. Ajouter un joueur.\n 2. Afficher la liste de tous les joueurs.\n 3. Modifier un joueur.\n 4. Supprimer un joueur.\n 5. Rechercher un joueur.\n 6. Statistiques.\n 7. Quitter.\n");
}

struct Joueur get_infos_joueur() {
    
    struct Joueur joueur;
    char nom[30], prenom[30], poste[30];
    int numeroMaillot, age, buts;

    joueur.id = id;
    id++;

    printf("\nNom: ");
    fgets(nom, sizeof(nom), stdin);
    nom[strcspn(nom, "\n")] = 0;
    strcpy(joueur.nom, nom);

    printf("\nPrenom: ");
    fgets(prenom, sizeof(prenom), stdin);
    prenom[strcspn(prenom, "\n")] = 0;
    strcpy(joueur.prenom, prenom);
    
    printf("\nNumero Maillot: ");
    scanf("%d", &numeroMaillot);
    getchar();
    joueur.numeroMaillot = numeroMaillot;
    
    printf("\nPoste (gardien / defenseur / milieu / attaquant): ");
    fgets(poste, sizeof(poste), stdin);
    poste[strcspn(poste, "\n")] = 0;
    strcpy(joueur.poste, poste);
    
    printf("\nAge: ");
    scanf("%d", &age);    
    joueur.age = age;

    printf("\nButs: ");
    scanf("%d", &buts);
    joueur.buts = buts;

    return joueur;
}

void ajouter_joueur(struct Joueur joueur, int index) {
    equipe[index] = joueur;
}

void ajouter_plusieurs_joueur() {
    printf("\nEntrez le nombre de joueurs que vous voulez")
}

int main() {

    affiche_menu();

    struct Joueur joueur = get_infos_joueur();

    ajouter_joueur(joueur, 0);

    printf("\nID: %d, Nom: %s, Prenom: %s, Numero Maillot: %d, Poste: %s, Age: %d, Buts: %d.\n",joueur.id, joueur.nom, joueur.prenom, joueur.numeroMaillot, joueur.poste, joueur.age, joueur.buts);
    return 0;
}