#ifndef functions_h
#define functions_h
#include <math.h>

/*   * означает, что функция еще не проверена на корректность работы
     ** означает, что функция объявлена полностью в заголовочном файле, но не объявлена в .cpp
     *** означает, что функция не объявлена до конца в заголовочном файле (здесь) */

/* Следующие функции используют перегрузку имен. Они конвертируют варианты представления углов.
    На вход необходимо подать первоначальную величину и адрес переменной, в которую нужно поместить результат.*/
//эти функции необязательно нужны здесь

/* функция находит счислимые азимут и высоту звезды и помещает их в структуру, на которую указывает указатель.
    На вход функции подаются также счислимая широта, местный часовой угол и склонение звезды
    lat -- счислимая широта, вводится пользователем;
    HA -- часовой угол, находится с помощью функции findHA
    decl -- видимое склонение, находится с помощью функции findDecl*/
double Az(double lat, double HA, double decl);  //*
double Ht(double lat, double HA, double decl);

/*функция находит местный часовой угол, который отсчитывается к западу от южного меридиана
    Grin -- истинное звездное время Гринвича, находится с помощью функции findGrin
    lon -- счислимая долгота, задается пользователем;
    RA -- видимое прямое восхождение, находится с помощью функции findRA*/
double findHA(double Grin, double lon, double RA); //*

/*функция находит видимое склонение небесного тела*/
//DMS findDecl();   // ***

/*функция находит видимое прямое восхождение небесного тела*/
//HMS findRA();       //  ***

/*функция находит истинное звездное время Гринвича в часах(стр. 38 Меес)
    Это не что иное, как Гринвический часовой угол точки Овна
    Date -- Дата, в дальнейшем ее надо преобразовать в Юлианскую с помощью функции findJD;
    Time -- Время в часах, минутах и секундах, задается пользователем
        В этой функции не учитывается поправка за нутацию. */
double findGrin(int Y, int Mon, float D, int H, float Min, float S);   //        *

//переход от эклиптических координат к экваториальным
double RAfromECL(double lambda, double beta, double E);
double DECLfromECL(double lambda, double beta, double E);

/*поправка за нутацию и аберрацию прямого восхождения*/
double DeltaNutAberRA(int Y, int Mon, float D, double RA, double decl);

/*поправка за нутацию и аберрацию склонения
    эта и предыдущие поправки применяются после исправления за прецессию и годовое изменение*/
double DeltaNutAberDecl(int Y, int Mon, float D, double RA);

//поправки за прецессию и собственное движение звезды.
 // на вход подаются средние координаты на начальную эпоху, изменение их и искомая эпоха
double DeltaPrecMovRA(double RA, double decl,double uRA, double JD);
double DeltaPrecMovDecl(double RA, double decl,double uDec, double JD);

/*функция преобразует дату в формате год - мес -день в Юлианскую дату*/
double findJD(int Y, int Mon, double D); //   *

//Решение уравнения Кеплера -- нахождение эксцентрической аномалии E
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
//определение азимута и высоты звезды. функция для консольного варианта
void star();

//определение азимута и высоты Солнца. функция для консольного варианта
void Sun();

//определение азимута и высоты Луны. функция для консольного варианта
void Moon();

//определение азимута и высоты одной из четырех навигационных планет. функция для консольного варианта
void planet();
#endif // functions_h
