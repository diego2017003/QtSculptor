#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QWidget>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_BtnSculpCreate_clicked();

    void on_BtnSetClor_clicked();

    void on_BtnOpBox_clicked();

    void on_BtnOpSphere_clicked();

    void on_BtnOpElipsoide_clicked();

    void on_BtnOpVoxel_clicked();

    void on_RBPut_clicked();

    void on_RBCut_clicked();

    void on_BtnPlan0_clicked();

    void on_BtnPlsn1_clicked();

    void on_BtnPlan2_clicked();

    void on_BtnPutCoordenadas_clicked();

    void on_BtnCutCoordenadas_clicked();

    void on_CbCoordenadas_clicked();


    void on_SliPlanX_valueChanged(int value);

    void on_SliPlanY_valueChanged(int value);

    void on_SliPlanZ_valueChanged(int value);

    void on_SliRaio_valueChanged(int value);

    void on_SliRx_valueChanged(int value);

    void on_SliRy_valueChanged(int value);

    void on_SliRz_valueChanged(int value);

    void on_SliRed_valueChanged(int value);


    void on_SliGreen_valueChanged(int value);

    void on_SliBlue_valueChanged(int value);

    void on_SliTransparencia_valueChanged(int value);

    void on_BtnSaveOFF_clicked();

    void on_BtnSaveVECT_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
