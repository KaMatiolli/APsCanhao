#include <stdio.h>
#include <math.h>

int main(void) {
 float v_inicial=0, angulo=0, distancia_alvo=0, tamanho_alvo=0; 
 float g = 9.81, pi = 3.14, alcance_horizontal, tempo_trajeto, altura_maxima; 
 float desvio, distancia_mais, distancia_menos;
 float media_alcance=0, maior_altura_agora = 0;
 int menu, cont = 0, acertou_alvo = 0;
 
printf("\n\tAPS - Algoritmos e Programação 2020\n\n");
printf("Karina de Oliveira Matiolli\t\t- 20773925\n");
printf("Karen Arantes de O. Novaes\t\t- 20818536\n");
printf("Letycia Amorim dos Santos\t\t- 20988033\n");
printf("Ashlley Maria de Lima Assis\t\t- 21505602\n");
printf("Fernanda Beatriz Leme Bergoci\t- 21506812\n\n\n");

printf("\n       MENU DE OPÇÕES: \n\n1 - Simular disparo \n2 - Mostrar estatísticas \n3 - Sair \n\n");
printf("Selecione a opção desejada: ");
scanf("%d", &menu);
 
do{
if(menu==1){
 
do{
printf("\n\t\tSimular disparo\n");  
printf("\nQual a velocidade inicial: ");
scanf("%f", &v_inicial);
if(v_inicial<=0){
 printf("Informação invalida, digite novamente!\n");
}
}while(v_inicial<=0);
 
do{
printf("\nQual o angulo do lancamento: ");
scanf("%f", &angulo);
if(angulo<=0 || angulo >=90){
 printf("Informação invalida, digite novamente!\n");
}
}while(angulo<=0 || angulo >=90);
 
do{
printf("\nQual a distância do alvo: ");
scanf("%f", &distancia_alvo);
if(distancia_alvo<=0){
 printf("Informação invalida, digite novamente!\n");
}
}while(distancia_alvo<=0);
 
do{
  printf("\nQual tamanho do alvo: ");
  scanf("%f", &tamanho_alvo);
if(tamanho_alvo<20 || tamanho_alvo>50){
 printf("Informação invalida, digite novamente!\n");
}  
}while(tamanho_alvo<20 || tamanho_alvo>50);
//Alcance horizontal
angulo = (angulo*pi)/180;
alcance_horizontal = ((2.0*v_inicial*v_inicial*cos(angulo)*sin(angulo))/g);
printf("\nAlcance Horizontal: %.2f m/s", alcance_horizontal);
//Tempo do trajeto
tempo_trajeto = ((2*v_inicial*sin(angulo))/g);
printf("\nTempo do Trajeto: %.2f s", tempo_trajeto);
//altura maxima
altura_maxima = (v_inicial*v_inicial*sin(angulo))/(2.0*g);
printf("\nAltura Máxima: %.2f m", altura_maxima);
//atingiu o alvo
desvio= tamanho_alvo/2.0;
distancia_mais = distancia_alvo+desvio;
distancia_menos = distancia_alvo-desvio;
 if(alcance_horizontal >= distancia_menos && alcance_horizontal <= distancia_mais){
  acertou_alvo ++;
  printf("\n\nVoce acertou o alvo!!");
}else if(alcance_horizontal<distancia_menos){
  printf("\n\nVoce acertou antes do alvo");
}else{
  printf("\n\nVoce acertou depois do alvo");
}
cont ++;
media_alcance = (media_alcance + alcance_horizontal)/cont;
if(altura_maxima ==0 || altura_maxima>maior_altura_agora){
maior_altura_agora = altura_maxima;
}
 
printf("\n\n       MENU DE OPÇÕES: \n\n1 - Simular disparo \n2 - Mostrar estatísticas \n3 - Sair \n\n");
printf("Selecione a opção desejada: ");
scanf("%d", &menu);
}else if(menu==2){
printf("\n\t\tEstatísticas\n");
printf("\nMédia Alcance Horizontal: %.2f\n", media_alcance);
printf("Maior altura atingida: %.2f\n", maior_altura_agora);
printf("Porcentagem dos disparos que acertaram o alvo: %.2f\n", 100.0*acertou_alvo/cont);

printf("\n\n       MENU DE OPÇÕES: \n\n1 - Simular disparo \n2 - Mostrar estatísticas \n3 - Sair \n\n");
printf("Selecione a opção desejada: ");
scanf("%d", &menu);
}else if(menu<1 || menu>3){
printf("Opção inválida. Tente novamente.\n");

printf("\n\n       MENU DE OPÇÕES: \n\n1 - Simular disparo \n2 - Mostrar estatísticas \n3 - Sair \n\n");
printf("Selecione a opção desejada: ");
scanf("%d", &menu);
}
}while(menu!=3);
printf("\nPrograma finalizado!!");
return 0;
}