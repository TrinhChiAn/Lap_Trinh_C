
/*
Câu 2: Viết chương trình cộng hai ma trận C¬mxn = Amxn + Bmxn. Trong đó dữ liệu về  m,n và hai ma trận A, B được lưu trữ trên tệp 'MA_TRAN.C' theo dạng sau:
Dòng đầu tiên ghi: m n; dòng tiếp theo ghi: Ma trận A; các dòng tiếp theo là các hàng của ma trận A; dòng tiếp theo ghi: Ma trận B; các dòng tiếp theo là các hàng của ma trận B. Chương trình được tổ chức thành các công việc và các chương trình con sau:

  1) Tạo tệp MA TRAN.C theo cấu trúc như trên (giống như soạn thảo một chương
trình C)
  2) Đọc tệp MA_TRAN.C
  3) Tính ma trận tổng C rồi ghi vào cuối tệp trên (sử dụng kiểu nhập xuất văn bản)
  4) Mở tệp MA_TRAN.C để xem kết quả

 Hàm main() hiển thị menu để chọn các chức năng bằng cách nhập số tương ứng như
sau :
1. Doc tep ma tran A, B tu tep
2. Tinh ma tran C va ghi bo sung vao cuoi tep
3. Ket thuc

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void nhapMaTran(int m[][MAX_SIZE], int dong, int cot)
{
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            printf("Nhap m[%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

void ghiMaTran(FILE *f, const char *tieuDe, int m[][MAX_SIZE], int dong, int cot)
{
    fprintf(f, "\n%s\n", tieuDe);
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            fprintf(f, "%4d", m[i][j]);
        }
        fprintf(f, "\n");
    }
}

void congMaTran(int a[][MAX_SIZE], int b[][MAX_SIZE], int c[][MAX_SIZE], int dong, int cot)
{
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void docFile(const char *tenFile)
{
    FILE *f = fopen(tenFile, "r");
    if (f == NULL)
    {
        printf("Khong the mo file de doc!\n");
        return;
    }

    char line[256];
    printf("\n----- Noi dung tep -----\n");
    while (fgets(line, sizeof(line), f))
    {
        printf("%s", line);
    }
    printf("------------------------\n");

    fclose(f);
}

int main()
{
    int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], c[MAX_SIZE][MAX_SIZE];
    int dong = 0, cot = 0;
    int chon;

    while (1)
    {
        printf("\n-------------- MENU --------------\n");
        printf("1) Nhap ma tran\n");
        printf("2) Doc file\n");
        printf("3) Ghi ma tran bo sung\n");
        printf("4) Ket thuc\n");

        printf("Lua chon: ");
        scanf("%d", &chon);

        switch (chon)
        {
        case 1:
        {
            printf("Ban da chon nhap ma tran\n");

            FILE *f = fopen("MATRAN.C", "w");
            if (f == NULL)
            {
                printf("Khong the mo file de ghi!\n");
                break;
            }

            printf("Nhap so dong va cot: ");
            scanf("%d%d", &dong, &cot);
            fprintf(f, "%d %d\n", dong, cot);

            printf("Nhap ma tran A:\n");
            nhapMaTran(a, dong, cot);
            ghiMaTran(f, "Ma tran A:", a, dong, cot);

            printf("Nhap ma tran B:\n");
            nhapMaTran(b, dong, cot);
            ghiMaTran(f, "Ma tran B:", b, dong, cot);

            fclose(f);
            break;
        }
        case 2:
        {
            docFile("MATRAN.C");
            break;
        }
        case 3:
        {
            if (dong == 0 || cot == 0)
            {
                printf("Ban chua nhap ma tran. Vui long chon 1 truoc!\n");
                break;
            }

            printf("Ban da chon ghi ma tran bo sung\n");

            FILE *f = fopen("MATRAN.C", "a");
            if (f == NULL)
            {
                printf("Khong the mo file de ghi bo sung!\n");
                break;
            }

            congMaTran(a, b, c, dong, cot);
            ghiMaTran(f, "Ma tran C (A + B):", c, dong, cot);

            fclose(f);
            break;
        }
        case 4:
            printf("Ket thuc chuong trinh.\n");
            exit(0);
        default:
            printf("Chi nhap tu 1 den 4!\n");
        }
    }

    return 0;
}
