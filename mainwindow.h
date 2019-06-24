#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QWidget>
namespace Ui {
/**classe onde toda a interface eh criada*/
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    /**Cria o objeto do tipo sculptor e envia para Esculpper quando o botao eh clicado, e habilita todos os outros botoes e sliders
     * padroes da interface. quando pressionado esse botao eh desabilitado, logo nao eh possivel criar mais
     * de um esculptor durante uma unica execucao do programa
    */
    void on_BtnSculpCreate_clicked();
    /**Chama o metodo set color da classe sculpper atribuindos as cores dos sliders rgb*/
    void on_BtnSetClor_clicked();
    /**Seleciona como padrao a operacao de caixa do sculpper e atribui os lados em cada dimensao de acordo com o que
     * estava escrita nos lines edits especificos para informar as dimansoes da caixa;
    */
    void on_BtnOpBox_clicked();
    /**Seleciona como padrao a operacao de esfera do sculpper e desabilita o botao
    */
    void on_BtnOpSphere_clicked();
    /**Seleciona como padrao a operacao de elipsoide do sculpper e desabilita o botao
    */
    void on_BtnOpElipsoide_clicked();
    /**Seleciona como padrao a operacao de Voxel do sculpper e desabilita o botao(essa eh a operacao padrao
     * quando o sculptor eh criado)
    */
    void on_BtnOpVoxel_clicked();
    /**Seleciona como padrao a operacao do sculpper de inserir a figura */
    void on_RBPut_clicked();
    /**Seleciona como padrao a operacao do sculpper de cortar a figura */
    void on_RBCut_clicked();
    /**Seleciona como padrao o plano XY do sculpper */
    void on_BtnPlan0_clicked();
    /**Seleciona como padrao o plano XZ do sculpper */
    void on_BtnPlsn1_clicked();
    /**Seleciona como padrao o plano ZY do sculpper */
    void on_BtnPlan2_clicked();
    /**Envia um comando para o Sculpper inserir a figura geometrica que atualmente eh a padrao, e, coordenadas
     *    especificas
    */
    void on_BtnPutCoordenadas_clicked();
    /**Envia um comando para o Sculpper cortar a figura geometrica que atualmente eh a padrao, e, coordenadas
     *    especificas
    */
    void on_BtnCutCoordenadas_clicked();
    /**Habilita a insercao ou corte de figuras se escolhendo as coordenadas especificas
    */
    void on_CbCoordenadas_clicked();
    /**Atualiza as coordendas do plano x quando elas sao mudadas
    */
    void on_SliPlanX_valueChanged(int value);
    /**Atualiza as coordendas do plano y quando elas sao mudadas
    */
    void on_SliPlanY_valueChanged(int value);
    /**Atualiza as coordendas do plano z quando elas sao mudadas
    */
    void on_SliPlanZ_valueChanged(int value);
    /**Atualiza os valores do raio da esfera quando ocorre a alteracao do slider
    */
    void on_SliRaio_valueChanged(int value);
    /**Atualiza os valores do raio da elipsoide na coordenada x quando ocorre a alteracao do slider
    */
    void on_SliRx_valueChanged(int value);
    /**Atualiza os valores do raio da elipsoide na coordenada y quando ocorre a alteracao do slider
    */
    void on_SliRy_valueChanged(int value);
    /**Atualiza os valores do raio da elipsoide na coordenada z quando ocorre a alteracao do slider
    */
    void on_SliRz_valueChanged(int value);
    /**Atualiza os valores da cor vermelha quando ocorre a alteracao do slider
    */
    void on_SliRed_valueChanged(int value);
    /**Atualiza os valores da cor verde quando ocorre a alteracao do slider
    */
    void on_SliGreen_valueChanged(int value);
    /**Atualiza os valores da cor azul quando ocorre a alteracao do slider
    */
    void on_SliBlue_valueChanged(int value);
    /**Atualiza os valores da transparencia quando ocorre a alteracao do slider
    */
    void on_SliTransparencia_valueChanged(int value);
    /**Manda para o Esculpper o nome do arquivo tipo OFF que se deseja salvar o desenho atual que esta
     * sendo desenvolvido na interface
    */
    void on_BtnSaveOFF_clicked();
    /**Manda para o Esculpper o nome do arquivo tipo VECT que se deseja salvar o desenho atual que esta
     * sendo desenvolvido na interface
    */
    void on_BtnSaveVECT_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
