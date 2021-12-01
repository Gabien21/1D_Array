//VCT nhập một mảng số có n phần tử và một giá trị X, xây dựng các hàm thực hiện:
//a) Kiểm tra X có trong mảng không. 
//b) Nếu X không có trong mảng thì chèn X vào mảng tại vị trí sau phần tử đầu tiên. 

#include <iostream>
using namespace std;
#define MAX 1000

//Ham kiem tra xem x co trong mang khong
bool KiemTraX(double a[], int n, double x)
{
    //Dung vong lap for de xet den tat ca phan tu trong mang
    for(int i = 0; i < n; i++)
        //Neu tim duoc 1 phan tu co gia tri bang x thi tra ve true
        if(a[i] == x) return true;
    return false;   //Nguoc lai tra ve false
}

//Ham chen x vao vi tri sau vi tri dau tien
void ChenX(double a[], int& n, double x)
{
    //Thay doi cac phan tu sau a[1]
    for(int i = n; i > 1; i--)
    {
        a[i] = a[i-1];  //Gan gia tri a[i-1] cho a[i] vi da chen them x vao a[1]
    }
    a[1] = x;   //Gan a[1] = x vi a[1] la phan tu sau phan tu dau tien la a[0]
    n++;    //Sau khi chen them x thi n tang them 1 don vi
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
    double a[MAX], x;
    int n;
    NhapMang(a,n);  //Nhap vao mang can xet
    cout << "Nhap vao gia tri x can kiem tra: "; cin >> x;
    //Kiem tra xem x co trong mang khong
    if(KiemTraX(a,n,x)) cout << "X co trong mang!" << endl;
    //Neu khong co x trong mang thi chen x vao vi tri sau vi tri dau tien
    else
    {
        cout << "X khong co trong mang!" << endl;
        ChenX(a,n,x);   //Chen x vao vi tri sau vi tri dau tien
        cout << "Mang sau khi chen X vao vi tri sau phan tu dau tien la: ";
        XuatMang(a,n);  //Xuat mang sau khi chen X vao vi tri sau phan tu dau tien
    }
    return 0;
}
