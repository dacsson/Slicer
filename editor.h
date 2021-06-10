#ifndef EDITOR_H
#define EDITOR_H

#include <QDialog>

namespace Ui {
class editor;
}

class editor : public QDialog
{
    Q_OBJECT

public:
    explicit editor(QWidget *parent = nullptr);
    ~editor();

private slots:
    void on_apply_clicked();

    void on_swish_clicked();

    void on_pull_clicked();

    void on_ok_clicked();

private:
    Ui::editor *ui;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;
    void Replace(QString &text);
};

#endif // EDITOR_H
