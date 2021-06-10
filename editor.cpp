#include "editor.h"
#include "ui_editor.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QMouseEvent>
#include <QThread>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>

editor::editor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editor)
{
    ui->setupUi(this);
    ui->tutor->hide();
    ui->ok->hide();
    this->setWindowFlag(Qt::FramelessWindowHint, true);
    setWindowOpacity(0.0);
    QPropertyAnimation *a = new QPropertyAnimation(this,"windowOpacity");
    a->setStartValue(0.0);
    a->setDuration(400);
    a->setEndValue(1.0);
    a->setEasingCurve(QEasingCurve::InSine);
    a->start(QPropertyAnimation::DeleteWhenStopped);

    extern QString file_name;
    if(file_name.mid(file_name.size()-3, 3) == "txt") {
        extern QString all_str;
        ui->textEdit->setText(all_str);
    }

}

editor::~editor()
{
    delete ui;
}

void editor::on_apply_clicked()
{
    QString file_path, text;
    file_path = QFileDialog::getSaveFileName( this,
                                              tr("Сохранить файл как"),
                                              QDir::homePath(),
                                              tr("Slicer file (*.slc)")
                                              );


    QFile file(file_path);
    if(file.open(QIODevice::ReadWrite)) {
       QTextStream in (&file);
       text = ui->textEdit->toPlainText();

       Replace(text);

       file.write(text.toLocal8Bit());
    }

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
}

void editor::on_swish_clicked()
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
}



void editor::on_pull_clicked()
{
    QPropertyAnimation *a = new QPropertyAnimation(this,"windowOpacity");
    a->setStartValue(1.0);
    a->setDuration(200);
    a->setEndValue(0.5);
    a->setEasingCurve(QEasingCurve::InSine);
    a->start(QPropertyAnimation::DeleteWhenStopped);
    ui->textEdit->hide();
    ui->pull->hide();
    ui->apply->hide();
    ui->ok->show();
    ui->tutor->show();
    a->setStartValue(0.5);
    a->setDuration(200);
    a->setEndValue(1.0);
    a->setEasingCurve(QEasingCurve::InSine);
    this->parentWidget()->show();
    a->start(QPropertyAnimation::DeleteWhenStopped);
}

void editor::on_ok_clicked()
{
    QPropertyAnimation *a = new QPropertyAnimation(this,"windowOpacity");
    a->setStartValue(1.0);
    a->setDuration(200);
    a->setEndValue(0.5);
    a->setEasingCurve(QEasingCurve::InSine);
    a->start(QPropertyAnimation::DeleteWhenStopped);
    ui->textEdit->show();
    ui->pull->show();
    ui->apply->show();
    ui->ok->hide();
    ui->tutor->hide();
    a->setStartValue(0.5);
    a->setDuration(200);
    a->setEndValue(1.0);
    a->setEasingCurve(QEasingCurve::InSine);
    a->start(QPropertyAnimation::DeleteWhenStopped);
}

void editor::mousePressEvent(QMouseEvent *event) {
    m_nMouseClick_X_Coordinate = event->position().x();
    m_nMouseClick_Y_Coordinate = event->position().y();
    qDebug() << m_nMouseClick_X_Coordinate << " -settings- " << m_nMouseClick_Y_Coordinate;
}

void editor::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalPosition().x()-m_nMouseClick_X_Coordinate,event->globalPosition().y()-m_nMouseClick_Y_Coordinate);
}

void editor::Replace(QString &text) {
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
        text.replace(i.key(), i.value());
        ++i;
    }
}
