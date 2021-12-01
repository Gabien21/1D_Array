//VCT nhập vào 1 số nguyên dương n. Chuyển đổi n sang hệ nhị phân và xuất  ra màn hình, sử dụng mảng một chiều. (Nâng cao: với -255 <= n <= 255)

#include <iostream>
#include <cmath>
using namespace std;
#define MAX 9

//Ham chuyen doi so tu he thap phan sang he nhi phan (phuong phap bu 2)
void DecToBin(int a[], int& n, int x)
{
    n = 9;
    for(int i = 0; i < n; i++)
    {
        a[i] = 0;
    }
    int i = abs(x), k = 0;
    while(i!=0)
    {
        a[k++] = i%2; //Gan cho a[n] ket qua phep chia lay du cua n cho 2 
        i /= 2; //Chia i cho 2 sau moi lan lap
    }
    //Neu x la so duong thi a[8] = 0
    //Neu x la so am thi a[8] = 1
    if(x > 0) a[8] = 0;
    else if(x < 0)
    {
        a[8] = 1;
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
}

//Ham nhap x
void NhapX(int &x)
{
    do
    {
        cout << "Nhap n (-255 <= n <= 255): "; cin >> x;
        if(x < -255 || x > 255) //Neu x < -255 hay x > 255 thi khong hop le
            cout << "n khong hop le, moi ban nhap lai!" << endl;
    } while (x < -255 || x > 255); //Nhap den khi nao x thoa
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
    int a[MAX],x,n;
    cout << "Chuyen he thap phan sang he nhi phan bang phuong phap bu 2!" << endl;
    NhapX(x);
    DecToBin(a,n,x);    //Chuyen x sang he nhi phan
    XuatMang(a,n);  //Xuat ra mang chua nhi phan cua x
    return 0;
}
