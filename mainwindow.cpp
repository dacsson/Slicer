#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QThread>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowIcon(QIcon(":icon.png"));
    ui->progress->setValue(5);
    ui->pass->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Test_clicked()
{
    //hide();
    int small = 33;
    while(small < 66) {
        ui->progress->setValue(small);
        small+=2;
        QThread::msleep(40);
    }
    test_w = new test_wind(this);
    int x = geometry().x();
    int y = geometry().y();
    test_w->move(x, y);
    test_w->show();

}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    m_nMouseClick_X_Coordinate = event->position().x();
    m_nMouseClick_Y_Coordinate = event->position().y();
    qDebug() << m_nMouseClick_X_Coordinate << " 1 " << m_nMouseClick_Y_Coordinate;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalPosition().x()-m_nMouseClick_X_Coordinate,event->globalPosition().y()-m_nMouseClick_Y_Coordinate);
    qDebug() << m_nMouseClick_X_Coordinate << " 2 " << m_nMouseClick_Y_Coordinate;
}

void MainWindow::on_execute_clicked()
{
    this->close();
}

void MainWindow::on_swish_clicked()
{
    this->showMinimized();
}

void MainWindow::on_Settings_clicked()
{
    int small = 5;
    while(small < 33) {
        ui->progress->setValue(small);
        small+=2;
        QThread::msleep(40);
    }
    settin = new settings(this);
    int x = geometry().x();
    int y = geometry().y();
    settin->move(x, y);
    settin->show();
}

void MainWindow::on_Paper_clicked()
{
    int small = 66;
    while(small < 100) {
        ui->progress->setValue(small);
        small+=2;
        QThread::msleep(40);
    }
    quest = new questions(this);
    int x = geometry().x();
    int y = geometry().y();
    quest->move(x, y);
    quest->show();

    //add an animation plz later
    ui->pass->show();
}

void MainWindow::on_pass_clicked()
{
    int small = 98;
    while(small > 5) {
        ui->progress->setValue(small);
        small-=2;
        QThread::msleep(30);
    }
    ui->pass->hide();
}
