#include "visual.h"
#include "ui_visual.h"
#include <QPropertyAnimation>
#include <QMouseEvent>

int step = 0;

std::vector<std::vector<int>> Matrix1, Matrix11_1, Matrix12_1, Matrix21_1, Matrix22_1, Matrix2, Matrix11_2, Matrix12_2, Matrix21_2, Matrix22_2;

std::vector<std::vector<int>> d1, d2, d3, d4, d5, d6, d7, c1, c2, c3, c4;

std::vector<int> Row, Column;

std::vector<std::vector<int>> C, R;

QLineEdit* Elements[16];

visual::visual(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::visual)
{
    ui->setupUi(this);
    ui->line->hide();
    ui->line_2->hide();
    ui->Row1->hide();
    ui->Row2->hide();
    ui->Row3->hide();
    ui->Row4->hide();
    ui->Row5->hide();
    ui->Row6->hide();
    ui->Row7->hide();
    ui->Row8->hide();
    ui->Row9->hide();
    ui->Col1->hide();
    ui->Col2->hide();
    ui->Col3->hide();
    ui->Col4->hide();
    ui->Col5->hide();
    ui->Col6->hide();
    ui->Col7->hide();
    ui->Col8->hide();
    ui->Col9->hide();
    ui->RowP1->hide();
    ui->RowP2->hide();
    ui->RowP3->hide();
    ui->ColP1->hide();
    ui->ColP2->hide();
    ui->ColP3->hide();
    this->setWindowFlag(Qt::FramelessWindowHint, true);
    setWindowOpacity(0.0);
    QPropertyAnimation *a = new QPropertyAnimation(this,"windowOpacity");
    a->setStartValue(0.0);
    a->setDuration(400);
    a->setEndValue(1.0);
    a->setEasingCurve(QEasingCurve::InSine);
    a->start(QPropertyAnimation::DeleteWhenStopped);
}

visual::~visual()
{
    delete ui;
}

std::vector<std::vector<int>> visual::MultiplyMatrix(std::vector<std::vector<int>> Matrix1, std::vector<std::vector<int>> Matrix2)
{
    std::vector<std::vector<int>> Result;
    int n = Matrix1.size();
    for (int i = 0; i < n; i++) {
        std::vector<int> line;
        for (int j = 0; j < n; j++)
        {
            line.push_back(0);
            for (int k = 0; k < n; k++){
                line[j] += Matrix1[i][k] * Matrix2[k][j];
            }
            qDebug() << "\n " << line[j];
        }
        Result.push_back(line);
    }
    return Result;
}

std::vector<std::vector<int>> visual::SumMatrix(std::vector<std::vector<int>> Matrix1, std::vector<std::vector<int>> Matrix2) {
    std::vector<std::vector<int>> Result;
    qDebug() << "\n зашёл в функцию суммы с " << Matrix1[0][0] << " b " << Matrix2[0][0];
    int n = Matrix1.size();
    for (int i = 0; i < n; i++) {
        std::vector<int> line;
        for (int j = 0; j < n; j++)
        {
            line.push_back(Matrix1[i][j] + Matrix2[i][j]);
            qDebug() << "\n sum res " << line[j] << " element " << Matrix1[i][j] << " + " << Matrix2[i][j];
        }
        Result.push_back(line);
    }
    return Result;
}

std::vector<std::vector<int>> visual::MinusMatrix(std::vector<std::vector<int>> Matrix1, std::vector<std::vector<int>> Matrix2) {
    std::vector<std::vector<int>> Result;
    int n = Matrix1.size();
    for (int i = 0; i < n; i++) {
        std::vector<int> line;
        for (int j = 0; j < n; j++)
        {
            line.push_back(Matrix1[i][j] - Matrix2[i][j]);
            qDebug() << "\n sum res " << line[j] << " element " << Matrix1[i][j] << " - " << Matrix2[i][j];
        }
        Result.push_back(line);
    }
    return Result;
}

void visual::ShowMatrix(std::vector<std::vector<int>> Matrix, int n) {
    QString text;

    Elements[0] = ui->insertNum;
    Elements[1] = ui->insertNum_2;
    Elements[2] = ui->insertNum_3;
    Elements[3] = ui->insertNum_4;
    Elements[4] = ui->insertNum_5;
    Elements[5] = ui->insertNum_6;
    Elements[6] = ui->insertNum_7;
    Elements[7] = ui->insertNum_8;
    Elements[8] = ui->insertNum_9;
    Elements[9] = ui->insertNum_10;
    Elements[10] = ui->insertNum_11;
    Elements[11] = ui->insertNum_12;
    Elements[12] = ui->insertNum_13;
    Elements[13] = ui->insertNum_14;
    Elements[14] = ui->insertNum_15;
    Elements[15] = ui->insertNum_16;

    if(n == 2) {
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j++) {
                text = QString::number(Matrix[i][j]);
                Elements[i*n*2 + j] -> setText(text);
            }
        }
    }
    else {
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j++) {
                text = QString::number(Matrix[i][j]);
                Elements[i*n + j] -> setText(text);
            }
        }
    }
}

void visual::ClearScreen() {
    ui->insertNum->clear();
    ui->insertNum_2->clear();
    ui->insertNum_3->clear();
    ui->insertNum_4->clear();
    ui->insertNum_5->clear();
    ui->insertNum_6->clear();
    ui->insertNum_7->clear();
    ui->insertNum_8->clear();
    ui->insertNum_9->clear();
    ui->insertNum_10->clear();
    ui->insertNum_11->clear();
    ui->insertNum_12->clear();
    ui->insertNum_13->clear();
    ui->insertNum_14->clear();
    ui->insertNum_15->clear();
    ui->insertNum_16->clear();
}

void visual::on_ok_clicked()
{

    if(step == 0) {
        QString getText;

        Elements[0] = ui->insertNum;
        Elements[1] = ui->insertNum_2;
        Elements[2] = ui->insertNum_3;
        Elements[3] = ui->insertNum_4;
        Elements[4] = ui->insertNum_5;
        Elements[5] = ui->insertNum_6;
        Elements[6] = ui->insertNum_7;
        Elements[7] = ui->insertNum_8;
        Elements[8] = ui->insertNum_9;
        Elements[9] = ui->insertNum_10;
        Elements[10] = ui->insertNum_11;
        Elements[11] = ui->insertNum_12;
        Elements[12] = ui->insertNum_13;
        Elements[13] = ui->insertNum_14;
        Elements[14] = ui->insertNum_15;
        Elements[15] = ui->insertNum_16;

        for(int i = 0; i < 4; i ++) {
            std::vector<int> line;
            for(int j = 0; j < 4; j++) {
                getText = Elements[i*4 + j]->text();
                line.push_back(getText.toInt());
            }
            Matrix1.push_back(line);
        }
        ui->ok->setText("Далее");
        step++;
    }
    else if(step == 1) {
        animate();
        ui->tutor->setText("\nРазбиваем на 4 матрицы размером n/2");
        ui->tutor->setAlignment(Qt::AlignCenter);
        ui->line->show();
        ui->line_2->show();

        for(int i = 0; i < 2; i ++) {
            std::vector<int> line;
            for(int j = 0; j < 2; j++) {
                line.push_back(Matrix1[i][j]);
                qDebug() << "\n M " << Matrix1[i][j] << " - " << i << " - " << j;
            }
            Matrix11_1.push_back(line);
        }

        for(int i = 0; i < 2; i ++) {
            std::vector<int> line;
            for(int j = 2; j < 4; j++) {
                line.push_back(Matrix1[i][j]);
            }
            Matrix12_1.push_back(line);
        }

        for(int i = 2; i < 4; i ++) {
            std::vector<int> line;
            for(int j = 0; j < 2; j++) {
                line.push_back(Matrix1[i][j]);
            }
            Matrix21_1.push_back(line);
        }

        for(int i = 2; i < 4; i ++) {
            std::vector<int> line;
            for(int j = 2; j < 4; j++) {
                line.push_back(Matrix1[i][j]);
            }
            Matrix22_1.push_back(line);
        }
        step++;
    }
    else if(step == 2) {
        animate();
        ClearScreen();
        ui->tutor->setText("\nВведите вторую матрицу");
        ui->tutor->setAlignment(Qt::AlignCenter);
        ui->line->hide();
        ui->line_2->hide();
        step++;

    }
    else if(step == 3) {
        animate();
        QString getText;
        Elements[0] = ui->insertNum;
        Elements[1] = ui->insertNum_2;
        Elements[2] = ui->insertNum_3;
        Elements[3] = ui->insertNum_4;
        Elements[4] = ui->insertNum_5;
        Elements[5] = ui->insertNum_6;
        Elements[6] = ui->insertNum_7;
        Elements[7] = ui->insertNum_8;
        Elements[8] = ui->insertNum_9;
        Elements[9] = ui->insertNum_10;
        Elements[10] = ui->insertNum_11;
        Elements[11] = ui->insertNum_12;
        Elements[12] = ui->insertNum_13;
        Elements[13] = ui->insertNum_14;
        Elements[14] = ui->insertNum_15;
        Elements[15] = ui->insertNum_16;

        for(int i = 0; i < 4; i ++) {
            std::vector<int> line;
            for(int j = 0; j < 4; j++) {
                getText = Elements[i*4 + j]->text();
                line.push_back(getText.toInt());
            }
            Matrix2.push_back(line);
        }
        ui->tutor->setText("\nРазбиваем на 4 матрицы размером n/2");
        ui->tutor->setAlignment(Qt::AlignCenter);
        ui->line->show();
        ui->line_2->show();

        for(int i = 0; i < 2; i ++) {
            std::vector<int> line;
            for(int j = 0; j < 2; j++) {
                line.push_back(Matrix2[i][j]);
                qDebug() << "\n M11_2 doing " << Matrix2[i][j];
            }
            Matrix11_2.push_back(line);
        }

        for(int i = 0; i < 2; i ++) {
            std::vector<int> line;
            for(int j = 2; j < 4; j++) {
                line.push_back(Matrix2[i][j]);
            }
            Matrix12_2.push_back(line);
        }

        for(int i = 2; i < 4; i ++) {
            std::vector<int> line;
            for(int j = 0; j < 2; j++) {
                line.push_back(Matrix2[i][j]);
            }
            Matrix21_2.push_back(line);
        }

        for(int i = 2; i < 4; i ++) {
            std::vector<int> line;
            for(int j = 2; j < 4; j++) {
                line.push_back(Matrix2[i][j]);
            }
            Matrix22_2.push_back(line);
        }
        step++;
    }
    else if(step == 4) {
        animate();
        ClearScreen();
        ui->tutor->setText("\nВычисляем d1 = ");
        ui->tutor->setAlignment(Qt::AlignCenter);
        ui->line->hide();
        ui->line_2->hide();
        std::vector<std::vector<int>> temp1 = SumMatrix(Matrix11_1, Matrix22_1);
        std::vector<std::vector<int>> temp2 = SumMatrix(Matrix11_2, Matrix22_2);
        d1 = MultiplyMatrix(temp1, temp2);
        qDebug() << "\n вывод d1 " << d1[0][0] << " " << d1[0][1] << "\n" << d1[1][0] << " " << d1[1][1];
        ShowMatrix(d1, 2);
        step++;
    }
    else if(step == 5) {
        animate();
        ClearScreen();
        ui->tutor->setText("\nВычисляем d2 = ");
        ui->tutor->setAlignment(Qt::AlignCenter);
        d2 = MultiplyMatrix(SumMatrix(Matrix21_1, Matrix22_1), Matrix11_2);
        //qDebug() << "\n вывод d1 " << d1[0][0];
        ShowMatrix(d2, 2);
        step++;
    }
    else if(step == 6) {
        animate();
        ClearScreen();
        ui->tutor->setText("\nВычисляем d3 = ");
        ui->tutor->setAlignment(Qt::AlignCenter);
        qDebug() << "\ndoing d3: " << " M11_1" << Matrix11_1[0][0] << " M22_1 " << Matrix12_1[0][0];
        d3 = MultiplyMatrix(Matrix11_1, MinusMatrix(Matrix12_2, Matrix22_2));
        //qDebug() << "\n вывод d1 " << d1[0][0];
        ShowMatrix(d3, 2);
        step++;
    }
    else if(step == 7) {
        animate();
        ClearScreen();
        ui->tutor->setText("\nВычисляем d4 = ");
        ui->tutor->setAlignment(Qt::AlignCenter);
        d4 = MultiplyMatrix(Matrix22_1, MinusMatrix(Matrix21_2, Matrix11_2));
        //qDebug() << "\n вывод d1 " << d1[0][0];
        ShowMatrix(d4, 2);
        step++;
    }
    else if(step == 8) {
        animate();
        ClearScreen();
        ui->tutor->setText("\nВычисляем d5 = ");
        ui->tutor->setAlignment(Qt::AlignCenter);
        d5 = MultiplyMatrix(SumMatrix(Matrix11_1, Matrix12_1), Matrix22_2);
        //qDebug() << "\n вывод d1 " << d1[0][0];
        ShowMatrix(d5, 2);
        step++;
    }
    else if(step == 9) {
        animate();
        ClearScreen();
        ui->tutor->setText("\nВычисляем d6 = ");
        ui->tutor->setAlignment(Qt::AlignCenter);
        d6 = MultiplyMatrix(MinusMatrix(Matrix21_1, Matrix11_1), SumMatrix(Matrix11_2, Matrix12_2));
        //qDebug() << "\n вывод d1 " << d1[0][0];
        ShowMatrix(d6, 2);
        step++;
    }
    else if(step == 10) {
        animate();
        ClearScreen();
        ui->tutor->setText("\nВычисляем d7 = ");
        ui->tutor->setAlignment(Qt::AlignCenter);
        d7 = MultiplyMatrix(MinusMatrix(Matrix12_1, Matrix22_1), SumMatrix(Matrix21_2, Matrix22_2));
        ShowMatrix(d7, 2);
        step++;
        qDebug() << "\n закончил d7 " << d1[0][0] << "\n d4 " << d4[0][0];
    }
    else if(step == 11) {
        animate();
        qDebug() << "\n приступил к C11 ";
        ClearScreen();
        ui->tutor->setText("\nВычисляем C11 = ");
        ui->tutor->setAlignment(Qt::AlignCenter);
        c1 = SumMatrix(SumMatrix(d1, d4), MinusMatrix(d7, d5));
        ShowMatrix(c1, 2);
        step++;
    }
    else if(step == 12) {
        animate();
        qDebug() << "\n c 1 " << c1[0][0];
        ClearScreen();
        ui->tutor->setText("\nВычисляем C12 = ");
        ui->tutor->setAlignment(Qt::AlignCenter);
        c2 = SumMatrix(d3, d5);
        ShowMatrix(c2, 2);
        step++;
    }
    else if(step == 13) {
        animate();
        ClearScreen();
        ui->tutor->setText("\nВычисляем C21 = ");
        ui->tutor->setAlignment(Qt::AlignCenter);
        c3 = SumMatrix(d2, d4);
        ShowMatrix(c3, 2);
        step++;
    }
    else if(step == 14) {
        animate();
        qDebug() << "\n C1 " << c1[0][0] << " " << c2[0][0] << " " << c3[0][0];
        ClearScreen();
        ui->tutor->setText("\nВычисляем C22 = ");
        ui->tutor->setAlignment(Qt::AlignCenter);
        c4 = SumMatrix(SumMatrix(d1, d3), MinusMatrix(d6, d2));
        ShowMatrix(c4, 2);
        step++;
    }
    else if(step == 15) {
        animate();
        ClearScreen();
        ui->tutor->setText("\nНаконец матрица C =  ");
        ui->tutor->setAlignment(Qt::AlignCenter);
        for(int i = 0; i < 2; i++) {
            std::vector<int> line;
            line.push_back(c1[i][0]);
            line.push_back(c1[i][1]);
            line.push_back(c2[i][0]);
            line.push_back(c2[i][1]);
            C.push_back(line);
        }

        for(int i = 0; i < 2; i++) {
            std::vector<int> line;
            line.push_back(c3[i][0]);
            line.push_back(c3[i][1]);
            line.push_back(c4[i][0]);
            line.push_back(c4[i][1]);
            C.push_back(line);
        }
        ShowMatrix(C, 4);
        step++;
    }
    else if(step == 16) {
        animate();
        ClearScreen();
        ui->tutor->setText("Теперь выполним умножение\n    методом Винограда, \n    используя введённые матрицы");
        ui->tutor->setAlignment(Qt::AlignCenter);
        step++;
        for(int i = 0; i < 4; i++) {
            std::vector<int> line;
            for(int j = 0; j < 4; j++) {
                line.push_back(0);
            }
            Column.push_back(0);
            Row.push_back(0);
            R.push_back(line);
        }
    }
    else if(step == 17) {
        animate();
        ClearScreen();
        ui->tutor->setText("Найдём сумму \n               𝚺(Ai*Ai+1), i - номер столбца \nкаждой строки матрицы");
        ui->tutor->setAlignment(Qt::AlignCenter);
        ui->Row1->show();
        ui->Row2->show();
        ui->Row3->show();
        ui->Row4->show();
        ui->Row5->show();
        ui->Row6->show();
        ui->Row7->show();
        ui->Row8->show();
        ui->Row9->show();
        ui->RowP1->show();
        ui->RowP2->show();
        ui->RowP3->show();
        ShowMatrix(Matrix1, 4);
        step++;

    }
    else if(step == 18) {
        animate();
        ClearScreen();
        ui->Row1->hide();
        ui->Row2->hide();
        ui->Row3->hide();
        ui->Row4->hide();
        ui->Row5->hide();
        ui->Row6->hide();
        ui->Row7->hide();
        ui->Row8->hide();
        ui->Row9->hide();
        ui->RowP1->hide();
        ui->RowP2->hide();
        ui->RowP3->hide();
        ui->tutor->setText("\nОна равна");
        ui->tutor->setAlignment(Qt::AlignCenter);
        for(int i = 0; i < 4; i++) {
            Row[i] = Matrix1[i][0] * Matrix1[i][1];
            for(int j = 1; j < 2; j++) {
                Row[i] = Row[i] + Matrix1[i][2*j] * Matrix1[i][2*j+1];
            }
        }
        ui->insertNum->setText(QString::number(Row[0]));
        ui->insertNum_2->setText(QString::number(Row[1]));
        ui->insertNum_3->setText(QString::number(Row[2]));
        ui->insertNum_4->setText(QString::number(Row[3]));
        step++;

    }
    else if(step == 19) {
        animate();
        ClearScreen();
        ui->tutor->setText("Найдём сумму \n           𝚺(BjBAj+1), i - номер строки \nдля каждого столбца матрицы");
        ui->tutor->setAlignment(Qt::AlignCenter);
        ui->Col1->show();
        ui->Col2->show();
        ui->Col3->show();
        ui->Col4->show();
        ui->Col5->show();
        ui->Col6->show();
        ui->Col7->show();
        ui->Col8->show();
        ui->Col9->show();
        ui->ColP1->show();
        ui->ColP2->show();
        ui->ColP3->show();
        ShowMatrix(Matrix2, 4);
        step++;

    }
    else if(step == 20) {
        animate();
        ClearScreen();
        ui->tutor->setText("\nОна равна");
        ui->tutor->setAlignment(Qt::AlignCenter);
        ui->Col1->hide();
        ui->Col2->hide();
        ui->Col3->hide();
        ui->Col4->hide();
        ui->Col5->hide();
        ui->Col6->hide();
        ui->Col7->hide();
        ui->Col8->hide();
        ui->Col9->hide();
        ui->ColP1->hide();
        ui->ColP2->hide();
        ui->ColP3->hide();
        for(int i = 0; i < 4; i++) {
            Column[i] = Matrix2[0][i] * Matrix2[1][i];
            for(int j = 1; j < 2; j++) {
                Column[i] = Column[i] + Matrix2[2*j][i] * Matrix2[2*j+1][i];
            }
        }
        ui->insertNum->setText(QString::number(Column[0]));
        ui->insertNum_2->setText(QString::number(Column[1]));
        ui->insertNum_3->setText(QString::number(Column[2]));
        ui->insertNum_4->setText(QString::number(Column[3]));
        step++;

    }
    else if(step == 21) {
        animate();
        ClearScreen();
        ui->tutor->setText("Наконец, отнимем от суммы \n𝚺(A2i + B2i+1)(A2i+1 + B2i) \nполученные ранние суммы");
        ui->tutor->setAlignment(Qt::AlignCenter);
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                qDebug() << "\n 1) R[i][j]: " << R[i][j] << " и " << Row[i] << " " << Column[j];
                R[i][j] = - Row[i] - Column[j];
                qDebug() << "\n 2) R[i][j]: " << R[i][j];
                for(int k = 0; k < 2; k++) {
                    qDebug() << "\n 3) Matrix[i][2*k]:  " << Matrix1[i][2*k] << " Matrix[2*k+1][j]: " << Matrix2[2*k + 1][j] << " Matrix1[i][2*k + 1]: " << Matrix1[i][2*k + 1] << "  Matrix2[2*k][j] " <<  Matrix2[2*k][j];
                    R[i][j] = R[i][j] + (Matrix1[i][2*k] + Matrix2[2*k + 1][j]) * (Matrix1[i][2*k + 1] + Matrix2[2*k][j]);
                    qDebug() << "\n 4) R[i][j]: " << R[i][j];
                }
            }
        }
        ShowMatrix(R, 4);
        step++;
    }
    else if(step == 22) {
        step = 0;
        this->parentWidget()->parentWidget()->setWindowOpacity(1.0);
        this->parentWidget()->parentWidget()->move(geometry().x(),geometry().y());
        this->parentWidget()->parentWidget()->show();
        this->parentWidget()->close();
        QPropertyAnimation *a = new QPropertyAnimation(this,"windowOpacity");
        a->setStartValue(1.0);
        a->setDuration(400);
        a->setEndValue(0.0);
        a->setEasingCurve(QEasingCurve::InSine);
        a->start(QPropertyAnimation::DeleteWhenStopped);
        connect(a,SIGNAL(finished()),this,SLOT(close()));
    }
}

void visual::mousePressEvent(QMouseEvent *event) {
    m_nMouseClick_X_Coordinate = event->position().x();
    m_nMouseClick_Y_Coordinate = event->position().y();
    qDebug() << m_nMouseClick_X_Coordinate << " -1tst- " << m_nMouseClick_Y_Coordinate;
}

void visual::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalPosition().x()-m_nMouseClick_X_Coordinate,event->globalPosition().y()-m_nMouseClick_Y_Coordinate);
    qDebug() << m_nMouseClick_X_Coordinate << " -2tst- " << m_nMouseClick_Y_Coordinate;
}

void visual::animate() {
    QPropertyAnimation *a = new QPropertyAnimation(this,"windowOpacity");
    a->setStartValue(1.0);
    a->setDuration(200);
    a->setEndValue(0.9);
    a->setEasingCurve(QEasingCurve::InSine);
    a->start(QPropertyAnimation::DeleteWhenStopped);
    a->setStartValue(0.9);
    a->setDuration(200);
    a->setEndValue(1.0);
    a->setEasingCurve(QEasingCurve::InSine);
    a->start(QPropertyAnimation::DeleteWhenStopped);
}

void visual::on_swish_clicked()
{
    this->parentWidget()->parentWidget()->setWindowOpacity(1.0);
    this->parentWidget()->parentWidget()->move(geometry().x(),geometry().y());
    this->parentWidget()->parentWidget()->show();
    this->parentWidget()->close();
    QPropertyAnimation *a = new QPropertyAnimation(this,"windowOpacity");
    a->setStartValue(1.0);
    a->setDuration(400);
    a->setEndValue(0.0);
    a->setEasingCurve(QEasingCurve::InSine);
    a->start(QPropertyAnimation::DeleteWhenStopped);
    connect(a,SIGNAL(finished()),this,SLOT(hide()));
}
