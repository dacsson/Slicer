#ifndef TEST_WIND_H
#define TEST_WIND_H

#include <QDialog>
#include <windows.h>
#include <questions.h>
#include <settings.h>
namespace Ui {
class test_wind;
}

class test_wind : public QDialog
{
    Q_OBJECT

public:
    explicit test_wind(QWidget *parent = nullptr);
    ~test_wind();

private slots:
    void on_execute_clicked();

    void on_swish_clicked();

    void on_Test_clicked();

    void on_right_clicked();

    void on_left_clicked();

    void on_Paper_clicked();

    void on_Settings_clicked();

private:
    Ui::test_wind *ui;
    questions *quest;
    settings *sett;
//    void mousePressEvent(QMouseEvent *event);
//    void mouseMoveEvent(QMouseEvent *event);
//    int m_nMouseClick_X_Coordinate;
//    int m_nMouseClick_Y_Coordinate;
};

#endif // TEST_WIND_H
