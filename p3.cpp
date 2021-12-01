//VCT nhập một mảng số nguyên có n phần tử, xây dựng các hàm thực hiện: 
//a)  Kiểm tra mảng có đối xứng không. 
//b)  Kiểm tra mảng có đan xen âm dương không. 
//c)  Kiểm tra mảng có tất cả các cặp phần tử đứng cạnh nhau đều có giá trị khác nhau.
//d) Kiểm tra mảng có tất cả bộ 3 phần tử đứng cạnh nhau lập thành cấp số cộng. 

#include <iostream>
using namespace std;
#define MAX 1000

//Ham kiem tra xem mang co doi xung hay khong
bool MangDoiXung(int a[], int n)
{
    //Ta chi kiem tra so doi xung voi i chay tu 0 den n/2
    for(int i = 0; i <= n/2; i++)
        //Neu ton tai a[i] khac a[n-1-i] thi day khong phai la mang doi xung
        if(a[i] != a[n-1-i]) return false;
    return true;    //Nguoc lai, tra ve true
}

//Ham kiem tra cac phan tu trong mang co dan xen am duong hay khong
bool DanXenAmDuong(int a[], int n)
{
    //Dung vong lap for de xet den tat ca phan tu trong mang
    //Vi tinh tich hai so ke nhau nen i < n-1
    for(int i = 0; i < n - 1; i++)
        //Neu ton tai a[i]*a[i+1] >= 0 
        //Luc do a[i] va a[i+1] cung dau, tra ve false
        if(a[i]*a[i+1] >= 0) return false;
    return true;    //Nguoc lai tra ve true
}

//Ham kiem tra tat ca cac cap phan tu dung canh nhau trong mang co khac nhau khong
bool PhanTuCanhNhauKhacNhau(int a[], int n)
{
    //Dung vong lap for de xet den tat ca phan tu trong mang
    //Vi xet hai so ke nhau nen i < n-1
    for(int i = 0; i < n - 1; i++)
        //Neu ton tai a[i] = a[i+1] thi tra ve false
        if(a[i] == a[i+1]) return false;
    return true;    //Nguoc lai, tra ve true
}

//Ham kiem tra tat ca bo 3 phan tu dung canh nhau trong mang co lap thanh mot cap so cong hay khong
bool CapSoCong(int a[], int n)
{
    //Dung vong lap for de xet den tat ca phan tu trong mang
    //Vi xet ba so ke nhau nen i chay tu 1 den n-1
    for(int i = 1; i < n - 1; i++)
        //a,b,c so la cap so cong neu 2b = a + c
        //Neu tim ton tai ba so a[i-1] + a[i+1] != 2 * a[i] thi tra ve false
        if(a[i-1] + a[i+1] != 2 * a[i]) return false;
    return true;    //Nguoc lai tra ve true
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

    //Kiem tra xem mang co doi xung hay khong
    if(MangDoiXung(a,n))
        cout << "Day la mang doi xung!" << endl;
    else 
        cout << "Day khong phai la mang doi xung!" << endl;

    //Kiem tra cac phan tu trong mang co dan xen am duong hay khong
    if(DanXenAmDuong(a,n))
        cout << "Cac phan tu trong mang co dan xen am duong!" << endl;
    else 
        cout << "Cac phan tu trong mang khong dan xen am duong!" << endl;

    //Kiem tra tat ca cac cap phan tu dung canh nhau trong mang co khac nhau khong
    if(PhanTuCanhNhauKhacNhau(a,n))
        cout << "Tat ca cac cap phan tu dung canh nhau trong mang co khac nhau!" << endl;
    else 
        cout << "Ton tai cap phan tu dung canh nhau trong mang giong nhau!" << endl;

    //Kiem tra tat ca bo 3 phan tu dung canh nhau trong mang co lap thanh mot cap so cong hay khong
    if(CapSoCong(a,n))
        cout << "Tat ca bo 3 phan tu dung canh nhau trong mang co lap thanh mot cap so cong!" << endl;
    else 
        cout << "Ton tai bo 3 phan tu dung canh nhau trong mang khong lap thanh mot cap so cong!" << endl;
        
    return 0;
}
