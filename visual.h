#ifndef VISUAL_H
#define VISUAL_H

#include <QDialog>
#include <vector>

namespace Ui {
class visual;
}

class visual : public QDialog
{
    Q_OBJECT

public:
    explicit visual(QWidget *parent = nullptr);
    ~visual();

private slots:
    void on_ok_clicked();

    void on_swish_clicked();

private:
    Ui::visual *ui;
    std::vector<std::vector<int>> MultiplyMatrix(std::vector<std::vector<int>> Matrix1, std::vector<std::vector<int>> Matrix2);
    std::vector<std::vector<int>> SumMatrix(std::vector<std::vector<int>> Matrix1, std::vector<std::vector<int>> Matrix2);
    std::vector<std::vector<int>> MinusMatrix(std::vector<std::vector<int>> Matrix1, std::vector<std::vector<int>> Matrix2);
    void ShowMatrix(std::vector<std::vector<int>> Matrix, int n);
    void ClearScreen();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;
    void animate();
};

#endif // VISUAL_H
