#include <stdio.h>

#define MAX 100

void nhapMaTran(int a[][MAX], int dong, int cot) {
    printf("Nhap gia tri cho ma tran (%d x %d):\n", dong, cot);
    for(int i = 0; i < dong; i++) {
        for(int j = 0; j < cot; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void hienthi(int a[][MAX], int dong, int cot) {
    for(int i = 0; i < dong; i++) {
        for(int j = 0; j < cot; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

void tichHaiMaTran(int a1[][MAX], int a2[][MAX], int a3[][MAX], int dong1, int cot1, int cot2) {
    for(int i = 0; i < dong1; i++) {
        for(int j = 0; j < cot2; j++) {
            a3[i][j] = 0;
            for(int k = 0; k < cot1; k++) {
                a3[i][j] += a1[i][k] * a2[k][j];
            }
        }
    }
}

void menu() {
    printf("\n========= MENU =========\n");
    printf("1. Nhap hai ma tran A va B\n");
    printf("2. Tinh tich A * B -> C\n");
    printf("3. Hien thi A, B, va C\n");
    printf("0. Thoat\n");
    printf("========================\n");
    printf("Lua chon cua ban: ");
}

int main() {
    int a1[MAX][MAX], a2[MAX][MAX], a3[MAX][MAX];
    int dong1 = 0, cot1 = 0;
    int dong2 = 0, cot2 = 0;
    int daCoKetQua = 0;

    while(1) {
        menu();
        int c;
        scanf("%d", &c);
        switch(c) {
            case 1:
                printf("\n--- Nhap Ma Tran A ---\n");
                printf("Nhap so dong va cot: ");
                scanf("%d%d", &dong1, &cot1);
                nhapMaTran(a1, dong1, cot1);

                printf("\n--- Nhap Ma Tran B ---\n");
                printf("Nhap so dong va cot: ");
                scanf("%d%d", &dong2, &cot2);
                nhapMaTran(a2, dong2, cot2);
                daCoKetQua = 0;
                break;

            case 2:
                if (cot1 != dong2) {
                    printf("Khong the nhan! So cot cua A (%d) khac so dong cua B (%d).\n", cot1, dong2);
                } else {
                    tichHaiMaTran(a1, a2, a3, dong1, cot1, cot2);
                    printf("Da tinh xong tich hai ma tran!\n");
                    daCoKetQua = 1;
                }
                break;

            case 3:
                printf("\n--- Ma Tran A ---\n");
                hienthi(a1, dong1, cot1);

                printf("\n--- Ma Tran B ---\n");
                hienthi(a2, dong2, cot2);

                if (daCoKetQua) {
                    printf("\n--- Ma Tran C = A * B ---\n");
                    hienthi(a3, dong1, cot2);
                } else {
                    printf("\nChua co ket qua! Hay chon '2' de tinh tich truoc.\n");
                }
                break;

            case 0:
                printf("Tam biet!\n");
                return 0;

            default:
                printf("Lua chon khong hop le. Vui long chon tu 0 den 3.\n");
                break;
        }
    }

    return 0;
}
