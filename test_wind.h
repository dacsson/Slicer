#ifndef TEST_WIND_H
#define TEST_WIND_H

#include <QDialog>
#include <windows.h>
#include "visual.h"

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

private:
    Ui::test_wind *ui;
    visual *vis;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;
    void Replace(QString &text);
};

#endif // TEST_WIND_H
