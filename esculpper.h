#ifndef ESCULPPER_H
#define ESCULPPER_H
#include <QWidget>
#include "sculptor.h"
/**Esculpper eh uma classe que herda os parametros e metodos da classe principal
 * QWidget e sobrepoe os atributos dessa classe no intuito de possibilitar ao usuario desse
 * programa desenhar figurar geometricas dentro do container
*/
class Esculpper : public QWidget{
  Q_OBJECT
private:
/**os atributos nx, ny, nz dizem respeito as dimensoes escolhidas para a criação do objeto esculptor
 * nao ha nenhum limite para a escolha desses parametros entretanto acima de 35 o desenho comeca a
 * ter caracteristicas distorcidas;
*/
int nx=1,ny=1,nz=1;
/**o atributo pc diz respeito ao tipo de operacao selcionada na interface valor 0 significa colocar
 * valor 1 significa cortar
*/
int pc=0;
/**OperationVBSE diz respeito a operacao selecionada no presente momento, valor 0 significa voxel,
 * valor 1 significa operacao de caixa, valor 2 operacao de esfera, valor 3 operacao de elipsoide
*/
int OperationVBSE=0;
/**os atributos lx,ly,lz dizem respeito as dimensoes dos lados em uma operacao do tipo caixa
*/
int lx=1,ly=1,lz=1;
/**o atributo plan diz qual eh o plano atual no qual se esta trabalhando, 0-plano XY, 1- plano XZ
 * 2-plano ZY
*/
int plan=0;
/**planCoordenada diz respeito ao plano atual que esta sendo selecionado pelo slide dos planos na interface
 * por exemplo se o plano que esta sendo mostrada no widget eh o XY, planCoordenada diz qual eh a coordenada z
*/
int planCoordenada=0;
/**parametros de cores e transparencia; r- red,g-green , b- blue, t - transparencia
*/
float r=0,g=0,b=0,t=0;
/**os parametros dizem respeito as dimensoes dos raios quando esta selecionada a operacao de esfera ou elipse
 * raio eh o raio da esfera, rx - raio da elipse nas coordenadas x, ry - raio da elipse nas coordenadas y,
 * rz - raio da elipse nas coordenadas z.
*/
float raio=1,rx=1,ry=1,rz=1;
/**os parametros h dizem respeito as dimensoes de uma celula dentro do widget Esculpper da mainWindow, hx eh o
 * tamanho em pixels do lado x na celula, hy eh o tamanho do lado y em pixels na celula, hz eh o tamanho do lado z
 * em pixels na celula;
*/
float hx,hy,hz;
/**s eh um objeto da classe esculptor onde todas as figuras sao criadas como uma matriz tridimensional de voxels
*/
Sculptor *s;
/**o parametro mousePress eh o parametro auxiliar que informa se o botao esquerdo do mouse esta sendo pressionado
*/
bool mousePress=0;
public:
/**Construtor padrao da classe esculpper
*/
  explicit Esculpper(QWidget *parent = nullptr);
/**metodo responsavel por desenhar todas as formas geometricas na tela de acordo com a utilizacao do programa pelo
 * usuario;
*/
  void paintEvent(QPaintEvent *e);
/**metodo responsavel pelo rastreamento do mouse no widget e tambem pelo insercao de figuras no esculptor quando
 * o mouse esta pressionado
*/
  void mouseMoveEvent(QMouseEvent *e);
/**metodo responsavel pela insercao de um voxel no sculptor quando o usuario der dois cliques no mouse
*/
  void mouseDoubleClickEvent(QMouseEvent *e);
/**metodo responsavel por identificar quando o mouse deixa de ser pressionado
*/
  void mouseReleaseEvent(QMouseEvent *e);
/**metodo responsavel por identificar quando o botao do mouse for pressionado e inserir ou remover a forma geometrica
 * no sculptor
*/
  void mousePressEvent(QMouseEvent *e);
/**metodo responsavel por receber do usuario as dimensoes do escultor em x
*/
  void setNx(int nx);
 /**metodo responsavel por receber do usuario as dimensoes do escultor em y
 */
  void setNy(int ny);
  /**metodo responsavel por receber do usuario as dimensoes do escultor em z
  */
  void setNz(int nz);
  /**metodo responsavel por receber do usuario as dimensoes em x do raio da elipse
  */
  void setRx(float rx);
  /**metodo responsavel por receber do usuario as dimensoes em y do raio da elipse
  */
  void setRy(float ry);
  /**metodo responsavel por receber do usuario as dimensoes em z do raio da elipse
  */
  void setRz(float rz);
  /**metodo responsavel por receber do usuario as dimensoes do raio da esfera
  */
  void setRaio(float r);
  /**metodo responsavel por receber do usuario qual eh o plano escolhido para se trabalhar
  */
  void setPlano(int plan);
  /**metodo responsavel por receber do usuario se a operacao eh de inserir ou cortar a figura
  */
  void setPutCut(int pc);
  /**metodo responsavel por receber do usuario qual eh a operacao desejada
  */
  void setOperation(int op);
  /**metodo responsavel por receber do usuario as dimensoes da caixa
  */
  void setBox(int lx,int ly,int lz);
  /**metodo responsavel por receber do usuario qual eh a coordenada atual do plano corrente
  */
  void setPlanoCoordenada(int planoCoordenada);
  /**metodo responsavel por receber do usuario um objeto escultor novo
  */
  void setSculptor(Sculptor &s);
  /**metodo responsavel por receber do usuario as coordenadas desejadas e entao cortar a figura que
   * esta atualmente selecionada na interface
  */
  void cortar(int x,int y,int z);
  /**metodo responsavel por receber do usuario as coordenadas desejadas e entao inserir a figura que
   * esta atualmente selecionada na interface
  */
  void Inserir(int x,int y,int z);
  /**metodo responsavel por receber do usuario a intensidade desejada da cor vermelha
  */
  void SetRed(int r);
  /**metodo responsavel por receber do usuario a intensidade desejada da cor verde
  */
  void SetGreen(int g);
  /**metodo responsavel por receber do usuario a intensidade desejada da cor azul
  */
  void SetBlue(int b);
  /**metodo responsavel por receber do usuario o grau de transparencia desejado
  */
  void SetTransparencia(int t);
  /**metodo responsavel por receber do usuario o nome do arquivo a ser criada e salvar a figura em
   * um arquivo do tipo OFF
  */
  void SalvarOFF(QString s);
  /**metodo responsavel por receber do usuario o nome do arquivo a ser criada e salvar a figura em
   * um arquivo do tipo VECT
  */
  void SalvarVECT(QString s);
  /**metodo responsavel por retornar o objeto sculptor quando desejado
  */
  Sculptor getSculptor();
  /**metodo responsavel por selecionar a cor rgb de forma sincrona;
  */
  void setColor(float r,float g,float b,float a);
signals:
  /**informa a coordenada x para a interface
  */
  void posx(int);
  /**informa a coordenada y para a interface
  */
  void posy(int);
};


#endif // ESCULPPER_H
