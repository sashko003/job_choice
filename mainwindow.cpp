#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::initUI(vector<Job> jobs)
{
    ui->setupUi(this);

    fillJobTable(jobs);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QStringList MainWindow::makeHzHeader(const vector<Job> &jobs)
{
    QStringList header;
    for(vector<Job>::const_iterator job = jobs.begin();
        job != jobs.end();
        ++job){

        header.append(QString(job->getName().c_str()));
    }
    return header;
}

QStringList MainWindow::makeVrHeader(const map<string, float> &jobs)
{
    QStringList header;
    for(map<string, float>::const_iterator job = jobs.begin();
        job != jobs.end();
        ++job){

        header.append(QString( (job->first).c_str() ));
    }
    return header;
}

void MainWindow::fillJobTable(const vector<Job>& jobs)
{
    ui->tableWidget_JobsData->setRowCount(ROW_COUNT);
    ui->tableWidget_JobsData->setColumnCount(COL_COUNT);
    QStringList hzHeaders = makeHzHeader(jobs);/*QStringList()<<        "Manager"<<
                                                   "Programmer"<<
                                                   "Driver"<<
                                                   "Referant"<<
                                                   "Translater";*/
    QStringList vtHeaders = makeVrHeader(jobs[0].getFeatures());/*QStringList()<<         "швидкість та гнучкість мислення"<<
                                                    "вміння швидко приймати рішення"<<
                                                    "стійкість та концентрація уваги"<<
                                                    "зорова память"<<
                                                    "швидкість реакції"<<
                                                    "рухлива память" <<
                                                    "фізична виносливість"<<
                                                    "координація рухів"<<
                                                    "емоційно-вольова стійкість"<<
                                                    "відповідальність";*/
    ui->tableWidget_JobsData->setHorizontalHeaderLabels(hzHeaders);
    ui->tableWidget_JobsData->setVerticalHeaderLabels(vtHeaders);
    addJobValue(jobs);
    //ui->tableWidget_JobsData->
}

void MainWindow::addJobValue(const vector<Job> &jobs)
{
    int i = 0;
    for(vector<Job>::const_iterator job = jobs.begin();
        job != jobs.end();
        ++job){
        map<string, float> values = job->getFeatures();
        int j = 0;
        for(map<string, float>::const_iterator val = values.begin();
            val != values.end();
            ++val){
            double temp = val->second;
            ui->tableWidget_JobsData->setItem(j, i, new QTableWidgetItem(
                                                    QString::number(temp,'g', 2)));
            ++j;
        }
        ++i;
    }
}
