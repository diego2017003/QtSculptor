#ifndef ESCULPPER_H
#define ESCULPPER_H
#include <QWidget>
#include "sculptor.h"
class Esculpper : public QWidget{
  Q_OBJECT
private:
int nx=1,ny=1,nz=1,pc=0,OperationVBSE=0,lx=1,ly=1,lz=1,plan=0;
float r=0,g=0,b=0,t=0,raio=1,rx=1,ry=1,rz=1;
float hx,hy,hz;
Sculptor *s;
bool mousePress=0;
public:
  explicit Esculpper(QWidget *parent = nullptr);

  void paintEvent(QPaintEvent *e);
  void mouseMoveEvent(QMouseEvent *e);
  void mouseDoubleClickEvent(QMouseEvent *e);
  void mouseReleaseEvent(QMouseEvent *e);
  void mousePressEvent(QMouseEvent *e);
  void setNx(int nx);
  void setNy(int ny);
  void setNz(int nz);
  void setRx(float rx);
  void setRy(float ry);
  void setRz(float rz);
  void setRaio(float r);
  void setPlano(int plan);
  void setPutCut(int pc);
  void setOperation(int op);
  void setBox(int lx,int ly,int lz);
  void setSculptor(Sculptor &s);
  void cortar(int x,int y,int z);
  void Inserir(int x,int y,int z);
  Sculptor getSculptor();
  void setColor(float r,float g,float b,float a);
signals:
  void posx(int);
  void posy(int);

};


#endif // ESCULPPER_H
