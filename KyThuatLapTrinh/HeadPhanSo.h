
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <iostream>

struct PHANSO
{
	int tu;
	int mau;
};

void nhap(PHANSO a[], int &n);

void xuat(PHANSO a[], int n);

int ucln(int a, int b);

PHANSO rutGonPS(PHANSO a);

PHANSO congPhanSo(PHANSO a[], int n);

PHANSO tichPhanSo(PHANSO a[], int n);

PHANSO maxPS(PHANSO a[], int n);

PHANSO minPS(PHANSO a[], int n);

void distanceMax(PHANSO a[], int n);
