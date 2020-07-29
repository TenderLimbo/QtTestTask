#ifndef VIEWER_H
#define VIEWER_H

#include <QGLViewer/qglviewer.h>
#include "datamanager.h"

class Viewer : public QGLViewer {
public:
    Viewer(DataManager* dm);
protected:
  virtual void draw();
  virtual void init();
  virtual QString helpString() const;
private:
    DataManager* dataManager;
};


#endif // VIEWER_H
