#ifndef functions_h
#define functions_h
#include <math.h>

/*   * ��������, ��� ������� ��� �� ��������� �� ������������ ������
     ** ��������, ��� ������� ��������� ��������� � ������������ �����, �� �� ��������� � .cpp
     *** ��������, ��� ������� �� ��������� �� ����� � ������������ ����� (�����) */

/* ��������� ������� ���������� ���������� ����. ��� ������������ �������� ������������� �����.
    �� ���� ���������� ������ �������������� �������� � ����� ����������, � ������� ����� ��������� ���������.*/
//��� ������� ������������� ����� �����

/* ������� ������� ��������� ������ � ������ ������ � �������� �� � ���������, �� ������� ��������� ���������.
    �� ���� ������� �������� ����� ��������� ������, ������� ������� ���� � ��������� ������
    lat -- ��������� ������, �������� �������������;
    HA -- ������� ����, ��������� � ������� ������� findHA
    decl -- ������� ���������, ��������� � ������� ������� findDecl*/
double Az(double lat, double HA, double decl);  //*
double Ht(double lat, double HA, double decl);

/*������� ������� ������� ������� ����, ������� ������������� � ������ �� ������ ���������
    Grin -- �������� �������� ����� ��������, ��������� � ������� ������� findGrin
    lon -- ��������� �������, �������� �������������;
    RA -- ������� ������ �����������, ��������� � ������� ������� findRA*/
double findHA(double Grin, double lon, double RA); //*

/*������� ������� ������� ��������� ��������� ����*/
//DMS findDecl();   // ***

/*������� ������� ������� ������ ����������� ��������� ����*/
//HMS findRA();       //  ***

/*������� ������� �������� �������� ����� �������� � �����(���. 38 ����)
    ��� �� ��� ����, ��� ������������ ������� ���� ����� ����
    Date -- ����, � ���������� �� ���� ������������� � ��������� � ������� ������� findJD;
    Time -- ����� � �����, ������� � ��������, �������� �������������
        � ���� ������� �� ����������� �������� �� �������. */
double findGrin(int Y, int Mon, float D, int H, float Min, float S);   //        *

//������� �� ������������� ��������� � ��������������
double RAfromECL(double lambda, double beta, double E);
double DECLfromECL(double lambda, double beta, double E);

/*�������� �� ������� � ��������� ������� �����������*/
double DeltaNutAberRA(int Y, int Mon, float D, double RA, double decl);

/*�������� �� ������� � ��������� ���������
    ��� � ���������� �������� ����������� ����� ����������� �� ��������� � ������� ���������*/
double DeltaNutAberDecl(int Y, int Mon, float D, double RA);

//�������� �� ��������� � ����������� �������� ������.
 // �� ���� �������� ������� ���������� �� ��������� �����, ��������� �� � ������� �����
double DeltaPrecMovRA(double RA, double decl,double uRA, double JD);
double DeltaPrecMovDecl(double RA, double decl,double uDec, double JD);

/*������� ����������� ���� � ������� ��� - ��� -���� � ��������� ����*/
double findJD(int Y, int Mon, double D); //   *

//������� ��������� ������� -- ���������� ��������������� �������� E
double findE(double M, double e);

double HmsToDeg(float H, float M, float S);
double DmsToDeg(float D, float M, float S);
double DmToDeg(double D, double M, double Dec);
double RadToDeg(double rad);
double DegToRad(double deg);

float findPcosL(float H,float lat);
float findPsinL(float H,float lat);

double Venus_L0 (double t);
double Venus_L1 (double t);
double Venus_L2 (double t);
double Venus_L3 (double t);
double Venus_L4 (double t);
double Venus_L5 (double t);
double Venus_B0 (double t);
double Venus_B1 (double t);
double Venus_B2 (double t);
double Venus_B3 (double t);
double Venus_B4 (double t);
double Venus_B5 (double t);
double Venus_R0 (double t);
double Venus_R1 (double t);
double Venus_R2 (double t);
double Venus_R3 (double t);
double Venus_R4 (double t);
double Venus_R5 (double t);

double Mars_L0 (double t);
double Mars_L1 (double t);
double Mars_L2 (double t);
double Mars_L3 (double t);
double Mars_L4 (double t);
double Mars_L5 (double t);
double Mars_B0 (double t);
double Mars_B1 (double t);
double Mars_B2 (double t);
double Mars_B3 (double t);
double Mars_B4 (double t);
double Mars_B5 (double t);
double Mars_R0 (double t);
double Mars_R1 (double t);
double Mars_R2 (double t);
double Mars_R3 (double t);
double Mars_R4 (double t);
double Mars_R5 (double t);

double Jupiter_L0 (double t);
double Jupiter_L1 (double t);
double Jupiter_L2 (double t);
double Jupiter_L3 (double t);
double Jupiter_L4 (double t);
double Jupiter_L5 (double t);
double Jupiter_B0 (double t);
double Jupiter_B1 (double t);
double Jupiter_B2 (double t);
double Jupiter_B3 (double t);
double Jupiter_B4 (double t);
double Jupiter_B5 (double t);
double Jupiter_R0 (double t);
double Jupiter_R1 (double t);
double Jupiter_R2 (double t);
double Jupiter_R3 (double t);
double Jupiter_R4 (double t);
double Jupiter_R5 (double t);

double Saturn_L0 (double t);
double Saturn_L1 (double t);
double Saturn_L2 (double t);
double Saturn_L3 (double t);
double Saturn_L4 (double t);
double Saturn_L5 (double t);
double Saturn_B0 (double t);
double Saturn_B1 (double t);
double Saturn_B2 (double t);
double Saturn_B3 (double t);
double Saturn_B4 (double t);
double Saturn_B5 (double t);
double Saturn_R0 (double t);
double Saturn_R1 (double t);
double Saturn_R2 (double t);
double Saturn_R3 (double t);
double Saturn_R4 (double t);
double Saturn_R5 (double t);

double sind(double deg);
double cosd(double deg);
double tand(double deg);
double asind(double sn);
double atand(double tg);

double TypeLat(char lat[7]);
//����������� ������� � ������ ������. ������� ��� ����������� ��������
void star();

//����������� ������� � ������ ������. ������� ��� ����������� ��������
void Sun();

//����������� ������� � ������ ����. ������� ��� ����������� ��������
void Moon();

//����������� ������� � ������ ����� �� ������� ������������� ������. ������� ��� ����������� ��������
void planet();
#endif // functions_h
