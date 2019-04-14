#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_comboBox_2_activated(const QString &arg1);

    void on_comboBox_2_highlighted(const QString &arg1);

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_comboBox_2_currentTextChanged(const QString &arg1);

    void on_lat_deg_edit_textEdited(const QString &arg1);

    void on_lon_deg_edit_textEdited(const QString &arg1);

    void on_lat_min_edit_textEdited(const QString &arg1);

    void on_lon_min_edit_textEdited(const QString &arg1);

    void on_lat_dec_edit_textEdited(const QString &arg1);

    void on_lon_dec_edit_textEdited(const QString &arg1);

    void find_coordinates();

    bool check_inputs();

    void star();
    void Sun();
    void Moon();
    void planet();

    void on_lat_deg_edit_textChanged(const QString &arg1);

    void on_lat_min_edit_textChanged(const QString &arg1);

    void on_lat_dec_edit_textChanged(const QString &arg1);

    void on_lon_deg_edit_textChanged(const QString &arg1);

    void on_lon_min_edit_textChanged(const QString &arg1);

    void on_lon_dec_edit_textChanged(const QString &arg1);

    void on_NS_comboBox_currentIndexChanged(const QString &arg1);

    void on_EW_comboBox_currentIndexChanged(const QString &arg1);

    void on_memo1_button_clicked();

    void on_memo2_button_clicked();

    void on_memo3_button_clicked();

    void on_timeEdit_timeChanged(const QTime &time);

    void on_dateEdit_dateChanged(const QDate &date);

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
