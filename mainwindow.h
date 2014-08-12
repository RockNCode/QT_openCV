#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_rb_grayscale_toggled(bool checked);

    void on_rb_bw_toggled(bool checked);

    void on_rb_normal_toggled(bool checked);

    void on_slider_bw_sliderMoved(int position);

    void on_rb_hblur_toggled(bool checked);

    void on_actionTest_triggered();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
