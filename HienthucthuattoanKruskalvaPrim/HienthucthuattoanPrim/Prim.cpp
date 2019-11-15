#include<iostream>
#include<conio.h>
using namespace std;
#define TRUE 1 
#define FALSE  0 
#define MAX  10000 
int a[100][100];//ma tran trong so cua do thi
int n;//so dinh cua do thi
int m;//so canh cua do thi
int sc;//so canh cua cay khung nho nhat
int w;//Ðo dai cua cay khung nho nhat
int chuaxet[100];//mang danh dau danh sach dinh da them vao cay khung nho nhat
int cck[100][3];//danh sach canh cua cay khung nho nhat
void nhap (void){
 int i, j, k;
 freopen("Prim.inp", "r",stdin);
 scanf("%d %d ",&n,&m);
 printf("So dinh: %d\n",n);
 printf("So canh: %d\n",m);
 //khoi tao ma tran trong so cua do thi a[i][j] = MAX.
 for (i = 1; i <= n; i++){
  chuaxet[i] = TRUE;//Gan nhan cho cac dinh
  for (j = 1; j <= n; j++)
   a[i][j] = MAX;
 }
 
 //nhap danh sach canh
 for (int p = 1; p <= m; p++){
  scanf("%d %d %d ",&i,&j,&k);
  a[i][j] = k;
  a[j][i] = k;
 }
}
void PRIM (void){
 int k, top, min, l, t, u;
 int s[100];//mang chua cac dinh cua cay khung nho nhat
 sc = 0; w = 0; u = 1;
 top = 1;
 s[top] = u;// them dinh u bat ky vao mang s[]
 chuaxet[u] = FALSE;
 while (sc<n - 1) {
  min = MAX;
  //tim canh co do do dai nho nhat voi cac dinh trong mang s[]
  for (int i = 1; i <= top; i++){
   t = s[i];
   for (int j = 1; j <= n; j++){
    if (chuaxet[j] && min>a[t][j]){
     min = a[t][j];
     k = t;
     l = j;
    }
   }
  }
  sc++;
  w = w + min;
  //them vao danh sach canh cua cay khung
  cck[sc][1] = k;
  cck[sc][2] = l;
  chuaxet[l] = FALSE; 
  top++;
  s[top] = l;
 }
}
void Result (void){
 printf("Do dai ngan nhat: %d\n",w);
 printf("Cac canh cua cay khung nho nhat\n");
 for (int i = 1; i <= sc; i++)
  printf("%d %d \n",cck[i][1],cck[i][2]);
}
int main (void){
 nhap(); 
 PRIM();
 Result();
 getch();
 return 0;
}