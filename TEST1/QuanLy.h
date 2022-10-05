#pragma once
#include "SV.h"
#include <stdio.h>
#include <stdlib.h>
class quanLySinhVien{

private:
    sinhVien* p;
    int length;
public:
    quanLySinhVien();
    ~quanLySinhVien();
    void Insert(sinhVien*, int);
    void Add(sinhVien*&, int, int);
    int indexOf(sinhVien*,long);
    void RemoveAt(sinhVien*&,int index);
    void Remove(sinhVien*&);
    void Show(sinhVien*,int);
    void Update(sinhVien*&, int); // truyen mssv -> edit info !mssv
    int getLength(sinhVien* sv); // tra ve length of SV
};
