#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <QDialog>
#include <settings.h>

namespace Ui {
class questions;
}

class questions : public QDialog
{
    Q_OBJECT

public:
    explicit questions(QWidget *parent = nullptr);
    ~questions();

private slots:
    void on_execute_clicked();

    void on_swish_clicked();

//    void on_Test_clicked();

//    void on_Settings_clicked();

    void on_right_clicked();

    void on_left_clicked();

    void on_questions_accepted();

    void on_check1_clicked();

    void on_check2_clicked();

    void on_check3_clicked();

    void on_check4_clicked();

    void on_pass_clicked();

    void on_save_clicked();

private:
    Ui::questions *ui;
    settings *sett;
//    void mousePressEvent(QMouseEvent *event);
//    void mouseMoveEvent(QMouseEvent *event);
//    int m_nMouseClick_X_Coordinate;
//    int m_nMouseClick_Y_Coordinate;
};

#endif // QUESTIONS_H
