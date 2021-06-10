#include "test_wind.h"
#include "ui_test_wind.h"
#include <mainwindow.h>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QTextCodec>
#include <questions.h>
#include <QMouseEvent>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QThread>

//to read non-english letters
QTextCodec* codec = QTextCodec::codecForName("UTF-8");

//position of my own markdowns to orientate in the text
int i = 0;

//list number
int paperlist = 1; int past, k, next_K;
QString paperindex, past_str;

//temporary var to make markdown ( like "|1|")
QString addit;

//storing text in BIG strings
QString bigstr; QString str;

//to see if user at the begining or not of process
int flag = 0;

//values to show progress to user
int progressValues, chunck;
QString progressing;
int animate_progressing = 0;
int vare, tempo;

test_wind::test_wind(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::test_wind)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint, true);
    setWindowOpacity(0.0);
    QPropertyAnimation *a = new QPropertyAnimation(this,"windowOpacity");
    a->setStartValue(0.0);
    a->setDuration(400);
    a->setEndValue(1.0);
    a->setEasingCurve(QEasingCurve::InSine);
    a->start(QPropertyAnimation::DeleteWhenStopped);
}

test_wind::~test_wind()
{
    delete ui;
}

void test_wind::on_execute_clicked()
{
    this->close();

}

void test_wind::on_swish_clicked()
{
    QPropertyAnimation *a = new QPropertyAnimation(this,"windowOpacity");
    a->setStartValue(1.0);
    a->setDuration(400);
    a->setEndValue(0.0);
    a->setEasingCurve(QEasingCurve::InSine);
    a->start(QPropertyAnimation::DeleteWhenStopped);
    this->parentWidget()->setWindowOpacity(1.0);
    this->parentWidget()->move(geometry().x(),geometry().y());
    this->parentWidget()->show();
    connect(a,SIGNAL(finished()),this,SLOT(close()));
    //this->hide();
}

void test_wind::on_Test_clicked()
{
    if(flag==0) {
        extern QString file_name;
        QFile file(file_name);
        if(!file.open(QIODevice::ReadOnly))
            QMessageBox::information(0, "info", file.errorString());
        QTextStream in (&file);
        while(!file.atEnd()) {
            bigstr = QString::fromLocal8Bit((file.readAll()));
            Replace(bigstr);
            progressing = bigstr;
            int que = bigstr.indexOf("[0]");
            bigstr = bigstr.mid(0, que-2);
            int k = bigstr.indexOf("|1|");
            str = bigstr.mid(0+3, k-3);
            qDebug() << "\n * " << str;
            i += k;
            ui->Readin->setText((str));
            flag=1;
        }

        //progress
        progressValues = progressing.indexOf("[0]");
        qDebug() << progressing.mid(progressValues-3, 10) << " progress ";
        progressing = progressing.mid(progressValues-3, 1);
        qDebug() << progressing << " progress ";
        progressValues = progressing.toInt();
        tempo = progressValues;
        //qDebug() << "5 test: " << tempo;
        chunck = 100/progressValues;
        progressValues = 100/progressValues;
        animate_progressing = chunck;
        ui->quest_progress->setValue(chunck);
    }


    //ui -> Readin->setText(in.readAll());
}

void test_wind::on_right_clicked()
{
    if(flag != 0) {
        extern QString file_name;
        QFile file(file_name);
        if(!file.open(QIODevice::ReadOnly))
            QMessageBox::information(0, "info", file.errorString());
        QTextStream in (&file);
        while(!file.atEnd()) {
            bigstr = QString::fromLocal8Bit((file.readAll()));
            Replace(bigstr);
            int que = bigstr.indexOf("[0]");
            bigstr = bigstr.mid(0, que-1);
            if(i+3 < bigstr.length()) {
                paperlist++;
                paperindex = QString::number(paperlist);
                addit = "|";
                addit = addit.append(paperindex);
                addit = addit.append("|");
                k = bigstr.indexOf(addit);
                past_str = str;
                str = bigstr.mid(i+3, (k-3)-i);
                i = k;
                ui->Readin->setText((str));

                //animate progressbat
                progressValues+=chunck;
                while(animate_progressing < progressValues) {
                    ui->quest_progress->setValue(animate_progressing);
                    animate_progressing+=2;
                    QThread::msleep(30);
                }
                animate_progressing = progressValues;
                //ui->quest_progress->setValue(progressValue);
            }
            else {
                //update variables so they can reuse "reading" section
                flag = 0;
                i = 0;
                paperlist = 1;

                //animation (fade out and close)
                QPropertyAnimation *a = new QPropertyAnimation(this,"windowOpacity");
                a->setStartValue(1.0);
                a->setDuration(400);
                a->setEndValue(0.0);
                a->setEasingCurve(QEasingCurve::InSine);
                a->start(QPropertyAnimation::DeleteWhenStopped);
                vis = new visual(this);
                int x = geometry().x();
                int y = geometry().y();
                vis ->move(x, y);
                vis ->show();
                connect(a,SIGNAL(finished()),this,SLOT(hide()));


            }
        }
    }
}

void test_wind::on_left_clicked()
{
    flag = 1;
    extern QString file_name;
    QFile file(file_name);
    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0, "info", file.errorString());
    QTextStream in (&file);
    while(!file.atEnd()) {
        bigstr = QString::fromLocal8Bit((file.readAll()));
        Replace(bigstr);
        int que = bigstr.indexOf("[0]");
        bigstr = bigstr.mid(0, que-2);
        if(paperlist > 1) {
            paperlist-=2;
            paperindex = QString::number(paperlist);
            addit = "|";
            addit = addit.append(paperindex);
            addit = addit.append("|");
            k = bigstr.indexOf(addit);
            paperlist++;
            paperindex = QString::number(paperlist);
            addit = "|";
            addit = addit.append(paperindex);
            addit = addit.append("|");
            next_K = bigstr.indexOf(addit);
            str = bigstr.mid(k+3, (next_K-3)-k);
            i = next_K;
            ui->Readin->setText((str));

            //animate progressbat
            progressValues-=chunck;
            while(animate_progressing > progressValues) {
                ui->quest_progress->setValue(animate_progressing);
                animate_progressing-=2;
                QThread::msleep(30);
            }
            animate_progressing = progressValues;
        }

    }
}

void test_wind::mousePressEvent(QMouseEvent *event) {
    m_nMouseClick_X_Coordinate = event->position().x();
    m_nMouseClick_Y_Coordinate = event->position().y();
    qDebug() << m_nMouseClick_X_Coordinate << " -1tst- " << m_nMouseClick_Y_Coordinate;
}

void test_wind::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalPosition().x()-m_nMouseClick_X_Coordinate,event->globalPosition().y()-m_nMouseClick_Y_Coordinate);
    qDebug() << m_nMouseClick_X_Coordinate << " -2tst- " << m_nMouseClick_Y_Coordinate;
}

void test_wind::Replace(QString &text) {
    QMap<QString, QString> replace {
        {"0", "?!*(#-=#"},
        {"1", "!*!(#-#--"},
        {"2", "*))!(#=@"},
        {"3", "?*#)=#-=#"},
        {"4", "-!(#-=!#="},
        {"5", "=$:;==--"},
        {"6", "Ap;l==#-$"},
        {"7", "-#=#-??*"},
        {"а", "###-=-@@@"},
        {"б", "@@@-=-###"},
        {"в", "###===@@$"},
        {"г", "$##---@@@"},
        {"д", "$##===-@@"},
        {"е", "@-=-!##$#"},
        {"ж", "#%=%@@@-#"},
        {"з", "##====@@$"},
        {"и", "##$$$=-=#"},
        {"к", "#!!#$=$##"},
        {"л", "#$#$#$=--"},
        {"м", "$#$#$#!-!"},
        {"н", "!#!#!#!-$"},
        {"о", "!#!#!#!=$"},
        {"п", "%#%#%#%-!"},
        {"с", "$!$!-#=#!"},
        {"у", "(#(#=-$!%"},
        {"х", "##-(%-=#!"}
    };
    QMap<QString, QString>::const_iterator i = replace.constBegin();
    while (i != replace.constEnd()) {
        text.replace(i.value(), i.key());
        ++i;
    }
}



