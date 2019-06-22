#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include "sculptor.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->widgetSculpper,
             SIGNAL(posx(int)),
             ui->LCDPosX,
             SLOT(display(int)));

     connect(ui->widgetSculpper,
             SIGNAL(posy(int)),
             ui->LCDPosY,
             SLOT(display(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_BtnSculpCreate_clicked()
{
    int nx,ny,nz;
    QString x,y,z;
    if(ui->txtNx->text().trimmed()!=""){
    x=ui->txtNx->text();
    nx=x.toInt();
    }
    else{
     nx=20;
    }
    if(ui->txtNy->text().trimmed()!=""){
    y=ui->txtNy->text();
    ny=y.toInt();
    }
    else{
     ny=20;
    }
    if(ui->txtNz->text().trimmed()!=""){
    z=ui->txtNz->text();
    nz=z.toInt();
    }
    else{
       nz=20;
    }
    ui->widgetSculpper->setNx(nx);
    ui->widgetSculpper->setNy(ny);
    ui->widgetSculpper->setNz(nz);
    Sculptor *t = new Sculptor(nx,ny,nz);
    ui->widgetSculpper->setSculptor(*t);
    ui->widgetSculpper->repaint();
    ui->BtnSculpCreate->setDisabled(true);
    ui->BtnOpVoxel->setDisabled(true);
    ui->BtnSetClor->setDisabled(false);
    ui->BtnOpBox->setDisabled(false);
    ui->BtnOpSphere->setDisabled(false);
    ui->BtnOpElipsoide->setDisabled(false);
    ui->BtnPlsn1->setDisabled(false);
    ui->BtnPlan2->setDisabled(false);
    ui->BtnSetClor->setDisabled(false);
    ui->CbManual->setCheckState(Qt::Checked);
    ui->RBPut->setChecked(true);
    ui->SliPlanX->setMaximum(nx);
    ui->SliPlanY->setMaximum(ny);
    ui->SliPlanZ->setMaximum(nz);
    ui->SliRaio->setMaximum(nx/2);
    ui->SliRx->setMaximum(nx/2);
    ui->SliRy->setMaximum(ny/2);
    ui->SliRz->setMaximum(nz/2);
}

void MainWindow::on_BtnSetClor_clicked()
{
    float r,g,b,t;
    r = (ui->SliRed->value());
    g = (ui->SliGreen->value());
    b = (ui->SliBlue->value());
    t = ui->SliTransparencia->value();
    ui->widgetSculpper->setColor(r,g,b,t);
}

void MainWindow::on_BtnOpBox_clicked()
{
    int lx,ly,lz;
    QString x,y,z;
    if(ui->TxtLx->text().trimmed()!=""){
    x=ui->TxtLx->text();
    lx=x.toInt();
    }
    else{
     lx=10;
    }
    if(ui->TxtLy->text().trimmed()!=""){
    y=ui->TxtLy->text();
    ly=y.toInt();
    }
    else{
     ly=10;
    }
    if(ui->TxtLz->text().trimmed()!=""){
    z=ui->TxtLz->text();
    lz=z.toInt();
    }
    else{
       lz=10;
    }
    ui->widgetSculpper->setBox(lx,ly,lz);
    ui->widgetSculpper->setOperation(1);
    ui->BtnOpVoxel->setDisabled(false);
}

void MainWindow::on_BtnOpSphere_clicked()
{
    float raio;
    raio = ui->SliRaio->value();
    ui->widgetSculpper->setRaio(raio);
    ui->widgetSculpper->setOperation(2);
    ui->BtnOpVoxel->setDisabled(false);

}

void MainWindow::on_BtnOpElipsoide_clicked()
{
    float rx,ry,rz;
    rx = ui->SliRx->value();
    ry = ui->SliRx->value();
    rz = ui->SliRx->value();
    if((rx==0)||(ry==0)||(rz==0)){
        rx=1;
        ry=1;
        rz=1;
    }
    ui->widgetSculpper->setRx(rx);
    ui->widgetSculpper->setRy(ry);
    ui->widgetSculpper->setRz(rz);
    ui->widgetSculpper->setOperation(3);
    ui->BtnOpVoxel->setDisabled(false);
}

void MainWindow::on_BtnOpVoxel_clicked()
{
    ui->widgetSculpper->setOperation(0);
    ui->BtnOpVoxel->setDisabled(true);
}

void MainWindow::on_RBPut_clicked()
{
    ui->widgetSculpper->setPutCut(0);
}


void MainWindow::on_RBCut_clicked()
{
    ui->widgetSculpper->setPutCut(1);
}

void MainWindow::on_BtnPlan0_clicked()
{
    ui->widgetSculpper->setPlano(0);
    ui->BtnPlan0->setDisabled(true);
    ui->BtnPlsn1->setDisabled(false);
    ui->BtnPlan2->setDisabled(false);
}

void MainWindow::on_BtnPlsn1_clicked()
{
    ui->widgetSculpper->setPlano(1);
    ui->BtnPlan0->setDisabled(false);
    ui->BtnPlsn1->setDisabled(true);
    ui->BtnPlan2->setDisabled(false);
}

void MainWindow::on_BtnPlan2_clicked()
{
    ui->widgetSculpper->setPlano(2);
    ui->BtnPlan0->setDisabled(false);
    ui->BtnPlsn1->setDisabled(false);
    ui->BtnPlan2->setDisabled(true);
}

void MainWindow::on_BtnPutCoordenadas_clicked()
{
    int x,y,z;
    QString cx,cy,cz;

    cx = ui->TxtcoordenadaX->text();
    cy = ui->TxtcoordenadaY->text();
    cz = ui->TxtcoordenadaZ->text();
    if(cx.trimmed()!=""){
    x = cx.toInt();
    }
    else{
        x = 0;
    }
    if(cy.trimmed()!=""){
    y = cy.toInt();
    }
    else{
        y = 0;
    }
    if(cz.trimmed()!=""){
    z = cz.toInt();
    }
    else{
        z = 0;
   }
    ui->widgetSculpper->Inserir(x,y,z);
}

void MainWindow::on_BtnCutCoordenadas_clicked()
{
    int x,y,z;
    QString cx,cy,cz;

    cx = ui->TxtcoordenadaX->text();
    cy = ui->TxtcoordenadaY->text();
    cz = ui->TxtcoordenadaZ->text();
    if(cx.trimmed()!=""){
    x = cx.toInt();
    }
    else{
        x = 0;
    }
    if(cy.trimmed()!=""){
    y = cy.toInt();
    }
    else{
        y = 0;
    }
    if(cz.trimmed()!=""){
    z = cz.toInt();
    }
    else{
        z = 0;
   }
    ui->widgetSculpper->cortar(x,y,z);
}

void MainWindow::on_CbCoordenadas_clicked()
{
  if(ui->CbCoordenadas->checkState()==Qt::Checked){
    ui->BtnPutCoordenadas->setDisabled(false);
    ui->BtnCutCoordenadas->setDisabled(false);
  }
  else{
      ui->BtnPutCoordenadas->setDisabled(true);
      ui->BtnCutCoordenadas->setDisabled(true);
  }
}
