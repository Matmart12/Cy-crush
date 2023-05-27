#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
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




void main()
{
    srand(time(NULL));
    time_t begin = time(NULL);
    int tab2[DEUX], length, width, sign, totalTime, roundNmb, score = 0, loadScore; // longueur, largeur, nombre de symboles
    char** tab;
    if(checkGame())
    {
        if(wantLoadGame())
        {
            length = loadLength();
            width = loadWidth(); 
            tab = malloc(width * sizeof(char*));
            for (int i = 0; i < width; i++)
            {
                tab[i] = malloc(length * sizeof(char));
            }
            tab[width] = malloc(length * sizeof(int));
            loadGame(tab,length,width);
            roundNmb = roundNumber();
        }
        else
        {
            system("clear");
            createLength_and_Width(tab2);
            length = tab2[0];
            width = tab2[1];
            sign = createSign(tab2);
            roundNmb = roundNumber();
            tab = malloc(width * sizeof(char*));
            for (int i = 0; i < width; i++)
            {
                tab[i] = malloc(length * sizeof(char));
            }
            tab[width] = malloc(length * sizeof(int));
            buildTab(tab, length, width, sign);
            destroyTabforStart(tab, length, width, sign);
        }
    }
    else
    {
        system("clear");
        createLength_and_Width(tab2);
        length = tab2[0];
        width = tab2[1];
        sign = createSign(tab2);
        roundNmb = roundNumber();
        tab = malloc(width * sizeof(char*));
        for (int i = 0; i < width; i++)
        {
            tab[i] = malloc(length * sizeof(char));
        }
        tab[width] = malloc(length * sizeof(int));
        buildTab(tab, length, width, sign);
        destroyTabforStart(tab, length, width, sign);
    }
    score = tab[width][0];
    showTab(tab, length, width, score);
    
    if(length<=32 && width<=99)
    {   
        game(tab,length,width,sign,score,roundNmb);
    }
    savehighscore(score);
    loadhighscore();
    time_t end = time(NULL);
    totalTime = end - begin;
    changeHour(totalTime);
    free(tab);
}
