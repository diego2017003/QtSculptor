#include "esculpper.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QColor>
#include <QPointF>
#include <cmath>
#include <QMouseEvent>
#include<cstring>
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
   if(plan==1){
        hz = height()/nz;
   }
   else {
       hz=width()/nz;
   }
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

 if(nx!=1||ny!=1||nz!=1){
    if(plan==0){
    for(int i =0;i<nx;i++){
      for(int j=0;j<ny;j++){
        painter.drawRect(i*hx,j*hy,(i+1)*hx,(j+1)*hy);
      }
  }

  for(int i =0;i<nx;i++){
      for(int j=0;j<ny;j++){
          Voxel *v = s->AcessarElementoMatriz3D(i,j,planCoordenada);
          if((*v).isOn==true){
              s->getColor(i,j,planCoordenada,r,g,b);
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
 else if(plan==1){
    for(int i =0;i<nx;i++){
      for(int j=0;j<nz;j++){
        painter.drawRect(i*hx,j*hz,(i+1)*hx,(j+1)*hz);
      }
  }
  for(int i =0;i<nx;i++){
      for(int j=0;j<nz;j++){
          Voxel *v = s->AcessarElementoMatriz3D(i,planCoordenada,j);
          if((*v).isOn==true){
              s->getColor(i,planCoordenada,j,r,g,b);
              r = r*255;
              g = g*255;
              b = b*255;
              pen.setColor(QColor(r,g,b));
              brush.setColor(QColor(r,g,b));
              painter.setPen(pen);
              painter.setBrush(brush);
              QPointF *c =new QPointF(qreal(hx*(i+0.5)),qreal(hz*(j+0.5)));
              painter.drawEllipse(*c,qreal(hx/2),qreal(hz/2));
              }
          }

        }
    }
 else if(plan==2){
    for(int i =0;i<nz;i++){
      for(int j=0;j<ny;j++){
        painter.drawRect(i*hz,j*hy,(i+1)*hz,(j+1)*hy);
      }
  }
  for(int i =0;i<nz;i++){
      for(int j=0;j<ny;j++){
          Voxel *v = s->AcessarElementoMatriz3D(planCoordenada,j,i);
          if((*v).isOn==true){
              s->getColor(planCoordenada,j,i,r,g,b);
              r = r*255;
              g = g*255;
              b = b*255;
              pen.setColor(QColor(r,g,b));
              brush.setColor(QColor(r,g,b));
              painter.setPen(pen);
              painter.setBrush(brush);
              QPointF *c =new QPointF(qreal(hz*(i+0.5)),qreal(hy*(j+0.5)));
              painter.drawEllipse(*c,qreal(hz/2),qreal(hy/2));
              }
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
        if(plan==0){
        px=(int)px/hx;
        py=(int)py/hy;
        }
        else if(plan==1){
        px=(int)px/hx;
        py=(int)py/hz;
        }
        else if(plan==2){
            px=(int)px/hz;
            py=(int)py/hy;
         }
    }
    emit posx(px);
    emit posy(py);
    if(mousePress==1){
        if(plan==0){
            if(pc==0){
            if(OperationVBSE==0){
                this->s->setColor(this->r,this->g,this->b,this->t);
                this->s->putVoxel(px,py,planCoordenada);
             }
            if(OperationVBSE==1){
                this->s->setColor(this->r,this->g,this->b,this->t);
                this->s->putBox(px-((float)(lx-1)/2),px+((float)(lx-1)/2),py-((float)(lx-1)/2),py+((float)(ly-1)/2),
                                planCoordenada-((float)(lz-1)/2),planCoordenada+((float)(lz-1)/2));
             }
            if(OperationVBSE==2){
                this->s->setColor(this->r,this->g,this->b,this->t);
                this->s->putSphere(px,py,planCoordenada,raio);
             }
            if(OperationVBSE==3){
                this->s->setColor(this->r,this->g,this->b,this->t);
                this->s->putEllipsoid(px,py,planCoordenada,rx,ry,rz);
             }
            }
            if(pc==1){
            if(OperationVBSE==0){

                this->s->cutVoxel(px,py,planCoordenada);
             }
            if(OperationVBSE==1){

                this->s->cutBox(px-((float)(lx-1)/2),px+((float)(lx-1)/2),py-((float)(lx-1)/2),py+((float)(ly-1)/2),
                                planCoordenada-((float)(lz-1)/2),planCoordenada+((float)(lz-1)/2));
             }
            if(OperationVBSE==2){

                this->s->cutSphere(px,py,planCoordenada,raio);
             }
            if(OperationVBSE==3){

                this->s->cutEllipsoid(px,py,planCoordenada,rx,ry,rz);
             }
            }
        }
        else if(plan==2){
            if(pc==0){
            if(OperationVBSE==0){
                this->s->setColor(this->r,this->g,this->b,this->t);
                this->s->putVoxel(planCoordenada,py,px);
             }
            else if(OperationVBSE==1){
                this->s->setColor(this->r,this->g,this->b,this->t);
                this->s->putBox(planCoordenada-((float)(lz-1)/2),planCoordenada+((float)(lz-1)/2),py-((float)(lx-1)/2),py+((float)(ly-1)/2),
                                px-((float)(lx-1)/2),px+((float)(lx-1)/2));
             }
            else if(OperationVBSE==2){
                this->s->setColor(this->r,this->g,this->b,this->t);
                this->s->putSphere(planCoordenada,py,px,raio);
             }
            else if(OperationVBSE==3){
                this->s->setColor(this->r,this->g,this->b,this->t);
                this->s->putEllipsoid(planCoordenada,py,px,rx,ry,rz);
             }
            }
            else if(pc==1){
            if(OperationVBSE==0){

                this->s->cutVoxel(planCoordenada,py,px);
             }
            else if(OperationVBSE==1){

                this->s->cutBox(planCoordenada-((float)(lz-1)/2),planCoordenada+((float)(lz-1)/2),py-((float)(lx-1)/2),py+((float)(ly-1)/2),
                                px-((float)(lx-1)/2),px+((float)(lx-1)/2));
             }
            else if(OperationVBSE==2){

                this->s->cutSphere(planCoordenada,py,px,raio);
             }
            else if(OperationVBSE==3){

                this->s->cutEllipsoid(planCoordenada,py,px,rx,ry,rz);
             }
            }
        }
        else if(plan==1){
            if(pc==0){
            if(OperationVBSE==0){
                this->s->setColor(this->r,this->g,this->b,this->t);
                this->s->putVoxel(px,planCoordenada,py);
             }
            else if(OperationVBSE==1){
                this->s->setColor(this->r,this->g,this->b,this->t);
                this->s->putBox(px-((float)(lx-1)/2),px+((float)(lx-1)/2),planCoordenada-((float)(lz-1)/2),planCoordenada+((float)(lz-1)/2),
                                py-((float)(lx-1)/2),py+((float)(ly-1)/2));
             }
            else if(OperationVBSE==2){
                this->s->setColor(this->r,this->g,this->b,this->t);
                this->s->putSphere(px,planCoordenada,py,raio);
             }
            else if(OperationVBSE==3){
                this->s->setColor(this->r,this->g,this->b,this->t);
                this->s->putEllipsoid(px,planCoordenada,py,rx,ry,rz);
             }
            }
            else if(pc==1){
            if(OperationVBSE==0){

                this->s->cutVoxel(px,planCoordenada,py);
             }
            else if(OperationVBSE==1){

                this->s->cutBox(px-((float)(lx-1)/2),px+((float)(lx-1)/2),planCoordenada-((float)(lz-1)/2),planCoordenada+((float)(lz-1)/2),
                                py-((float)(lx-1)/2),py+((float)(ly-1)/2));
             }
            else if(OperationVBSE==2){

                this->s->cutSphere(px,planCoordenada,py,raio);
             }
            else if(OperationVBSE==3){

                this->s->cutEllipsoid(px,planCoordenada,py,rx,ry,rz);
             }
            }
        }
       // s->writeOFF("C:/Users/Cliente/Desktop/teste.off");
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
    this->s->setColor(this->r,this->g,this->b,this->t);
    this->s->putVoxel(px,py,planCoordenada);
    s->writeOFF("C:/Users/Cliente/Desktop/teste.txt");
    repaint();
}
void Esculpper::mousePressEvent(QMouseEvent *e){
    int px,py;
    this->mousePress=1;
    px = e->x();
    py = e->y();
    if(nx!=1 && ny!=1){
        if(plan==0){
        px=(int)px/hx;
        py=(int)py/hy;
        }
        else if(plan==1){
        px=(int)px/hx;
        py=(int)py/hz;
        }
        else if(plan==2){
            px=(int)px/hz;
            py=(int)py/hy;
         }
    }
if(plan==0){
    if(pc==0){
    if(OperationVBSE==0){
        this->s->setColor(this->r,this->g,this->b,this->t);
        this->s->putVoxel(px,py,planCoordenada);
     }
    if(OperationVBSE==1){
        this->s->setColor(this->r,this->g,this->b,this->t);
        this->s->putBox(px-((float)(lx-1)/2),px+((float)(lx-1)/2),py-((float)(lx-1)/2),py+((float)(ly-1)/2),
                        planCoordenada-((float)(lz-1)/2),planCoordenada+((float)(lz-1)/2));
     }
    if(OperationVBSE==2){
        this->s->setColor(this->r,this->g,this->b,this->t);
        this->s->putSphere(px,py,planCoordenada,raio);
     }
    if(OperationVBSE==3){
        this->s->setColor(this->r,this->g,this->b,this->t);
        this->s->putEllipsoid(px,py,planCoordenada,rx,ry,rz);
     }
    }
    if(pc==1){
    if(OperationVBSE==0){

        this->s->cutVoxel(px,py,planCoordenada);
     }
    if(OperationVBSE==1){

        this->s->cutBox(px-((float)(lx-1)/2),px+((float)(lx-1)/2),py-((float)(lx-1)/2),py+((float)(ly-1)/2),
                        planCoordenada-((float)(lz-1)/2),planCoordenada+((float)(lz-1)/2));
     }
    if(OperationVBSE==2){

        this->s->cutSphere(px,py,planCoordenada,raio);
     }
    if(OperationVBSE==3){

        this->s->cutEllipsoid(px,py,planCoordenada,rx,ry,rz);
     }
    }
}
else if(plan==2){
    if(pc==0){
    if(OperationVBSE==0){
        this->s->setColor(this->r,this->g,this->b,this->t);
        this->s->putVoxel(planCoordenada,py,px);
     }
    else if(OperationVBSE==1){
        this->s->setColor(this->r,this->g,this->b,this->t);
        this->s->putBox(planCoordenada-((float)(lz-1)/2),planCoordenada+((float)(lz-1)/2),py-((float)(lx-1)/2),py+((float)(ly-1)/2),
                        px-((float)(lx-1)/2),px+((float)(lx-1)/2));
     }
    else if(OperationVBSE==2){
        this->s->setColor(this->r,this->g,this->b,this->t);
        this->s->putSphere(planCoordenada,py,px,raio);
     }
    else if(OperationVBSE==3){
        this->s->setColor(this->r,this->g,this->b,this->t);
        this->s->putEllipsoid(planCoordenada,py,px,rx,ry,rz);
     }
    }
    else if(pc==1){
    if(OperationVBSE==0){

        this->s->cutVoxel(planCoordenada,py,px);
     }
    else if(OperationVBSE==1){

        this->s->cutBox(planCoordenada-((float)(lz-1)/2),planCoordenada+((float)(lz-1)/2),py-((float)(lx-1)/2),py+((float)(ly-1)/2),
                        px-((float)(lx-1)/2),px+((float)(lx-1)/2));
     }
    else if(OperationVBSE==2){

        this->s->cutSphere(planCoordenada,py,px,raio);
     }
    else if(OperationVBSE==3){

        this->s->cutEllipsoid(planCoordenada,py,px,rx,ry,rz);
     }
    }
}
else if(plan==1){
    if(pc==0){
    if(OperationVBSE==0){
        this->s->setColor(this->r,this->g,this->b,this->t);
        this->s->putVoxel(px,planCoordenada,py);
     }
    else if(OperationVBSE==1){
        this->s->setColor(this->r,this->g,this->b,this->t);
        this->s->putBox(px-((float)(lx-1)/2),px+((float)(lx-1)/2),planCoordenada-((float)(lz-1)/2),planCoordenada+((float)(lz-1)/2),
                        py-((float)(lx-1)/2),py+((float)(ly-1)/2));
     }
    else if(OperationVBSE==2){
        this->s->setColor(this->r,this->g,this->b,this->t);
        this->s->putSphere(px,planCoordenada,py,raio);
     }
    else if(OperationVBSE==3){
        this->s->setColor(this->r,this->g,this->b,this->t);
        this->s->putEllipsoid(px,planCoordenada,py,rx,ry,rz);
     }
    }
    else if(pc==1){
    if(OperationVBSE==0){

        this->s->cutVoxel(px,planCoordenada,py);
     }
    else if(OperationVBSE==1){

        this->s->cutBox(px-((float)(lx-1)/2),px+((float)(lx-1)/2),planCoordenada-((float)(lz-1)/2),planCoordenada+((float)(lz-1)/2),
                        py-((float)(lx-1)/2),py+((float)(ly-1)/2));
     }
    else if(OperationVBSE==2){

        this->s->cutSphere(px,planCoordenada,py,raio);
     }
    else if(OperationVBSE==3){

        this->s->cutEllipsoid(px,planCoordenada,py,rx,ry,rz);
     }
    }
}
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
    float red=(float)r/255,green=(float)g/255,blue=(float)b/255,trans=(float)a/255;
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
    repaint();
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
    if(plan==0){
        if(OperationVBSE==0){

            this->s->cutVoxel(x,y,z);
         }
        if(OperationVBSE==1){

            this->s->cutBox(x-((float)(lx-1)/2),x+((float)(lx-1)/2),y-((float)(lx-1)/2),y+((float)(ly-1)/2),
                            z-((float)(lz-1)/2),z+((float)(lz-1)/2));
         }
        if(OperationVBSE==2){

            this->s->cutSphere(x,y,z,raio);
         }
        if(OperationVBSE==3){

            this->s->cutEllipsoid(x,y,z,rx,ry,rz);
         }
    }
    else if(plan==2){
        if(OperationVBSE==0){

            this->s->cutVoxel(x,y,z);
         }
        else if(OperationVBSE==1){

            this->s->cutBox(x-((float)(lz-1)/2),x+((float)(lz-1)/2),y-((float)(lx-1)/2),y+((float)(ly-1)/2),
                            z-((float)(lx-1)/2),z+((float)(lx-1)/2));
         }
        else if(OperationVBSE==2){

            this->s->cutSphere(x,y,z,raio);
         }
        else if(OperationVBSE==3){

            this->s->cutEllipsoid(x,y,z,rx,ry,rz);
         }

    }
    else if(plan==1){

        if(OperationVBSE==0){

            this->s->cutVoxel(x,y,z);
         }
        else if(OperationVBSE==1){

            this->s->cutBox(x-((float)(lx-1)/2),x+((float)(lx-1)/2),y-((float)(lz-1)/2),y+((float)(lz-1)/2),
                            z-((float)(lx-1)/2),z+((float)(ly-1)/2));
         }
        else if(OperationVBSE==2){

            this->s->cutSphere(x,y,z,raio);
         }
        else if(OperationVBSE==3){

            this->s->cutEllipsoid(x,y,z,rx,ry,rz);
         }
      }

            //s->writeOFF("C:/Users/Cliente/Desktop/teste.off");
           repaint();
}
void Esculpper::Inserir(int x,int y,int z){
    if(plan==0){
        if(OperationVBSE==0){
            this->s->setColor(this->r,this->g,this->b,this->t);
            this->s->putVoxel(x,y,z);
         }
        if(OperationVBSE==1){
            this->s->setColor(this->r,this->g,this->b,this->t);
            this->s->putBox(x-((float)(lx-1)/2),x+((float)(lx-1)/2),y-((float)(lx-1)/2),y+((float)(ly-1)/2),
                            z-((float)(lz-1)/2),z+((float)(lz-1)/2));
         }
        if(OperationVBSE==2){
            this->s->setColor(this->r,this->g,this->b,this->t);
            this->s->putSphere(x,y,z,raio);
         }
        if(OperationVBSE==3){
            this->s->setColor(this->r,this->g,this->b,this->t);
            this->s->putEllipsoid(x,y,z,rx,ry,rz);
         }
    }
    else if(plan==2){
        if(OperationVBSE==0){
            this->s->setColor(this->r,this->g,this->b,this->t);
            this->s->putVoxel(x,y,z);
         }
        else if(OperationVBSE==1){
            this->s->setColor(this->r,this->g,this->b,this->t);
            this->s->putBox(x-((float)(lz-1)/2),x+((float)(lz-1)/2),y-((float)(lx-1)/2),y+((float)(ly-1)/2),
                            z-((float)(lx-1)/2),z+((float)(lx-1)/2));
         }
        else if(OperationVBSE==2){
            this->s->setColor(this->r,this->g,this->b,this->t);
            this->s->putSphere(x,y,z,raio);
         }
        else if(OperationVBSE==3){
            this->s->setColor(this->r,this->g,this->b,this->t);
            this->s->putEllipsoid(x,y,z,rx,ry,rz);
         }

    }
    else if(plan==1){

        if(OperationVBSE==0){
            this->s->setColor(this->r,this->g,this->b,this->t);
            this->s->putVoxel(x,y,z);
         }
        else if(OperationVBSE==1){
            this->s->setColor(this->r,this->g,this->b,this->t);
            this->s->putBox(x-((float)(lx-1)/2),x+((float)(lx-1)/2),y-((float)(lz-1)/2),y+((float)(lz-1)/2),
                            z-((float)(lx-1)/2),z+((float)(ly-1)/2));
         }
        else if(OperationVBSE==2){
            this->s->setColor(this->r,this->g,this->b,this->t);
            this->s->putSphere(x,y,z,raio);
         }
        else if(OperationVBSE==3){
            this->s->setColor(this->r,this->g,this->b,this->t);
            this->s->putEllipsoid(x,y,z,rx,ry,rz);
         }
      }

            //s->writeOFF("C:/Users/Cliente/Desktop/teste.off");
           repaint();

}
void Esculpper::setPlanoCoordenada(int planoCoordenada){
    this->planCoordenada=planoCoordenada;
    repaint();
}
void Esculpper::SetRed(int r){
    this->r=(float)r/255;
    repaint();
}
void Esculpper::SetGreen(int g){
    this->g=(float)g/255;
    repaint();
}
void Esculpper::SetBlue(int b){
    this->b=(float)b/255;
    repaint();
}
void Esculpper::SetTransparencia(int t){
    this->t=(float)t/255;
    repaint();
}
void Esculpper::SalvarOFF(QString s){
    std::string txt="C:/Users/Cliente/Desktop/"+s.toStdString()+".off";
    this->s->writeOFF(txt);
}
void Esculpper::SalvarVECT(QString s){
    std::string txt="C:/Users/Cliente/Desktop/"+s.toStdString()+".vect";
    this->s->writeOFF(txt);
}
