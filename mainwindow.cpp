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
    setJobColWidth(80);

    initUserTable(jobs);
    initResultTable(jobs);
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

void MainWindow::setJobColWidth(const int width)
{
    for(int i = 0; i<COL_COUNT_JOB; ++i){
        ui->tableWidget_JobsData->setColumnWidth(i, width);
    }
}

void MainWindow::fillJobTable(const vector<Job>& jobs)
{
    ui->tableWidget_JobsData->setRowCount(ROW_COUNT_JOB);
    ui->tableWidget_JobsData->setColumnCount(COL_COUNT_JOB);
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

void MainWindow::initUserTable(const vector<Job> &jobs)
{
    ui->tableWidget_UserData->setRowCount(ROW_COUNT_USER);
    ui->tableWidget_UserData->setColumnCount(COL_COUNT_USER);
    QStringList hzHeaders = {"Value"};
    QStringList vtHeaders = makeVrHeader(jobs[0].getFeatures());
    vtHeaders.insert(vtHeaders.begin(), "User Name");
    ui->tableWidget_UserData->setHorizontalHeaderLabels(hzHeaders);
    ui->tableWidget_UserData->setVerticalHeaderLabels(vtHeaders);
}

void MainWindow::initResultTable(const vector<Job> &jobs)
{
    ui->tableWidget_Result->setRowCount(ROW_COUNT_RESULT);
    ui->tableWidget_Result->setColumnCount(COL_COUNT_RESULT);
    QStringList vtHeaders = {"Value"};
    QStringList hzHeaders = makeHzHeader(jobs);
    ui->tableWidget_Result->setHorizontalHeaderLabels(hzHeaders);
    ui->tableWidget_Result->setVerticalHeaderLabels(vtHeaders);
    ui->tableWidget_Result->setColumnWidth(-1, 300);
}

void MainWindow::on_pushButton_EnterData_clicked()
{
    string name = ui->tableWidget_UserData->item(0, 1)->text().toStdString();
    vector<float> values;
    float temp = 0.0;
    for(int i = 1; i<ui->tableWidget_UserData->rowCount(); ++i){
        if(ui->tableWidget_UserData->item(i, 1)->text() == "")
            temp = 0.0;
        temp = ui->tableWidget_UserData->item(i, 1)->text().toFloat();
        values.push_back(temp);
    }
    user.set(name, values);
}

void MainWindow::on_pushButton_BuildDiagram_clicked()
{
    string name = ui->tableWidget_UserData->item(0, 1)->text().toStdString();
    vector<float> values;
    float temp = 0.0;
    for(int i = 1; i<ui->tableWidget_UserData->rowCount(); ++i){
        if(ui->tableWidget_UserData->item(i, 1)->text() == "")
            temp = 0.0;
        temp = ui->tableWidget_UserData->item(i, 1)->text().toFloat();
        values.push_back(temp);
    }
    user.set(name, values);
}
