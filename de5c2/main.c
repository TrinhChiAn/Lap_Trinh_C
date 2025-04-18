/*Câu 2: Viết chương trình sử dụng kiểu nhập xuất nhị phân với tệp có tên là DS_SV.C để ghi danh sách các sinh viên có cấu trúc gồm các thành phần: maSV, ho_ten, nam_sinh. Chương trình được tổ chức thành các chương trình con sau:

  1) Tạo danh sách sinh viên lên tệp DS_Sv.
  2) Hiển thị danh sách sinh viên trên tệp theo:

             DANH SACH SINH VIEN

        STT         Ma SV      Ho ten       Nam sinh

……………..


  3) Sửa thông tin (họ tên, năm sinh) của một sinh viên (với mã SV được nhập từ bàn
    phím)
  Hàm main() hiển thị menu để chọn các chức năng băng cách nhập số tương ứng như sau:
      1. Tao danh sach
      2. Hien danh sach
      3. Sua thong tin sinh vien
      4. Ket thuc

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char MaSV[30];
    char HoTen[50];
    int NamSinh;
} SV;

void suaThongTin() {
    FILE *f = fopen("DS_SV.C", "rb");
    if (f == NULL) {
        printf("Khong the mo file de doc!\n");
        return;
    }

    SV ds[100];
    int n = 0;


    while (fread(&ds[n], sizeof(SV), 1, f)) {
        n++;
    }
    fclose(f);

    char masvCanSua[30];
    int found = 0;
    printf("Nhap ma sinh vien can sua: ");
    fflush(stdin);
    gets(masvCanSua);

    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].MaSV, masvCanSua) == 0) {
            found = 1;
            printf("Thong tin hien tai:\n");
            printf("Ma SV: %s\n", ds[i].MaSV);
            printf("Ho ten: %s\n", ds[i].HoTen);
            printf("Nam sinh: %d\n", ds[i].NamSinh);

            printf("Nhap ho ten moi: ");
            fflush(stdin);
            gets(ds[i].HoTen);
            printf("Nhap nam sinh moi: ");
            scanf("%d", &ds[i].NamSinh);
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien!\n");
        return;
    }

    f = fopen("DS_SV.C", "wb");
    if (f == NULL) {
        printf("Khong the mo file de ghi!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fwrite(&ds[i], sizeof(SV), 1, f);
    }

    fclose(f);
    printf("Da cap nhat thong tin thanh cong!\n");
}
void writeFile() {
    FILE *f;
    f = fopen("DS_SV.C", "wb");
    if (f == NULL) {
        printf("Khong the mo file de ghi!\n");
        return;
    }

    SV sv;
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin sinh vien %d\n", i + 1);
        printf("Ma SV: ");
        fflush(stdin);
        gets(sv.MaSV);
        printf("Ho ten: ");
        gets(sv.HoTen);
        printf("Nam sinh: ");
        scanf("%d", &sv.NamSinh);

        fwrite(&sv, sizeof(SV), 1, f);
    }

    fclose(f);
}

void readFile() {
    FILE *f;
    f = fopen("DS_SV.C", "rb");
    if (f == NULL) {
        printf("Khong the mo file de doc!\n");
        return;
    }

    SV sv;
    int i = 0;

    printf("%5s | %-20s | %-30s | %-10s\n", "STT", "Ma SV", "Ho ten", "Nam sinh");
    printf("-------------------------------------------------------------------------\n");

    while (fread(&sv, sizeof(SV), 1, f)) {
        printf("%5d | %-20s | %-30s | %-10d\n", ++i, sv.MaSV, sv.HoTen, sv.NamSinh);
    }

    fclose(f);
}

void menu() {
    printf("1. Nhap du lieu sinh vien\n");
    printf("2. Hien thi danh sach sinh vien\n");
    printf("3. Sua thong tin sinh vien\n");
    printf("4. Thoat\n");
    printf("Lua chon: ");
}

int main() {
    int c;
    do {
        menu();
        scanf("%d", &c);
        switch (c) {
            case 1:
                writeFile();
                system("pause");
                system("cls");
                break;
            case 2:
                readFile();
                system("pause");
                system("cls");
                break;
            case 3:
                suaThongTin();
                break;
            case 4:
                exit(0);
            default:
                printf("Vui long chon tu 1 den 3!\n");
        }
    } while (c > 0 && c < 4);

    return 0;
}
