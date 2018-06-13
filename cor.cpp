#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

const int MAX = 1000;
int nElementos; // sfafasfas
int cores[MAX];
int auxAdj[MAX];
int ArrayAux[MAX];

int VerificarVizinhanca(int Array[][1000], int nElementos, int vertice, int iMaiorCor, int ArrayNCores[]){

  int menorCor = 1;

  for (int i = 1; i <= nElementos; i++)//4656546
  {

    if (Array[vertice][i] == 1 )
    {
      if (cores[i] == menorCor || menorCor == cores[vertice] || ArrayNCores[menorCor] == -1)
      {
        menorCor++;
        i = 1; //fsdfsdfsdfsd
      }
    }
  }

  if(menorCor > cores[iMaiorCor]) {
    return cores[vertice];
  }
  else return menorCor;

}

int Verificar(int Array[][1000], int nElementos, int maiorGrau){

    int menorCor = 1;

    for (int i = 1; i <= nElementos; i++)//4656546
    {

      if (Array[maiorGrau][i] == 1)
      {
          if (cores[i] == menorCor)
          {
            menorCor++;
            i = 1; //fsdfsdfsdfsd
          }
      }
    }
    return menorCor;
}
 
void MovimentoVizinhanca(int count, int cores[], int iMaiorCor, int Array[][1000]) {

  int count2 =1;
  int menorCorAdjacente;

  while(count > 0 && cores[iMaiorCor] == ArrayAux[iMaiorCor]){

    ArrayAux[iMaiorCor] = 0;
    ArrayAux[auxAdj[count2]] = 0;


    menorCorAdjacente = Verificar(Array, nElementos, iMaiorCor); //Menor cor possível dos adjacentes ao vertice de maior cor 
    ArrayAux[iMaiorCor] = menorCorAdjacente;
    cout << "Nova menor cor do vertice de maior cor "  << menorCorAdjacente;


    menorCorAdjacente = Verificar(Array, nElementos, auxAdj[count2]); //Menor cor possível dos adjacentes ao adjacente do vertice de maior cor 
    ArrayAux[auxAdj[count2]] = menorCorAdjacente;
    cout << "Nova menor cor do vertice adjacente ao de maior cor " << menorCorAdjacente;
    count2++;
    count--;

  }
}


int IndicesAdjacentes(int Array[][1000], int nElementos, int iMaiorCor) {

  int count = 0;
  int auxAdj[nElementos];
  for (int i = 1; i <= nElementos; i++) //Percorre vertices e guarda o índice de seus adjacentes
  { 

    if (Array[iMaiorCor][i] == 1)
    {
      count++;
      auxAdj[count] = i;
    }
  }

  return count;
}


int ExibirCores(int cores[], int nElementos){

  for (int i = 1; i <= nElementos; ++i)
  {
    cout << i << "  " << cores[i] << endl;
  }

}

int MaiorValor(int Grau[], int nElementos) { //dfsdfsdfsdf

  int aux = Grau[1];
  int aux2 = 1;
  int maiorGrau;

  for (int i = 2; i <= nElementos; i++){

    if (Grau[i] > aux){
        aux = Grau[i];
        aux2 = i;
    }
  }
  maiorGrau = aux2;
  return maiorGrau;
  //cout << "aux2 "<< aux2 << endl;
  //cout << "maiorGrau "<< maiorGrau << endl;
}


void Colorir(int Grau[], int Array[][1000], int nElementos){
  
  int numeroDeCores = 0;
  int vertices = nElementos;
  int maiorGrau;

  while(vertices > 0){
    maiorGrau = MaiorValor(Grau, nElementos);
    //cout << "opa1" << endl;
    //cout << "maiorGrau"<< maiorGrau << endl;
    Grau[maiorGrau] = 0;
    int menorCor = Verificar(Array, nElementos, maiorGrau);
    //cout << "opa2" << endl;
    cores[maiorGrau] = menorCor;
    vertices--;
    //cout << "vertices "<< vertices << endl;
    //cout << "maiorGrau "<< maiorGrau << endl;
    //cout << "cor " << cores[maiorGrau] << endl;
  }

}

int main() {
  
  ifstream file("instancia6.txt");
  string line;
  int Array[1000][1000] = {{0}};


  while(getline(file, line)) {
    string var, edge;
    int vertex, from, to;
    stringstream linhap(line);
    while(linhap >> var >> edge >> vertex) {
       if(var == "p") {
          Array[vertex][vertex];
          nElementos = vertex;
           break;
       }
    }
    stringstream linhae(line);
    while(linhae >> var >> from >> to) {
        if(var == "e"){
          Array[from][to] = 1;
          Array[to][from] = 1;
        }
    }
  }


  int Grau[nElementos];

  for (int from = 1; from <= nElementos; ++from)
  {
    int cont = 1; 
    for (int to = 1; to <= nElementos; ++to)
    { 
        if (Array[from][to] == 1)
        {
          Grau[from] = cont;
          cont++;
        }
    }
  }

  Colorir(Grau, Array, nElementos);
  ExibirCores(cores, nElementos);

  int maiorValor;
  maiorValor = MaiorValor(cores, nElementos);
  cout<< "N° de cores (sem refinamento): "<< cores[maiorValor] << endl;

  int ArrayAux[nElementos];

  /*****MOVIMENTO DE VIZINHANÇA 1******/
  for (int i = 1; i <= nElementos; i++) {
    ArrayAux[i]= cores[i];
  }

  int iMaiorCor = MaiorValor(ArrayAux, nElementos);

  cout << "Vertice/indice que possui a maior cor (sem refinamento): " << iMaiorCor << endl;

  //int count = IndicesAdjacentes(Array, nElementos, iMaiorCor); //Verifica os vertices adjacentes ao indice de maior cor e retorna a quantidade de adjacentes a ele
  //MovimentoVizinhanca(count, cores, iMaiorCor, Array);
  //ExibirCores(ArrayAux, nElementos);
  //iMaiorCor = MaiorValor(ArrayAux, nElementos);
  //cout << "Vertice/indice maior cor (depois do refinamento): " << iMaiorCor << endl;
  //ExibirCores(ArrayAux, nElementos);
  //iMaiorCor = MaiorValor(ArrayAux, nElementos);

  //cout << "Vertice/indice maior cor (depois do refinamento): " <<iMaiorCor << endl;
  /*****TERMINOU MOVIMENTO DE VIZINHANÇA 1******/

  int Matrix[cores[iMaiorCor]+1][nElementos] = {{0}};
  int menorCorVizinhanca;

  for (int i = 1; i <= cores[iMaiorCor]+1; i++)
  {
    for (int j = 1; j <= nElementos; j++)
    {
        if (cores[j] == i) Matrix[i][j] = 1;
    }
  }

  int contador = 0;
  int contador2 = 0;
  int nCoresXau = 0;
  int NovaMaiorCor=iMaiorCor;
  int ArrayNCores[cores[iMaiorCor]] = {1};

  for (int i = 1; i <= cores[NovaMaiorCor]; i++)
  {
    for (int j = 1; j <= nElementos; ++j){

      if(Matrix[i][j] == 1) {

      // cout << j << " Cor antes: " << ArrayAux[j] << endl;
      //cout << "Cor: " << i << " Vertice: "<< j << endl; 
      menorCorVizinhanca = VerificarVizinhanca(Array, nElementos, j, NovaMaiorCor, ArrayNCores); 

      if (menorCorVizinhanca != cores[j])
        {
          //cout << j << " Cor antes: " << ArrayAux[j] << endl;
          ArrayAux[j] = menorCorVizinhanca;
          //cout << j << " Cor depois: " << ArrayAux[j] << endl;
          contador++;
        }
        contador2++;
      }
    } 

    if (contador == contador2 && contador != 0) {

      nCoresXau++;

      for (int j = 1; j <= nElementos; ++j){

        cores[j] = ArrayAux[j];

        if(Matrix[i][j] = 1){
            
          Matrix[i][j] = 0; 
          Matrix[menorCorVizinhanca][j] = 1;
          
          //cout << "Cor anterior :" << i <<endl;
          //cout << "Cor atual :" << menorCorVizinhanca <<endl;
        }
          //cout << "cor deletada " << i << endl;
      }

      ArrayNCores[i] = -1;
      cout << ArrayNCores[i] << " Sinal q foi deletado! cor :"  << i << endl;
      i=1;

    }
    else {

      for (int j = 1; j <= nElementos; ++j)
      {
        ArrayAux[j] = cores[j];  

      }
    }

  contador2 = 0;
  contador = 0;
      
  //cout << nCoresXau << " N cores" << endl;
  } 
  //cout << "Nova Maior Cor"<<cores[NovaMaiorCor] << endl;

  ExibirCores(cores, nElementos);

  NovaMaiorCor = MaiorValor(cores, nElementos);
  cout << "Numero de cores após movimento de vizinhança: " << cores[NovaMaiorCor] - nCoresXau << endl;
  return 0;
}
