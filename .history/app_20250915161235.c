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
        printf("\nJoueur %d:\n", i + 1);
        joueur = get_infos_joueur();
        ajouter_joueur(joueur, index);
        index++;
    }
}

void trier_joueurs_par_nom(int size_joueurs) {

    struct Joueur joueur_temp;
    int swapped;
    for (int i = 0; i < size_joueurs - 1; i++) {
        swapped = 0;
        for (int j = 0; j < size_joueurs - i - 1; j++) {
            if (strcmp(equipe[j].nom, equipe[j+1].nom) > 0) {
                joueur_temp = equipe[j];
                equipe[j] = equipe[j+1];
                equipe[j+1] = joueur_temp;
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
    }

}

void trier_joueurs_par_age(int size_joueurs) {

    int swapped;
    struct Joueur joueur_temp;
    for (int i = 0; i < size_joueurs - 1; i++) {
        swapped = 0;
        for (int j = 0; j < size_joueurs - i - 1; j++) {
            if (equipe[j].age > equipe[j+1].age) {
                joueur_temp = equipe[j];
                equipe[j] = equipe[j+1];
                equipe[j+1] = joueur_temp;
                swapped = 1;
            }
        }

        if (!swapped) {
            break;
        }

    }
}

void afficher_joueurs(int size_joueurs) {
    
    for (int i = 0; i < size_joueurs; i++) {
        if (equipe[i].id != 0) {
            printf("\nID: %d, Nom: %s, Prenom: %s, Numero Maillot: %d, Poste: %s, Age: %d, Buts: %d.\n", equipe[i].id, equipe[i].nom, equipe[i].prenom, equipe[i].numeroMaillot, equipe[i].poste, equipe[i].age, equipe[i].buts);
        }
    }

}

void afficher_postes() {

    for (int i = 0; i < size_joueurs; i++) {
        if (gardiens[j].id != 0) {
            printf("\nID: %d, Nom: %s, Prenom: %s, Numero Maillot: %d, Poste: %s, Age: %d, Buts: %d.\n", equipe[i].id, equipe[i].nom, equipe[i].prenom, equipe[i].numeroMaillot, equipe[i].poste, equipe[i].age, equipe[i].buts);
        }
    }
    
}

void afficher_joueurs_par_poste(int size_joueurs) {

    struct Joueur gardiens[100], defenseurs[100], milieux[100], attaquants[100];
    int j = 0;
    for (int i = 0; i < size_joueurs; i++) {
        if (strcmp(equipe[i].poste, "gardien") == 0) {
            gardiens[j] = equipe[i];
            j++;
        } else if (strcmp(equipe[i].poste, "defenseur") == 0) {
            defenseurs[j] = equipe[i];
            j++;
        } else if (strcmp(equipe[i].poste, "milieu") == 0) {
            milieux[j] = equipe[i];
            j++;
        } else if (strcmp(equipe[i].poste, "attaquant") == 0) {
            attaquants[j] = equipe[i];
            j++;
        }
    }

    for (int i = 0; i < size_joueurs; i++) {
        if (gardiens[j].id != 0) {
            printf("\nID: %d, Nom: %s, Prenom: %s, Numero Maillot: %d, Poste: %s, Age: %d, Buts: %d.\n", equipe[i].id, equipe[i].nom, equipe[i].prenom, equipe[i].numeroMaillot, equipe[i].poste, equipe[i].age, equipe[i].buts);
        }
    }


}

int main() {

    struct Joueur joueur;
    int index = 0;
    int size_joueurs = sizeof(equipe) / sizeof(equipe[0]);
    char choix[20], choix_ajoute[20], choix_affiche[20];

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

                printf("\n 1. Trier les joueurs par ordre alphabetique (Nom A->Z).\n 2. Trier les joueurs par age.\n 3. Afficher les joueurs par poste.\n #. Menu principale.\n");

                printf("\nEntrez votre choix: ");
                fgets(choix_affiche, sizeof(choix_affiche), stdin);
                choix_affiche[strcspn(choix_affiche, "\n")] = 0;

                if (strcmp(choix_affiche, "1") == 0) {
                    
                    // Trier les joueurs par Nom (A->Z)
                    trier_joueurs_par_nom(size_joueurs);
                    afficher_joueurs(size_joueurs);
                    
                } else if (strcmp(choix_affiche, "2") == 0) {

                    // Trier les joueurs par age.
                    trier_joueurs_par_age(size_joueurs);
                    afficher_joueurs(size_joueurs);

                } else if (strcmp(choix_affiche, "3") == 0) {

                    // Afficher les joueurs par poste
                    afficher_joueurs_par_poste(size_joueurs);

                } else if (strcmp(choix_affiche, "#") == 0) {
                    
                    break;

                } else {
                    
                    printf("\nInvalid choix!\n");

                }

            }

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