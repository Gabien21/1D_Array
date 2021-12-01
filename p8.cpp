//VCT nhập vào một mảng các số nguyên dương gồm n phần tử (1 ≤ n ≤ 15):
//a) Đếm số phần tử tận cùng là 6 và chia hết cho 6 trong mảng.
//b) Tính trung bình cộng các số nguyên tố hiện có trong mảng.
//c) Cho biết trong mảng có bao nhiêu số nguyên tố phân biệt.

#include <iostream>
using namespace std;
#define MAX 1000

//Ham dem cac phan tu co chu so tan cung la 6 va chia het cho 6
int Dem6VaChiaHet6(int a[], int n)
{
    int dem = 0;
    //Dung vong lap for de xet tat ca phan tu cua mang
    for(int i = 0; i < n; i++)
        //Neu tim duoc so co tan cung bang 6 va chia het cho 6 thi tang dem them 1 don vi
        if(a[i] % 10 == 6 && a[i] % 6 == 0)
            dem++;
    return dem; //Tra ve bien dem
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

//Ham kiem tra xem x co trong mang khong
bool KiemTraX(int a[], int n, int x)
{
    //Dung vong lap for de xet den tat ca phan tu trong mang
    for(int i = 0; i < n; i++)
        //Neu tim duoc 1 phan tu co gia tri bang x thi tra ve true
        if(a[i] == x) return true;
    return false;   //Nguoc lai tra ve false
}

//Ham tinh trung binh cong cua cac so nguyen to co trong mang
float TrungBinhCongSNT(int a[], int n)
{
    int tong = 0;
    int dem = 0;
    //Dung vong lap for de xet tat ca phan tu cua mang
    for(int i = 0; i < n; i++)
    {
        //Neu a[i] la so nguyen to
        if(SoNguyenTo(a[i])) 
        {
            tong += a[i];   //Tinh tong a[i]
            dem++;  //Tang bine dem them 1 don vi
        }
    }
    return (float)tong/dem; //Tra ve trung binh cong cua cac so nguyen to trong mang bang tong/dem
}

//Ham dem so nguyen to phan biet trong mang
int DemSNTPhanBiet(int a[], int n)
{
    int SNT[n], k = 0;
    //Dung vong lap for de tim cac so nguyen to torng mang a va truyen no vao mang SNT
    for(int i = 0; i < n; i++)
    {
        //Neu tim duoc so nguyen to a[i] va a[i] khac cac phan tu trong mang SNT da luu
        if(SoNguyenTo(a[i]) && !KiemTraX(SNT,k,a[i]))
        {
            SNT[k++] = a[i]; //Gan a[i] vao mang SNT va tang k them 1 don vi
        }
    }
    return k;     //Tra ve bien k dem cac so nguyen to khac nhau
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
    int a[MAX],n;
    NhapMang(a,n);  //Nhap mang can xet
    //Dem cac phan tu co chu so tan cung la 6 va chia het cho 6
    cout << "Co " << Dem6VaChiaHet6(a,n) << " phan tu co chu so tan cung la 6 va chia het cho 6" << endl;
    //Tinh trung binh cong cua cac so nguyen to co trong mang
    cout << "Trung binh cong cua cac so nguyen to la: " << TrungBinhCongSNT(a,n) << endl;
    //Dem so nguyen to phan biet trong mang
    cout << "Trong mang co " << DemSNTPhanBiet(a,n) << " so nguyen to phan biet" << endl;
    return 0;
}
