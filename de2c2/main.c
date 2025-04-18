/*
Viết chương trình tạo ra một danh tách liên kết thuận để quân lý đanh
sách điểm thi THPT khối A01. Cầu trúc gồm các thành phẩn so bao_danh, ho ten,
diem_toan, diem_ly, diem_tieng_anh, tong diem. Chương trình được tổ chức thành các chương trình con sau:
  1) Tạo danh sách diem thi 
  2) Hiển thị danh sách ra mản hình theo dạng:

       DANH SACH DIEM THI THPT

      STT    SBD     Ho ten     Diem Toan     Diem Ly     Diem TA      Tong
  3) Sắp xếp danh sách điểm thi theo từmg điểm và theo tổng điểm (có danh sách để
 lựa chọn) 

Hàm main() hiển thị menu để chọn các chức năng bằng cách nhập số tương ứng như sau:
      1. Tao danh sach thi sinh
      2. Hien thi danh sach thi sinh
      3. Sap xep diem thi
      4. Ket thuc
*/

#include <stdio.h>

typedef struct ThiSinh
{
    char sbd[15];
    char ho_ten[50];
    float diem_toan, diem_ly, diem_ta, tong_diem;
    struct ThiSinh* next;
} ThiSinh;

ThiSinh* head = NULL;

ThiSinh* taoThiSinh(char sbd[], char ho_ten[], float toan, float ly, float ta)
{
    ThiSinh* ts = (ThiSinh*)malloc(sizeof(ThiSinh));
    strcpy(ts->sbd, sbd);
    strcpy(ts->ho_ten, ho_ten);
    ts->diem_toan = toan;
    ts->diem_ly = ly;
    ts->diem_ta = ta;
    ts->tong_diem = toan + ly + ta;
    ts->next = NULL;
    return ts;
}

void themThiSinh()
{
    char sbd[15], ho_ten[50];
    float toan, ly, ta;

    printf("Nhap so bao danh: ");
    scanf("%s", sbd);
    getchar();

    printf("Nhap ho ten: ");
    fgets(ho_ten, sizeof(ho_ten), stdin);
    ho_ten[strcspn(ho_ten, "\n")] = 0;

    printf("Nhap diem Toan: ");
    scanf("%f", &toan);
    printf("Nhap diem Ly: ");
    scanf("%f", &ly);
    printf("Nhap diem Tieng Anh: ");
    scanf("%f", &ta);

    ThiSinh* ts = taoThiSinh(sbd, ho_ten, toan, ly, ta);
    ts->next = head;
    head = ts;

    printf("=> Da them thi sinh!\n");
}

void hienThiDanhSach()
{
    if (head == NULL)
    {
        printf("Danh sach rong.\n");
        return;
    }

    printf("\n\tDANH SACH DIEM THI THPT\n");
    printf("%-5s | %-10s | %-30s | %-10s | %-10s | %-10s | %-10s\n", "STT","SBD","Ho ten", "Toan", "Ly", "TA", "Tong");

    ThiSinh* current = head;
    int stt = 1;
    while (current != NULL)
    {
        printf("%-5d | %-10s | %-30s | %-10.2f | %-10.2f | %-10.2f | %-10.2f\n",
               stt++, current->sbd, current->ho_ten,
               current->diem_toan, current->diem_ly, current->diem_ta, current->tong_diem);
        current = current->next;
    }
}

void hoanDoi(ThiSinh* a, ThiSinh* b)
{
    ThiSinh temp = *a;
    *a = *b;
    *b = temp;

    ThiSinh* tmp2 = a->next;
    a->next = b->next;
    b->next = tmp2;
}

void sapXep(int lua_chon) {
    if (head == NULL || head->next == NULL) {
        printf("Danh sach it hon 2 thi sinh.\n");
        return;
    }

    ThiSinh* i, *j;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            int flag = 0;
            switch (lua_chon) {
                case 1:
                    if (i->diem_toan < j->diem_toan) flag = 1;
                    break;
                case 2:
                    if (i->diem_ly < j->diem_ly) flag = 1;
                    break;
                case 3:
                    if (i->diem_ta < j->diem_ta) flag = 1;
                    break;
                case 4:
                    if (i->tong_diem < j->tong_diem) flag = 1;
                    break;
            }
            if (flag) {
                hoanDoi(i, j);
            }
        }
    }

    printf("=> Danh sach da duoc sap xep!\n");
}

void sapXepMenu() {
    int chon;
    printf("\n=== LUA CHON SAP XEP ===\n");
    printf("1. Theo diem Toan\n");
    printf("2. Theo diem Ly\n");
    printf("3. Theo diem Tieng Anh\n");
    printf("4. Theo tong diem\n");
    printf("Chon kieu sap xep: ");
    scanf("%d", &chon);
    if (chon >= 1 && chon <= 4)
        sapXep(chon);
    else
        printf("Lua chon khong hop le!\n");
}

void xoaDanhSach()
{
    ThiSinh* current = head;
    while (current != NULL)
    {
        ThiSinh* temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    int lua_chon;

    do
    {
        printf("\n========== MENU ==========\n");
        printf("1. Tao danh sach thi sinh\n");
        printf("2. Hien thi danh sach thi sinh\n");
        printf("3. Sap xep diem thi\n");
        printf("4. Ket thuc\n");
        printf("Chon chuc nang: ");
        scanf("%d", &lua_chon);

        switch (lua_chon)
        {
        case 1:
            themThiSinh();
            break;
        case 2:
            hienThiDanhSach();
            break;
        case 3:
            sapXepMenu();
            break;
        case 4:
            xoaDanhSach();
            printf("Ket thuc chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
        }
    }
    while (lua_chon != 4);

    return 0;
}
