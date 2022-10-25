#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

struct SINHVIEN
{
	char hoTen[100];
	char ngayThangNamSinh[50];
	char lop[20];
	char mssv[20];
	float diemTB;
	unsigned int nguoiThan;
};

void nhap(SINHVIEN &a);
void nhapSV(SINHVIEN a[], int &n);
void xuat(SINHVIEN a);
void xuatSV(SINHVIEN a[], int n);
void maxTB(SINHVIEN a[], int n);
void testStudentcode(SINHVIEN a[], int n);
void getName(char hovaTen[], char temp[]);
void testStudentName(SINHVIEN a[], int n);
void testClass(SINHVIEN a[], int n);
void ktNguoiThan(SINHVIEN a[], int n);