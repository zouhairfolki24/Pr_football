#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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
    getchar();
    joueur.buts = buts;

    return joueur;
}

void ajouter_joueur(struct Joueur joueur, int index) {
    equipe[index] = joueur;
}

int get_nombre_joueurs(int size_joueurs) {

    int nombre_joueurs;

    while (true) {
        printf("\nEntrez le nombre de joueurs que vous voulez ajouter: ");
        scanf("%d", &nombre_joueurs);
        getchar();

        if (nombre_joueurs > 0 && nombre_joueurs <= size_joueurs) {
            return nombre_joueurs;
        }
        printf("\nLe nombre de joueurs doit etre superieur a zero et ne pas depasser le nombre autorise.\n");
    }
}

void ajouter_plusieurs_joueur(int size_joueurs, int index) {

    struct Joueur joueur;
    int nombre_joueurs = get_nombre_joueurs(size_joueurs);
    
    for (int i = 0; i < nombre_joueurs; i++) {
        joueur = get_infos_joueur();
        ajouter_joueur(joueur, index);
    }
}

int main() {

    struct Joueur joueur;
    int index = 0;
    int size_joueurs = sizeof(equipe) / sizeof(equipe[0]);
    char choix[20], choix_ajoute[20];

    while (true) {
        
        affiche_menu();

        printf("\nEntrez votre choix: ");
        fgets(choix, sizeof(choix), stdin);
        choix[strcspn(choix, "\n")] = 0;
    
        if (strcmp(choix, "1") == 0) {

            while (true) {

                printf("\n 1. Ajouter un nouveau joueur.\n 2. Ajouter plusieurs joueurs en une seule operation.\n #. Menu principale.\n");

                printf("\nEntrez votre choix: ");
                fgets(choix_ajoute, sizeof(choix_ajoute), stdin);
                choix_ajoute[strcspn(choix_ajoute, "\n")] = 0;

                if (strcmp(choix_ajoute, "1") == 0) {
                    
                    // Ajouter un joueur
                    joueur = get_infos_joueur();
                    ajouter_joueur(joueur, index);
                    index++;

                } else if (strcmp(choix_ajoute, "2") == 0) {

                    // Ajouter plusieurs joueurs (une seule operation)
                    ajouter_plusieurs_joueur(size_joueurs, index);
                    index++;

                } else if (strcmp(choix_ajoute, "#") == 0) {

                    break;

                } else {

                    printf("\nInvalid choix!\n");

                }

            }
        
        } else if (strcmp(choix, "2") == 0) {
            
            while (true) {

                printf("\n 1. Trier les joueurs par ordre alpha")

            }

            break;

        } else if (strcmp(choix, "3") == 0) {
            
            break;
 
        } else if (strcmp(choix, "4") == 0) {
            
            break;

        } else if (strcmp(choix, "5") == 0) {
            
            break;

        } else if (strcmp(choix, "6") == 0) {
            
            break;

        } else if (strcmp(choix, "7") == 0) {
            
            break;

        } else {
            
            printf("\nInvalid choix!\n");

        }
    
    }




    return 0;
}