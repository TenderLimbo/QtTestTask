#include "MyWindow.h"
#include "ZeroTaskTab.h"
#include "FirstTaskTab.h"
#include "SecondTaskTab.h"


MyWindow::MyWindow(QWidget*parent) : QDialog(parent){
    tabWidget = new QTabWidget;
    tabWidget->addTab(new ZeroTaskTab,"ZeroTask");
    tabWidget->addTab(new FirstTaskTab,"FirstTask");
    tabWidget->addTab(new SecondTaskTab,"SecondTask");

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tabWidget);
    setLayout(mainLayout);
}
