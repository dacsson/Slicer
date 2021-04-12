#include "questions.h"
#include "ui_questions.h"
#include <test_wind.h>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QMessageBox>
#include <QTextCodec>
#include <settings.h>
#include <QThread>
#include <QMouseEvent>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QTextCodec>

//to read non-english letters
QTextCodec* codeck = QTextCodec::codecForName("UTF-8");

//reading all text in file into one BIG string
//+ findind actual text and putting in other BIG string
QString bigstring, substr;

//number of questin to orientate with arrows
int quest_index;
int quest_num = 1;

//findind borders to store question that is between thos borderd
//its my own markdowns (=symbols)
QString first_index, second_index;
int iqst, jqst, ansb, anse;

//progress bar that tells you your progress in questions
int progressValue, chunk;
QString progress;
int animate_progress = 0;
int var, temp;

//array of right answers (read from file)
int numb_of_ans;
int *right_answers;
QString ans_line, all;

//in order to read russian letters (and other than english)
QTextCodec* codec2 = QTextCodec::codecForName("UTF-8");

//user answers
int *user_ans;

questions::questions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::questions)
{
    extern QString file_name;
    ui->setupUi(this);
    ui->pass->hide();
    ui->save->hide();
    ui->okay->hide();
    this->setWindowFlag(Qt::FramelessWindowHint, true);

    //fade animation
    setWindowOpacity(0.0);
    QPropertyAnimation *a = new QPropertyAnimation(this,"windowOpacity");
    a->setStartValue(0.0);
    a->setDuration(400);
    a->setEndValue(1.0);
    a->setEasingCurve(QEasingCurve::InSine);
    a->start(QPropertyAnimation::DeleteWhenStopped);

    //quickly finding question
    QFile file(file_name);
    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0, "info", file.errorString());
    QTextStream in (&file);
    qDebug() << "1 test: " << file_name;
    while(!file.atEnd()) {
        bigstring = QString::fromLocal8Bit((file.readAll()));
        qDebug() << "2 test: " << bigstring;
        all = bigstring; //to find answers later
        int i = bigstring.indexOf("?1?");
        int j = bigstring.indexOf(".1.");
        QString all_str = bigstring.mid(i+3, j);
        qDebug() << "3 test: " << all_str;
        int exp = all_str.indexOf("!1");
        QString q_str = all_str.mid(0, exp);
        int var1 = all_str.indexOf("!2");
        QString v1 = all_str.mid(exp+2, (var1-exp-2));
        ui->Readin_2->setText(v1);
        int var2 = all_str.indexOf("!3");
        QString v2 = all_str.mid((var1+2), (var2-var1-2));
        ui->Readin_3->setText(v2);
        int var3 = all_str.indexOf("!4");
        QString v3 = all_str.mid((var2+2), (var3-var2-2));
        ui->Readin_4->setText(v3);
        int var4 = all_str.indexOf("!5");
        QString v4 = all_str.mid((var3+2), (var4-var3-2));
        ui->Readin_5->setText(v4);
        bigstring = bigstring.mid(j);
        qDebug() << "4 test: " << q_str;
        ui->Questions->setText((q_str));
    }
    progress = bigstring.mid(bigstring.length()-2, 1);
    progressValue = progress.toInt();
    temp = progressValue;
    qDebug() << "5 test: " << temp;
    chunk = 100/progressValue;
    progressValue = 100/progressValue;
    animate_progress = chunk;
    ui->quest_progress->setValue(chunk);
    //store right ans
    right_answers = new int [temp];
    int num_of_ans = all.indexOf("[0]");
    for(int i = 0; i < temp; i++) {
        ans_line = all.mid(num_of_ans+4, 1);
        right_answers[i] = ans_line.toInt();
        //qDebug() << ans_line << "answer" << right_answers[i];
        num_of_ans++;

    //user ans
    user_ans = new int [temp];
    }
}

questions::~questions()
{
    delete ui;
}

void questions::on_execute_clicked()
{
    this->close();
}

void questions::on_swish_clicked()
{
    quest_num = 1;
    QPropertyAnimation *a = new QPropertyAnimation(this,"windowOpacity");
    a->setStartValue(1.0);
    a->setDuration(400);
    a->setEndValue(0.0);
    a->setEasingCurve(QEasingCurve::InSine);
    a->start(QPropertyAnimation::DeleteWhenStopped);
    connect(a,SIGNAL(finished()),this,SLOT(close()));
    this->hide();
}

//void questions::on_Test_clicked()
//{
//    this->hide();
//}

//void questions::on_Settings_clicked()
//{
//    sett = new settings(this);
//    int x = geometry().x();
//    int y = geometry().y();
//    sett -> move(x, y);
//    sett -> show();
//}

void questions::on_right_clicked()
{
    extern QString file_name;
    QFile file(file_name);
    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0, "info", file.errorString());
    QTextStream in (&file);
    while(!file.atEnd()) {
        quest_num++;
        bigstring = QString::fromLocal8Bit((file.readAll()));
        first_index = "?";
        substr = QString::number(quest_num);
        first_index = first_index.append(substr);
        first_index = first_index.append("?");
        iqst = bigstring.indexOf(first_index);
        second_index = ".";
        second_index = second_index.append(substr);
        second_index = second_index.append(".");
        jqst = bigstring.indexOf(second_index);
        qDebug() << jqst << " ####### " << bigstring.size();
        if(jqst < bigstring.size() && jqst > 0) {
            substr = bigstring.mid(iqst+3, (jqst-3)-iqst);
            int exp = substr.indexOf("!1");
            QString q_str = substr.mid(0, exp-2);
            int var1 = substr.indexOf("!2");
            QString v1 = substr.mid(exp+2, (var1-exp-2));
            ui->Readin_2->setText(v1);
            int var2 = substr.indexOf("!3");
            QString v2 = substr.mid((var1+2), (var2-var1-2));
            ui->Readin_3->setText(v2);
            int var3 = substr.indexOf("!4");
            QString v3 = substr.mid((var2+2), (var3-var2-2));
            ui->Readin_4->setText(v3);
            int var4 = substr.indexOf("!5");
            QString v4 = substr.mid((var3+2), (var4-var3-2));
            ui->Readin_5->setText(v4);
            ui->Questions->setText((q_str));
            ui->quest_progress->setValue(10);
            progressValue+=chunk;
            while(animate_progress < progressValue) {
                ui->quest_progress->setValue(animate_progress);
                animate_progress+=2;
                QThread::msleep(30);
            }
            animate_progress = progressValue;
            //ui->quest_progress->setValue(progressValue);

            //show button to save results
            if(quest_num == temp) {
                 ui->pass->show();
            }

            //clear button
            //add -setAutoExclusive(flase) ... -setAutoExclusive(true) later!!
            ui->check1->setChecked(false);
            ui->check2->setChecked(false);
            ui->check3->setChecked(false);
            ui->check4->setChecked(false);
        }
        else {
            quest_num--;

        }
    }
}

void questions::on_left_clicked()
{
    if(quest_num > 1) {
    extern QString file_name;
    QFile file(file_name);
    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0, "info", file.errorString());
    QTextStream in (&file);
    while(!file.atEnd()) {
        quest_num--;
        bigstring = QString::fromLocal8Bit((file.readAll()));
        first_index = "?";
        substr = QString::number(quest_num);
        first_index = first_index.append(substr);
        first_index = first_index.append("?");
        iqst = bigstring.indexOf(first_index);
        second_index = ".";
        second_index = second_index.append(substr);
        second_index = second_index.append(".");
        jqst = bigstring.indexOf(second_index);
        qDebug() << jqst << " ####### " << bigstring.size();
        substr = bigstring.mid(iqst+3, (jqst-3)-iqst);
        int exp = substr.indexOf("!1");
        QString q_str = substr.mid(0, exp-2);
        int var1 = substr.indexOf("!2");
        QString v1 = substr.mid(exp+2, (var1-exp-2));
        ui->Readin_2->setText(v1);
        int var2 = substr.indexOf("!3");
        QString v2 = substr.mid((var1+2), (var2-var1-2));
        ui->Readin_3->setText(v2);
        int var3 = substr.indexOf("!4");
        QString v3 = substr.mid((var2+2), (var3-var2-2));
        ui->Readin_4->setText(v3);
        int var4 = substr.indexOf("!5");
        QString v4 = substr.mid((var3+2), (var4-var3-2));
        ui->Readin_5->setText(v4);
        ui->Questions->setText((q_str));
        progressValue-=chunk;
        while(animate_progress > progressValue) {
            ui->quest_progress->setValue(animate_progress);
            animate_progress-=2;
            QThread::msleep(30);
        }
        animate_progress = progressValue;
        ui->quest_progress->setValue(progressValue);
    }
}
}

//void questions::mousePressEvent(QMouseEvent *event) {
//    m_nMouseClick_X_Coordinate = event->position().x();
//    m_nMouseClick_Y_Coordinate = event->position().y();
//}

//void questions::mouseMoveEvent(QMouseEvent *event) {
//    move(event->globalPosition().x()-m_nMouseClick_X_Coordinate,event->globalPosition().y()-m_nMouseClick_Y_Coordinate);
//}

void questions::on_questions_accepted()
{

}

void questions::on_check1_clicked()
{
    user_ans[quest_num-1] = 1;
    //qDebug() << user_ans[quest_num-1] << " - " << right_answers[quest_num-1];
}


void questions::on_check2_clicked()
{
    user_ans[quest_num-1] = 2;
    //qDebug() << user_ans[quest_num-1] << " - " << right_answers[quest_num-1];
}

void questions::on_check3_clicked()
{
    user_ans[quest_num-1] = 3;
}

void questions::on_check4_clicked()
{
    user_ans[quest_num-1] = 4;
}

void questions::on_pass_clicked()
{
    //animate it
    QPropertyAnimation *a = new QPropertyAnimation(this,"windowOpacity");
    a->setStartValue(1.0);
    a->setDuration(400);
    a->setEndValue(0.0);
    a->setEasingCurve(QEasingCurve::InSine);
    a->start(QPropertyAnimation::DeleteWhenStopped);
    //connect(a,SIGNAL(finished()),this,SLOT(hide()));
    QPropertyAnimation *a2 = new QPropertyAnimation(this,"windowOpacity");
    a2->setStartValue(0.0);
    a2->setDuration(400);
    a2->setEndValue(1.0);
    a2->setEasingCurve(QEasingCurve::InSine);
    a2->start(QPropertyAnimation::DeleteWhenStopped);

    QString temp_text;
    QString temp_text1;
    QString temp_text2;
    QString temp_text3;
    QString temp_text4;
    int all;

    //change button from sumbit to save
    ui->pass->hide();
    ui->save->show();
    ui->okay->show();

    ui->check1->hide();
    ui->check2->hide();
    ui->check3->hide();
    ui->check4->hide();
    ui->right->hide();
    ui->left->hide();
    ui->Readin_2->hide();
    ui->Readin_3->hide();
    ui->Readin_4->hide();
    ui->Readin_5->hide();
    qDebug() << user_ans << " - " << right_answers;
    all = quest_num;
    ui->Questions->setFixedHeight(500);
    ui->Questions->setText("\t\tВаш результат:\n");
    for(int i = 0; i < quest_num; i++) {

        temp_text = QString::number(i+1);
        temp_text1 = QString::number(user_ans[i]);
        temp_text2 = QString::number(right_answers[i]);
        ui->Questions->append("\n" + temp_text + " вопрос: " + temp_text1 + "/" + temp_text2);
        if(user_ans[i] != right_answers[i]) {
            all--;
        }
    }
    temp_text3 = QString::number(all);
    temp_text4 = QString::number(quest_num);
    ui->Questions->append("\n\t\tИтого: " + temp_text3 + " из " + temp_text4);

    //delete[]user_ans;
    //delete[]right_answers;
}

void questions::on_save_clicked()
{
    extern QString user_name;
    QString temp_text;
    QString temp_text1;
    QString temp_text2;
    QString temp_text3;
    QString temp_text4;
    int all;
    all = quest_num;
    QString file_path;
    file_path = QFileDialog::getSaveFileName( this,
                                              tr("Сохранить файл как"),
                                              QDir::homePath(),
                                              tr("Text file (*.txt)")
                                              );
    QFile file( file_path );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );
        stream.setEncoding( QStringConverter::Utf8 );
        for(int i = 0; i < quest_num; i++) {

            temp_text = QString::number(i+1);
            temp_text1 = QString::number(user_ans[i]);
            temp_text2 = QString::number(right_answers[i]);
            QString everything = ("\n" + temp_text + ": " + temp_text1 + "/" + temp_text2);
            stream << everything;
            if(user_ans[i] != right_answers[i]) {
                all--;
            }
        }
        temp_text3 = QString::number(all);
        temp_text4 = QString::number(quest_num);
        stream << ("\n\n" + temp_text3 + " | " + temp_text4);
        stream << ("\n\nVar: " + user_name);
    }

    //clearing memory otherwise itll be...too bad!

    delete[]user_ans;
    delete[]right_answers;

    QPropertyAnimation *a = new QPropertyAnimation(this,"windowOpacity");
    a->setStartValue(1.0);
    a->setDuration(400);
    a->setEndValue(0.0);
    a->setEasingCurve(QEasingCurve::InSine);
    a->start(QPropertyAnimation::DeleteWhenStopped);
    connect(a,SIGNAL(finished()),this,SLOT(close()));
}

void questions::on_okay_clicked()
{

    delete[]user_ans;
    delete[]right_answers;

    QPropertyAnimation *a = new QPropertyAnimation(this,"windowOpacity");
    a->setStartValue(1.0);
    a->setDuration(400);
    a->setEndValue(0.0);
    a->setEasingCurve(QEasingCurve::InSine);
    a->start(QPropertyAnimation::DeleteWhenStopped);
    connect(a,SIGNAL(finished()),this,SLOT(close()));
}
