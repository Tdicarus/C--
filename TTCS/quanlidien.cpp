#include <stdio.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <fstream>
#define MAX 1000
using namespace std;
//====================CAC CAU TRUC==============//

struct Date
{
	int thang, nam;
};

struct khachHang 
{
	char maKH[10];
	char TenKH[30];
	char diaChi[50];
	char soDT[15];
};
typedef khachHang KH;

struct HoaDon
{
	char maKH[10];
	char maHD[10];
	Date thangSuDung;
	int soDK; 
	int soCK;
	int soTieuThu;
	float tienDien;
};
typedef HoaDon HD;

//-=============================================//


//===============VECTOR==================//
vector <khachHang> dsKH;
vector <HoaDon> dsHD;
//======================================//

//================DANH SACH CAC HAM================//
char* fileName="khachhang.dat";
char* fileHD="hoadon.dat";
void docKH (char* fileName);
void docHD (char* fileHD);
void ghiKH (char* fileName);
void ghiHD (char* fileHD);
KH nhapKH();
HD nhapHD();
bool themKH (KH kh);
bool themHD (HD hd);
void inKH (KH kh);
void inHD (HD hd);
void inDSKH();
void inDSHD();
void capNhatKH (KH khMoi);
bool xoaKH (char* khID);
bool xoaHD (char* hdID);
void anyKey();
void tinhTienDien(HD &hd);
int timKiemKH(char* khID);
int timKiemHD(char* hdID, char* khach);

//==================================================//



//=======================CHUONG TRINH CHINH====================//
int main()
{
	docKH(fileName);
	docHD(fileHD);
	int key;
	while(true)
	{
		printf("======== QUAN LY SU DUNG DIEN CUA KHACH HANG ========= \n");
		printf("******************** CHUC NANG ********************\n\n");
		printf("1. Them thong tin khach hang\n");
		printf("2. Xoa thong tin khach hang\n");
		printf("3. Cap nhat thong tin khach hang\n");
		printf("4. Them Hoa don\n");
		printf("5. Xoa hoa don\n");
		printf("6. Tim kiem khach hang\n");
		printf("7. Tim kiem hoa don\n");
		printf("8. Danh sach khach hang\n");
		printf("9. Danh sach hoa don\n\n");
		printf("**************************************************\n");	
		printf ("Nhap lua chon cua ban: ");
		scanf ("%d",&key);
		printf("=========================================\n");
	switch (key)
	{
		default:
			printf("Khong co chuc nang nay! Vui long chon lai !\n");
			break;
		
		case 1:
			{
				printf("1. Them thong tin khach hang\n\n");
				printf("============ Danh sach khach hang ============\n\n");
				int slKH=0;
				int a;
				KH kh1, kh2;
				strcpy(kh1.maKH, "001");
				strcpy(kh1.TenKH, "Nguyen Van An");
				strcpy(kh1.diaChi, "80 HTT");
				strcpy(kh1.soDT, "0982xxxxxx");
				strcpy(kh2.maKH, "002");
				strcpy(kh2.TenKH, "Nguyen Van Binh");
				strcpy(kh2.diaChi, "24 HVT");
				strcpy(kh2.soDT, "0952xxxxxx");
					themKH(kh1);
					inDSKH();
				printf("**************************************************\n");
				printf("Nhap so luong khach hang can them: ");
				scanf("%d", &slKH);
				for (int i=0;i<slKH;i++)
				{
					printf("nhap thong tin khach hang thu %d:\n", i);
					themKH(nhapKH());
					printf("\n");
								printf("Tiep tuc nhap ?\n");
								scanf ("%d", &a);
								if (a==0)
								{
									printf("nhap thong tin khach hang thu %d:\n", i);
									themKH(nhapKH());
								}
								else if (a==1)
								{
								break;	
								}
				}
				printf("========== Danh sach khach hang sau khi them ========== \n\n");
					docKH(fileName);
					inDSKH();
					break;
			}


		case 2:
			{
				KH kh;
				char* khID;
				kh.maKH;
				printf("2. Xoa thong tin khach hang\n");
				printf("=============================\n");
				inDSKH();
				printf("nhap ma khach hang can xoa: \n");
				scanf("%s",&kh.maKH);
				khID = kh.maKH;
				xoaKH(khID);
				docKH(fileName);
				printf("******************************************\n");
				printf("danh sach khach hang sau khi xoa: \n");
				inDSKH();
				break;
			}
	
		case 3:
			{ 
				printf("3. Cap nhat thong tin khach hang\n");
				printf("=============================\n");
				inDSKH();
				printf("Nhap thong tin khach hang can cap nhat:\n");
				khachHang khMoi = nhapKH();
				capNhatKH(khMoi);
				printf("Danh sach khach hang sau khi cap nhat:\n");
				docKH(fileName);
				inDSKH();
				break;
			}	
		
		case 4:
			{
				int slHD=0;
				printf("4. Them Hoa don\n");
				printf("=============================\n");
				inDSHD();
				printf("**************************************************\n");
				printf("Nhap so luong hoa don can them: \n");
				scanf("%d", &slHD);
				for (int i=0;i<slHD;i++)
				{
					printf ("nhap thong tin hoa don thu %d:\n", i);
					themHD(nhapHD());
				}
				printf ("**************************************************\n");
				printf("========= Danh sach hoa don sau khi them ===========\n");
					docHD(fileHD);
					inDSHD();
				break;
			}
	
		case 5:
			{
				HD hd;
				char* hdID;
				printf("5. Xoa hoa don\n");
				printf("=============================\n");
				inDSHD();
				printf("nhap thong tin hoa don can xoa: \n");
				scanf("%s",&hd.maHD);
				hdID = hd.maHD;
				xoaHD(hdID);
				docHD(fileHD);
				printf("******************************************\n");
				printf("danh sach hoa don sau khi xoa: \n");
				inDSHD();
				break;
			}

		case 6:
			{
			 	KH kh;
				char* khID;
				printf("6. Tim kiem khach hang: \n");
				printf("=============================\n");
				printf("Nhap ma khach hang can tim kiem: \n");
				scanf("%s", &kh.maKH);
				khID = kh.maKH;
				printf("[Khach hang can tim kiem la: ]\n\n");
				int index = timKiemKH(khID);
				if(index == -1)
				{
					printf("Khong tim thay khach hang !\n");
				}
				else inKH(dsKH[index]);
				docKH(fileName);
				break;
			}

		case 7:
			{
			 	HD hd;
				char* hdID;
				char* khach;
				printf("7. Tim kiem hoa don: \n");
				printf("=============================\n");
				printf("Nhap ma khach hang:\n");
				scanf("%s", &hd.maKH);
				printf("Nhap ma hoa don can tim kiem: \n");
				scanf("%s", &hd.maHD);
				hdID = hd.maHD;
				khach = hd.maKH;
				printf("Hoa don can tim kiem la: \n");
				int index = timKiemHD(hdID, khach);
				if(index == -1)
				{
					printf("Khong tim thay hoa don !\n");
				}
				else {
				inHD(dsHD[index]);
				}
				docHD(fileHD);
				break;
			}

		case 8:
			{
				printf("8. Danh sach khach hang\n");	
				printf("=====================================\n");
			 	docKH(fileName);
				inDSKH();
				break;
			}
			
		case 9:
			{
				printf("9. Danh sach hoa don\n");
				printf("=====================================\n");
				docHD(fileHD);
				inDSHD();
				break;
			}
	}
	anyKey();
}
}




//=========================== Khach Hang ===================//

//----------------------In khach hang--------------------//
void inKH(KH kh)
	{
		printf("Ma Khach Hang: %s\n", kh.maKH);
		printf("Ten Khach Hang: %s\n", kh.TenKH);
		printf("Dia Chi:%s\n", kh.diaChi);
		printf("So dien thoai:%s\n", kh.soDT);
	}
	
//----------------------In danh sach khach hang--------------------//
void inDSKH()
	{
		int size= dsKH.size();
		for(int i=0; i<size; i++)
		{
			inKH(dsKH[i]);
			printf("-----------------------------------------\n");
		}
	}

//----------------------Nhap khach hang--------------------//
KH nhapKH()
	{
		KH kh;
		printf("Nhap ma KH: \n"); fflush(stdin);
		gets(kh.maKH);
		printf("Nhap ten KH: \n"); fflush(stdin);
		gets(kh.TenKH);
		printf("Nhap dia chi: \n"); fflush(stdin);
		gets(kh.diaChi);
		printf("Nhap so dien thoai:\n");
		gets(kh.soDT);
		return kh;
	}		

//----------------------Xoa khach hang--------------------//
bool xoaKH(char* khID)
{
	int size= dsKH.size();
	int vtXoa=-1;
	for(int i=0; i<size; i++)
		if(strcmp(khID, dsKH[i].maKH)==0)
		{
			vtXoa=i;
			printf("=======================================\n");
			printf("[Xoa khach hang thanh cong !]\n\n");
			break;
		}
	if(vtXoa!=-1)
	{
		dsKH.erase(dsKH.begin()+vtXoa);
		ghiKH(fileName);
		return true;
	}
	return false;
}


//----------------------Cap nhat khach hang--------------------//
void capNhatKH (KH khMoi)
{
	int size= dsKH.size();
	int vtCapNhat=-1;
	for(int i=0; i<size; i++)
		if(strcmp(khMoi.maKH, dsKH[i].maKH)==0) //so sanh ma khach hang moi duoc nhap, trung khop thi cap nhat
		{
			vtCapNhat=i;
			break;
		}
		else
		{
			printf("=======================================\n");
			printf("[Khong ton tai khach hang nay !]\n\n");
			break;
		}
		
	if(vtCapNhat!=-1)
	{
		strcpy(dsKH[vtCapNhat].maKH, khMoi.maKH);
		strcpy(dsKH[vtCapNhat].TenKH, khMoi.TenKH);	
		strcpy(dsKH[vtCapNhat].diaChi, khMoi.diaChi);
		strcpy(dsKH[vtCapNhat].soDT, khMoi.soDT);
		ghiKH(fileName);
	}
}


//----------------------Doc file khach hang--------------------//
void docKH(char* fileName)
{
	dsKH.clear();
	FILE *f;
	f= fopen(fileName, "rb");
	//use "rb" if you're opening non-text files, because in this case, the translations are not appropriate
	if(f!=NULL)
	{
		while(!feof(f))  //khac gia tri cuoi cung trong file thi tiep tuc doc
		{
			KH kh;
			fread(&kh, sizeof(KH), 1, f);
			dsKH.push_back(kh);
		}
		fclose(f);
		dsKH.pop_back();
	}	
}

//----------------------Ghi file khach hang--------------------//
void ghiKH(char* fileName)
{
	int size = dsKH.size();
	FILE *f;
	f= fopen(fileName, "wb");
	//use "wb" if you're writing non-text files, because in this case, the translations are not appropriate
	KH kh;
	for(int i=0; i<size; i++)
	{
		kh= dsKH[i];
		fwrite(&kh, sizeof(KH), 1, f);
	}
	fclose(f);
}


//----------------------Them khach hang--------------------//
bool themKH(KH kh)
	{
	int size= dsKH.size();
	for(int i=0; i<size; i++)
		if(strcmp(kh.maKH, dsKH[i].maKH)==0)
			return false;
	dsKH.push_back(kh);
	ghiKH(fileName);
	return true;
	}


//----------------------Xoa man hinh--------------------//
void anyKey() 
	{
    printf("\nBam phim bat ky de tiep tuc...");
    getch();
    system("cls");
	}

//----------------------Tim kiem khach hang--------------------//
int timKiemKH(char* khID)
	{	
	int size= dsKH.size();
	for(int i=0; i<size; i++)
		if(strcmp(khID, dsKH[i].maKH)==0)
			return i;
	return -1;
	}



//==================== HOA DON =============================//


//----------------------Nhap Hoa don--------------------//
HD nhapHD()
{
	HD hd;
	printf("Nhap ma KH: \n"); fflush(stdin);
	gets(hd.maKH);
	printf("Nhap ma HD: \n"); fflush(stdin);
	gets(hd.maHD);
	printf("Nhap thang su dung: \n"); fflush(stdin);
	scanf("%d", &hd.thangSuDung.thang);
	printf("Nhap nam su dung: \n"); fflush(stdin);
	scanf("%d", &hd.thangSuDung.nam); 
	printf("Nhap so cuoi ki: \n"); fflush(stdin);
	scanf("%d", &hd.soCK);
	printf("Nhap so dau ki: \n"); fflush(stdin);
	scanf("%d", &hd.soDK);
	hd.tienDien=0;
	tinhTienDien(hd); 
	return hd;
}


//----------------------Them hoa don--------------------//
bool themHD(HD hd)
	{
	int size= dsHD.size();
	for(int i=0; i<size; i++)
		if(strcmp(hd.maHD, dsHD[i].maHD)==0)
			{
			printf("==============================================\n");
			printf("[Trung ma hoa don! Khong the them hoa don]\n\n");
			return false;
			}
	dsHD.push_back(hd);
	ghiHD(fileHD);
	return true;
	}


//----------------------Xoa hoa don--------------------//
bool xoaHD(char* hdID)
{
	int size= dsHD.size();
	int vtXoa=-1;
	for(int i=0; i<size; i++)
		if(strcmp(hdID, dsHD[i].maHD)==0)
		{
			vtXoa=i;
			printf("=======================================\n");
			printf("[Xoa hoa don thanh cong !]\n\n");
			break;
		}
	if(vtXoa!=-1)
	{
		dsHD.erase(dsHD.begin()+vtXoa);
		ghiHD(fileHD);
		return true;
	}
	return false;
}
	
//----------------------In hoa don--------------------//
void inHD(HD hd)
{
	printf("Ma Khach Hang: %s\n", hd.maKH);
	printf("Ma Hoa don: %s\n", hd.maHD);
	printf("Thang Su dung: %d, %d\n", hd.thangSuDung.thang, hd.thangSuDung.nam);
	printf("So dau ki: %d\n ",hd.soDK);
	printf("So cuoi ki: %d\n",hd.soCK);
	printf("So dien tieu thu: %d\n",hd.soTieuThu);
	printf("Tien dien: %f\n",hd.tienDien);
	printf("--------------------------------------\n");
}



//----------------------In danh sach hoa don--------------------//
void inDSHD()
{
	int size= dsHD.size();
	for(int i=0; i<size; i++)
		inHD(dsHD[i]);
}

//----------------------Doc file hoa don--------------------//
void docHD(char* fileHD)
{
	dsHD.clear();
	FILE *f;
	f= fopen(fileHD, "rb");
	//use "rb" if you're opening non-text files, because in this case, the translations are not appropriate
	if(f!=NULL)
	{
		while(!feof(f))
		{
			HD hd;
			fread(&hd, sizeof(HD), 1, f);
			dsHD.push_back(hd);
		}
		fclose(f);
		dsHD.pop_back();
	}	
}

//----------------------Ghi file hoa don--------------------//
void ghiHD(char* fileHD)
{
	int size = dsHD.size();
	FILE *f;
	f= fopen(fileHD, "wb");
	//use "wb" if you're writing non-text files, because in this case, the translations are not appropriate
	HD hd;
	for(int i=0; i<size; i++)
	{
		hd= dsHD[i];
		fwrite(&hd, sizeof(HD), 1, f);
	}
	fclose(f);
}


//----------------------Tim kiem hoa don--------------------//
int timKiemHD(char* hdID, char* khach)
{
	int size= dsHD.size();
	for(int i=0; i<size; i++)
		if(strcmp(hdID, dsHD[i].maHD)==0 && strcmp(khach, dsHD[i].maKH)==0)
			return i;
	return -1;
}


//----------------------Tinh tien dien--------------------//
void tinhTienDien(HD &hd)
{
	hd.soTieuThu= hd.soCK - hd.soDK;
 	int bac1=1678, bac2=1734, bac3=2014, bac4=2536, bac5=2834, bac6=2927;
 if(hd.soTieuThu<0)
 	printf("\nVui long nhap lai So Dien\nSo dien khong duoc nho hon 0\n");
 if(hd.soTieuThu<=50)
 	 hd.tienDien=hd.soTieuThu*bac1; 
 if(hd.soTieuThu<=100)
 	 hd.tienDien=50*bac1+((hd.soTieuThu-50)*bac2); 
 if(hd.soTieuThu<=200)
	 hd.tienDien=50*bac1+(50*bac2)+((hd.soTieuThu-100)*bac3); 
 if(hd.soTieuThu<=300)
 	 hd.tienDien=50*bac1+(50*bac2)+(100*bac3)+((hd.soTieuThu-200)*bac4);
 if(hd.soTieuThu<=400)  
 	 hd.tienDien=50*bac1+(50*bac2)+(100*bac3)+(100*bac4)+((hd.soTieuThu-300)*bac5);
 if(hd.soTieuThu>400)
	 hd.tienDien=50*bac1+(50*bac2)+(100*bac3)+(100*bac4)+(100*bac5)+((hd.soTieuThu-400)*bac6);
}




