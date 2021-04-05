#include "settings.h"
#include "ui_settings.h"
#include "questions.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QMouseEvent>
#include <QThread>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>

//path to the file user downl
QString file_name;

//name of student
QString user_name;

settings::settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint, true);
    //QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    //this->setGraphicsEffect(eff);
    setWindowOpacity(0.0);
    QPropertyAnimation *a = new QPropertyAnimation(this,"windowOpacity");
    a->setStartValue(0.0);
    a->setDuration(400);
    a->setEndValue(1.0);
    a->setEasingCurve(QEasingCurve::InSine);
    a->start(QPropertyAnimation::DeleteWhenStopped);

}

settings::~settings()
{
    delete ui;
}

void settings::on_Test_clicked()
{

}

void settings::on_Paper_clicked()
{

}


void settings::on_Settings_clicked()
{

}

void settings::on_swish_clicked()
{
    this->hide();
}

void settings::on_downl_clicked()
{
    file_name = QFileDialog::getOpenFileName(this, "Открыть файл", QDir::homePath(), "Text file (*.txt)");
    //QMessageBox::information(this, "...", file_name);

    QFile file(file_name);
    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0, "info", file.errorString());
    QTextStream in (&file);
    if(file.isOpen()) {
        while(!file.atEnd()) {
            QString bigstr = QString::fromLocal8Bit((file.readAll()));
            ui->Readin->setText(bigstr);
    }
  }
}

//void settings::mousePressEvent(QMouseEvent *event) {
//    m_nMouseClick_X_Coordinate = event->position().x();
//    m_nMouseClick_Y_Coordinate = event->position().y();
//    qDebug() << m_nMouseClick_X_Coordinate << " -settings- " << m_nMouseClick_Y_Coordinate;
//}

//void settings::mouseMoveEvent(QMouseEvent *event) {
//    move(event->globalPosition().x()-m_nMouseClick_X_Coordinate,event->globalPosition().y()-m_nMouseClick_Y_Coordinate);
//}

void settings::on_apply_clicked()
{
    //get users name
    user_name = ui->ID->toPlainText();

    QPropertyAnimation *a = new QPropertyAnimation(this,"windowOpacity");
    a->setStartValue(1.0);
    a->setDuration(400);
    a->setEndValue(0.0);
    a->setEasingCurve(QEasingCurve::InSine);
    a->start(QPropertyAnimation::DeleteWhenStopped);
    connect(a,SIGNAL(finished()),this,SLOT(close()));
    //this->close();

}
