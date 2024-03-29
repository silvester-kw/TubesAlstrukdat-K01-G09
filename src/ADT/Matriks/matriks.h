#ifndef MATRIKS_H
#define MATRIKS_H

/* Kamus Umum */

#define IndxUndef ' '  /* indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */

typedef struct
	{
		int TM[5][5]; /* memori tempat penyimpan elemen (container) */
		int Ceff; /* banyaknya elemen efektif */
	} matriks;

/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses:
 * T.Ceff untuk mengetahui banyaknya elemen
 * T.TI untuk mengakses seluruh nilai elemen tabel
 * T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
 * Tabel kosong: T.Ceff = 0
 * Definisi elemen pertama : T.TI[i] dengan i=1
 * Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Ceff */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmptyMatriks (matriks *T);
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */

void Display(matriks M);
/* I.S. sembarang */
/* F.S. Mencetak matriks dengan letak snake yang sudah dalam koordinat */

#endif