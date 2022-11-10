#include <stdio.h>
#include "skipgame.h"


void SKIPGAME(Word n, Queue *q){
    int i, hasil = 0;
    boolean valid = true;
    ElType namagame;

    printf("Berikut adalah daftar antrian game-mu\n");
    displayQueueGame(*q);

    while ((valid) && (i < n.Length)) {
        if ((n.TabWord[i] < '0') || (n.TabWord[i] > '9')) {
            valid = false;
        }
    }

    if (!valid) {
        printf("\nMasukan banyak game yang diskip tidak valid.\n");
    } else {
        for (i = 0; i < n.Length; i++) {
            hasil = hasil*10 + (n.TabWord[i] - '0');
        }

        if (hasil < length(*q)) {
            for (i = 0; i < hasil; i++) {
                dequeue(q, &namagame);
            }
            PLAYGAME(q);
        } else {
            printf("\nTidak ada permainan lagi dalam daftar antrian game-mu.\n");
        }
    }
}