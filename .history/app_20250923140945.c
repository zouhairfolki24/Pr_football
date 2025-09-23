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


void remplissage_donnees_joueurs() {

    struct Joueur joueur1 = {1, "messi", "lionel", "attaquant", 10, 38, 91};
    struct Joueur joueur2 = {2, "ronaldo", "crestiano", "attaquant", 7, 40, 32};
    struct Joueur joueur3 = {3, "lamine", "yamal", "attaquant", 19, 18, 12};
    struct Joueur joueur4 = {4, "palmer", "cole", "milieu", 24, 23, 19};
    struct Joueur joueur5 = {5, "van dijk", "virgil", "defenseur", 4, 34, 4};
    struct Joueur joueur6 = {6, "raphinha", "dias", "attaquant", 11, 28, 21};
    struct Joueur joueur7 = {7, "pedri", "gonzalez", "milieu", 8, 22, 7};
    struct Joueur joueur8 = {8, "garcia", "joan", "gardien", 13, 24, 0};
    struct Joueur joueur9 = {9, "dias", "ruben", "defenseur", 3, 28, 1};
    struct Joueur joueur10 = {10, "diaz", "luis", "attaquant", 14, 28, 16};

    equipe[0] = joueur1;
    equipe[0] = joueur1;
    equipe[0] = joueur1;
    equipe[0] = joueur1;

}


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

char * get_choix_user() {

    static char choix[20];

    printf("\nEntrez votre choix: ");
    fgets(choix, sizeof(choix), stdin);
    choix[strcspn(choix, "\n")] = 0;

    return choix;

}

void ajouter_joueur(struct Joueur joueur, int index) {
    equipe[index] = joueur;
    printf("\nLe joueur a ete ajoute avec succes.\n");
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

int ajouter_plusieurs_joueur(int size_joueurs, int index) {

    struct Joueur joueur;
    int nombre_joueurs = get_nombre_joueurs(size_joueurs);
    
    for (int i = 0; i < nombre_joueurs; i++) {
        printf("\nJoueur %d:\n", i + 1);
        joueur = get_infos_joueur();
        ajouter_joueur(joueur, index);
        index++;
    }

    return index;
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

void afficher_un_joueur(int pos_joueur) {

    if (pos_joueur != -1) {

        printf("\nID: %d, Nom: %s, Prenom: %s, Numero Maillot: %d, Poste: %s, Age: %d, Buts: %d.\n", equipe[pos_joueur].id, equipe[pos_joueur].nom, equipe[pos_joueur].prenom, equipe[pos_joueur].numeroMaillot, equipe[pos_joueur].poste, equipe[pos_joueur].age, equipe[pos_joueur].buts);

    } else {

        printf("\nLe joueur n'existe pas!\n");

    }
}

void afficher_joueurs(int size_joueurs) {
    
    int joueur_existe = 0;
    for (int i = 0; i < size_joueurs; i++) {
        if (equipe[i].id != 0) {
            afficher_un_joueur(i);
            joueur_existe = 1;
        }
    }

    if (!joueur_existe) {
        printf("\nIl n'y a aucun joueur dans la liste!\n");
    }

}

void afficher_joueurs_par_poste(int size_joueurs) {

    char new_poste[30];
    printf("\nEntrez le poste du joueur: ");
    fgets(new_poste, sizeof(new_poste), stdin);
    new_poste[strcspn(new_poste, "\n")] = 0;

    int poste_existe = 0;
    for (int i = 0; i < size_joueurs; i++) {
        if (strcmp(equipe[i].poste, new_poste) == 0 && equipe[i].id != 0) {
            afficher_un_joueur(i);
            poste_existe = 1;
        }
    }

    if (!poste_existe) {
        printf("\nLe poste du joueur n'existe pas!\n");
    }

}

int recherche_par_id(int size_joueurs) {

    int new_id;

    printf("\nEntrez l'identifiant: ");
    scanf("%d", &new_id);
    getchar();

    for (int i = 0; i < size_joueurs; i++) {
        if (equipe[i].id == new_id && equipe[i].id != 0) {
            return i;
        }
    }

    return -1;

}

void modifier_poste_joueur(int size_joueurs) {

    int pos_joueur;
    char new_poste[30];

    pos_joueur = recherche_par_id(size_joueurs);

    if (pos_joueur != -1) {

        printf("\nEntrez le poste d'un joueur: ");
        fgets(new_poste, sizeof(new_poste), stdin);
        new_poste[strcspn(new_poste, "\n")] = 0;

        strcpy(equipe[pos_joueur].poste, new_poste);

        printf("\nLe poste du joueur a ete modifie avec succes.\n");

    } else {

        printf("\nLe joueur n'existe pas!\n");

    }

}

void modifier_age_joueur(int size_joueurs) {

    int pos_joueur, new_age;

    pos_joueur = recherche_par_id(size_joueurs);

    if (pos_joueur != -1) {

        printf("\nEntrez l'age: ");
        scanf("%d", &new_age);
        getchar();

        equipe[pos_joueur].age = new_age;

        printf("\nL'age du joueur a ete modifie avec succes.\n");

    } else {

        printf("\nLe joueur n'existe pas!\n");

    }
}

void modifier_buts_joueur(int size_joueurs) {

    int pos_joueur, new_buts;

    pos_joueur = recherche_par_id(size_joueurs);

    if (pos_joueur != -1) {

        printf("\nEntrez le nombre de buts: ");
        scanf("%d", &new_buts);
        getchar();

        equipe[pos_joueur].buts = new_buts;

        printf("\nLe nombre de buts a ete modifie avec succes.\n");

    } else {

        printf("\nLe joueur n'existe pas!\n");

    }
}

void supprimer_joueur(int size_joueurs) {

    int pos_joueur;

    pos_joueur = recherche_par_id(size_joueurs);

    if (pos_joueur != -1) {

        equipe[pos_joueur].id = 0;
        strcpy(equipe[pos_joueur].nom, ""); 
        strcpy(equipe[pos_joueur].prenom, "");
        equipe[pos_joueur].numeroMaillot = 0;
        strcpy(equipe[pos_joueur].poste, "");
        equipe[pos_joueur].age = 0;
        equipe[pos_joueur].buts = 0;

        printf("\nLe joueur a ete supprime avec succes.\n");

    } else {

        printf("\nLe joueur n'existe pas!\n");

    }
}

int recherche_par_nom(int size_joueurs) {

    char new_nom[30];
    printf("\nEntrez le nom: ");
    fgets(new_nom, sizeof(new_nom), stdin);
    new_nom[strcspn(new_nom, "\n")] = 0;

    for (int i = 0; i < size_joueurs; i++) {
        if (strcmp(equipe[i].nom, new_nom) == 0 && equipe[i].id != 0) {
            return i;
        }
    }

    return -1;
}

int calcule_nombre_total_joueurs(int size_joueurs) {

    int total = 0;
    for (int i = 0; i < size_joueurs; i++) {
        if (equipe[i].id != 0) {
            total += 1;
        }
    }

    return total;
}

float calcule_age_moyen_joueurs(int size_joueurs) {

    int total_joueurs = calcule_nombre_total_joueurs(size_joueurs);
    int ages = 0;

    for (int i = 0; i < size_joueurs; i++) {
        if (equipe[i].id != 0) {
            ages += equipe[i].age;
        }
    }

    if (total_joueurs != 0) {
        return (float) ages / total_joueurs;
    } else {
        return -1;
    }
}

void afficher_joueurs_marque_xbuts(int size_joueurs) {

    int x_buts, joueur_existe = 0;
    printf("\nEntrez le nombre de buts (X): ");
    scanf("%d", &x_buts);
    getchar();

    for (int i = 0; i < size_joueurs; i++) {
        if (equipe[i].buts >= x_buts && equipe[i].id != 0) {
            afficher_un_joueur(i);
            joueur_existe = 1;
        }
    }

    if (!joueur_existe) {
        printf("\nAucun joueur de l'equipe n'a ce nombre de buts!\n");
    }

}

int nombre_buts_meilleur_buteur(int size_joueurs) {

    int buts_buteur = equipe[0].buts, buteur_exist = 0;
    for (int i = 1; i < size_joueurs; i++) {
        if (equipe[i].buts > buts_buteur && equipe[i].id != 0) {
            buts_buteur = equipe[i].buts;
            buteur_exist = 1;
        }
    }

    if (!buteur_exist) {
        return -1;
    } else {
        return buts_buteur;
    }
}

void afficher_plus_jeune_age(int size_joueurs) {

    int nombre_joueurs = calcule_nombre_total_joueurs(size_joueurs);
    struct Joueur joueurs[nombre_joueurs];
    int j = 0;
    
    int plus_jeune, plus_age;

    if (nombre_joueurs > 1) {
        for (int i = 0; i < size_joueurs; i++) {
            if (equipe[i].id != 0) {
                joueurs[j] = equipe[i];
                j++;
            }
        }

        plus_jeune = joueurs[0].age;
        plus_age = joueurs[0].age;
    
        for (int i = 1; i < nombre_joueurs; i++) {
            if (joueurs[i].age < plus_jeune) {
                plus_jeune = joueurs[i].age;
            } 
            if (joueurs[i].age > plus_age) {
                plus_age = joueurs[i].age;
            }
        }

    }

    if (nombre_joueurs != 0) {
        
        printf("\nLes joueurs plus age: \n");

        if (nombre_joueurs == 1) {
                afficher_joueurs(size_joueurs);
                return;
            }

        for (int i = 0; i < nombre_joueurs; i++) {
            if (joueurs[i].age == plus_age) {
                printf("\n  ID: %d, Nom: %s, Prenom: %s, Numero Maillot: %d, Poste: %s, Age: %d, Buts: %d.\n", joueurs[i].id, joueurs[i].nom, joueurs[i].prenom, joueurs[i].numeroMaillot, joueurs[i].poste, joueurs[i].age, joueurs[i].buts);
            } 
        }
        
        printf("\nLes joueurs plus jeune: \n");
        for (int i = 0; i < nombre_joueurs; i++) {
            if (joueurs[i].age == plus_jeune) {
                printf("\n  ID: %d, Nom: %s, Prenom: %s, Numero Maillot: %d, Poste: %s, Age: %d, Buts: %d.\n", joueurs[i].id, joueurs[i].nom, joueurs[i].prenom, joueurs[i].numeroMaillot, joueurs[i].poste, joueurs[i].age, joueurs[i].buts);
            }
        }

    } else {

        printf("\nIl n'y a aucun joueur dans la liste!\n");

    }

}

int main() {

    struct Joueur joueur;
    int index = 0, pos_joueur, total, buts_buteur;
    int size_joueurs = sizeof(equipe) / sizeof(equipe[0]);
    char * choix;
    float age_moyen;

    while (true) {
        
        affiche_menu();

        choix = get_choix_user();
    
        if (strcmp(choix, "1") == 0) {

            while (true) {

                printf("\n 1. Ajouter un nouveau joueur.\n 2. Ajouter plusieurs joueurs en une seule operation.\n #. Menu principale.\n");

                choix = get_choix_user();

                if (strcmp(choix, "1") == 0) {
                    
                    // Ajouter un joueur
                    joueur = get_infos_joueur();
                    ajouter_joueur(joueur, index);
                    index++;

                } else if (strcmp(choix, "2") == 0) {

                    // Ajouter plusieurs joueurs (une seule operation)
                    index = ajouter_plusieurs_joueur(size_joueurs, index);

                } else if (strcmp(choix, "#") == 0) {

                    break;

                } else {

                    printf("\nInvalid choix!\n");

                }

            }
        
        } else if (strcmp(choix, "2") == 0) {
            
            while (true) {

                printf("\n 1. Trier les joueurs par ordre alphabetique (Nom A->Z).\n 2. Trier les joueurs par age.\n 3. Afficher les joueurs par poste.\n #. Menu principale.\n");

                choix = get_choix_user();

                if (strcmp(choix, "1") == 0) {
                    
                    // Trier les joueurs par Nom (A->Z)
                    trier_joueurs_par_nom(size_joueurs);
                    afficher_joueurs(size_joueurs);
                    
                } else if (strcmp(choix, "2") == 0) {

                    // Trier les joueurs par age.
                    trier_joueurs_par_age(size_joueurs);
                    afficher_joueurs(size_joueurs);

                } else if (strcmp(choix, "3") == 0) {

                    // Afficher les joueurs par poste
                    afficher_joueurs_par_poste(size_joueurs);

                } else if (strcmp(choix, "#") == 0) {
                    
                    break;

                } else {
                    
                    printf("\nInvalid choix!\n");

                }

            }

        } else if (strcmp(choix, "3") == 0) {
            
            while (true) {

                printf("\n 1. Modifier le poste d'un joueur.\n 2. Modifier l'age d'un joueur.\n 3. Modifier le nombre de buts marques par un joueur.\n #. Menu principale.\n");

                choix = get_choix_user();

                if (strcmp(choix, "1") == 0) {
                    
                    // Modifier le poste d'un joueur
                    modifier_poste_joueur(size_joueurs);

                } else if (strcmp(choix, "2") == 0) {

                    // Modifier l'age d'un joueur
                    modifier_age_joueur(size_joueurs);

                } else if (strcmp(choix, "3") == 0) {

                    // Modifier le nombre de buts marques par un joueur
                    modifier_buts_joueur(size_joueurs);

                } else if (strcmp(choix, "#") == 0) {

                    break;

                } else {

                    printf("\nInvalid choix!\n");

                }

            }
            
        } else if (strcmp(choix, "4") == 0) {
            
            // Supprimer un joueur
            supprimer_joueur(size_joueurs);

        } else if (strcmp(choix, "5") == 0) {
            
            while (true) {

                printf("\n 1. Rchercher un joueur par ID.\n 2. Rechercher un joueur par Nom.\n #. Menu principale.\n");

                choix = get_choix_user();

                if (strcmp(choix, "1") == 0) {

                    // Rechercher un joueur par ID
                    pos_joueur = recherche_par_id(size_joueurs);
                    afficher_un_joueur(pos_joueur);

                } else if (strcmp(choix, "2") == 0) {
                    
                    // Rechercher un joueur par Nom
                    pos_joueur = recherche_par_nom(size_joueurs);
                    afficher_un_joueur(pos_joueur);

                } else if (strcmp(choix, "#") == 0) {

                    break;

                } else {

                    printf("\nInvalid choix!\n");

                }

            }

        } else if (strcmp(choix, "6") == 0) {
            
            while (true) {

                printf("\n 1. Afficher le nombre total de joueurs dans l'equipe.\n 2. Afficher l'age moyen des joueurs.\n 3. Afficher les joueurs ayant marque plus de X buts.\n 4. Afficher le meilleur buteur.\n 5. Afficher le joueur le plus jeune et le plus age.\n #. Menu principale.\n");

                choix = get_choix_user();

                if (strcmp(choix, "1") == 0) {

                    // Afficher le nombre total de joueurs dans l'equipe
                    total = calcule_nombre_total_joueurs(size_joueurs);
                    printf("\nLe nombre total de joueurs dans l'equipe est de %d.\n", total);

                } else if (strcmp(choix, "2") == 0) {

                    // Afficher l'age moyen des joueurs
                    age_moyen = calcule_age_moyen_joueurs(size_joueurs);
                    if (age_moyen != -1) {
                        printf("\nL'age moyen des joueurs est de %.2f.\n", age_moyen);
                    } else {
                        printf("\nIl n'y a aucun joueur dans la liste!\n");
                    }

                } else if (strcmp(choix, "3") == 0) {

                    // Afficher les joueurs ayant marques plus de X buts
                    afficher_joueurs_marque_xbuts(size_joueurs);

                } else if (strcmp(choix, "4") == 0) {

                    // Afficher le meilleur buteur
                    buts_buteur = nombre_buts_meilleur_buteur(size_joueurs);
                    if (buts_buteur != -1) {
                        
                        for (int i = 0; i < size_joueurs; i++) {
                            if (equipe[i].buts == buts_buteur) {
                                afficher_un_joueur(i);
                            }
                        }
                        
                    } else {
                        printf("\nIl n'y a aucun joueur buteur!\n");
                    }

                } else if (strcmp(choix, "5") == 0) {

                    // Afficher le joueur le plus jeune et le plus age
                    afficher_plus_jeune_age(size_joueurs);

                } else if (strcmp(choix, "#") == 0) {

                    break;

                } else {

                    printf("\nInvalid choix!\n");

                }

            }

        } else if (strcmp(choix, "7") == 0) {
            
            // Quitter program
            return 0;

        } else {
            
            printf("\nInvalid choix!\n");

        }
    
    }
}