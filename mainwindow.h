#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "windows.h"
#include "test_wind.h"
#include "settings.h"
#include "questions.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Test_clicked();

    void on_execute_clicked();

    void on_swish_clicked();

    void on_Settings_clicked();

    void on_Paper_clicked();

    void on_pass_clicked();

private:
    Ui::MainWindow *ui;
    test_wind *test_w;
    settings *settin;
    questions *quest;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;

};
#endif // MAINWINDOW_H
