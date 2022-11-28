#include <stdio.h>
#include "ToH.h"
#include "towerofhanoi.h"

void TOWEROFHANOI(int *skor) {
    printf("\n========================================================================================================\n");
    printf(" _____    ___   __        __  _____   ____       ___    _____     _   _      _      _   _    ___    ___ \n");
    printf("|_   _|  / _ \\  \\ \\      / / | ____| |  _ \\     / _ \\  |  ___|   | | | |    / \\    | \\ | |  / _ \\  |_ _|\n");
    printf("  | |   | | | |  \\ \\ /\\ / /  |  _|   | |_) |   | | | | | |_      | |_| |   / _ \\   |  \\| | | | | |  | | \n");
    printf("  | |   | |_| |   \\ V  V /   | |___  |  _ <    | |_| | |  _|     |  _  |  / ___ \\  | |\\  | | |_| |  | | \n");
    printf("  |_|    \\___/     \\_/\\_/    |_____| |_| \\_\\    \\___/  |_|       |_| |_| /_/   \\_\\ |_| \\_|  \\___/  |___|\n\n");
    printf("========================================================================================================\n\n\n");

    int step = 0;
    int piringan;
    char src, dst;
    Stack A, B, C;
    Word in1, in2;
    CreateSEmpty(&A);
    CreateSEmpty(&B);
    CreateSEmpty(&C);

    do {
        printf("Masukkan jumlah piringan >> ");
        Scan(&in1, &in2);
        if (in2.Length == 0) {
            GetInt(in1, &piringan);
        } else {
            piringan = 0;
        }
    } while (!IsPiringanValid(piringan));
    
    InisialisasiS(&A, piringan);

    printf("\n");
    while (!GameFinish(C, piringan)) {
        DisplayStack(A, piringan);
        for (int l = 0; l < piringan-1; l++) {
            printf(" ");
        }
        printf("A\n\n");
        DisplayStack(B, piringan);
        for (int m = 0; m < piringan-1; m++) {
            printf(" ");
        }
        printf("B\n\n");
        DisplayStack(C, piringan);
        for (int n = 0; n < piringan-1; n++) {
            printf(" ");
        }
        printf("C\n\n");
        boolean done = false;

        do {
            do {
                printf("TIANG ASAL >> ");
                Scan(&in1, &in2);
                GetChar(in1, in2, &src);
                printf("TIANG TUJUAN >> ");
                Scan(&in1, &in2);
                GetChar(in1, in2, &dst);
            } while (!IsInputValid(src, dst));
        } while (!IsCommandSValid(src, dst, A, B, C));
        ProsesCommandS(src, dst, &A, &B, &C);
        step++;
    }
    DisplayStack(A, piringan);
    for (int l = 0; l < piringan-1; l++) {
        printf(" ");
    }
    printf("A\n\n");
    DisplayStack(B, piringan);
    for (int m = 0; m < piringan-1; m++) {
        printf(" ");
    }
    printf("B\n\n");
    DisplayStack(C, piringan);
    for (int n = 0; n < piringan-1; n++) {
        printf(" ");
    }
    printf("C\n\n");

    printf("\nSelamat, Anda berhasil!\n\n");
    *skor = CountScore(step, piringan);
    printf("\n===============================\n");
    printf("||     G A M E   O V E R     ||\n");
    printf("===============================\n\n");
    printf("Skor akhir = %d\n\n", *skor);
}