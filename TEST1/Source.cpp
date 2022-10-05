#include "SV.h"
#include "QuanLy.h"
using namespace std;
sinhVien* sv;
int n;
void pressAnyKey() {
    cout << "\n\nBam phim bat ky de tiep tuc...";
    getchar();
    system("cls");
}

int main() {
	quanLySinhVien db;
    int key;
    while (true) {
        std::cout << "CHUONG TRINH QUAN LY SINH VIEN C/C++\n";
        std::cout << "*************************MENU**************************\n";
        std::cout << "**  1. Them sinh vien.                               **\n";
        std::cout << "**  2. Them 1 sinh vien.                             **\n";
        std::cout << "**  3. Xoa sinh vien theo STT.                       **\n";
        std::cout << "**  4. Xoa toan bo sinh vien                         **\n";
        std::cout << "**  5. Tim kiem sinh vien theo MSSV va sua thong tin.**\n";
        std::cout << "**  8. Tim kiem sinh vien theo MSSV.                 **\n";
        std::cout << "**  6. Hien thi danh sach sinh vien.                 **\n";
        std::cout << "**  7. Hien thi so luong sinh vien.                  **\n";
        std::cout << "**  0. Thoat                                         **\n";
        std::cout << "*******************************************************\n";
        std::cout << "Nhap tuy chon: ";
        std::cin >> key;
        switch (key) {
        case 1:

            cout << "Nhap so luong sv can them "; cin >> n;
            sv = (sinhVien*)malloc(n * sizeof(sinhVien));
            db.Insert(sv, n);
            pressAnyKey();
            break;
        case 2:
            n = db.getLength(sv);
            db.Add(sv,n,n+1);
            pressAnyKey();
            break;
        case 3:
            int index;
            cout << "Nhap STT sinh vien can xoa : "; cin >> index;
            db.RemoveAt(sv,index);
            pressAnyKey();
            break;
        case 4:
            db.Remove(sv);
            pressAnyKey();
            break;
        case 5:
            long x;
            cout << "Nhap MSSV can sua : "; cin >> x;
            db.Update(sv, x);
            pressAnyKey();
            break;
        case 6:
            db.Show(sv,-1);
            system("pause");
            pressAnyKey();
            break;
        case 7:
            cout << db.getLength(sv) << endl;
            system("pause");
            pressAnyKey();
            break;
        case 8:
            long y;
            cout << "Nhap MSSV can tim : "; cin >> y;
            db.indexOf(sv,y);
            system("pause");
            pressAnyKey();
            break;
        case 0:
            std::cout << "\nBan da chon thoat chuong trinh!";
            return 0;
        default:
            std::cout << "\nKhong co chuc nang nay!";
            std::cout << "\nHay chon chuc nang trong hop menu.";
            break;
        }
    }

}
	