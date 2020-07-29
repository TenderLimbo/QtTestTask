#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QDialog>
#include <QTabWidget>
#include <QVBoxLayout>


class MyWindow : public QDialog {
    Q_OBJECT

public:
    MyWindow(QWidget* parent = 0);
private:
    QTabWidget* tabWidget;
};



#endif // MYWINDOW_H
