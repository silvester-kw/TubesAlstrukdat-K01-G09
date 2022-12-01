#include "playgame.h"
#include <stdio.h>

void PLAYGAME(Queue *queuegame, TabMap *TM, Tab T, Stack *S) {
    ElType game;
    int i=0,skor=-1;
    boolean found;
    Map M;

    dequeue(queuegame, &game);

    insertHistory(S, game);

    printf("Loading ");
    PrintWord(game);
    printf(" ...\n");

    found = false;
    while (!found && i < NbElmtArray(T)) {
        if (IsWordSame(game, T.TI[i])) {
            found = true;
        } else {
            i++;
        }
    }
    if (i == 0){
        RNGGAME(&skor);
    } else if (i == 1){
        DINNERDASH(&skor);
    } else if (i == 2){
        HANGMAN(&skor);
    } else if (i == 3){
        TOWEROFHANOI(&skor);
    } else if (i == 4){
        SNAKEONMETEOR(&skor);
    } else {
        SKORGAME(&skor);
    }
    if (skor>=0){
        INSERTSCOREBOARD(skor,TM,i);
    }
    // TAMBAH KE HISTORY
}
/*
I.S. Daftar antrian game terdefinisi
F.S. Game pertama pada daftar antrian game dimainkan
*/