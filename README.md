# QtSculptor
## Descrição do projeto
  Esse projeto tem por objetivo criar imagens tridimensionais formadas por cubos. O projeto contém uma interface gráfica
 desenvolvida no Qt para auxiliar a criação de figuras geométricas de forma intuitiva para o usúario. As figuras geométricas
 padrões do programa possibilitam a criação de ellipsoides, esferas, caixas e um único ponto.A criação das formas geometricas 
 pode ser feita ao clicar em uma célula disponível no espaço destinado para desenho, ou inserindo as coordenadas desejadas para 
 o centro da figura tridimensional que se deseja inserir no desenho.
    Além das formas geometricas tridimensionais o usuario pode escolher os valores da cor no padrão RGB e também a transparência 
  que deseja dar às figuras que está desenvolvendo. O projeto possibilita salvar o desenho feito em arquivos do formato OFF e VECT
  que podem ser abertos em softwares como o meshlab e o geomview.
## Observações importantes
  *Os Espaços para texto disponiveis para dados numéricos como as dimensões do Escultor, lados da caixa ou coordenadas, só estão 
  preparados para lidar com dados numéricos;
  
  *Ao apertar na opção de criar o Escultor sem ter delimitado as dimensões o programa utiliza 20 unidades de medida como padrão;
  
  *Os lados da caixa devem ser digitados no espaço devido antes de apertar o botão da operação.
  
  *Ao apertar na operação de caixa sem estabelecer as dimensões desejadas o programa utiliza 10 unidades de medida como padrão;
  
  *Antes de inciar o programa é importante ir até as operações de salvar o arquivo e adaptar o diretorio de salvamento para os 
  parametros do computador do usuário;
  
  *O programa tem tamanho fixo em tela.
 ## Funcionamento
 ![interfaceInicial](interface.PNG)
    Ao executar o programa ele terá as caracteristica da imagem acima. No inicio da execução todos os botões, com excessão do criar
  Escultor e dos botões de salvar, começam desabilitados, além dos botões os slider verticais, 'checkboxes' e radiu buttons também 
  começam desabilitados para usuário.
    Nesse momento o usuário deve informar no espaço de titulo "tamanho" quais serão as dimensões do escultor que ele deseja criar.
   Lembrando que os dados passados no espaço de texto devem ser dados numéricos e que se nenhum parametro for repassado ao clicar 
   no botão "criar Escultor" todas as dimensões terão como tamanho padrão o número 20.Vale ressaltar que pelo tamanho do programa 
   ser fixo, selecionando acima de 35 unidades para as dimensões o widget que desenha as células pode ganhar caracteristicas 
   peculiares por causa das equações por trás da criação das células de desenho no widget.
    Só é possível criar um escultor durante o tempo de  execução do programa pois ao clicar para criar o escultor o botão fica 
   desabilitado á medida que todas as outras funcionalidades do programa são habilitadas para o usuário utilizar. 
   
