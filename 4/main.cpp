#include <QDialog>
#include "viewer.h"
#include <qapplication.h>
#include <datamanager.h>

int main(int argc, char **argv) {

  QApplication application(argc, argv);
  DataManager dataManager;
  dataManager.GenerateDots();

  Viewer viewer(&dataManager);

  viewer.setWindowTitle("simpleViewer");

  dataManager.OpenFile(&application);

  viewer.show();

  return application.exec();
}
