#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <windows.h>
#include "editor.h"

namespace Ui {
class settings;
}

class settings : public QDialog
{
    Q_OBJECT

public:
    explicit settings(QWidget *parent = nullptr);
    ~settings();

private slots:

    void on_swish_clicked();

    void on_downl_clicked();

    void on_apply_clicked();

    void on_edit_clicked();

private:
    Ui::settings *ui;
    editor *edit;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;
};

#endif // SETTINGS_H
