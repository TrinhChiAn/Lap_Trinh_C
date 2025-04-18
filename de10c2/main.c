#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>

typedef struct node{
    int data;
    struct node * next;
}node;

char Chars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9','a', 'b', 'c', 'd', 'e', 'f'};
node *top = NULL;

node* taoNode(int n)
{
    node *p;
    p=(node*)malloc(sizeof(node));
    p->data = n;
    p->next = NULL;
}

void push(int n)
{
    node *p = taoNode(n);
    if(top == NULL){
        top = p;
    }
    else{
        p->next = top;
        top = p;
    }
}

int  pop()
{
    if(top == NULL){
        return -1;
    }
    else {
        int n = top->data;
        node*k = top;
        top=top->next;
        free(k);
        return n;
    }
}
 void chuyenDoiCoSo(int he10, int coSo)
 {
     while(he10>0){
        push(he10%coSo);
        he10 /= coSo;
     }

 }
 void hienThi()
 {
     while(top!=NULL){
        printf("%c ", Chars[pop()]);
     }
     printf("\n");
 }

 void Menu()
 {
     printf("1. sang he 2\n");
     printf("2. sang he 8\n");
     printf("3. sang he 16\n");
     printf("0. thoat\n");
     printf("Lua Chon: ");

 }

 int main ()
 {
     int c;
     int n;
     do{
         Menu();
         scanf("%d", &c);
         switch(c)
         {
         case 1:
            printf("nhap he co so 10: ");
            scanf("%d", &n);
            chuyenDoiCoSo(n,2);
            printf("hien thi he co so 2: ");
            hienThi();
            getch();
            system("cls");
            break;

         case 2:
            printf("nhap he co so 10: ");
            scanf("%d", &n);
            chuyenDoiCoSo(n, 8);
            printf("hien thi he co so 8: ");
            hienThi();
            getch();
            system("cls");
            break;
        case 3:
            printf("nhap he co so 10: ");
            scanf("%d", &n);
            chuyenDoiCoSo(n, 8);
            printf("hien thi he co so 16: ");
            printf("%x", n);
            getch();
            system("cls");
            break;
        case 0:
            exit(0);
        default:
            printf("chi chon tu 0 den 3");
         }
     }while (c<4&& c>=0);
     return 0;
 }
