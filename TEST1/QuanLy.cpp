#pragma once
#include <iostream>
#include "QuanLy.h"
#include "SV.h"
#include<iomanip>

quanLySinhVien::quanLySinhVien() {
    sinhVien* p = nullptr;
    length = 0;
}

quanLySinhVien::~quanLySinhVien() {
}

void quanLySinhVien::Insert(sinhVien *sv, int n) {
    length = n;
    for (int i = 0; i < n; i++) {
        cout << "Nhap MSSV cua sv " << i+1 << " ";
        scanf_s("%d", &(sv + i)->MSSV);
        getchar();
        cout << "Nhap ten cua sv " << i + 1 << " ";
        gets_s((sv + i)->name);
        cout << "Nhap ngay sinh cua sv " << i + 1 << " ";
        gets_s((sv + i)->date);
    }
    
}

void quanLySinhVien::Add(sinhVien* &sv, int oldLength, int newLength) {
    sinhVien* new_sv;
    length = newLength;
    new_sv = (sinhVien*)malloc(newLength * sizeof(sinhVien));
    for (int i = 0; i < oldLength; i++) {
        new_sv[i] = sv[i];
    }
    //delete[] sv;
    cout << "Nhap MSSV cua sv " << newLength << " ";
    scanf_s("%d", &(new_sv + oldLength)->MSSV);
    getchar();
    cout << "Nhap ten cua sv " << newLength << " ";
    gets_s((new_sv + oldLength)->name);
    cout << "Nhap ngay sinh cua sv " << newLength << " ";
    gets_s((new_sv + oldLength)->date);

    sv = (sinhVien*)malloc((newLength) * sizeof(sinhVien));
    for (int i = 0; i < newLength; i++) {
        sv[i] = new_sv[i];
    }
    //delete[] new_sv;
}

int quanLySinhVien::indexOf(sinhVien* sv,long mssv) {
    for (int i = 0; i < length; i++) {
        if ((sv + i)->MSSV == mssv) {
            Show(sv,i);
        }
    }
    return 0;
}

void quanLySinhVien::Remove(sinhVien* &sv) {
    sv = (sinhVien*)malloc(0 * sizeof(sinhVien));
    length = 0;
    cout << "Deleted !!"<<endl;
}

void quanLySinhVien::RemoveAt(sinhVien* &sv, int index) {
    int _index = index - 1;
    sinhVien* new_sv;
    new_sv = (sinhVien*)malloc((length - 1) * sizeof(sinhVien));
    if (index > length) {
        cout << "@@ on k v 3 ??" << endl;
        exit(0);
    }
    else if (index == 1) {
        for (int i = 0; i < length-1; i++) {
            new_sv[i] = sv[i+1];
        }
    }
    else if (index == length) {
        for (int i = 0; i < _index; i++) {
            new_sv[i] = sv[i];
        }
    }
    else {
        for (int i = 0; i < _index; i++) {
            new_sv[i] = sv[i];
        }
        for (int j = _index; j < length - 1; j++) {
            new_sv[j] = sv[j + 1];
        }
    }
    length--;
    sv = (sinhVien*)malloc((length) * sizeof(sinhVien));
    for (int i = 0; i < length; i++) {
        sv[i] = new_sv[i];
    }
}

int quanLySinhVien::getLength(sinhVien* sv) {
    return length;
}

void quanLySinhVien::Update(sinhVien* &sv,int mssv) {
    for (int i = 0; i < length; i++) {
        if ((sv + i)->MSSV == mssv) {
            cout << "Nhap ten moi cua sinh vien : ";
            getchar();
            gets_s((sv + i)->name);
            cout << "Nhap ngay sinh moi cua sv ";
            gets_s((sv + i)->date);
            cout << "Updated !!" << endl;
            Show(sv,-1);
        }
    }
}

void quanLySinhVien::Show(sinhVien* sv, int index = -1) {
    if (length > 0 && index == -1) {
        cout <<"STT" << setw(15) << "MSSV" << setw(15) << "Ten" << setw(30) << "Ngay Sinh" << endl;
        for (int i = 0; i < length; i++) {

            cout <<" "<< i + 1 << setw(20) << (sv + i)->MSSV << setw(20) << (sv + i)->name << setw(15) << (sv + i)->date << endl;
        }
    }
    else if (length > 0 && index != -1) {
        cout << "STT" << setw(15) << "MSSV" << setw(15) << "Ten" << setw(30) << "Ngay Sinh" << endl;
        cout << " " << index + 1 << setw(20) << (sv + index)->MSSV << setw(20) << (sv + index)->name << setw(15) << (sv + index)->date << endl;
    }
    else {
        cout << "Nothing to show @@ !!"<<endl;
    }
}

