#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fillJobTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fillJobTable()
{
    ui->tableWidget_JobsData->setRowCount(ROW_COUNT);
    ui->tableWidget_JobsData->setColumnCount(COL_COUNT);
    QStringList hzHeaders = QStringList()<<        "Manager"<<
                                                   "Programmer"<<
                                                   "Driver"<<
                                                   "Referant"<<
                                                   "Translater";
    QStringList vtHeaders = QStringList()<<         "швидкість та гнучкість мислення"<<
                                                    "вміння швидко приймати рішення"<<
                                                    "стійкість та концентрація уваги"<<
                                                    "зорова память"<<
                                                    "швидкість реакції"<<
                                                    "рухлива память" <<
                                                    "фізична виносливість"<<
                                                    "координація рухів"<<
                                                    "емоційно-вольова стійкість"<<
                                                    "відповідальність";
    ui->tableWidget_JobsData->setHorizontalHeaderLabels(hzHeaders);
    ui->tableWidget_JobsData->setVerticalHeaderLabels(vtHeaders);
}
