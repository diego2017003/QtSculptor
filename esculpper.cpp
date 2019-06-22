#include "esculpper.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QColor>
#include <QPointF>
#include <cmath>
#include <QMouseEvent>
#include "sculptor.h"
Esculpper::Esculpper(QWidget *parent) : QWidget(parent){
    setMouseTracking(true);

    // habilita o rastreio do mouse
}
void Esculpper::paintEvent(QPaintEvent *e){
  QPainter painter(this);
  QBrush brush;
  QPen pen;
  int nx=this->nx,ny=this->ny,nz=this->nz;
  float hx,hy,hz,r,g,b;
   hx = width()/nx;
   hy = height()/ny;
   hz = height()/nz;
   this->hx=hx;
   this->hy=hy;
   this->hz=hz;
  painter.setRenderHint(QPainter::Antialiasing);

  brush.setColor(QColor(0,120,155));
  brush.setStyle(Qt::SolidPattern);

  pen.setColor(QColor(0,0,0));
  pen.setWidth(2);


  painter.setBrush(brush);
  painter.setPen(pen);
    painter.drawRect(0,0,width(), height());
    pen.setColor(QColor(0,23,140));
    brush.setColor(QColor(255,255,255));
    painter.setPen(pen);
    painter.setBrush(brush);
  for(int i =0;i<nx;i++){
      for(int j=0;j<ny;j++){
        painter.drawRect(i*hx,j*hy,(i+1)*hx,(j+1)*hy);
      }
  }
if(nx!=1||ny!=1||nz!=1){
  for(int i =0;i<nx;i++){
      for(int j=0;j<ny;j++){
          Voxel *v = s->AcessarElementoMatriz3D(i,j,0);
          if((*v).isOn==true){
              s->getColor(i,j,0,r,g,b);
              r = r*255;
              g = g*255;
              b = b*255;
              pen.setColor(QColor(r,g,b));
              brush.setColor(QColor(r,g,b));
              painter.setPen(pen);
              painter.setBrush(brush);
              QPointF *c =new QPointF(qreal(hx*(i+0.5)),qreal(hy*(j+0.5)));
              painter.drawEllipse(*c,qreal(hx/2),qreal(hy/2));
          }
      }

  }
}

}

void Esculpper::mouseMoveEvent(QMouseEvent *e){
    int px,py;
    px = e->x();
    py = e->y();
    if(nx!=1 && ny!=1){
     px=(int)px/hx;
     py=(int)py/hy;
    }
    emit posx(px);
    emit posy(py);
    if(mousePress==1){
        this->s->putVoxel(px,py,0);
    //s->writeOFF("C:/Users/Cliente/Desktop/teste.off");
       repaint();
    }
}
void Esculpper::mouseDoubleClickEvent(QMouseEvent *e){
    int px,py;
    px = e->x();
    py = e->y();
    if(nx!=1 && ny!=1){
     px=(int)px/hx;
     py=(int)py/hy;
    }
    this->s->putVoxel(px,py,0);
    s->writeOFF("C:/Users/Cliente/Desktop/teste.txt");
    repaint();
}
void Esculpper::mousePressEvent(QMouseEvent *e){
    int px,py;
    this->mousePress=1;
    px = e->x();
    py = e->y();
    if(nx!=1 && ny!=1){
     px=(int)px/hx;
     py=(int)py/hy;
    }
        this->s->putVoxel(px,py,0);
    //s->writeOFF("C:/Users/Cliente/Desktop/teste.off");
       repaint();


}
void Esculpper::mouseReleaseEvent(QMouseEvent *e){
    if(e->button()==Qt::LeftButton){
        mousePress=0;
    }
}
void Esculpper::setNx(int nx){
    this->nx=nx;
}
void Esculpper::setNy(int ny){
    this->ny=ny;
}
void Esculpper::setNz(int nz){
    this->nz=nz;
}
void Esculpper::setSculptor(Sculptor &s){
    this->s=&s;
}
void Esculpper::setColor(float r,float g,float b,float a){
    this->r=r;
    this->g=g;
    this->b=b;
    this->t=a;
    float red=r/255,green=g/255,blue=b/255,trans=a/255;
    this->s->setColor(red,green,blue,trans);

}
void Esculpper::setRx(float rx){
    this->rx=rx;
}
void Esculpper::setRy(float ry){
    this->ry=ry;
}
void Esculpper::setRz(float rz){
    this->rz=rz;
}
void Esculpper::setRaio(float r){
    this->raio=r;
}
void Esculpper::setPlano(int plan){
    this->plan=plan;
}
void Esculpper::setPutCut(int pc){
    this->pc = pc;
}
void Esculpper::setOperation(int op){
    this->OperationVBSE=op;
}
void Esculpper::setBox(int lx,int ly,int lz){
    this->lx=lx;
    this->ly=ly;
    this->lz=lz;
}
void Esculpper::cortar(int x,int y,int z){

}
void Esculpper::Inserir(int x,int y,int z){

}
