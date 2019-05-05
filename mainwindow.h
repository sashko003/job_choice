#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#define ROW_COUNT_JOB 10
#define COL_COUNT_JOB 5
#define COL_COUNT_USER 1
#define ROW_COUNT_USER 11
#define COL_COUNT_RESULT 5
#define ROW_COUNT_RESULT 1

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
    void initUserTable(const vector<Job> &jobs);
    void initResultTable(const vector<Job> &jobs);
private slots:
    void on_pushButton_EnterData_clicked();

    void on_pushButton_BuildDiagram_clicked();

private:
    QStringList makeHzHeader(const vector<Job>& jobs);
    QStringList makeVrHeader(const map<string, float> &jobs);
    void setJobColWidth(const int width);
private:
    Ui::MainWindow *ui;
    User user;
};

#endif // MAINWINDOW_H
