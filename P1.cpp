//VCT nhập vào  N số  thực từ  bàn phím và lưu vào mảng các số  thực, cho biết trong  mảng có bao nhiêu số âm.

#include <iostream>
using namespace std;
#define MAX 1000

//Ham dem so phan tu am trong mang
int DemSoAm(double a[], int n)
{
    int dem = 0;
    //Dung vong lap for de xet tat ca phan tu trong mang
    for(int i = 0; i < n; i++)
    {
        //Neu tim duoc phan tu am thi tang bien dem them 1 don vi
        if(a[i] < 0) dem++;
    }
    return dem; //Tra ve so phan tu am
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
            {
                cin >> a[i];
            }
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
    double a[MAX];
    int n;
    NhapMang(a,n);  //Nhap vao mang can xet
    //Dem so am trong mang
    cout << "Trong mang co " << DemSoAm(a,n) << " so am";
    return 0;
}
