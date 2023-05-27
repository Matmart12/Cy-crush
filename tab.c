#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "main.h"
#define CB_RED "\033[91m"
#define CB_GREEN "\033[92m"
#define CB_YELLOW "\033[93m"
#define CB_BLUE "\033[94m"
#define CB_CYAN "\033[96m"
#define CB_WHITE "\033[37m"
#define CB_PURPLE "\033[95m"

#define BB_RED "\033[41m"
#define BB_DEFAULT "\033[0m"

#define DEUX 2

void buildTab(char **tab, int length, int width, int sign) // programme pour construire le tableau avec sa longueur, sa largeur et son nombre de symboles
{
    int NmbofSymbol;
    for (int i = 0; i < width; i++) // parcourt complet de chaque case du tableau
    {
        for (int j = 0; j < length; j++)
        {
            switch (sign) // configure le nombre de symboles
            {
            case 4:
                NmbofSymbol = rand() % 4;
                break;
            case 5:
                NmbofSymbol = rand() % 5;
                break;
            default:
                NmbofSymbol = rand() % 6;
                break;
            }
            switch (NmbofSymbol) // en fonction du nombre de symboles, génère aléatoirement un symbole parmi ceux possibles pour la case. Les symboles sont : U,X,I,O,L,N.
            {
            case 0:
                tab[i][j] = 'U';
                break;
            case 1:
                tab[i][j] = 'X';
                break;
            case 2:
                tab[i][j] = 'I';
                break;
            case 3:
                tab[i][j] = 'O';
                break;
            case 4:
                tab[i][j] = 'L';
                break;
            default:
                tab[i][j] = 'N';
                break;
            }
        }
    }
}

char buildoneTab(char **tab, int i, int j, int sign) // fonctionne exactement de la même façon que buildTab, mais ne génère que pour une seule case
{
    int NmbofSymbol;
    switch (sign)
    {
    case 4:
        NmbofSymbol = rand() % 4;
        break;
    case 5:
        NmbofSymbol = rand() % 5;
        break;
    default:
        NmbofSymbol = rand() % 6;
        break;
    }
    switch (NmbofSymbol)
    {
    case 0:
        tab[i][j] = 'U';
        break;
    case 1:
        tab[i][j] = 'X';
        break;
    case 2:
        tab[i][j] = 'I';
        break;
    case 3:
        tab[i][j] = 'O';
        break;
    case 4:
        tab[i][j] = 'L';
        break;
    default:
        tab[i][j] = 'N';
        break;
    }
    return tab[i][j];
}

void showTab(char **tab, int length, int width, int score)
{
    printf("\n");
    printf("    ");
    for (int j = 0; j < length; j++)
    {
        printf("%c ", j + 65);
    }
    printf("\n");
    printf("    ");
    for (int j = 0; j < length; j++)
    {
        printf("_ ");
    }
    printf("\n");
    for (int i = 0; i < width; i++)
    {
        if (i + 1 < 10)
        {
            printf("%d | ", i + 1);
        }
        else
        {
            printf("%d| ", i + 1);
        }
        for (int j = 0; j < length; j++)
        {
            switch (tab[i][j])
            {
            case 'U':
                printf("%s%c ", CB_CYAN, tab[i][j]);
                break;
            case 'X':
                printf("%s%c ", CB_RED, tab[i][j]);
                break;
            case 'I':
                printf("%s%c ", CB_PURPLE, tab[i][j]);
                break;
            case 'O':
                printf("%s%c ", CB_GREEN, tab[i][j]);
                break;
            case 'L':
                printf("%s%c ", CB_BLUE, tab[i][j]);
                break;
            case ' ':
                printf("  ");
                break;
            default:
                printf("%s%c ", CB_YELLOW, tab[i][j]);
                break;
            }
        }
        printf("%s\n", CB_WHITE);
    }
    printf("\n");
    printf("score = %d\n\n", score);
}



void showTabTransition(char **tab, char **tab2, int length, int width, int score)
{
    printf("\n");
    printf("    ");
    for (int j = 0; j < length; j++)
    {
        printf("%c ", j + 65);
    }
    printf("\n");
    printf("    ");
    for (int j = 0; j < length; j++)
    {
        printf("_ ");
    }
    printf("\n");
    for (int i = 0; i < width; i++)
    {
        if (i + 1 < 10)
        {
            printf("%d | ", i + 1);
        }
        else
        {
            printf("%d| ", i + 1);
        }
        for (int j = 0; j < length; j++)
        {
            if (tab2[i][j] == ' ')
            {
                switch (tab[i][j])
                {
                case 'U':
                    printf("%s%s%c%s ", BB_RED, CB_CYAN, tab[i][j], BB_DEFAULT);
                    break;
                case 'X':
                    printf("%s%s%c%s ", BB_RED, CB_RED, tab[i][j], BB_DEFAULT);
                    break;
                case 'I':
                    printf("%s%s%c%s ", BB_RED, CB_PURPLE, tab[i][j], BB_DEFAULT);
                    break;
                case 'O':
                    printf("%s%s%c%s ", BB_RED, CB_GREEN, tab[i][j], BB_DEFAULT);
                    break;
                case 'L':
                    printf("%s%s%c%s ", BB_RED, CB_BLUE, tab[i][j], BB_DEFAULT);
                    break;
                default:
                    printf("%s%s%c%s ", BB_RED, CB_YELLOW, tab[i][j], BB_DEFAULT);
                    break;
                }
            }
            else
            {
                switch (tab[i][j])
                {
                case 'U':
                    printf("%s%c ", CB_CYAN, tab[i][j]);
                    break;
                case 'X':
                    printf("%s%c ", CB_RED, tab[i][j]);
                    break;
                case 'I':
                    printf("%s%c ", CB_PURPLE, tab[i][j]);
                    break;
                case 'O':
                    printf("%s%c ", CB_GREEN, tab[i][j]);
                    break;
                case 'L':
                    printf("%s%c ", CB_BLUE, tab[i][j]);
                    break;
                default:
                    printf("%s%c ", CB_YELLOW, tab[i][j]);
                    break;
                }
            }
        }
        printf("%s\n", CB_WHITE);
    }
    printf("\n");
    printf("score = %d\n\n", score);
}



// Fonction de verrification du tableau de jeu, si case vide, alors
char **GravityCol(char **tab, int i, int j, int length, int width, int sign)
{
    if (i == 0)
    {
        if (tab[i][j] == ' ')
        {
            tab[i][j] = buildoneTab(tab, i, j, sign); // ne marche pas sans le programme de victor
        }
        return tab;
    }
    else
    { // la case du tableau est vide et ce n'est pas la première ligne
        char x;
        x = tab[i - 1][j];
        tab[i][j] = x;
        tab[i - 1][j] = ' ';
        return GravityCol(tab, i - 1, j, length, width, sign);
    }
}



int checkSpace(char **tab, int length, int width)
{
    int v = 0;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (tab[i][j] == ' ')
            {
                v = 1;
                break;
            }
        }
    }
    return v;
}



void Gravity(char **tab, int length, int width, int sign, int score)
{
    system("clear");
    showTab(tab, length, width, score);
    usleep(100000);
    while (checkSpace(tab, length, width))
    {
        for (int j = 0; j < length; j++)
        {
            for (int i = width - 1; i >= 0; i--)
            {
                if (tab[i][j] == ' ')
                {
                    tab = GravityCol(tab, i, j, length, width, sign);
                    break;
                }
            }
        }
        system("clear");
        showTab(tab, length, width, score);
        usleep(70000);
    }
}



void destroyTabforStart(char **tab, int length, int width, int sign) // renvoie un tableau qui ne possède pas trois symboles côte à côte en longueur et en largeur
{
    int v1 = 0, v2 = 0, v3 = 0, v4 = 0, v5 = 0, i2, j2;
    while (v1 != 1) // vérifie le tableau tant qu'il n'y a pas un tour sans modification du tableau : le booléen v1 prend 1 comme valeur au début et 0 s'il y a une modification par la suite
    {
        v1 = 1;
        for (int i = 0; i < width; i++) // parcourt le tableau
        {
            for (int j = 0; j < length; j++)
            {
                if ((j >= 1 && j < length - 1) && (tab[i][j] == tab[i][j - 1] && tab[i][j] == tab[i][j + 1])) // teste si trois symboles sont identiques horizontalement
                {
                    v2 = 1;
                }
                if (v2 == 1) // teste les symboles voisins en largeur si v2 vaut 1 (3 symboles identiques en longueur) et les remplace en vide (le vide correspond à un espace ' ' mais est appelé vide car il doit être remplacé ensuite) s'ils sont identiques
                {
                    j2 = j;
                    while ((j2 + 1 < length) && (tab[i][j2 + 1] == tab[i][j])) // teste toutes les cases à droite de la case du tableau où on se trouve actuellement avec le parcours du tableau (tab[i][j]) et les remplace en vide si les symboles des cases sont identiques à celui de la case du tableau où on se trouve actuellement
                    {
                        tab[i][j2 + 1] = buildoneTab(tab, i, j2 + 1, sign);
                        j2++;
                    }
                    j2 = j;
                    while ((j2 - 1 >= 0) && (tab[i][j2 - 1] == tab[i][j])) // puis celles à gauche de la case du tableau où on se trouve actuellement
                    {
                        tab[i][j2 - 1] = buildoneTab(tab, i, j2 - 1, sign);
                        j2--;
                    }
                }                                                                                            // ATTENTION : les annotations suivantes sont identiques au précédentes à la différences qu'elle s'appliquent pour 3 symboles en largeur au lieu de 3 symboles en longueur
                if ((i >= 1 && i < width - 1) && (tab[i][j] == tab[i - 1][j] && tab[i][j] == tab[i + 1][j])) // teste si trois symboles sont identiques verticalement
                {
                    v3 = 1;
                }
                if (v3 == 1) // teste les symboles voisins en largeur si v3 vaut 1 (3 symboles identiques en largeur) et les remplace en vide(le vide correspond à un espace ' ' mais est appelé vide car plus logique) s'ils sont identiques
                {
                    i2 = i;
                    while ((i2 + 1 < width) && (tab[i][j] == tab[i2 + 1][j])) // teste toutes les cases au dessus de la case du tableau où on se trouve actuellement avec le parcours du tableau (tab[i][j]) et les remplace en vide si les symboles des cases sont identiques à celui de la case du tableau où on se trouve actuellement
                    {
                        tab[i2 + 1][j] = buildoneTab(tab, i2 - 1, j, sign);
                        i2++;
                    }
                    i2 = i;
                    while ((i2 - 1 >= 0) && (tab[i][j] == tab[i2 - 1][j])) // puis celles en dessous de la case du tableau où on se trouve actuellement
                    {
                        tab[i2 - 1][j] = buildoneTab(tab, i2 - 1, j, sign);
                        i2--;
                    }
                }
                if (((i >= 1 && i < width - 1) && (j >= 1 && j < length - 1)) && (tab[i][j] == tab[i - 1][j + 1] && tab[i][j] == tab[i + 1][j - 1])) // teste si trois symboles sont identiques diagonalement de bas à gauche en haut à droite
                {
                    v4 = 1;
                }
                if (v4 == 1)
                {
                    i2 = i;
                    j2 = j;
                    while (((i2 - 1 > 0) && (j2 + 1 < length)) && ((tab[i][j] == tab[i2 - 1][j2 + 1]))) // teste toutes les cases au dessus de la case du tableau où on se trouve actuellement avec le parcours du tableau (tab[i][j]) et les remplace en vide si les symboles des cases sont identiques à celui de la case du tableau où on se trouve actuellement
                    {
                        tab[i2 - 1][j2 + 1] = buildoneTab(tab, i2 - 1, j2 + 1, sign);
                        i2--;
                        j2++;
                    }
                    i2 = i;
                    j2 = j;
                    while (((i2 + 1 < width) && (j2 - 1 > 0)) && ((tab[i][j] == tab[i2 + 1][j2 - 1]))) // puis celles en dessous de la case du tableau où on se trouve actuellement
                    {
                        tab[i2 + 1][j2 - 1] = buildoneTab(tab, i2 + 1, j2 - 1, sign);
                        i2++;
                        j2--;
                    }
                }
                if (((i >= 1 && i < width - 1) && (j >= 1 && j < length - 1)) && (tab[i][j] == tab[i - 1][j - 1] && tab[i][j] == tab[i + 1][j + 1])) // teste si trois symboles sont identiques diagonalement de bas à droite en haut à gauche
                {
                    v5 = 1;
                }
                if (v5 == 1)
                {
                    i2 = i;
                    j2 = j;
                    while (((i2 - 1 >= 0) && (j2 - 1 >= 0)) && ((tab[i][j] == tab[i2 - 1][j2 - 1]))) // teste toutes les cases au dessus de la case du tableau où on se trouve actuellement avec le parcours du tableau (tab[i][j]) et les remplace en vide si les symboles des cases sont identiques à celui de la case du tableau où on se trouve actuellement
                    {
                        tab[i2 - 1][j2 - 1] = buildoneTab(tab, i2 - 1, j2 - 1, sign);
                        i2--;
                        j2--;
                    }
                    i2 = i;
                    j2 = j;
                    while (((i2 + 1 < width) && (j2 + 1 < length)) && ((tab[i][j] == tab[i2 + 1][j2 + 1]))) // puis celles en dessous de la case du tableau où on se trouve actuellement
                    {
                        tab[i2 + 1][j2 + 1] = buildoneTab(tab, i2 + 1, j2 + 1, sign);
                        i2++;
                        j2++;
                    }
                }
                if (((v2 == 1) || (v3 == 1)) || ((v4 == 1) || (v5 == 1))) // on execute ce script si on a eu une détection de 3 cases identiques en largeur ou en longueur
                {
                    tab[i][j] = buildoneTab(tab, i, j, sign); // enfin, après avoir changé les cases voisines identiques en vide, on change la case du tableau où on est actuellement en vide aussi
                    v1 = 0, v2 = 0, v3 = 0, v4 = 0, v5 = 0;   // et on remet les booléens à 0
                }
            }
        }
    }
}



int checkSpaceNumber(char **tab2, int width, int length)
{
    int score = 0;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (tab2[i][j] == ' ')
            {
                score++;
            }
        }
    }
    return score;
}



void destroyTab(char **tab, int length, int width, int sign, int score) // renvoie un tableau qui ne possède pas trois symboles côte à côte en longueur et en largeur
{
    int v1 = 0, v2 = 0, v3 = 0, v4 = 0, v5 = 0, i2, j2;
    char **tab2;
    tab2 = malloc((width + 1) * sizeof(char *)); // on fait un tableau de pointeurs pour pouvoir faire un double tableau de caractères
    for (int a = 0; a < width; a++)
    {
        tab2[a] = malloc(length * sizeof(char));
    }
    while (v1 != 1) // vérifie le tableau tant qu'il n'y a pas un tour sans modification du tableau : le booléen v1 prend 1 comme valeur au début et 0 s'il y a une modification par la suite
    {
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < length; j++)
            {
                tab2[i][j] = tab[i][j];
            }
        }
        v1 = 1;
        for (int i = 0; i < width; i++) // parcourt le tableau
        {
            for (int j = 0; j < length; j++)
            {
                if ((j >= 1 && j < length - 1) && (tab[i][j] == tab[i][j - 1] && tab[i][j] == tab[i][j + 1])) // teste si trois symboles sont identiques horizontalement
                {
                    v2 = 1;
                }
                if (v2 == 1) // teste les symboles voisins en largeur si v2 vaut 1 (3 symboles identiques en longueur) et les remplace en vide (le vide correspond à un espace ' ' mais est appelé vide car il doit être remplacé ensuite) s'ils sont identiques
                {
                    tab2[i][j] = ' ';
                    tab2[i][j - 1] = ' ';
                    tab2[i][j + 1] = ' ';
                    v1 = 0, v2 = 0;
                }
                if ((i >= 1 && i < width - 1) && (tab[i][j] == tab[i - 1][j] && tab[i][j] == tab[i + 1][j])) // teste si trois symboles sont identiques verticalement
                {
                    v3 = 1;
                }
                if (v3 == 1) // teste les symboles voisins en largeur si v3 vaut 1 (3 symboles identiques en largeur) et les remplace en vide(le vide correspond à un espace ' ' mais est appelé vide car plus logique) s'ils sont identiques
                {
                    tab2[i][j] = ' ';
                    tab2[i - 1][j] = ' ';
                    tab2[i + 1][j] = ' ';
                    v1 = 0, v3 = 0;
                }
                if (((i >= 1 && i < width - 1) && (j >= 1 && j < length - 1)) && (tab[i][j] == tab[i - 1][j + 1] && tab[i][j] == tab[i + 1][j - 1])) // teste si trois symboles sont identiques diagonalement de bas à gauche en haut à droite
                {
                    v4 = 1;
                }
                if (v4 == 1)
                {
                    tab2[i][j] = ' ';
                    tab2[i - 1][j + 1] = ' ';
                    tab2[i + 1][j - 1] = ' ';
                    v1 = 0, v4 = 0;
                }
                if (((i >= 1 && i < width - 1) && (j >= 1 && j < length - 1)) && (tab[i][j] == tab[i - 1][j - 1] && tab[i][j] == tab[i + 1][j + 1])) // teste si trois symboles sont identiques diagonalement de bas à droite en haut à gauche
                {
                    v5 = 1;
                }
                if (v5 == 1)
                {
                    tab2[i][j] = ' ';
                    tab2[i - 1][j - 1] = ' ';
                    tab2[i + 1][j + 1] = ' ';
                    v1 = 0, v5 = 0;
                }
            }
        }
        score += checkSpaceNumber(tab2, width, length);
        system("clear");
        showTabTransition(tab, tab2, length, width, score);
        sleep(1);
        Gravity(tab2, length, width, sign, score);
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < length; j++)
            {
                tab[i][j] = tab2[i][j];
            }
        }
    }
    tab[width][0] = score;
}



int checkTab(char **tab, int length, int width) // sert à vérifier si un échange est possible dans le tableau
{
    int v = 0;                      // valeur de vérité
    for (int i = 0; i < width; i++) // parcourt le tableau
    {
        for (int j = 0; j < length; j++) // teste si trois symboles sont identiques en largeur ou en longueur et met la valeur de vérité à 1 si c'est le cas
        {
            if ((i >= 1 && i < width - 1) && (tab[i][j] == tab[i - 1][j] && tab[i][j] == tab[i + 1][j]))
            {
                v = 1;
            }
            if ((j >= 1 && j < length - 1) && (tab[i][j] == tab[i][j - 1] && tab[i][j] == tab[i][j + 1]))
            {
                v = 1;
            }
            if (((i >= 1 && i < width - 1) && (j >= 1 && j < length - 1)) && (tab[i][j] == tab[i - 1][j + 1] && tab[i][j] == tab[i + 1][j - 1]))
            {
                v = 1;
            }
            if (((i >= 1 && i < width - 1) && (j >= 1 && j < length - 1)) && (tab[i][j] == tab[i - 1][j - 1] && tab[i][j] == tab[i + 1][j + 1]))
            {
                v = 1;
            }
        }
    }
    return v; // renvoie la valeur de vérité qui sert pour des conditions. Si v vaut 1 (le tableau est échangable), alors la condition if est vraie sinon elle est fausse
}



int checkEnd(char **tab, int length, int width)
{
    char temp1, temp2;
    int v = 0;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (i > 0)
            {
                temp1 = tab[i][j];
                temp2 = tab[i - 1][j];
                tab[i][j] = temp2;
                tab[i - 1][j] = temp1;
                v = checkTab(tab, length, width);
                tab[i][j] = temp1;
                tab[i - 1][j] = temp2;
                if (v == 1)
                {
                    return v;
                }
            }
            if (j > 0)
            {
                temp1 = tab[i][j];
                temp2 = tab[i][j - 1];
                tab[i][j] = temp2;
                tab[i][j - 1] = temp1;
                v = checkTab(tab, length, width);
                tab[i][j] = temp1;
                tab[i][j - 1] = temp2;
                if (v == 1)
                {
                    return v;
                }
            }
            if (i < width - 1)
            {
                temp1 = tab[i][j];
                temp2 = tab[i + 1][j];
                tab[i][j] = temp2;
                tab[i + 1][j] = temp1;
                v = checkTab(tab, length, width);
                tab[i][j] = temp1;
                tab[i + 1][j] = temp2;
                if (v == 1)
                {
                    return v;
                }
            }
            if (j < length - 1)
            {
                temp1 = tab[i][j];
                temp2 = tab[i][j + 1];
                tab[i][j] = temp2;
                tab[i][j + 1] = temp1;
                v = checkTab(tab, length, width);
                tab[i][j] = temp1;
                tab[i][j + 1] = temp2;
                if (v == 1)
                {
                    return v;
                }
            }
        }
    }
    return v;
}



int createLength_and_Width_withoutLimits(int *tab)
{
    printf("%sWARNING: you are in the limitless version of CY-crush.\nYou can create boards of any size you want.\nHowever, the game may run very slowly regularly.\nIf you put a length greater than 32 or a width greater than 99, the game cannot be played and your table will only be displayed.\nIf you put a length greater than 63 or a width greater than 99, the display will not be able to be done correctly but will still be left.\nPress '-1' again to switch back to limit version.%s\n\nATTENTION INFORMATIONS IMPORTANTES : \n-ce jeu est deconseillé au épileptiques\n-il est déconseillé de faire des grands tableaux avec peu de symboles car le programme pourrait ne jamais se terminer\n-ne modifiez pas les fichiers textes associez au programme (length,width,score et tableau).\nSi vous le faites, remettez les anciennes valeurs ou supprimez le fichier (supprimer le fichier vous fera perdre votre sauvegarde).\n\n", CB_RED, CB_WHITE);
    int length = 0, width = 0, trash = 0;
    printf("Select a number of boxes with a length greater than 1: ");
    scanf("%d", &length);
    while (trash != '\n' && trash != EOF)
    {
        trash = getchar();
    }
    trash = 0;
    if (length == -1)
    {
        system("clear");
        return createLength_and_Width(tab);
    }
    while (length < 1)
    {
        printf("Please select a number of boxes with a length greater than 1: ");
        scanf("%d", &length);
        while (trash != '\n' && trash != EOF)
        {
            trash = getchar();
        }
        trash = 0;
        if (length == -1)
        {
            system("clear");
            return createLength_and_Width(tab);
        }
    }
    printf("Select a number of boxes with a width greater than 1: ");
    scanf("%d", &width);
    while (trash != '\n' && trash != EOF)
    {
        trash = getchar();
    }
    trash = 0;
    if (width == -1)
    {
        system("clear");
        return createLength_and_Width(tab);
    }
    while (width < 1)
    {
        printf("Please select a number of boxes with a width greater than 1: ");
        scanf("%d", &width);
        while (trash != '\n' && trash != EOF)
        {
            trash = getchar();
        }
        trash = 0;
        if (width == -1)
        {
            system("clear");
            return createLength_and_Width(tab);
        }
    }
    tab[0] = length;
    tab[1] = width;
    return 0;
}



int createLength_and_Width(int *tab)
{
    printf("You are in the limited version of CY-crush.\nIn this version, the number of squares in length and width is limited to 26.\nPress '-1' when choosing squares in length or width to switch to the version limitless.\n\nATTENTION INFORMATIONS IMPORTANTES : \n-ce jeu est deconseillé au épileptiques\n-il est déconseillé de faire des grands tableaux avec peu de symboles car le programme pourrait ne jamais se terminer\n-ne modifiez pas les fichiers textes associez au programme (length,width,score et tableau).\nSi vous le faites, remettez les anciennes valeurs ou supprimez le fichier (supprimer le fichier vous fera perdre votre sauvegarde).\n\n");
    int width = 0, length = 0, trash = 0;
    printf("Select a number of boxes of length between 1 and 26: ");
    scanf("%d", &length);
    while (trash != '\n' && trash != EOF)
    {
        trash = getchar();
    }
    trash = 0;
    if (length == -1)
    {
        system("clear");
        return createLength_and_Width_withoutLimits(tab);
    }
    while (length < 1 || length > 26)
    {
        printf("Please select a number of boxes of length between 1 and 26: ");
        scanf("%d", &length);
        while (trash != '\n' && trash != EOF)
        {
            trash = getchar();
        }
        trash = 0;
        if (length == -1)
        {
            system("clear");
            return createLength_and_Width_withoutLimits(tab);
        }
    }
    printf("Select a number of boxes of width between 1 and 26: ");
    scanf("%d", &width);
    while (trash != '\n' && trash != EOF)
    {
        trash = getchar();
    }
    trash = 0;
    if (width == -1)
    {
        system("clear");
        return createLength_and_Width_withoutLimits(tab);
    }
    while (width < 1 || width > 26)
    {
        printf("Please select a number of boxes of width between 1 and 26: ");
        scanf("%d", &width);
        while (trash != '\n' && trash != EOF)
        {
            trash = getchar();
        }
        trash = 0;
        if (width == -1)
        {
            system("clear");
            return createLength_and_Width_withoutLimits(tab);
        }
    }
    tab[0] = length;
    tab[1] = width;
    return 0;
}



int createSign(int* tab)
{
    int sign = 0, trash = 0;
    printf("Select a number of symbols between 4 and 6: ");
    scanf("%d", &sign);
    while (trash != '\n' && trash != EOF)
    {
        trash = getchar();
    }
    trash = 0;
    while (sign < 4 || sign > 6)
    {
        printf("Please select a number of symbols between 4 and 6: ");
        scanf("%d", &sign);
        while (trash != '\n' && trash != EOF)
        {
            trash = getchar();
        }
        trash = 0;
    }
    return sign;
}



int wantStop()
{
    int trash = 0;
    char wantStop;
    printf("Do you want to stop here (print 'y' or 'Y' for yes and something else for no) : ");
    wantStop = getchar();
    while (trash != '\n' && trash != EOF)
    {
        trash = getchar();
    }
    if (wantStop == 'Y')
    {
        return 1;
    }
    if (wantStop == 'y')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



char **Placeswitch(char **tab, int length, int width, int score)
{
    int x = 0, y = 0, x2 = 0, y2 = 0, trash = 0, S, H;
    char m1, m2, switchValidate;
    do
    {
        system("clear");
        showTab(tab,length,width,score);
        S = 0, H = 0, switchValidate = 0;
        printf("What's the letter of the first place : ");
        x = getchar(); //prendre la première lettre/chiffre
        while (trash != '\n' && trash != EOF)
        { //vider le buffer
            trash = getchar();
        }
        trash = 0;
        if (x >= 97 && x <= 122)
        {
            x = toupper(x);
        }
        x -= 'A';
        while (x < 0 || x > width - 1)
        {
            printf("Please select again the letter of the first place : ");
            x = getchar();
            while (trash != '\n' && trash != EOF)
            {
                trash = getchar();
            }
            trash = 0;
            if (x >= 97 && x <= 122)
            {
                x = toupper(x);
            }
            x -= 'A';
        }
        printf("Next, what's the number of the first place : ");
        scanf("%d", &y);
        while (trash != '\n' && trash != EOF)
        {
            trash = getchar();
        }
        trash = 0;
        while (y <= 0 || y > width)
        {
            printf("Please select again the number of the first place : ");
            scanf("%d", &y);
            while (trash != '\n' && trash != EOF)
            {
                trash = getchar();
            }
            trash = 0;
        }
        y--;
        printf("La case choisie est (%c,%d).\n\n", (x + 65), (y + 1));
        printf("What's the letter of the second place : ");
        x2 = getchar(); // prendre la première lettre/chiffre
        while (trash != '\n' && trash != EOF)
        { // vider le buffer
            trash = getchar();
        }
        trash = 0; 
        if (x2 >= 97 && x2 <= 122)
        {
            x2 = toupper(x2);
        }
        x2 -= 'A';
        while (x2 < 0 || x2 > width - 1)
        {
            printf("Please, select again the letter of the second place : ");
            x2 = getchar(); // prendre la première lettre/chiffre
            while (trash != '\n' && trash != EOF)
            { // vider le buffer
                trash = getchar();
            }
            trash = 0; 
            if (x2 >= 97 && x2 <= 122)
            {
                x2 = toupper(x2);
            }
            x2 -= 'A';
        }
        printf("Next, what's the number of the second place : ");
        scanf("%d", &y2);
        while (trash != '\n' && trash != EOF)
        {
            trash = getchar();
        }
        trash = 0;
        while (y2 <= 0 || y2 > width)
        {
            printf("Please select again the number of the second place : ");
            scanf("%d", &y2);
            while (trash != '\n' && trash != EOF)
            {
                trash = getchar();
            }
            trash = 0;
        }
        y2--;
        if((x!=x2+1 && x!=x2-1 && x!= x2) || (y!=y2+1 && y!=y2-1 && y!= y2)||(x==x2+1 && y==y2+1)||(x==x2-1 && y==y2+1)||(x==x2+1 && y==y2-1)||(x==x2-1 && y==y2-1)){
            printf("Try again to switch caracter's places in 3 secondes.\n");
        sleep(3);
        }
        } while ((x!=x2+1 && x!=x2-1 && x!= x2) || (y!=y2+1 && y!=y2-1 && y!= y2)||(x==x2+1 && y==y2+1)||(x==x2-1 && y==y2+1)||(x==x2+1 && y==y2-1)||(x==x2-1 && y==y2-1));

        printf("La case choisie est (%c,%d).\n\n", (x2 + 65), (y2 + 1));
        printf("Est-ce bien cette case que vous avez choisi ? (print 'y' or 'Y' for yes and something else for no) : ");
        switchValidate = getchar();
        while (trash != '\n' && trash != EOF)
        { // vider le buffer
            trash = getchar();
        }
        trash = 0;
        printf("\n");
        if(switchValidate != 'y' && switchValidate != 'Y')
        {
            H = 1;
        }
        else if(x == x2 && y == y2)
        { // vérifier que les deux soit différents
            S = 1;
            printf("Same case! Try again!\n");
        }
        else
        {
            m1 = tab[y][x];
            m2 = tab[y2][x2];
            tab[y][x] = m2;
            tab[y2][x2] = m1;
            if (checkTab(tab, length, width))
            { // vérifier que l'on peut détruire après l'échange
                return tab;
            }
            else
            {
                tab[y2][x2] = m2;
                tab[y][x] = m1;
                H = 1;
                printf("Cannot destroy anything! Try again!\n");
            }
        }
    }



int roundNumber()
{
    int roundNumber = 0;
    char roundValidate, trash = 0;
    printf("Do you want to define a number of round(s) ? (print 'y' or 'Y' for yes and something else for no) : ");
    roundValidate = getchar();
    while (trash != '\n' && trash != EOF)
    {
        trash = getchar();
    }
    trash = 0;
    if(roundValidate == 'y' || roundValidate == 'Y')
    {
        while(roundNumber <= 0)
        {
            printf("choose a number of round(s) higher than 0 : ");
            scanf("%d",&roundNumber);
            while (trash != '\n' && trash != EOF)
            {
                trash = getchar();
            }
            trash = 0;
        }
        return roundNumber;
    }
    else
    {
        return -1;
    }
}



// Fonction pour sauvegarder le score dans un fichier
void saveScore(int score) 
{
    FILE* fichier = fopen("score.txt", "w");
    if (fichier != NULL) 
    {
        fprintf(fichier, "%d", score);
        fclose(fichier);
        printf("Score sauvegardé avec succès.\n");
    } 
    else 
    {
        printf("error with the opening of the score file.\n");
    }
}



void saveLength(int length) 
{
    FILE* fichier = fopen("length.txt", "w");
    if (fichier != NULL) 
    {
        fprintf(fichier, "%d", length);
        fclose(fichier);
    } 
    else 
    {
        printf("error with the opening of the length file.\n");
    }
}



void saveWidth(int width) 
{
    FILE* fichier = fopen("width.txt", "w");
    if (fichier != NULL) 
    {
        fprintf(fichier, "%d", width);
        fclose(fichier);
    } 
    else 
    {
        printf("error with the opening of the width file.\n");
    }
}



// Fonction pour sauvegarder le tableau de bonbons dans un fichier
void saveTab(char** tab, int length, int width) {
    FILE* fichier = fopen("tab.txt", "w");
    if (fichier != NULL) {
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < length; j++) {
                fprintf(fichier, "%c", tab[i][j]);
            }
            fprintf(fichier, "\n");
        }
        fclose(fichier);
        printf("Tab successfuly loaded.\n");
    } 
    else 
    {
        printf("error with the opening of the tab file.\n");
    }
}



void saveGame(char** tab, int length, int width, int score)
{
    char saveValidate = 0, trash = 0;
    printf("Do you want to save your actual game ? (print 'y' or 'Y' for yes and something else for no) : ");
    saveValidate = getchar();
    while (trash != '\n' && trash != EOF)
    {
        trash = getchar();
    }
    trash = 0;
    if(saveValidate == 'y' || saveValidate == 'Y')
    {
        saveLength(length);
        saveWidth(width);
        saveScore(score);
        saveTab(tab,length,width);
    }
    printf("\n");
}  



// Fonction pour charger le score à partir d'un fichier
int loadScore() {
    int score = 0;
    FILE* fichier = fopen("score.txt", "r");
    if (fichier != NULL) 
    {
        fscanf(fichier, "%d", &score);
        fclose(fichier);
        printf("Score successfuly loaded.\n");
    } 
    else 
    {
        printf("error with the opening of the score file.\n");
    }
    return score;
}



int loadLength() {
    int length = 0;
    FILE* fichier = fopen("length.txt", "r");
    if (fichier != NULL) 
    {
        fscanf(fichier, "%d", &length);
        fclose(fichier);
    } 
    else 
    {
        printf("error with the opening of the length file.\n");
    }
    return length;
}



int loadWidth() {
    int width = 0;
    FILE* fichier = fopen("width.txt", "r");
    if (fichier != NULL) 
    {
        fscanf(fichier, "%d", &width);
        fclose(fichier);
    } 
    else 
    {
        printf("error with the opening of the width file.\n");
    }
    return width;
}



// Fonction pour charger le tableau de bonbons à partir d'un fichier
void loadTab(char** tab, int length, int width) {
    FILE* fichier = fopen("tab.txt", "r");
    if (fichier != NULL) {
        for (int i = 0; i < width; i++) 
        {
            for (int j = 0; j < length; j++) 
            {
                fscanf(fichier, "%c", &tab[i][j]);
            }
            fscanf(fichier, "\n");
        }
        fclose(fichier);
        printf("Tab successfuly loaded.\n");
    } 
    else 
    {
        printf("error with the opening of the tab file.\n");
    }
}



int wantLoadGame()
{
    char loadValidate = 0, trash = 0;
    printf("Do you want to load the game you save ? (print 'y' or 'Y' for yes and something else for no) : ");
    loadValidate = getchar();
    while (trash != '\n' && trash != EOF)
    {
        trash = getchar();
    }
    trash = 0;
    if(loadValidate == 'y' || loadValidate == 'Y')
    {
        return 1;
    }
    else
    {
        return 0;    
    }

}



void loadGame(char** tab, int length, int width)
{
    int score = loadScore();
    loadTab(tab,length,width);
    tab[width][0] = score;
}



void game(char** tab,int length, int width, int sign, int score, int roundNmb)
{
    while (checkEnd(tab, length, width))
    {
        tab = Placeswitch(tab, length, width, score);
        showTab(tab, length, width, score);
        destroyTab(tab, length, width, sign, score);
        score = tab[width][0];
        roundNmb--;
        if(roundNmb < 0)
        {
            //ne rien faire
        }
        else if(roundNmb == 0)
        {
            printf("Game's Over!\n\n");
            break;
        }
        else
        {
            printf("You have %d rounds.\n\n",roundNmb);
        }
        saveGame(tab,length,width,score);
        if (wantStop())
        {
            printf("\n");
            break;
        }
    }
}


int checkGame()
{
    int gameExist;
    FILE* fichier = fopen("score.txt", "r");
    if(fichier != NULL)
    {
        fclose(fichier);
        FILE* fichier = fopen("length.txt", "r");
        if(fichier != NULL)
        {
            fclose(fichier);
            FILE* fichier = fopen("width.txt", "r");
            if(fichier != NULL)
            {
                fclose(fichier);
                FILE* fichier = fopen("tableau.txt", "r");
                if(fichier != NULL)
                {
                    fclose(fichier);
                    return 1;
                }
            }
        }
    }
    return 0;
}



int savehighscore(int score){
    FILE *file = fopen("highscore.txt", "w"); //Ouvrir le fichier highscore en mode lecture
    if (file == NULL) {
        printf("Impossible to create highscore's file.\n");
        fclose(file);
        return 1;
    }
    FILE *tempFile = fopen("temp_highscore.txt", "w"); //Créer un nouveau fichier temporaire en mode écriture
    if (tempFile == NULL) {
        printf("Impossible to create temporary file.\n");
        fclose(file);
        return 1;
    }
    char newName[256];//pour avoir le nom de la personne
    printf("what's your name/surname?\n");
    scanf("%s", newName);
    // Lire le contenu du fichier highscore ligne par ligne
    char buffer[256];
    int scoreUpdated = 0; // Indicateur pour savoir si le score a été mis à jour

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        char *name = strtok(buffer, ",");
        char *scoreStr = strtok(NULL, ",");
        int scoreecr = atoi(scoreStr);
        if (scoreecr < score && !scoreUpdated) {// Vérifier si le score actuel est inférieur au nouveau score
            scoreecr = score;// Modifier le score
            strcpy(name, newName); // Mettre à jour le nom si nécessaire
            scoreUpdated = 1; // Indiquer que le score a été mis à jour
        }
        fprintf(tempFile, "%s,%d\n", name, score); // Écrire les données modifiées dans le fichier temporaire   
    }
    if (!scoreUpdated) {
        fprintf(tempFile, "%s,%d\n", newName, score);// Si le score n'a pas encore été mis à jour et qu'il n'y a plus de scores à lire
    // Ajouter le nouveau score à la fin de la liste
    }
    fclose(file);
    fclose(tempFile);
    remove("highscore.txt");// Supprimer l'ancien fichier highscore
    rename("temp_highscore.txt", "highscore.txt");// Renommer le fichier temporaire avec le nom de l'ancien fichier highscore
    return 1;
}



void loadhighscore(){
    int linemax=10;
    int linepr=0;
     FILE *file = fopen("highscore.txt", "r"); //Ouvrir le fichier highscore en mode lecture
    if (file == NULL) {
        printf("Impossible to read the file.\n");
        fclose(file);
        return 1;
    }
    char line[256];
    while(fgets(line,sizeof(line),file)!=NULL &&linepr<linemax){
        printf("%s", line);
        linepr++;
    }
    fclose(file);
}



void changeHour(int totalTime)
{
    int hours, minutes, seconds;
    if(totalTime < 60)
    {
        printf("Vous avez joué %d seconde(s).\n\n",totalTime);    
    }
    else if(totalTime < 3600)
    {
        minutes = totalTime / 60;
        seconds = (totalTime % 3600) % 60;
        printf("Vous avez joué %d minute(s) et %d seconde(s).\n\n",minutes,seconds);
    }
    else
    {
        hours = seconds / 3600;
        minutes = (seconds % 3600) / 60;
        seconds = (totalTime % 3600) % 60;
        printf("you played %d hour(s), %d minute(s) et %d second(s).\n\n",hours,minutes,seconds);
    }
}
