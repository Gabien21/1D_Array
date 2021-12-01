//VCT nhập một mảng số nguyên có n phần tử, xây dựng các hàm tính tổng các phần tử là: 
//a)  số chính phương 
//b)  số hoàn chỉnh 
//c)  số nguyên tố 
//d)  số dương đối xứng 

#include <iostream>
#include <cmath>
using namespace std;
#define MAX 1000

//Ham kiem tra n co phai la so chinh phuong hay khong
bool SoChinhPhuong(int n)
{
    if(n==1) return true; //1 la so chinh phuong
    //So chinh phuong la so ma can bac hai cua no la mot so nguyen
    for(int i = 1; i <= n/2; i++)
    {
        //Neu tim duoc i^2 = n thi tra ve true
        if(n == pow(i,2)) return true;
    }
    return false;   //Neu khong tim duoc i thi tra ve false
}

//Ham tinh tong cua cac so chinh phuong co trong mang
int TongSoChinhPhuong(int a[], int n)
{
    int tong = 0;
    //Dung vong lap for de xet den tat ca phan tu trong mang
    for(int i = 0; i < n; i++)
    {
        //Neu tim duoc gia tri nao la so chinh phuong thi cong gia tri do vao tong
        if(SoChinhPhuong(a[i])) tong += a[i];
    }
    return tong;    //Tra ve tong cac cac so chinh phuong
}

//Ham tinh tong cac uoc nho hon n 
int tongCacUoc(int n)
{
	int tong = 0;
    //Dung vong lap for de xet tat ca so nho hon n
	for(int i = 1; i < n; i++)
        //Neu tim duoc so chia het cho n thi cong so do vao tong
        if(n % i == 0) tong += i;
	return tong;    //Tra ve tong cac uoc so nho hon n
}

//Ham kiem tra n co phai la so hoan chinh hay khong
bool SoHoanChinh(int n)
{
	int tong = tongCacUoc(n);
	//Neu tong cac uoc cua n bang chinh no thi n la so hoan chinh
	if (tong == n) return true;
	else return false;  //Nguoc lai, tra ve false
}

//Ham tinh tong cua cac so hoan chinh co trong mang
int TongSoHoanChinh(int a[], int n)
{
    int tong = 0;
    //Dung vong lap for de xet den tat ca phan tu trong mang
    for(int i = 0; i < n; i++)
    {
        //Neu tim duoc gia tri nao la so hoan chinh thi cong gia tri do vao tong
        if(SoHoanChinh(a[i])) tong += a[i];
    }
    return tong; //Tra ve tong cac cac so hoan chinh
}

//Ham kiem tra n co phai la so nguyen to hay khong
bool SoNguyenTo(int n)
{
    if(n <= 1) return false;    //Neu n <= 1 thi n khong phai la so nguyen to
	//So nguyen to la so chi chia het cho 1 va chinh no
	for (int i = 2; i <= n/2; i++)	//Tao vong lap voi i chay tu 2 den n/2
		if (n % i == 0) return false;	//Neu co gia tri i nao chia het cho n thi tra ve false
	return true;    //Neu khong tim duoc so nao chia het cho n thi tra ve true
}

//Ham tinh tong cua cac so nguyen to co trong mang
int TongSoNguyenTo(int a[], int n)
{
    int tong = 0;
    //Dung vong lap for de xet den tat ca phan tu trong mang
    for(int i = 0; i < n; i++)
    {
        //Neu tim duoc gia tri nao la so nguyen to thi cong gia tri do vao tong
        if(SoNguyenTo(a[i])) tong += a[i];
    }
    return tong;    //Tra ve tong cac cac so nguyen to
}

//Ham tim so dao nguoc cua n
int soDaoNguoc(int n)
{
	int soDaoNguoc = 0;
	while (n > 0)   //Neu n > 0 thi tiep tuc vong lap
	{
		soDaoNguoc = soDaoNguoc * 10 + n % 10;		//Dao nguoc vi tri cac chu so cua so ban nhap vao
		n /= 10;									//Loai bo mot chu so hang don vi va tiep tuc vong lap
	}
	return soDaoNguoc;
}

//Ham kiem tra cac chu so cua n co doi xung hay khong
bool SoDoiXung(int n)
{
	//Neu so dao nguoc cua n bang chinh no thi n la so doi xung
	if (soDaoNguoc(n) == n) return true;
	else return false;
}

//Ham tinh tong cua cac so doi xung co trong mang
int TongSoDoiXung(int a[], int n)
{
    int tong = 0;
    //Dung vong lap for de xet den tat ca phan tu trong mang
    for(int i = 0; i < n; i++)
    {
        //Neu tim duoc gia tri nao la so doi xung thi cong gia tri do vao tong
        if(SoDoiXung(a[i])) tong += a[i];
    }
    return tong;       //Tra ve tong cac cac so doi xung
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

int main()
{
    int a[MAX], n;
    NhapMang(a,n);  //Nhap vao mang can xet

    //Tinh tong cac so chinh phuong trong mang
    cout << "Tong cac so chinh phuong trong mang la: " << TongSoChinhPhuong(a,n) << endl;

    //Tinh tong cac so hoan chinh trong mang
    cout << "Tong cac so hoan chinh trong mang la: " << TongSoHoanChinh(a,n) << endl;

    //Tinh tong cac so nguyen to trong mang
    cout << "Tong cac so nguyen to trong mang la: " << TongSoNguyenTo(a,n) << endl;

    //Tinh tong cac so doi xung trong mang
    cout << "Tong cac so doi xung trong mang la: " << TongSoDoiXung(a,n) << endl;
    return 0;
}
