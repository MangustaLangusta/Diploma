#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include<fstream>
#include<stdio.h>
#include<math.h>
#include"functions.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_comboBox_2_activated(const QString &arg1)
{

}

void MainWindow::on_comboBox_2_highlighted(const QString &arg1)
{

}

void MainWindow::on_radioButton_clicked()
{
        ui->comboBox_2->clear();  //Здесь звезды с видимой звездной величиной 2,0 и меньше (есть несколько исключений)
        ui->comboBox_2->addItem("Авиор");        //HYP #41037
        ui->comboBox_2->addItem("Адхара");       //HYP #33579
        ui->comboBox_2->addItem("Акрукс");       //HYP #60718
        ui->comboBox_2->addItem("Алиот");        //HYP #62956
        ui->comboBox_2->addItem("Альдебаран");   //HYP #21421
        ui->comboBox_2->addItem("Альнилам");     //HYP #26311
        ui->comboBox_2->addItem("Альтаир");      //HYP #97649
        ui->comboBox_2->addItem("Альферац");     //HYP #677
        ui->comboBox_2->addItem("Антарес");      //HYP #80763
        ui->comboBox_2->addItem("Арктур");       //HYP #69673
        ui->comboBox_2->addItem("Атриа");        //HYP #82273
        ui->comboBox_2->addItem("Ахернар");      //HYP #7588
        ui->comboBox_2->addItem("Бетельгейзе");  //HYP #27989
        ui->comboBox_2->addItem("Вега");         //HYP #91262
        ui->comboBox_2->addItem("Денеб");        //HYP #102098
        ui->comboBox_2->addItem("Дубхе");        //HYP #54061
        ui->comboBox_2->addItem("Жаула");        //HYP #85927
        ui->comboBox_2->addItem("Канопус");      //HYP #30438
        ui->comboBox_2->addItem("Капелла");      //HYP #24608
        ui->comboBox_2->addItem("Миаплацидус");  //HYP #45238
        ui->comboBox_2->addItem("Мимоза");       //HYP #62434
        ui->comboBox_2->addItem("Мирзам");       //HYP #30324
        ui->comboBox_2->addItem("Мирфак");       //HYP #15863
        ui->comboBox_2->addItem("Нат");          //HYP #25428
        ui->comboBox_2->addItem("Поллукс");      //HYP #37826
        ui->comboBox_2->addItem("Полярная");     //HYP #11767
        ui->comboBox_2->addItem("Процион");      //HYP #37279
        ui->comboBox_2->addItem("Регул");        //HYP #49669
        ui->comboBox_2->addItem("Ригель");       //HYP #24436
        ui->comboBox_2->addItem("Ригил-Кентавр");//HYP #71683
        ui->comboBox_2->addItem("Сириус");       //HYP #32349
        ui->comboBox_2->addItem("Спика");        //HYP #65474
        ui->comboBox_2->addItem("Фомальхаут");   //HYP #113368
        ui->comboBox_2->addItem("Хадар");        //HYP #68702
        ui->comboBox_2->addItem("Хамаль");       //HYP #9884

}

void MainWindow::on_radioButton_2_clicked()
{
    ui->comboBox_2->clear();
    ui->comboBox_2->addItem("Солнце");
    ui->comboBox_2->addItem("Луна");
    ui->comboBox_2->addItem("Венера");
    ui->comboBox_2->addItem("Марс");
    ui->comboBox_2->addItem("Юпитер");
    ui->comboBox_2->addItem("Сатурн");
}

void MainWindow::on_comboBox_2_currentTextChanged(const QString &arg1)
{

}

void MainWindow::on_lat_deg_edit_textEdited(const QString &arg1)
{
    int A = ui->lat_deg_edit->text().toInt();
    if (A>59) ui->lat_deg_edit->clear();
           else if(ui->lat_deg_edit->text().length()==2) {
        ui->lat_min_edit->setFocus();
        }
    if (check_inputs()) find_coordinates();
}

void MainWindow::on_lat_min_edit_textEdited(const QString &arg1)
{
    int A = ui->lat_min_edit->text().toInt();
    if (A>59) ui->lat_min_edit->clear();
           else if(ui->lat_min_edit->text().length()==2) {
        ui->lat_dec_edit->setFocus();
    }
    if (check_inputs()) find_coordinates();
}

void MainWindow::on_lat_dec_edit_textEdited(const QString &arg1)
{
    ui->NS_comboBox->setFocus();
    if (check_inputs()) find_coordinates();
}

void MainWindow::on_lon_deg_edit_textEdited(const QString &arg1)
{
    int A = ui->lon_deg_edit->text().toInt();
    if (A>179) ui->lon_deg_edit->clear();
           else if(ui->lon_deg_edit->text().length()==3) {
        ui->lon_min_edit->setFocus();
        }
    if (check_inputs()) find_coordinates();
}

void MainWindow::on_lon_min_edit_textEdited(const QString &arg1)
{
    int A = ui->lon_min_edit->text().toInt();
    if (A>59) ui->lon_min_edit->clear();
           else if(ui->lon_min_edit->text().length()==2) {
        ui->lon_dec_edit->setFocus();
        }
    if (check_inputs()) find_coordinates();
}

void MainWindow::on_lon_dec_edit_textEdited(const QString &arg1)
{
    ui->EW_comboBox->setFocus();
    if (check_inputs()) find_coordinates();
}

bool MainWindow::check_inputs()
{
    if ((ui->lat_deg_edit->text().isEmpty())||(ui->lon_deg_edit->text().isEmpty())||(ui->lat_min_edit->text().isEmpty())||(ui->lon_min_edit->text().isEmpty())||(ui->lat_dec_edit->text().isEmpty())||(ui->lon_dec_edit->text().isEmpty())||(ui->comboBox_2->currentText().isEmpty())) {
        return (false);
    }
    else return (true);
}

void MainWindow::find_coordinates()
{
    ui->label_6->setText("Пеленг:");
    ui->label_7->setText("Высота:");
    ui->SkyBody_name->setText(ui->comboBox_2->currentText());
    if (ui->radioButton->isChecked()) {  //если выбрана первая радиокнопка (звезды)
        star();
    }
    if (ui->radioButton_2->isChecked()){ //если выбрана вторая радиокнопка (Солнце, Луна, планеты)
        if (ui->comboBox_2->currentText()=="Солнце"){ //ищем координаты Солнца
            ui->SkyBody_name->setText("Солнце");
            Sun();
        }
        else if (ui->comboBox_2->currentText()=="Луна"){ //ищем координаты Луны
            ui->SkyBody_name->setText("Луна");
            Moon();
        }
        else { //ищем координаты одной из планет
            ui->SkyBody_name->setText(ui->comboBox_2->currentText());
            planet();
        }
    }
    ui->memo1_button->setEnabled(true);
    ui->memo2_button->setEnabled(true);
    ui->memo3_button->setEnabled(true);
}

void MainWindow::on_lat_deg_edit_textChanged(const QString &arg1)
{
    if (check_inputs()) find_coordinates();
}

void MainWindow::on_lat_min_edit_textChanged(const QString &arg1)
{
    if (check_inputs()) find_coordinates();
}

void MainWindow::on_lat_dec_edit_textChanged(const QString &arg1)
{
    if (check_inputs()) find_coordinates();
}

void MainWindow::on_lon_deg_edit_textChanged(const QString &arg1)
{
    if (check_inputs()) find_coordinates();
}

void MainWindow::on_lon_min_edit_textChanged(const QString &arg1)
{
    if (check_inputs()) find_coordinates();
}

void MainWindow::on_lon_dec_edit_textChanged(const QString &arg1)
{
    if (check_inputs()) find_coordinates();
}

void MainWindow::on_NS_comboBox_currentIndexChanged(const QString &arg1)
{
    if (check_inputs()) find_coordinates();
}

void MainWindow::on_EW_comboBox_currentIndexChanged(const QString &arg1)
{
    if (check_inputs()) find_coordinates();
}

void MainWindow::star(){
    double Grin;
    double lon,lat;
    double HA,SHA,RA,Decl;
    double A,H;
    int year, month, hour, minute, seconds,day;
    lat = DmToDeg(ui->lat_deg_edit->text().toDouble(),ui->lat_min_edit->text().toDouble(),ui->lat_dec_edit->text().toDouble());
    if (ui->NS_comboBox->currentText()=="S") lat = -lat;
    lon = DmToDeg(ui->lon_deg_edit->text().toDouble(),ui->lon_min_edit->text().toDouble(),ui->lon_dec_edit->text().toDouble());
    if (ui->EW_comboBox->currentText()=="W") lon = -lon;
    year = ui->dateEdit->dateTime().date().year();
    month = ui->dateEdit->dateTime().date().month();
    day = ui->dateEdit->dateTime().date().day();
    hour = ui->timeEdit->dateTime().time().hour();
    minute = ui->timeEdit->dateTime().time().minute();
    seconds = ui->timeEdit->dateTime().time().second();
    switch (ui->comboBox_2->currentIndex()){  //задание экваториальных координат звезды
        case 0: RA = 125.62860;  //("Авиор");        //HYP #41037
            Decl = -59.50954;
            break;
        case 1: RA = 104.65644;//Адхара");       //HYP #33579
            Decl = -28.97209;
            break;
        case 2: RA = 186.649756; //Акрукс      HYP #60718
            Decl = -63.099057;
            break;
        case 3: RA = 193.506804;//Алиот");        //HYP #62956
            Decl = 55.959843;
            break;
        case 4: RA = 68.980002;//Альдебаран");   //HYP #21421
            Decl = 16.509762;
            break;
        case 5: RA = 84.053385;//Альнилам");     //HYP #26311
            Decl = -1.201917;
            break;
        case 6: RA = 297.694508;//Альтаир");      //HYP #97649
            Decl = 8.867385;
            break;
        case 7: RA = 2.096534;//Альферац");     //HYP #677
            Decl = 29.090828;
            break;
        case 8: RA = 247.351948;//Антарес");      //HYP #80763
            Decl = -26.431946;
            break;
        case 9: RA = 213.918114;//Арктур");       //HYP #69673
            Decl = 19.187271;
            break;
        case 10: RA = 252.166107;//Атриа");        //HYP #82273
            Decl = -69.027635;
            break;
        case 11: RA = 24.428132;//Ахернар");      //HYP #7588
            Decl = -57.23666;
            break;
        case 12: RA = 88.792872;//Бетельгейзе");  //HYP #27989
            Decl = 7.407037;
            break;
        case 13: RA = 279.234108;//Вега");         //HYP #91262
            Decl = 38.782993;
            break;
        case 14: RA = 310.357973;//Денеб");        //HYP #102098
            Decl = 45.280334;
            break;
        case 15: RA = 165.932653;//Дубхе");        //HYP #54061
            Decl = 61.751119;
            break;
        case 16: RA = 263.402193;//Жаула");        //HYP #85927
            Decl = -37.103749;
            break;
        case 17: RA = 95.987978;//Канопус");      //HYP #30438
            Decl = -52.695718;
            break;
        case 18: RA = 79.172065;//Капелла");      //HYP #24608
            Decl = 45.999029;
            break;
        case 19: RA = 138.301003;//Миаплацидус");  //HYP #45238
            Decl = -69.717472;
            break;
        case 20: RA = 191.930494;//Мимоза");       //HYP #62434
            Decl = -59.688733;
            break;
        case 21: RA = 95.674947;//Мирзам");       //HYP #30324
            Decl = -17.955917;
            break;
        case 22: RA = 51.080619;//Мирфак");       //HYP #15863
            Decl = 49.861243;
            break;
        case 23: RA = 81.572908;//Нат");          //HYP #25428
            Decl = 28.607874;
            break;
        case 24: RA = 116.330683-0.000174*(findJD(year,month,day)-findJD(2000,1,1.0))/365.25;//Поллукс");      //HYP #37826
            Decl = 28.026310-0.0000127*(findJD(year,month,day)-findJD(2000,1,1.0))/365.25;
            break;
        case 25: RA = 37.946143;//Полярная");      //HYP #11767
            Decl = 89.2641378;
            break;
        case 26: RA = 114.827242;//Процион");      //HYP #37279
            Decl = 5.227508;
            break;
        case 27: RA = 152.09358;//Регул");        //HYP #49669
            Decl = 11.967195;
            break;
        case 28: RA = 78.634464;//Ригель");       //HYP #24436
            Decl = -8.20164;
            break;
        case 29: RA = 219.920410-0.001022*(findJD(year,month,day)-findJD(2000,1,1.0))/365.25;//Ригил-Кентавр");//HYP #71683
            Decl = -60.835145+0.000132*(findJD(year,month,day)-findJD(2000,1,1.0))/365.25;
            break;
        case 30: RA = 101.288541-0.000152*(findJD(year,month,day)-findJD(2000,1,1.0))/365.25;//Сириус");       //HYP #32349
            Decl = -16.713143-0.00034*(findJD(year,month,day)-findJD(2000,1,1.0))/365.25;
            break;
        case 31: RA = 201.298352;//Спика");        //HYP #65474
            Decl = -11.161245;
            break;
        case 32: RA = 344.411773;//Фомальхаут");   //HYP #113368
            Decl = -29.621837;
            break;
        case 33: RA = 210.956019;//Хадар");        //HYP #68702
            Decl = -60.372979;
            break;
        case 34: RA = 31.792858;//Хамаль");       //HYP #9884
            Decl = 23.462778;
            break;

    }

    double dNut, E_vis,C,O,T,MSun,LSun,omega,Lm,Mm,dE;//далее идут поправки за нутацию и абберрацию
    T = (findJD(year,month,day)-2415020.0)/36525.0; //время в Юлианских столетиях с 1900 янв,0
    MSun = 358.47583+35999.04975*T-0.000150*T*T-0.0000033*T*T*T;//средняя аномалия Солнца
    LSun = 279.69668+36000.76892*T+0.0003025*T*T;
    C = (1.919460-0.004789*T-0.000014*T*T)*sind(MSun)+(0.020094-0.000100*T)*sind(2*MSun)+0.000293*sind(3*MSun);
    O = LSun+C; //истинная долгота Солнца
    E_vis = 23.452294-0.0130125*T-0.00000164*T*T+0.000000503*T*T*T; //наклон эклиптики (не исправленный) по Меесу
    Lm = 270.4342+481267.8831*T-0.001133*T*T;//средняя долгота Луны
    Mm = 296.1046+477198.8491*T+0.009192*T*T; //средняя аномалия Луны
    omega = 259.18-1934.142*T+0.002078*T*T; //долгота восходящго узла
    O = O-0.00569-0.00479*sind(omega);
    double m,n;   //далее поправка за прецессию
    m = (3.07234+0.00186*T)*15/3600.0;
    n = (20.00468-0.0085*T)/3600.0;

    RA = RA+(m+n*sind(RA)*tand(Decl))*(findJD(year,month,day)-findJD(2000,1,1.0))/365.25;
    Decl = Decl+(n*cosd(RA))*(findJD(year,month,day)-findJD(2000,1,1.0))/365.25;
    cout<<(findJD(year,month,day)-findJD(1999,1,1.0))/365.25;
    dE = (9.21+0.00091*T)*cosd(omega)+(0.5522-0.00029*T)*cosd(2*LSun)-0.0904*cosd(2*omega)+0.0884*cosd(2*Lm)+0.0216*cosd(2*LSun+MSun)+0.0183*cosd(2*Lm-omega)+0.0113*cosd(2*Lm+Mm)-0.0093*cosd(2*LSun-MSun)-0.0066*cosd(2*LSun-omega);
    dE = dE/3600; //переводим dE в градусню меру
    E_vis = E_vis+dE;
    dNut = -(17.2327+0.01737*T)*sind(omega)-(1.2729+0.00013*T)*sind(2*LSun)+0.2088*sind(2*omega)-0.2037*sind(2*Lm)+(0.1261-0.00031*T)*sind(MSun)+0.0675*sind(Mm)-(0.0497-0.00012*T)*sind(2*LSun+MSun)-0.0342*sind(2*Lm-omega)-0.0261*sind(2*Lm+Mm)+0.0214*sind(2*LSun-MSun)-0.0149*sind(2*LSun-2*Lm+Mm)+0.0124*sind(2*LSun-omega)+0.0114*sind(2*Lm-Mm);
    dNut = dNut/3600;
    RA = RA - 0.005691666666667*((cosd(RA)*cosd(O)*cosd(E_vis)+sind(RA)*sind(O))/cosd(Decl));//за абберрацию
    Decl = Decl - 0.005691666666667*(cosd(O)*cosd(E_vis)*(tand(E_vis)*cosd(Decl)-sind(RA)*sind(Decl))+cosd(RA)*sind(Decl)*sind(O));//за абберрацию
    RA = RA+(cosd(E_vis)+sind(E_vis)*sind(RA)*tand(Decl))*dNut-(cosd(RA)*tand(Decl))*dE;
    Decl =Decl + (sind(E_vis)*cosd(RA))*dNut+sind(RA)*dE;
    Grin = findGrin(year,month,day,hour,minute,seconds);
    //cout<<"GHA Aries= "<<Grin*15<<endl;
    SHA = 360.0-RA;
    HA = findHA(Grin,lon,SHA);
    //cout<<"LHA= "<<HA<<endl;
    A = Az(lat,HA,Decl);
    H = Ht(lat,HA,Decl);
    ui->Bearing_label->setText(QString::number(round(A*10)/10)+QChar(176));
    ui->Height_label->setText(QString::number(int(H))+QChar(176)+QString::number(round(abs((H-int(H))*60)*10)/10)+"'");
    if ((int(H)==0)&&(H<0)) ui->Height_label->setText("-"+ui->Height_label->text());
    //cout<<"A = "<<A<<endl<<"H = "<<H;

    char index;
    if (Decl<0) index = 'S';
    else if (Decl>0) index = 'N';
    else index = ' ';

    ui->info_l1->setText("Прямое восхождение звезды:           "+QString::number(int(RA))+QChar(176)+QString::number(abs(round((RA-int(RA))*600)/10))+"'");
    ui->info_l2->setText("Склонение звезды:                           "+QString::number(abs(int(Decl)))+QChar(176)+QString::number(abs(round((Decl-int(Decl))*600)/10))+"'"+index);
    ui->info_l3->setText("Гринвичский часовой угол т. Овна:     "+QString::number(int(Grin*15))+QChar(176)+QString::number(abs(round((Grin*15-int(Grin*15))*600)/10))+"'");
    ui->info_l4->setText("Местный часовой угол звезды:         "+QString::number(int(HA))+QChar(176)+QString::number(abs(round((HA-int(HA))*600)/10))+"'");
}

void MainWindow::Sun() {
    double lat, lon, day;
    int year, month, hour, minute, seconds;
    lat = DmToDeg(ui->lat_deg_edit->text().toDouble(),ui->lat_min_edit->text().toDouble(),ui->lat_dec_edit->text().toDouble());
    if (ui->NS_comboBox->currentText()=="S") lat = -lat;
    lon = DmToDeg(ui->lon_deg_edit->text().toDouble(),ui->lon_min_edit->text().toDouble(),ui->lon_dec_edit->text().toDouble());
    if (ui->EW_comboBox->currentText()=="W") lon = -lon;
    year = ui->dateEdit->dateTime().date().year();
    month = ui->dateEdit->dateTime().date().month();
    day = ui->dateEdit->dateTime().date().day();
    hour = ui->timeEdit->dateTime().time().hour();
    minute = ui->timeEdit->dateTime().time().minute();
    seconds = ui->timeEdit->dateTime().time().second();
    double T, E_vis, O_vis, L, M, omega, C;
    double dJD;
    day = day+(hour+(minute+seconds/60.0)/60.0)/24.0;
    dJD = findJD(year,month,day)-findJD(1975,1,0.0);
    T = (findJD(year,month,day)-2415020.0)/36525.0; //????? ? ????????? ????????? ? 1900 ???, 0.5
    L = 279.69668+36000.76892*T+0.0003025*T*T; //??????? ?????????????? ??????? ?????? ?? ?????
    M = 358.47583+35999.04957*T-0.000150*T*T-0.0000033*T*T*T; //??????? ???????? ?????? ?? ????? ?????
    omega = 259.18-1934.142*T+0.002078*T*T; //??????? ?????????? ????
    while (omega<0) omega = omega + 360.0; //?????????? ????????????? ?????
    C = (1.919460-0.004789*T-0.000014*T*T)*sind(M)+(0.020094-0.000100*T)*sind(2*M)+0.000293*sind(3*M);
    E_vis = 23.452294-0.0130125*T-0.00000164*T*T+0.000000503*T*T*T; //?????? ????????? (?? ????????????) ?? ?????
    double dE,Lm,Mm; //??? ??? ???????? ?? ???????
    Lm = 270.4342+481267.8831*T-0.001133*T*T;//??????? ??????? ????
    Mm = 296.1046+477198.8491*T+0.009192*T*T; //??????? ???????? ????
    while(L>360) L = L-360.0;
    while(Lm>360) Lm = Lm-360.0;
    while(M>360) M = M-360.0;
    while(Mm>360) Mm = Mm-360.0;
    while(omega>360) omega = omega-360.0;
    dE = (9.21+0.00091*T)*cosd(omega)+(0.5522-0.00029*T)*cosd(2*L)-0.0904*cosd(2*omega)+0.0884*cosd(2*Lm)+0.0216*cosd(2*L+M)+0.0183*cosd(2*Lm-omega)+0.0113*cosd(2*Lm+Mm)-0.0093*cosd(2*L-M)-0.0066*cosd(2*L-omega);
    dE = dE/3600; //????????? dE ? ???????? ????
    E_vis = E_vis+0.00256*cosd(omega); //?????? ???????????? ??? ??????????? ??????? ????????? ??????
    E_vis = E_vis+dE; //??? ?????????, ??? ???????
    cout<<E_vis<<endl;
    O_vis = L+C; //???????? ??????? ??????
    O_vis = O_vis-0.00569-0.00479*sind(omega); //??????? ??????? ??????
    double a,b,c,d,e,h; //??? ?????????? ?????? ??????? ??????
    a = 153.23+22518.7541*T;
    b = 216.57+45037.5082*T;
    c = 312.69+32964.3577*T;
    d = 350.74+445267.1142*T;
    e = 231.19+20.20*T;
    h = 353.40+65928.7155*T;
    O_vis = O_vis + 0.00131*cosd(a)+0.00151*cosd(b)+0.002*cosd(c)+0.00179*sind(d)+0.00178*sind(e);//????? ??????? ???????? (????)
    double RA_O, decl_O;
    double tgRA;
    tgRA = cosd(E_vis)*sind(O_vis)/cosd(O_vis);
    if (tgRA<0) RA_O = 180.0-(atand(abs(tgRA)));//??????? ?????? ??????????? ??????
    else RA_O = atand(tgRA);
    if (RA_O>360) RA_O = RA_O-360;
    decl_O = asind(sind(E_vis)*sind(O_vis)); //??????? ????????? ??????
    if (decl_O<0) RA_O = RA_O +180;
    double GHA_O,LHA_O,Grin;
    Grin = findGrin(year,month,day,hour,minute,seconds);
    GHA_O = Grin-RA_O;
    if (GHA_O<0) GHA_O = GHA_O+360;
    LHA_O = findHA(Grin,lon,360.0-RA_O);
    double A,H;
    A = Az(lat, LHA_O, decl_O);
    H = Ht(lat, LHA_O, decl_O);
    ui->Bearing_label->setText(QString::number(round(A*10)/10)+QChar(176));
    ui->Height_label->setText(QString::number(int(H))+QChar(176)+QString::number(round(abs((H-int(H))*60)*10)/10)+"'");
    if ((int(H)==0)&&(H<0)) ui->Height_label->setText("-"+ui->Height_label->text());

    char index;
    if (decl_O<0) index = 'S';
    else if (decl_O>0) index = 'N';
    else index = ' ';

    ui->info_l1->setText("Прямое восхождение Солнца:           "+QString::number(int(RA_O))+QChar(176)+QString::number(abs(round((RA_O-int(RA_O))*600)/10))+"'");
    ui->info_l2->setText("Склонение Солнца:                           "+QString::number(abs(int(decl_O)))+QChar(176)+QString::number(abs(round((decl_O-int(decl_O))*600)/10))+"'"+index);
    ui->info_l3->setText("Гринвичский часовой угол т. Овна:     "+QString::number(int(Grin*15))+QChar(176)+QString::number(abs(round((Grin*15-int(Grin*15))*600)/10))+"'");
    ui->info_l4->setText("Местный часовой угол Солнца:         "+QString::number(int(LHA_O))+QChar(176)+QString::number(abs(round((LHA_O-int(LHA_O))*600)/10))+"'");
}

void MainWindow::Moon() {
    double lat, lon, dJD, T,day;
    int year, month, hour, minute, seconds;
    lat = DmToDeg(ui->lat_deg_edit->text().toDouble(),ui->lat_min_edit->text().toDouble(),ui->lat_dec_edit->text().toDouble());
    if (ui->NS_comboBox->currentText()=="S") lat = -lat;
    lon = DmToDeg(ui->lon_deg_edit->text().toDouble(),ui->lon_min_edit->text().toDouble(),ui->lon_dec_edit->text().toDouble());
    if (ui->EW_comboBox->currentText()=="W") lon = -lon;
    year = ui->dateEdit->dateTime().date().year();
    month = ui->dateEdit->dateTime().date().month();
    day = ui->dateEdit->dateTime().date().day();
    hour = ui->timeEdit->dateTime().time().hour();
    minute = ui->timeEdit->dateTime().time().minute();
    seconds = ui->timeEdit->dateTime().time().second();
    day = day+(hour+(minute+seconds/60.0)/60.0)/24.0;
    dJD = findJD(year,month,day)-findJD(1975,1,0.0);
    T = (findJD(year,month,day)-2415020.0)/36525.0; //время в Юлианских столетиях с 1900 янв, 0
    double Lm,M,Mm,D,F,omega;  //Lm и Mm это то же самое, что в книге Мееса L' и M'
    Lm = 270.434164+481267.8831*T-0.001133*T*T+0.0000019*T*T*T;
    M = 358.475833+35999.0498*T-0.000150*T*T-0.0000033*T*T*T;
    Mm = 296.104608+477198.8491*T+0.009192*T*T+0.0000144*T*T*T;
    D = 350.737486+445267.1142*T-0.001436*T*T+0.0000019*T*T*T;
    F = 11.250889+483202.0251*T-0.003211*T*T-0.0000003*T*T*T;
    omega = 259.183275-1934.1420*T+0.002078*T*T+0.0000022*T*T*T;
    double Ven; //"большое неравенство Венеры" (эту поправку добавлять к нескольким величинам
    Ven = 0.003964*sind(346.560+132.870*T-0.0091731*T*T);
    Lm = Lm+Ven+0.001964*sind(omega)+0.000233*sind(51.2+20.2*T); //Аддитивные члены
    M = M-0.001778*sind(51.2+20.2*T);
    Mm = Mm+Ven+0.002541*sind(omega)+0.000817*sind(51.2+20.2*T);
    D = D+Ven+0.002011*sind(51.2+20.2*T)+0.001964*sind(omega);
    F = F+Ven-0.024691*sind(omega)-0.004328*sind(omega+275.05-2.30*T);
    double e = 1-0.002495*T-0.00000752*T*T;
    double lambda,B,w1,w2,beta,parallax;
    //для координат также брались члены большие 0,001 град по апмплитуде
    lambda = Lm+6.288750*sind(Mm)+1.274018*sind(2*D-Mm)+0.658309*sind(2*D)+0.213616*sind(2*Mm)-e*0.185596*sind(M)-0.114336*sind(2*F);
    lambda = lambda+0.058793*sind(2*D-2*Mm)+e*0.057212*sind(2*D-M-Mm)+0.053320*sind(2*D+Mm)+e*0.045874*sind(2*D-M)+e*0.041024*sind(Mm-M);
    lambda = lambda-0.034718*sind(D)-e*0.030465*sind(M+Mm)+0.015326*sind(2*D-2*F)-0.012528*sind(2*F+Mm)-0.010980*sind(2*F-Mm);
    lambda = lambda+0.010674*sind(4*D-Mm)+0.010034*sind(3*Mm)+0.008548*sind(4*D-2*Mm)-e*0.007910*sind(M-Mm+2*D)-e*0.006783*sind(2*D+M);
    lambda = lambda+0.005162*sind(Mm-D)+e*0.005000*sind(M+D)+e*0.004049*sind(Mm-M+2*D)+0.003996*sind(2*Mm+2*D)+0.003862*sind(4*D);
    lambda = lambda+0.003665*sind(2*D-3*Mm)+e*0.002695*sind(2*Mm-M)+0.002602*sind(Mm-2*F-2*D)+e*0.002396*sind(2*D-M-2*Mm)-0.002349*sind(Mm+D);
    lambda = lambda+e*e*0.00249*sind(2*D-2*M)-e*0.002125*sind(2*Mm+M)-e*e*0.002079*sind(2*M)+e*e*0.002059*sind(2*D-Mm-2*M)-0.001773*sind(Mm+2*D-2*F);
    lambda = lambda-0.001595*sind(2*F+2*D)+e*0.001220*sind(4*D-M-Mm)-0.001110*sind(2*Mm+2*F)+0.000892*sind(Mm-3*D)-e*0.000811*sind(M+Mm+2*D);
    lambda = lambda+e*0.000761*sind(4*D-M-2*Mm)+e*e*0.000717*sind(Mm-2*M)+e*e*0.000704*sind(Mm-2*M+2*D)+e*0.000693*sind(M-2*Mm+2*D)+0.000598*sind(2*D-M-2*F)+0.00055*sind(Mm+4*D)+0.000538*sind(4*Mm)+e*0.000521*sind(4*D-M)+0.000486*sind(2*Mm-D);

    B = 5.128189*sind(F)+0.280606*sind(Mm+F)+0.277693*sind(Mm-F)+0.173238*sind(2*D-F)+0.055413*sind(2*D+F-Mm)+0.046272*sind(2*D-F-Mm);
    B = B+0.032573*sind(2*D+F)+0.017198*sind(2*Mm+F)+0.009267*sind(2*D+Mm-F)+0.008823*sind(2*Mm-F)+e*0.008247*sind(2*D-M-F)+0.004323*sind(2*D-F-2*Mm);
    B = B+0.004200*sind(2*D+F+Mm)+e*0.003372*sind(F-M-2*D)+e*0.002472*sind(2*D+F-M-Mm)+e*0.002222*sind(2*D+F-M)+e*0.002072*sind(2*D-F-M-Mm);
    B = B+0.001877*sind(F-M+Mm)+0.001828*sind(4*D-F-Mm)-e*0.001803*sind(F+M)-0.001750*sind(3*F)+e*0.001570*sind(Mm-M-F)-0.001487*sind(F+D);
    B = B-e*0.001481*sind(F+M+Mm)+e*0.001417*sind(F-M-Mm)+e*0.001350*sind(F-M)+0.001330*sind(F-D)+0.001106*sind(F+3*Mm)+0.001020*sind(4*D-F);
    w1 = 0.0004664*cosd(omega);
    w2 = 0.0000754*cosd(omega+275.05-2.3*T);
    beta = B*(1-w1-w2);

    parallax = 0.950724+0.051818*cosd(Mm)+0.009531*cosd(2*D-Mm)+0.007843*cosd(2*D)+0.002824*cosd(2*Mm)+0.000857*cosd(2*D+Mm);

    double E_vis,dE,dNut,L; //это для поправки за нутацию
    L = 279.6967+36000.7689*T+0.000303*T*T; //средняя долгота Солнца
    while(L>360) L = L-360.0;
    while(Lm>360) Lm = Lm-360.0;
    while(M>360) M = M-360.0;
    while(Mm>360) Mm = Mm-360.0;
    while(omega>360) omega = omega-360.0;
    E_vis = 23.452294-0.0130125*T-0.00000164*T*T+0.000000503*T*T*T;
    dNut = -(17.2327+0.01737*T)*sind(omega)-(1.2729+0.00013*T)*sind(2*L)+0.2088*sind(2*omega)-0.2037*sind(2*Lm)+(0.1261-0.00031*T)*sind(M)+0.0675*sind(Mm)-(0.0497-0.00012*T)*sind(2*L+M)-0.0342*sind(2*Lm-omega)-0.0261*sind(2*Lm+Mm)+0.0214*sind(2*L-M)-0.0149*sind(2*L-2*Lm+Mm)+0.0124*sind(2*L-omega)+0.0114*sind(2*Lm-Mm);
    dE = (9.21+0.00091*T)*cosd(omega)+(0.5522-0.00029*T)*cosd(2*L)-0.0904*cosd(2*omega)+0.0884*cosd(2*Lm)+0.0216*cosd(2*L+M)+0.0183*cosd(2*Lm-omega)+0.0113*cosd(2*Lm+Mm)-0.0093*cosd(2*L-M)-0.0066*cosd(2*L-omega);
    dNut = dNut/3600;//в часах времени
    dE = dE/3600; //переводим dE в градусню меру
  //  E_vis = E_vis+dE;//убрал, поскольку в книге Мееса написано, что метод для среднего равноденствия даты
   /* double E_vis;
    E_vis = 23.442533333333-0.00013*dJD/365.25; *///наклон эклиптики по Красавцеву
    while(lambda>360) lambda = lambda-360;
    double m,n;   //далее поправка за прецессию
    m = (3.07234+0.00186*T)*15/3600.0;
    n = (20.00468-0.0085*T)/3600.0;
    lambda = lambda+m+n*sind(lambda)*tand(beta);
    beta = beta+n*cosd(lambda);

    lambda = lambda+(cosd(E_vis)+sind(E_vis)*sind(lambda)*tand(beta))*dNut-(cosd(lambda)*tand(beta))*dE;//за нутацию
    beta =beta + (sind(E_vis)*cosd(lambda))*dNut+sind(lambda)*dE;

    cout<<" lambda: "<<lambda<<"  beta: "<<beta<<"  E_vis: "<<E_vis<<"   parallax: "<<parallax<<endl;
    double SHA = 360.0-RAfromECL(lambda,beta,E_vis);
    double decl = DECLfromECL(lambda,beta,E_vis);
    double Grin = findGrin(year,month,int(day),hour,minute,seconds);

 /*   cout<<endl<<"lambda = "<<lambda<<endl;
    cout<<"beta = "<<beta<<endl;
    cout<<"parallax = "<<parallax<<endl<<endl;

    cout<<"GHA Aries = "<<Grin<<endl;
    cout<<"LHA = "<<findHA(Grin,lon,SHA)<<endl;
    cout<<"SHA = "<<SHA<<endl;
    cout<<"RA = "<<360.0-SHA<<endl;
    cout<<"Decl = "<<decl<<endl<<endl;*/
    double A,H,HA;
    HA = findHA(Grin,lon,SHA);
    double p_cos_l,p_sin_l,dRA,topoDecl;//поправка за параллакс (topoDecl -- топоцентрическое видимое склонение)
    p_cos_l = findPcosL(0,lat); //находим для высоты наблюдателя 0м
    p_sin_l = findPsinL(0,lat);
    dRA = -p_cos_l*sind(parallax)*sind(HA)/((cosd(decl)-p_cos_l*sind(parallax)*cosd(HA)));//тангенс dRA
    cout<<"tg dRA: "<<dRA<<endl;
    if (dRA>=0) dRA = atand(dRA);
        else dRA = -atand(-dRA);
    //dRA = dRA/3600.0;
    topoDecl = (sind(decl)-p_sin_l*sind(parallax))*cosd(dRA)/(cosd(decl)-p_cos_l*sind(parallax)*cosd(HA));//тангенс topoDecl
    if (topoDecl>=0) topoDecl = atand(topoDecl);
        else topoDecl = -atand(-topoDecl);
    SHA = SHA-dRA;
    A = Az(lat,findHA(Grin,lon,SHA),topoDecl);
    H = Ht(lat,findHA(Grin,lon,SHA),topoDecl);
    cout<<"topoRA: "<<360.0-SHA<<"  topoDecl: "<<topoDecl<<"  dRA: "<<dRA<<endl;
    ui->Bearing_label->setText(QString::number(round(A*10)/10)+QChar(176));
    ui->Height_label->setText(QString::number(int(H))+QChar(176)+QString::number(round(abs((H-int(H))*60)*10)/10)+"'");
    if ((int(H)==0)&&(H<0)) ui->Height_label->setText("-"+ui->Height_label->text());

    char index;
    if (decl<0) index = 'S';
    else if (decl>0) index = 'N';
    else index = ' ';

    ui->info_l1->setText("Прямое восхождение Луны:              "+QString::number(int(360.0-SHA-dRA))+QChar(176)+QString::number(abs(round((360.0-SHA-int(360.0-SHA))*600)/10))+"'");
    ui->info_l2->setText("Склонение Луны:                              "+QString::number(abs(int(decl)))+QChar(176)+QString::number(abs(round((decl-int(decl))*600)/10))+"'"+index);
    ui->info_l3->setText("Гринвичский часовой угол т. Овна:     "+QString::number(int(Grin*15))+QChar(176)+QString::number(abs(round((Grin*15-int(Grin*15))*600)/10))+"'");
    ui->info_l4->setText("Местный часовой угол Луны:            "+QString::number(int(HA))+QChar(176)+QString::number(abs(round((HA-int(HA))*600)/10))+"'");
}

void MainWindow::planet(){
    double lat, lon, dJD, T,day;
    int year, month, hour, minute, seconds;
    char index, planet;
    if (ui->comboBox_2->currentText()=="Венера") planet = 'V';
    if (ui->comboBox_2->currentText()=="Марс") planet = 'M';
    if (ui->comboBox_2->currentText()=="Юпитер") planet = 'J';
    if (ui->comboBox_2->currentText()=="Сатурн") planet = 'S';
    lat = DmToDeg(ui->lat_deg_edit->text().toDouble(),ui->lat_min_edit->text().toDouble(),ui->lat_dec_edit->text().toDouble());
    if (ui->NS_comboBox->currentText()=="S") lat = -lat;
    lon = DmToDeg(ui->lon_deg_edit->text().toDouble(),ui->lon_min_edit->text().toDouble(),ui->lon_dec_edit->text().toDouble());
    if (ui->EW_comboBox->currentText()=="W") lon = -lon;
    year = ui->dateEdit->dateTime().date().year();
    month = ui->dateEdit->dateTime().date().month();
    day = ui->dateEdit->dateTime().date().day();
    hour = ui->timeEdit->dateTime().time().hour();
    minute = ui->timeEdit->dateTime().time().minute();
    seconds = ui->timeEdit->dateTime().time().second();
    day = day+(hour+(minute+seconds/60.0)/60.0)/24.0;
    dJD = findJD(year,month,day)-findJD(1975,1,0.0);
    T = (findJD(year,month,day)-2415020.0)/36525.0; //время в Юлианских столетиях с 1900 янв,0
    double omega,MSun,LSun,r,C,E_vis;
    double b,l; //эклиптическая широта и долгота
    double O,R; //геометрическая долгота Солнца и его радиус-вектор
    double eE,EE; //эксцентриситет Земли и эксцентрическая аномалия Земли
    MSun = 358.47583+35999.04975*T-0.000150*T*T-0.0000033*T*T*T;//средняя аномалия Солнца
    LSun = 279.69668+36000.76892*T+0.0003025*T*T;
    E_vis = 23.452294-0.0130125*T-0.00000164*T*T+0.000000503*T*T*T; //наклон эклиптики (не исправленный) по Меесу
    double dE,Lm,Mm; //это для поправки за нутацию
    Lm = 270.4342+481267.8831*T-0.001133*T*T;//средняя долгота Луны
    Mm = 296.1046+477198.8491*T+0.009192*T*T; //средняя аномалия Луны
    omega = 259.18-1934.142*T+0.002078*T*T; //долгота восходящго узла
    while (omega<0) omega = omega + 360.0; //необходимо положительное число
 //   E_vis = E_vis+0.00256*cosd(omega); //теперь исправленный для определения видимых координат Солнца
    C = (1.919460-0.004789*T-0.000014*T*T)*sind(MSun)+(0.020094-0.000100*T)*sind(2*MSun)+0.000293*sind(3*MSun);
    O = LSun+C; //истинная долгота Солнца
 //   O = O-0.00569-0.00479*sind(omega); //видимая долгота Солнца
    double aa,bb,cc,dd,ee,hh; //для нахождения точной долготы Солнца
    aa = 153.23+22518.7541*T;
    bb = 216.57+45037.5082*T;
    cc = 312.69+32964.3577*T;
    dd = 350.74+445267.1142*T;
    ee = 231.19+20.20*T;
    hh = 353.40+65928.7155*T;
    dE = (9.21+0.00091*T)*cosd(omega)+(0.5522-0.00029*T)*cosd(2*LSun)-0.0904*cosd(2*omega)+0.0884*cosd(2*Lm)+0.0216*cosd(2*LSun+MSun)+0.0183*cosd(2*Lm-omega)+0.0113*cosd(2*Lm+Mm)-0.0093*cosd(2*LSun-MSun)-0.0066*cosd(2*LSun-omega);
    dE = dE/3600; //переводим dE в градусню меру
  // E_vis = E_vis+dE;
    O = O + 0.00131*cosd(aa)+0.00151*cosd(bb)+0.002*cosd(cc)+0.00179*sind(dd)+0.00178*sind(ee);//более высокая точность (Меес)
    while (O>360) O = O-360.0;
    eE = 0.01675104-0.0000418*T-0.000000126*T*T;
    EE = findE(MSun,eE);
    R = 1.0000002*(1-eE*cosd(EE));
    R =  R+0.00000543*sind(aa)+0.00001575*sind(bb)+0.00001627*sind(cc)+0.00003076*cosd(dd)+0.00000927*sind(hh);
    double t = (findJD(year,month,day) - 2451545) / 365250;
    int n_planet; //просто номер планеты
    if (planet == 'V') { //задаем переменные для Венеры
        l = Venus_L0(t)+Venus_L1(t)+Venus_L2(t)+Venus_L3(t);
        b = Venus_B0(t)+Venus_B1(t)+Venus_B2(t)+Venus_B3(t);
        r = Venus_R0(t)+Venus_R1(t)+Venus_R2(t)+Venus_R3(t)+Venus_R4(t)+Venus_R5(t);
        n_planet = 2;
    }
    if (planet == 'M') { //задаем переменные для Марса
        l = Mars_L0(t)+Mars_L1(t)+Mars_L2(t)+Mars_L3(t);
        b = Mars_B0(t)+Mars_B1(t)+Mars_B2(t)+Mars_B3(t);
        r = Mars_R0(t)+Mars_R1(t)+Mars_R2(t)+Mars_R3(t)+Mars_R4(t)+Mars_R5(t);
        n_planet = 4;
    }
    if (planet == 'J') { //задаем переменные для Юпитера
        l = Jupiter_L0(t)+Jupiter_L1(t)+Jupiter_L2(t)+Jupiter_L3(t);
        b = Jupiter_B0(t)+Jupiter_B1(t)+Jupiter_B2(t)+Jupiter_B3(t);
        r = Jupiter_R0(t)+Jupiter_R1(t)+Jupiter_R2(t)+Jupiter_R3(t)+Jupiter_R4(t)+Jupiter_R5(t);
        n_planet = 5;
    }
    if (planet == 'S') { //задаем переменные для Сатурна
        l = Saturn_L0(t)+Saturn_L1(t)+Saturn_L2(t)+Saturn_L3(t);
        b = Saturn_B0(t)+Saturn_B1(t)+Saturn_B2(t)+Saturn_B3(t);
        r = Saturn_R0(t)+Saturn_R1(t)+Saturn_R2(t)+Saturn_R3(t)+Saturn_R4(t)+Saturn_R5(t);
        n_planet = 6;
    }
    l = RadToDeg(l);
    b = RadToDeg(b);
    while (l<0) l = l+360.0;
    while (b<0) b = b+360.0;
    while (l>360) l = l-360.0;
    while (b>360) b = b-360.0;
    double lambda,beta,delta; //геоцентрические долгота и широта планеты и расстояние от Земли до планеты
    double N,D; //вспомогательные переменные (Меес, формула 25.7)
    double dif = l-O; //вспомогательная величина
    while (dif<0) dif = dif+360.0;
    N = r*cosd(b)*sind(dif);
    D = r*cosd(b)*cosd(dif)+R;
    lambda = N/D;
    if (lambda<0) lambda = 180.0-atand(-lambda);
    else lambda = atand(lambda);
    double d = lambda-O;
    if (((d<180)&&((dif)>180)||(d>180)&&((dif)<180))) lambda = lambda+O+180.0;
    else lambda = lambda+O;
    while (lambda>360.0) lambda = lambda - 360.0;
    delta = pow(N*N+D*D+(r*sind(b)*r*sind(b)),0.5); //расстояние от планеты до Земли, а.е.
    beta = asind(r/delta*sind(b)); //это координаты, отнесенные к среднему равноденствию даты
    //найдя экваториальные координаты и исправив их за нутацию и аберрацию, получим видимые RA и Decl
    double RA,Decl;
 //   E_vis = E_vis+dE;
    RA = RAfromECL(lambda,beta,E_vis);
    Decl = DECLfromECL(lambda,beta,E_vis);
    double dNut;
    dNut = -(17.2327+0.01737*T)*sind(omega)-(1.2729+0.00013*T)*sind(2*LSun)+0.2088*sind(2*omega)-0.2037*sind(2*Lm)+(0.1261-0.00031*T)*sind(MSun)+0.0675*sind(Mm)-(0.0497-0.00012*T)*sind(2*LSun+MSun)-0.0342*sind(2*Lm-omega)-0.0261*sind(2*Lm+Mm)+0.0214*sind(2*LSun-MSun)-0.0149*sind(2*LSun-2*Lm+Mm)+0.0124*sind(2*LSun-omega)+0.0114*sind(2*Lm-Mm);
    dNut = dNut/3600;
    RA = RA - 0.005691666666667*((cosd(RA)*cosd(O)*cosd(E_vis)+sind(RA)*sind(O))/cosd(Decl));//за абберрацию
    Decl = Decl - 0.005691666666667*(cosd(O)*cosd(E_vis)*(tand(E_vis)*cosd(Decl)-sind(RA)*sind(Decl))+cosd(RA)*sind(Decl)*sind(O));//за абберрацию
    RA = RA+(cosd(E_vis)+sind(E_vis)*sind(RA)*tand(Decl))*dNut-(cosd(RA)*tand(Decl))*dE;
    Decl =Decl + (sind(E_vis)*cosd(RA))*dNut+sind(RA)*dE;
    double GHA,LHA,Grin;
    Grin = findGrin(year,month,int(day),hour,minute,seconds);
    GHA = Grin*15.0-RA;
    while (GHA<0) GHA = GHA+360;
    LHA = findHA(Grin,lon,360.0-RA);
    //исправление прямого восхождения и склонения за параллакс
    double p_cos_l,p_sin_l,parallax;
    parallax = 0.0024427777778/delta; //Меес, стр. 116
    p_cos_l = findPcosL(0,lat); //находим для высоты наблюдателя 0м
    p_sin_l = findPsinL(0,lat);
    cout<<"pCos "<<p_cos_l<<" pSin "<<p_sin_l<<endl;
    float dRA,dDCL;
    dRA = -parallax*p_cos_l*sind(LHA)/cosd(Decl);
    dDCL = -parallax*(p_sin_l*cosd(Decl)-p_cos_l*cosd(LHA)*sind(Decl));
   //     cout<<"Grin "<<Grin<<" LHA "<<LHA<<endl;
    RA = RA + dRA;
    Decl = Decl+dDCL;
//    cout<<"Grin "<<Grin<<" LHA "<<LHA<<endl<<"Decl "<<Decl<<endl;
    LHA = findHA(Grin,lon,360.0-RA);
    double Azim,Height;
    Azim = Az(lat, LHA, Decl);
    Height = Ht(lat, LHA, Decl);
    ui->Bearing_label->setText(QString::number(round(Azim*10)/10)+QChar(176));
    ui->Height_label->setText(QString::number(int(Height))+QChar(176)+QString::number(round(abs((Height-int(Height))*60)*10)/10)+"'");
    if ((int(Height)==0)&&(Height<0)) ui->Height_label->setText("-"+ui->Height_label->text());

    if (Decl<0) index = 'S';
    else if (Decl>0) index = 'N';
    else index = ' ';

    ui->info_l1->setText("Прямое восхождение планеты:           "+QString::number(int(RA))+QChar(176)+QString::number(abs(round((RA-int(RA))*600)/10))+"'");
    ui->info_l2->setText("Склонение планеты:                           "+QString::number(abs(int(Decl)))+QChar(176)+QString::number(abs(round((Decl-int(Decl))*600)/10))+"'"+index);
    ui->info_l3->setText("Гринвичский часовой угол т. Овна:       "+QString::number(int(Grin*15))+QChar(176)+QString::number(abs(round((Grin*15-int(Grin*15))*600)/10))+"'");
    ui->info_l4->setText("Местный часовой угол планеты:          "+QString::number(int(LHA))+QChar(176)+QString::number(abs(round((LHA-int(LHA))*600)/10))+"'");

}

void MainWindow::on_memo1_button_clicked()
{
    ui->memo1_l1->setText(ui->dateEdit->text()+"   в   "+ui->timeEdit->text()+" UTC");
    ui->memo1_l2->setText("широта: "+ui->lat_deg_edit->text()+QChar(176)+ui->lat_min_edit->text()+","+ui->lat_dec_edit->text()+"' " + ui->NS_comboBox->currentText()+"           долгота: "+ui->lon_deg_edit->text()+QChar(176)+ui->lon_min_edit->text()+","+ui->lon_dec_edit->text()+"' " + ui->EW_comboBox->currentText());
    ui->memo1_l3->setText("Пеленг: "+ui->Bearing_label->text()+"              Высота: "+ui->Height_label->text());
    ui->memo_1->setTitle(ui->SkyBody_name->text());
}

void MainWindow::on_memo2_button_clicked()
{
    ui->memo2_l1->setText(ui->dateEdit->text()+"   в   "+ui->timeEdit->text()+" UTC");
    ui->memo2_l2->setText("широта: "+ui->lat_deg_edit->text()+QChar(176)+ui->lat_min_edit->text()+","+ui->lat_dec_edit->text()+"' " + ui->NS_comboBox->currentText()+"           долгота: "+ui->lon_deg_edit->text()+QChar(176)+ui->lon_min_edit->text()+","+ui->lon_dec_edit->text()+"' " + ui->EW_comboBox->currentText());
    ui->memo2_l3->setText("Пеленг: "+ui->Bearing_label->text()+"              Высота: "+ui->Height_label->text());
    ui->memo_2->setTitle(ui->SkyBody_name->text());
}

void MainWindow::on_memo3_button_clicked()
{
    ui->memo3_l1->setText(ui->dateEdit->text()+"   в   "+ui->timeEdit->text()+" UTC");
    ui->memo3_l2->setText("широта: "+ui->lat_deg_edit->text()+QChar(176)+ui->lat_min_edit->text()+","+ui->lat_dec_edit->text()+"' " + ui->NS_comboBox->currentText()+"           долгота: "+ui->lon_deg_edit->text()+QChar(176)+ui->lon_min_edit->text()+","+ui->lon_dec_edit->text()+"' " + ui->EW_comboBox->currentText());
    ui->memo3_l3->setText("Пеленг: "+ui->Bearing_label->text()+"              Высота: "+ui->Height_label->text());
    ui->memo_3->setTitle(ui->SkyBody_name->text());
}

void MainWindow::on_timeEdit_timeChanged(const QTime &time)
{
    if (check_inputs()) find_coordinates();
}


void MainWindow::on_dateEdit_dateChanged(const QDate &date)
{
    if (check_inputs()) find_coordinates();
}

void MainWindow::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    if (check_inputs()) find_coordinates();
}
