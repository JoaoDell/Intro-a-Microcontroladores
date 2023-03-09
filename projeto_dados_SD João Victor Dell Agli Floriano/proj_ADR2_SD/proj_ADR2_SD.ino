#include <stdint.h>
#include <TFTv2.h>
#include <SPI.h>
TextOrientation orientation;
//definindo as variáveis 
int i;
float b =20;
int k=20;
int val;
int posy = 0;
int posy2 = 0;
int posymax=100;
int posymin = 0;
char leg[] = {' ', ' ', ' ', ' '};
char x[]={' ', ' ', ' ', ' '};
char y[]={' ', ' ', ' ', ' '};
char Np[]={' ', ' ', ' ', ' '};
char Nm[]={' ', ' ', ' ', ' '};
char Npp[]={' ', ' ', ' ', ' '};

char esc[]={' ', ' ', ' ', ' '};
int Npontos;
int Nmedias;
int Npassos;
const float pi = 3.14;



void setup() {
  Serial.begin(9600);
  TFT_BL_ON;
  Tft.TFTinit();
  //coleta de pontos e valores para o programa

}
void(* resetFunc) (void) = 0;



void loop() {
Serial.println("digite a para começar o programa");
while(Serial.find("a")==false){
}

  Npontos=0;
  Nmedias=0;
  Npassos=0;
  

  while(Npontos<1){
          Npontos = Serial.parseInt();
        }
  while(Nmedias<1){
          Nmedias = Serial.parseInt();
        }
  while(Npassos<1){
          Npassos = Serial.parseInt();
        }
  //desenhando a interface gráfica
  Tft.fillRectangle(0,0,240,320,GRAY1);
  Tft.drawRectangle(30,20,180,280,BLUE);
  orientation = LANDSCAPE;
  Tft.drawString("Titulo do projeto",90,220,1,YELLOW,orientation);
  Tft.drawString("Pontos",130,13,1,YELLOW,orientation);

  //a função spintf converter os valores para um char de strings que é exigido pela função para desenhar na tela
  Tft.drawString("Npontos=",0,13,1,YELLOW,orientation);
  sprintf(Np,"%d", Npontos);
  Tft.drawString(Np,50,13,1,YELLOW,orientation);

  
  Tft.drawString("Nmedias=",0,0,1,YELLOW,orientation);
  sprintf(Nm,"%d", Nmedias);
  Tft.drawString(Nm,50,0,1,YELLOW,orientation);

  
  Tft.drawString("Npassos=",85,0,1,YELLOW,orientation);
  sprintf(Npp,"%d", Npassos);
  Tft.drawString(Npp,135,0,1,YELLOW,orientation);


  Tft.drawHorizontalLine(25,85,10,BLUE);
  sprintf(Np,"%d", int(Npontos/4));
  Tft.drawString(x,85,22,1,YELLOW,orientation);

  Tft.drawHorizontalLine(25,150,10,BLUE);
  sprintf(Np,"%d",int(2*Npontos/4));
  Tft.drawString(x,150,22,1,YELLOW,orientation);
  Tft.drawHorizontalLine(25,215,10,BLUE);

  sprintf(Np,"%d",int(3*Npontos/4));
  Tft.drawString(x,215,22,1,YELLOW,orientation);

 
  
  Tft.drawString("valor de x=",230,13,1,YELLOW,orientation);
  Tft.drawString("valor de y=",230,0,1,YELLOW,orientation);
  Tft.drawString("Disponivel",220,220,1,YELLOW,orientation);
  orientation = PORTRAIT_UPSIDE_DOWN;
  Tft.drawString("legenda",100,0,1,YELLOW,orientation);
  Tft.fillCircle(225,300,10,GREEN);
 


  orientation = LANDSCAPE;
  
  //caso seja enviado a, o programa inicia a plotagem dos valores
 
    
    //mudando o estado para indisponível
    Tft.fillRectangle(31,21,177,277,GRAY1);
    Tft.drawString("Disponivel",220,220,1,GRAY1,orientation);
    Tft.drawString("Indisponivel",220,220,1,YELLOW,orientation);
    Tft.fillCircle(225,300,10,RED);
    
  
    for (i=0;i<Npontos;i++){
      
      posy = Serial.parseInt();

    
      if (posy>posymax){
        
        posymax=posy*1.1;
        sprintf(leg,"%d",posymax);
        Tft.drawString(leg,20,200,YELLOW,orientation);
        Serial.println("recomecar");
        
        Tft.fillRectangle(31,21,177,277,GRAY1);

        b = 20.0;
        
        for(int j = 0; j < i; j++){
          posy2 = Serial.parseInt();
          posy2 = map(posy2,0,posymax,35,180);
          Tft.fillCircle(posy2,round(b),3,RED);
          b += 280.0/float(Npontos);
        }
      }
      
      
      posy = map(posy,0,posymax,35,180);

      //plotagem feita com posição x e y
      Tft.fillCircle(posy,round(b),3,RED);
      Tft.drawString(x,300,20,1,YELLOW,orientation);
      Tft.drawString(x,300,20,1,GRAY1,orientation);
      Tft.drawString(y,300,0,1,YELLOW,orientation);
      Tft.drawString(y,300,0,1,GRAY1,orientation);
      b+=280.0/float(Npontos);
      }
    
    
        b = 20;
        
    //muda o estado novamente para disponível para iniciar uma nova coleta
    Tft.drawString("Indisponivel",220,220,1,GRAY1,orientation);
    Tft.fillCircle(225,300,10,GREEN);
    Tft.drawString("Disponivel",220,220,1,YELLOW,orientation);
  
  
}
