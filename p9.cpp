//VCT nhập 2 dãy số nguyên A, B gồm m, n phần tử (1 ≤ n, m ≤ 25):
//a) Xuất ra những phần tử có trong A mà không có trong B.
//b) Ghép A, B thành C sao cho C không có phần tử trùng nhau.

#include <iostream>
using namespace std;
#define MAX 1000

//Ham xuat cac phan tu co trong A nhung khong co trong B, truyen cac phan tu do vao mang c
void XuatPhanTuCoAKhongB(int a[], int n, int b[], int m, int c[], int& k)
{
    k = 0;
    //Dung vong lap for de xet tat ca phan tu trong a
    for(int i = 0; i < n; i++)
    {
        bool flag = true;   //Gan bien falg bang true
        //Dung vong lap de xet tat ca phan tu trong b
        for(int j = 0; j < m; j++)
        {
            //So sanh tung phan tu cua a voi tat ca phan tu cua b
            if(a[i] == b[j])    //Neu co a[i] = b[j] thi gan false cho bien flag va thoat khoi vong lap j
            {
                flag = false;
                break;
            }
        }
        if(flag)    //Neu bien flag = true thi gan gia tri cua a[i] cho c[k]
        {
            c[k] = a[i];
            k++;    //Tang so phan tu cua c them 1 don vi
        }
    }
    cout << "Cac phan tu co trong a nhung khong co trong b la: ";
    XuatMang(c,k);  //Xuat mang c chua tat ca phan tu co trong a nhung khong co trong b
    cout << endl;
}

//Dinh nghia ham xoa mot phan tu khi biet vi tri
void XoaPhanTu(int a[], int& n, int viTri)
{
    if(viTri<0) return;
    //Tao vong lap thay doi cac gia tri trong mang voi i tu viTri
    for(int i = viTri; i < n; i++)
    {
        //Gan gia tri cua phan tu sau cho phan tu truoc 
        //Nhu vay ta da cat bo duoc gia tri cua phan tu viTri
        a[i] = a[i+1];
    }
    n--;    //Vi xoa di mot phan tu nen n giam di mot don vi
}

//Ham ghepa va b vao c va xoa cac phan tu trung
void GhepMang(int a[], int n, int b[], int m, int c[], int& k)
{
    k = 0;
    //Dung vong lap for de gan tung gia tri cua phan tu mang a vao mang c
    for(int i = 0; i < n ; i++)
    {
        //Bat dau gan c tu vi tri k, sau moi lan gan k tang them 1 don vi
        c[k++] = a[i];
    }
    //Dung vong lap for de tiep tuc gan tung gia tri cua phan tu mang b vao mang c
    for(int i = 0; i < m ; i++)
    {
        //Bat dau gan c tu vi tri k, sau moi lan gan k tang them 1 don vi
        c[k++] = b[i];
    }

    //Xoa cac phan tu bi trung trong c
    for(int i = 0; i < k; i++)
    {
        for(int j = i+1; j < k; j++)
        {
            //Neu tim duoc c[j] = c[i] thi xoa c[j] do
        	if(c[i] == c[j]) XoaPhanTu(c,k,j);
		}
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
void XuatMang(int a[], int n)
{
    //Dung vong lap for de xuat tung gia tri cua mang
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int a[MAX], b[MAX];
    int n, m;
    cout << "Nhap mang a: " << endl;
    NhapMang(a,n);
    cout << "Nhap mang b: " << endl;
    NhapMang(b,m);
    int k = m + n, c[k];    //c chua nhieu nhat m + n phan tu

    //Xuat cac phan tu co trong A nhung khong co trong b
    XuatPhanTuCoAKhongB(a,n,b,m,c,k);

    //Ghep 2 mang a va b thanh mang c sao cho trong c khong co phan tu trung nhau
    GhepMang(a,n,b,m,c,k);
    cout << "Mang sau khi ghep: ";
    XuatMang(c,k);
    return 0;
}
