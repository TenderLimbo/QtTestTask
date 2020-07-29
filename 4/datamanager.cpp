#include "datamanager.h"
#include "Random.h"


#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

DataManager::DataManager()
{

}

void DataManager::GenerateDots(){
    QFile out("/Users/nikitapashko/Qt/Projects/4/output.txt");
    if (out.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&out);
        for(int i = 0; i < 1000000; i++) {
        stream << Random::get(0.0f,3.0f) << ' ';
        stream << Random::get(0.0f,3.0f) << ' ';
        stream << Random::get(0.0f,3.0f) << '\n';
        }
        out.close();
    }
}

void DataManager::OpenFile(QApplication* v) {
    QString fileName = QFileDialog::getOpenFileName(v->activeWindow(),
        "Open File", "/Users/nikitapashko/Qt/Projects/4/", "Text Files (*.txt)");
    QFile input(fileName);
    if (input.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&input);
        float x,y,z;

        while (!stream.atEnd()) {
           stream >> x >> y >> z;
           dots.push_back({x,y,z});
        }
        dots.pop_back();
        input.close();
    }
}
