#include <stdio.h>

typedef struct NhanVien {
    int id;
    char ho_ten[50];
    char chuc_vu[30];
    char so_dt[15];
    struct NhanVien* next;
} NhanVien;

NhanVien* head = NULL;

NhanVien* taoNhanVien(int id, char ho_ten[], char chuc_vu[], char so_dt[]) {
    NhanVien* nv = (NhanVien*)malloc(sizeof(NhanVien));
    nv->id = id;
    strcpy(nv->ho_ten, ho_ten);
    strcpy(nv->chuc_vu, chuc_vu);
    strcpy(nv->so_dt, so_dt);
    nv->next = NULL;
    return nv;
}

void themNhanVien() {
    int id;
    char ho_ten[50], chuc_vu[30], so_dt[15];

    printf("Nhap ID: ");
    scanf("%d", &id);
    getchar();

    printf("Nhap ho ten: ");
    gets(ho_ten);

    printf("Nhap chuc vu: ");
    gets(chuc_vu);

    printf("Nhap so dien thoai: ");
    gets(so_dt);

    NhanVien* nv = taoNhanVien(id, ho_ten, chuc_vu, so_dt);
    nv->next = head;
    head = nv;

    printf("Da them nhan vien!\n");
}


void hienThiDanhSach() {
    if (head == NULL) {
        printf("Danh sach rong.\n");
        return;
    }

    printf("\n\tDANH SACH NHAN VIEN\n");
    printf("%-5s | %-30s | %-20s | %-15s\n", "ID", "Ho ten","Chuc vu", "So DT");

    NhanVien* current = head;
    while (current != NULL) {
        printf("%-5d | %-30s | %-20s | %-15s\n", current->id, current->ho_ten, current->chuc_vu, current->so_dt);
        current = current->next;
    }
}


void xoaNhanVien() {
    if (head == NULL) {
        printf("Danh sach rong.\n");
        return;
    }

    int id;
    printf("Nhap ID nhan vien can xoa: ");
    scanf("%d", &id);

    NhanVien* current = head;
    NhanVien* prev = NULL;

    while (current != NULL && current->id != id) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("=> Khong tim thay nhan vien co ID %d\n", id);
        return;
    }

    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("=> Da xoa nhan vien co ID %d\n", id);
}


void xoaDanhSach() {
    NhanVien* current = head;
    while (current != NULL) {
        NhanVien* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int lua_chon;

    do {
        printf("\n========== MENU ==========\n");
        printf("1. Thêm nhan vien\n");
        printf("2. Hien thi danh sach nhan vien\n");
        printf("3. Xoa nhan vien\n");
        printf("4. Ket thuc\n");
        printf("Chon chuc nang: ");
        scanf("%d", &lua_chon);

        switch (lua_chon) {
            case 1:
                themNhanVien();
                break;
            case 2:
                hienThiDanhSach();
                break;
            case 3:
                xoaNhanVien();
                break;
            case 4:
                xoaDanhSach();
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (lua_chon != 4);

    return 0;
}
