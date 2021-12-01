//VCT nhập một mảng số nguyên có n phần tử, xây dựng các hàm thực hiện:
//1. Tính tổng tẩt cả các phần tử không âm.
//2. Tính tổng các phần tử chia hết cho 3.
//3. Tính tổng các phần tử có chữ số đầu tiên là số lẻ.
//4. Kiểm tra mảng có chứa số dương không.
//5. Kiểm tra mảng có gồm toàn số dương không.
//6. Nếu mảng không toàn dương thì đổi các số dương thành số âm. 

#include <iostream>
using namespace std;
#define MAX 1000

//Ham tinh tong cac phan tu khong am trong mang
int TongPhanTuKhongAm(int a[], int n)
{
    int tong = 0;
    //Dung vong lap for de xet tat ca phan tu trong mang
    for(int i = 0; i < n; i++)
    {
        //Neu phan tu nao co gia tri khong am thi truyen gia tri do vao tong
        if(a[i] >= 0) tong += a[i];
    }
    return tong;    //Tra ve tong gia tri cua cac phan tu khong am
}

//Ham tinh tong cac phan tu chia het cho 3 trong mang
int TongPhanTuChiaHetCho3(int a[], int n)
{
    int tong = 0;
    //Dung vong lap for de xet tat ca phan tu trong mang
    for(int i = 0; i < n; i++)
    {
        //Neu phan tu nao co gia tri chia het cho 3 thi truyen gia tri do vao tong
        if(a[i] % 3 == 0) tong += a[i];
    }
    return tong;    //Tra ve tong gia tri cua cac phan tu chia het cho 3
}

//Ham kiem tra chu so dau le cua mot so
bool ChuSoDauLe(int n)
{
    int soDau = 0;
    n = abs(n);     //Lay gia tri tuyet doi cua n
    while(n != 0)   //Thuc hien vong lap cho den khi n khac 0
    {
        soDau = n % 10; //Truyen chu so hang don vi cua n vao bien soDau
        n /= 10;   //Cat bo chu so hang don vi cua n 
    }
    if(soDau % 2 == 1) return true; //Neu soDau khong chia het cho 2 thi soDau le, tra ve true
    else return false; //Nguoc lai, tra ve false
}

//Ham tinh tong gia tri cua cac phan tu co chu so dau le trong mang
int TongChuSoDauLe(int a[], int n)
{
    int tong = 0;
    //Dung vong lap for de xet tat ca phan tu trong mang
    for(int i = 0; i < n; i++)
    {
        //Neu phan tu nao co gia tri chu so dau tien le thi truyen gia tri do vao tong
        if(ChuSoDauLe(a[i])) tong += a[i];
    }
    return tong;    //Tra ve tong gia tri cua cac phan tu co chu so dau le trong mang
}

//Ham kiem tra trong mang co gia tri duong hay khong
bool KiemTraSoDuong(int a[], int n)
{
    //Dung vong lap for de xet tat ca phan tu trong mang
    for(int i = 0; i < n; i++)
    {
        //Neu tim duoc 1 gia tri duong thi tra ve true
        if(a[i] > 0) return true;
    }
    return false;   //Nguoc lai tra ve false
}

//Ham kiem tra toan bo gia tri torng mang co duong hay khong
bool KiemTraToanBoMangDuong(int a[], int n)
{
    //Dung vong lap for de xet tat ca phan tu trong mang
    for(int i = 0; i < n; i++)
    {
        //Neu tim duoc trong mang co 1 gia tri khong duong thi tra ve false
        if(a[i] <= 0) return false;
    }
    return true; //Nguoc lai tra ve true
}

//Ham doi gia tri duong thanh gia tri am trong mang
void DoiSoDuongThanhSoAm(int a[], int n)
{
    //Dung vong lap for de xet tat ca phan tu trong mang
    for(int i = 0; i < n; i++)
    {
        //Neu tim duoc gia tri duong thi doi gia tri do thanh am
        if(a[i] > 0) a[i] = -a[i];
    }
}

//Ham nhap mang
void NhapMang(int a[], int& n)
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
            //Dung vong lap for de nhap gia tri cua tung phan tu trong mang
            for(int i = 0; i < n; i++)
            {
                cout << "a[" << i << "] = "; cin >> a[i];
            }
            //Neu n <= 0 hoac n > MAX thi so phan tu khong hop le
            if(n > MAX || n <= 0)
                cout << "So phan tu khong hop le, hay nhap lai!" << endl;
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
void XuatMang(int a[], int n)
{
    //Dung vong lap for de xuat tung gia tri cua mang
    for(int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = " << a[i] << endl;
    }
}

int main()
{
    int n, a[MAX];
    NhapMang(a,n);  //Nhap vao mang a

    //Tinh tong cac phan tu khong am
    cout << "Tong cac phan tu khong am la: " << TongPhanTuKhongAm(a,n) << endl;

    //Tinh tong cac phan tu chia het cho 3
    cout << "Tong cac phan tu chia het cho 3 la: " << TongPhanTuChiaHetCho3(a,n) << endl;

    //Tinh tong cac phan tu co chu so dau tien la so le
    cout << "Tong cac phan tu co chu so dau tien le la: " << TongChuSoDauLe(a,n) << endl;
    
    //Kiem tra trong mang co chua so duong hay khong
    if(KiemTraSoDuong(a,n)) cout << "Trong mang co so duong!" << endl;
    else cout << "Trong mang khong co so duong!" << endl;

    //Kiem tra mang co gom toan so duong hay khong
    if(KiemTraToanBoMangDuong(a,n)) cout << "Tat ca phan tu trong mang deu la so duong!" << endl;

    //Neu mang khong gom toan so duong thi doi so duong thanh so am
    else 
    {
        cout << "Tat ca phan tu trong mang khong la so duong!" << endl;
        DoiSoDuongThanhSoAm(a,n);
        cout << "Mang sau khi doi cac phan tu duong thanh am: " << endl;
        XuatMang(a,n);  //Xuat mang sau khi doi so duong thanh so am
    }
}
