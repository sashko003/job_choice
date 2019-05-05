#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#define ROW_COUNT 10
#define COL_COUNT 5

#include "job.h"
#include "user.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initUI(vector<Job> jobs);

    void fillJobTable(const vector<Job>& jobs);
    void addJobValue(const vector<Job>& jobs);
    void initUserTable(vector<string> features);
private:
    QStringList makeHzHeader(const vector<Job>& jobs);
    QStringList makeVrHeader(const map<string, float> &jobs);
private:
    Ui::MainWindow *ui;
    User user;
};

#endif // MAINWINDOW_H
