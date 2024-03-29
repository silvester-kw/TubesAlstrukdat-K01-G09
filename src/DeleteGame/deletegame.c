#include "deletegame.h"

void DELETEGAME (Tab *daftargame, Queue queuegame, TabMap *listscoreboard, Stack *history) {
    LISTGAME(*daftargame);

    printf("\nMasukkan nomor game yang akan dihapus >> ");
    STARTCOMMAND2();

    boolean valid = true, found = false;
    int i = 0, nomor;
    ElType antriangame;
    WordType namagame;

    while ((valid) && (i < CommandCC.Length)) {
        if ((CommandCC.TabWord[i] < '0') || (CommandCC.TabWord[i] > '9')) {
            valid = false;
        }
        i++;
    }

    if (!valid) {
        printf("\nMasukan nomor game tidak valid.\n");
    } else {
        nomor = 0;
        for (i = 0; i < CommandCC.Length; i++) {
            nomor = nomor*10 + (CommandCC.TabWord[i] - '0');
        }

        if (((nomor >= 0) && (nomor <= 5)) || (nomor > (*daftargame).Neff)) {
            printf("\nGame gagal dihapus.\n");
        } else {
            namagame = GetElmtArray(*daftargame, nomor-1);
            while ((!isEmpty(queuegame)) && (!found)) {
                dequeue(&queuegame, &antriangame);
                if (IsWordSame(namagame, antriangame)) {
                    found = true;
                }
            }
            if (found) {
                printf("\nGame gagal dihapus.\n");
            } else {
                for (i = nomor; i < (*daftargame).Neff; i++) {
                    (*daftargame).TI[i-1] = (*daftargame).TI[i];
                }
                (*daftargame).Neff--;
                DeleteArrMap(listscoreboard, nomor-1);
                DELETEHISTORY(history, namagame);
                printf("\nGame berhasil dihapus.\n");
            }
        }
    }
}
/* Proses : Menerima input nomor game yang ingin dihapus
            Game yang dapat dihapus hanya game yang dibuat secara custom oleh pengguna 
            Apabila input game merupakan salah satu dari 5 game pertama pada daftar game, maka game gagal dihapus
            Apabila input game merupakan salah satu dari game yang terdapat dalam queue game, maka game gagal dihapus */
/* I.S. Daftar game dan queue game terdefinisi */
/* F.S. Daftar game berkurang jika game berhasil dihapus atau tetap jika game gagal dihapus */