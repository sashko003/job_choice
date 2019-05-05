#include "mainwindow.h"
#include <QApplication>

vector<Job> createJobsVec( vector<string> features );


int main(int argc, char *argv[])
{
    vector<string> features = {"швидкість та гнучкість мислення",
                               "вміння швидко приймати рішення",
                               "стійкість та концентрація уваги",
                               "зорова память",
                               "швидкість реакції",
                               "рухлива память",
                               "фізична виносливість",
                               "координація рухів",
                               "емоційно-вольова стійкість",
                               "відповідальність"
    };
    vector<Job> jobs = createJobsVec( features );

    QApplication a(argc, argv);
    MainWindow w;
    w.initUI(jobs);
    w.show();

    return a.exec();
}

vector<Job> createJobsVec( vector<string> features )
{
    Job manager("Manager",
                features,
                vector<float>({0.9, 0.9, 0.8, 0.4, 0.5, 0.3, 0.6, 0.2, 0.9, 0.8}));
    Job programmer("Programmer",
                   features,
                   vector<float>({0.8, 0.5, 0.9, 0.3, 0.1, 0.2, 0.2, 0.2, 0.5, 0.5}));
    Job driver("Driver",
               features,
               vector<float>({0.3, 0.9, 0.6, 0.5, 0.9, 0.8, 0.9, 0.8, 0.6, 0.3}));
    Job referant("Referant",
                 features,
                 vector<float>({0.5, 0.4, 0.5, 0.5, 0.2, 0.2, 0.3, 0.3, 0.9, 0.8}));
    Job translater("Translater",
                   features,
                   vector<float>({0.7, 0.8, 0.8, 0.2, 0.6, 0.2, 0.2, 0.3, 0.3, 0.2}));

    return vector<Job>{manager, programmer, driver, referant, translater};
}
