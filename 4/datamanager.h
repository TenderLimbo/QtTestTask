#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QStack>
#include <qapplication.h>

struct Dot {
    float x,y,z;
};

class DataManager
{
public:
    DataManager();
    void GenerateDots();
    void OpenFile(QApplication* v);
    QVector<Dot>dots;

};

#endif // DATAMANAGER_H
