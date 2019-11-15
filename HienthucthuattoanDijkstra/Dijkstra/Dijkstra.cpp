#include <stdio.h>
#include <conio.h>
#include <values.h>
#include <iostream>
using namespace std;

#define max 100
#define FileDauVao "Dijkstra.inp"
//#define FileDauVao "Dijkstra1.inp"
//#define FileDauVao "Dijkstra2.inp"
//#define FileDauVao "Dijkstra3.inp"
//#define FileDauVao "Dijkstra4.inp"
//#define FileDauVao "Dijkstra5.inp"
//#define FileDauVao "Dijkstra6.inp"
//#define FileDauVao "Dijkstra7.inp"
#define MAXINT 999

void docFile(int a[max][max],int &n,int &dau,int &cuoi){
	FILE *f=fopen(FileDauVao,"rt");//Doc file dau vao Dijkstra.inp
	fscanf(f,"%d %d %d", &n,&dau,&cuoi);//doc so dinh, dinh dau va dinh cuoi
	printf("Ma tran ke tuong ung\n");
	printf("dau = %d	cuoi = %d\n",dau,cuoi);//in ra dinh dau va dinh cuoi
	for(int i=0;i<n;i++){//duyet mang theo hang ma tran trong so
		for(int j=0;j<n;j++){//duyet mang theo cot ma tran trong so
			fscanf(f,"%d",&a[i][j]);//doc phan tu a o hang i cot j (doc ma tran trong so)
			printf("%d ",a[i][j]);//in ra phan tu a o hang i cot j (in ra ma tran trong so)
		}
		printf("\n");
	}
	fclose(f);//dong file
	dau--;cuoi--;
}

void dijkstra(int a[max][max],int n,int dau,int cuoi){
	char danhDau[max];
	int nhan[max],truoc[max],xuatPhat,min;
	for(int i=0;i<n;i++){//duyet mang theo hang ma tran trong so
		nhan[i]=MAXINT;//gia tri nguyen lon nhat duoc gan nhan vao cho hang thu i
		danhDau[i]=0;//gia tri 0 duoc danh dau vao hang thu i
		truoc[i]=dau;//dinh dau duoc gan vao cho gia tri truoc cua hang thu i
	}
	nhan[dau]=0;//gia tri 0 duoc gan nhan vao cho dinh dau
	danhDau[dau]=1;//gia tri 1 duoc danh dau cho dinh dau
	xuatPhat=dau;//dinh dau la diem xuat phat
	while(xuatPhat!=cuoi){//kiem tra xem diem xuat phat khac dinh cuoi
		for(int j=0;j<n;j++){//duyet mang theo cot ma tran trong so
			if(a[xuatPhat][j]>0&&nhan[j]>a[xuatPhat][j]+nhan[xuatPhat]&&danhDau[j]==0){//neu gia tri cua phan tu a co hang duoc danh dau xuat phat va cot j lon hon 0 va nhan cua cot j lon hon gia tri cua phan tu a co hang duoc danh dau xuat phat va cot j cong voi nhan cua hang duoc danh dau xuat phat va cot j duoc danh dau la bang 0 
				nhan[j]=a[xuatPhat][j]+nhan[xuatPhat];//gia tri cua phan tu a co hang duoc danh dau xuat phat va cot j cong voi nhan cua hang duoc danh dau xuat phat duoc gan vao nhan cua cot j
				truoc[j]=xuatPhat;//hang duoc danh dau la diem xuat phat gan vao cho gia tri truoc cua cot thu j
			}
		}
		min=MAXINT;//gan gia tri nguyen lon nhat cho min
		for(int j=0;j<n;j++){//duyet mang theo cot ma tran trong so
			if(min>nhan[j]&&danhDau[j]==0){//neu gia tri min lon hon gia tri cua cot j duoc gan nhan va cot thu j duoc danh dau la bang 0
				min=nhan[j];//gia tri cua cot j duoc gan nhan duoc gan vao gia tri min 
				xuatPhat=j;//gia tri cua cot thu j duoc gan vao diem xuat phat
			}
		}
		danhDau[xuatPhat]=1;//gan gia tri 1 cho diem xuat phat duoc danh dau
	}
	printf("Duong di ngan nhat la: %d",nhan[cuoi]);//duong di ngan nhat la gia tri cuoi duoc gan nhan
	printf("\n%d <- %d",cuoi+1,truoc[cuoi]+1);//xuat duong di ngan nhat theo dinh dang gia tri cuoi + 1 <- gia tri truoc gia tri cuoi + 1 
	int i=truoc[cuoi];//gan gia tri truoc gia tri cuoi vao bien i
	while(i!=dau){//kiem tra i co khac gia tri dau khong?
		i=truoc[i];//gan gia tri truoc i vao i
		printf("<- %d",i+1);
	}
}

int main(int argc, char *argv[])
{
	int a[max][max],n,dau,cuoi;
	
	docFile(a,n,dau,cuoi);//goi ham doc file
	dijkstra(a,n,dau,cuoi);//goi ham tim duong di ngan nhat
	
	getch();
	
	return 0;
}