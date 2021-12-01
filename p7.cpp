#include <iostream>
#include <cmath>
using namespace std;
#define MAX 16

//Ham chuyen doi day bit nhi phan sang so thap phan tuong ung (bang phuong phap bu 2)
int BinToDec(int a[], int n)
{
    //Bit cuoi cung cua day bit dung de luu dau cua so do
    //Neu a[15] = 1 thi day la so duong, a[15] = 0 thi day la so am
    if(a[15] == 1)  //Neu day la so am
    {
        //Dao nguoc gia tri cua tung bit
        // chuyen 0 thanh 1 va nguoc lai
        for(int i = 0; i < n - 1; i++)
        {
            if(a[i] == 0) a[i] = 1;
            else a[i] = 0;
        }
        //Cong 1 vao day bit vua chuyen
        int nho = 1;
        for(int i = 0; i < n - 1; i++)
        {
            a[i] = a[i] + nho;
            if(a[i] == 2) 
            {
                a[i] = 0;
                nho = 1;
            }
            else nho = 0;
        }
    }
    int x = 0;
    //Vi bit cuoi cung la bit chua dau cua so
    //nen ta xet tu i = n-2
    for(int i = n - 2; i >= 0; i--)
    {
        if(a[i]==1) //Neu a[i] == 1
            x += pow(2,i); // Tinh tong 2^i
    }
    //Neu a[15] = 0 thi x la so duong
    //Neu a[15] = 1 thi x la so am
    if(a[15] == 0) return x;
    else return -x;
}

//Ham lay chuoi nhi phan truyen vao mang
void LayBin(int a[], int& n, long long bin)
{
    n = 16; //Vi chuoi nhi phan co 16 bit nen a co 16 phan tu
    int k = 0;
    while(k < 16)
    {
        a[k++] = bin % 10;    //Truyen tung chu so cho a[i]
        bin /= 10;  //Chia a cho 10 sau moi lan lap
    }
    //Dien gia tri 0 vao cac bit trong
    for(int i = k; i < n; i++)
    {
        a[i] = 0;
    }
}

//Ham nhap chuoi nhi phan
void NhapBin(long long& bin, int a[], int& n)
{
    do
    {
        cout << "Nhap vao day 16 bit nhi phan (co dau): "; cin >> bin;
        if((bin/pow(10,15) >= 2)) //Neu do dai cua chuoi nhi phan vua nhap lon hon 16 thi khong hop le
            cout << "Day bit vua nhap khong hop le, hay nhap lai!" << endl;
    } while ((bin/pow(10,15) >= 2));    //Nhap cho den khi bin hop le 
    LayBin(a,n,bin);  
}

//Ham xuat mang
void XuatMang(int a[], int n)
{
    //Dung vong lap for de xuat tung gia tri cua mang
    for(int i = n - 1; i >= 0; i--)
    {
        cout << a[i];
    }
}

int main()
{
    long long bin;
    int a[MAX],n;
    NhapBin(bin,a,n);   //Nhap chuoi nhi phan can xet
    cout << "Day bit ban vua nhap la: ";
    XuatMang(a,n);
    //Chuyen chuoi nhi phan (co dau) qua so trong he thap phan tuong tung
    cout << "\nChuoi nhi phan vua nhap duoc chuyen qua he thap phan (bang phuong phap bu 2) la so: " << BinToDec(a,n) << endl;     
    return 0;
}
