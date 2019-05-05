#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#define ROW_COUNT 9
#define COL_COUNT 5

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void fillJobTable();
    void initUserTable();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
