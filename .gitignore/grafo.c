#include<stdio.h>
#include<stdlib.h>
#define tam 10
void imprime(int m[tam][tam]);
void inicializa(int m[tam][tam], int v);
void conecta(int m[tam][tam], int a, int b, int v);
int adjacente(int m[tam][tam], int a, int b);
void gera_caminhos(int g[tam][tam], int p[tam][tam]);
void exibe_caminho(int m[tam][tam], int a, int b);
void menu1(int g[tam][tam], int c[tam][tam], int p[tam][tam], int Cd[tam][tam]);



int main ()
{
   int g[tam][tam],g1[tam][tam],c[tam][tam],p[tam][tam],cd[tam][tam],a,b,resp,x;
   system("clear");
   inicializa(g,0);
   inicializa(c,0);
   inicializa(p,-1);
   inicializa(g1,0);
   inicializa(cd,0);
   
   conecta(g,1,2,1);
   conecta(g,1,5,1);
   conecta(g,1,7,9);
   conecta(g,2,3,1);
   conecta(g,2,4,4);
   conecta(g,2,6,5);
   conecta(g,3,4,2);
   conecta(g,4,7,3);
   conecta(g,5,4,8);
   conecta(g,5,6,2);
   conecta(g,6,3,8);
   conecta(g,6,7,3);
   conecta(g,7,2,6);
   menu1(g,c,p,cd);
}

/***************************************************************************/

void menu1(int g[tam][tam], int c[tam][tam], int p[tam][tam], int cd[tam][tam])

{
   int opcao,a,b,k,resp,x;
   system("clear");
   printf("                             TRABALHO DE SISTEMAS OPERACIONAIS - GRAFOS EM C\n\n\n");
   printf("           [1]                  Imprimir Matriz Adjacencia \n");
   printf("           [2]                  Exibir Caminho\n");
   printf("           [3]                  Sair");
   printf("\n\n");
   printf("Digite a sua opcao: ");
   scanf("%d",&opcao);
      while((opcao!=1)&&(opcao!=2)&&(opcao!=3))
         {
            system("clear");
            printf("                     TRABALHO DE SISTEMAS OPERACIONAIS   - GRAFOS EM C\n\n\n");
            printf("                             TRABALHO DE ED II     -     GRAFOS\n\n\n");
            printf("           [1]            Imprimir Matriz Adjacencia \n");
            printf("           [2]            Exibir Caminho\n");
            printf("           [3]            Sair");
            printf("\n\n");
            printf("Digite a sua opcao: ");
            scanf("%d",&opcao);
         }
      if(opcao==1)
         {
            imprime(g);
            getchar();
            getchar();
            menu1(g,c,p,cd);
         }
    
       
      if(opcao==2)
         {
            printf("Digite o vertice de origem: ");
            scanf("%d",&a);
               while((a<=0)||(a>7))
                  {
                     printf("\n\nVERTICE INVALIDO! DIGITE NOVAMENTE!\n\n");
                     printf("Digite o vertice de origem: ");
                     scanf("%d",&a);
                  }
            printf("Digite o vertice de destino: ");
            scanf("%d",&b);
               while((b<=0)||(b>7))
                  {
                     printf("\n\nVERTICE INVALIDO! DIGITE NOVAMENTE!\n\n");
                     printf("Digite o vertice de destino: ");
                     scanf("%d",&b);
                  }
            printf("%d => ",a);
            exibe_caminho(p,a-1,b-1);
            printf("%d",b);
            getchar();
            getchar();
            menu1(g,c,p,cd);
         }
      if(opcao==3)
         {
            exit(1);
         }
}

/***************************************************************************/

void inicializa(int m[tam][tam], int v)

{
   int i,j;
   i=j=0;
      while(i!=10)
         {
               while(j!=10)
                  {
                     m[i][j]=v;
                     j++;
                  }
            j=0;
            i++;
         }
}
/***************************************************************************/

void conecta(int m[tam][tam], int a, int b, int v)

{
   m[a-1][b-1]=v;
}

/***************************************************************************/

void imprime(int m[tam][tam])

{
   int i,j,k;
   system("clear");
   i=j=0;
   k=1;
   printf("       ");
      while(k!=8) /* mostra os numeros de colunas*/
         {
            printf("  %d  ",k); //
            k++;
         }
   printf("  \n\n\n  ");
   k=1;
      while(i!=7) /* limita o numero de linhas*/
         {
            printf("  %d  ",k);/* limita numero de colunas*/
               while(j!=7)
                  {
                     printf("  %d  ",m[i][j]); //
                     j++;
                  }
            i++;
            j=0;
            k++;
            printf("  \n\n  ");
         }
}


/***************************************************************************/

void exibe_caminho(int m[tam][tam], int a, int b)

{
   int k,d,r;
   k=((m[a][b])+1);
      if(k!=0)
         {
            exibe_caminho(m, a, k-1);
            printf("%d => ",k);
            exibe_caminho(m, k-1, b);
         }
}

