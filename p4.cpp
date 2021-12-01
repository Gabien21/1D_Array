//VCT nhập một mảng có n phần tử là các số, xây dựng các hàm thực hiện: 
//a) Kiểm tra mảng có thứ tự tăng/giảm không. 
//b) Nếu mảng không có thứ tự thì sắp xếp các phần tử theo thứ tự tăng dần. 

#include <iostream>
using namespace std;
#define MAX 1000

//Ham kiem tra mang co thu tu tang dan hay khong
bool TangDan(double a[], int n)
{
    //Vi xet 2 phan tu ke tiep nen i < n - 1
    for(int i = 0; i < n - 1; i++)
        //Neu ton tai a[i] >= a[i+1] thi tra ve false
        if(a[i] >= a[i+1]) return false;
    return true;    //Nguoc lai, tra ve true
}

//Ham kiem tra mang co thu tu tang giam hay khong
bool GiamDan(double a[], int n)
{
    //Vi xet 2 phan tu ke tiep nen i < n - 1
    for(int i = 0; i < n - 1; i++)
        //Neu ton tai a[i] <= a[i+1] thi tra ve false
        if(a[i] <= a[i+1]) return false;
    return true;    //Nguoc lai, tra ve true
}

//Ham hoan doi gia tri cua hai so
void HoanDoi(double& a, double& b)
{
    double temp = a;   //Gan gia tri cua a vao bien phu temp
    a = b;  //Gan gia tri cua b vao a
    b = temp;   //Gan gia tri cua bien phu temp vao b
}

//Ham sap xep cac gia tri trong mang theo thu tu tang dan
void SapXepTangDan(double a[], int n)
{
    //So sanh a[i] voi tung a[j]
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            //Neu ton tai a[i] < a[j] thi hoan doi vi tri cua hai so
            if(a[i] > a[j]) HoanDoi(a[i],a[j]);
        }
    }
}

//Ham nhap mang
void NhapMang(double a[], int& n)
{
    char ans;
    //Hoi nguoi dung co biet truoc so phan tu cua mang hay khong
    cout << "Ban co biet so phan tu khong? (Y/N) "; cin >> ans;
    //Neu nguoi dung biet truoc so phan tu cua mang
    if(ans == 'Y' || ans == 'y')
    {
        do
        {
            cout << "Nhap so phan tu trong mang: "; cin >> n;
            //Neu n <= 0 hoac n > MAX thi so phan tu khong hop le
            if(n > MAX || n <= 0)
            {
                cout << "So phan tu khong hop le, hay nhap lai!" << endl;
                continue;
            }
            cout << "Nhap " << n << " phan tu: ";
            //Dung vong lap for de nhap gia tri cua tung phan tu trong mang
            for(int i = 0; i < n; i++)
                cin >> a[i];
        } while (n > MAX || n <= 0);  //Nhap cho den khi n hop le
    }
    //Neu nguoi dung khong biet truoc so phan tu cua mang
    else if(ans == 'N' || ans == 'n')
    {
        char ans2;
        n = 0;
        do
        {            
            cout << "a[" << n << "] = "; cin >> a[n]; //Lan luot nhap tung phan tu cua mang
            n++;    //Tang n len 1 sau moi lan nhap
            cout << "Ban co muon nhap tiep khong? (Y/N) "; cin >> ans2;
        } while (ans2 == 'Y' || ans2 == 'y');   //Neu nguoi dung muon nhap tiep thi tiep tuc vong lap   
    }
}

//Ham xuat mang
void XuatMang(double a[], int n)
{
    //Dung vong lap for de xuat tung gia tri cua mang
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    double a[MAX];
    int n;
    NhapMang(a,n);  //nhap vao amng can xet
    //Kiem tra mang co tang dan hay giam dan theo thu tu khong
    if(TangDan(a,n) || GiamDan(a,n))
    {
        if(GiamDan(a,n)) cout << "Mang giam dan theo thu tu" << endl;
        if(TangDan(a,n)) cout << "Mang tang dan theo thu tu" << endl;
    }
    else
    //Neu mang khong co thu tu thi sap xep mang theo thu tu tang dan
    {
        cout << "Mang khong co thu tu tang giam" << endl;
        SapXepTangDan(a,n); //Sap xep lai mang theo thu tu tang dan
        cout << "Mang sau khi sap xep tang dan la: ";
        XuatMang(a,n);  //Xuat mang sau khi sap xep
    }   
    return 0;
}
