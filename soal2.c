/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 * Modul           : 3 - Structures & Dynamic Arrays
 * Hari dan Tanggal    : Senin, 27 April 2026
 * Nama (NIM)          : Aqilah Safitri Sjarif (13224050)
 * Nama File           : soal1.c
 * Deskripsi           : ngurutin meteor
 */
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct Meteor {
    char nama[50];
    int massa;
    int kemurnian;
} Meteor;

int main(){
    int N;
    scanf("%d", &N);
    
    Meteor *list = (Meteor*) malloc(N * sizeof(Meteor));
    
    for (int i = 0; i < N; i++){
        scanf("%s", list[i].nama);
        scanf("%d", &list[i].massa);
        scanf("%d", &list[i].kemurnian);
    }
    
    for (int i = 0; i < N - 1; i++){
        for (int j = 0; j < N - i - 1; j++){
            int tukar = 0;
            if (list[j].kemurnian < list[j+1].kemurnian) {
                tukar = 1;
            } else if (list[j].kemurnian == list[j+1].kemurnian) {
                if (list[j].massa > list[j+1].massa) {
                    tukar = 1;
                } else if (list[j].massa == list[j+1].massa) {
                    if (strcmp(list[j].nama, list[j+1].nama) > 0) {
                        tukar = 1;
                    }
                }
            }
            if (tukar == 1) {
                Meteor temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
    
    for (int i = 0; i < 3; i++){
        printf("%s %d %d\n", list[i].nama, list[i].massa, list[i].kemurnian);
    }

    free(list);
    return 0;
}
