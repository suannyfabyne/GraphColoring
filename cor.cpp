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

<<<<<<< HEAD
  int count2 =1;
=======
	int count2 =1;
>>>>>>> e19e33c57202f15e70a0554704b385a93adc13e1
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


<<<<<<< HEAD

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
      // cout << i << "  " << cores[i] << endl;
    }

=======
>>>>>>> e19e33c57202f15e70a0554704b385a93adc13e1

}


<<<<<<< HEAD
=======
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
      // cout << i << "  " << cores[i] << endl;
    }


}


>>>>>>> e19e33c57202f15e70a0554704b385a93adc13e1


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
    ifstream file("instancia2.txt");
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
          //cout << Array[from][to]; 
          if (Array[from][to] == 1)
          {
            Grau[from] = cont;
            cont++;
          }
      }
      //cout << "line " << from << endl;
      //cout << Grau[from] << endl;
    }


    Colorir(Grau, Array, nElementos);
    ExibirCores(cores, nElementos);

    int maiorValor;
    maiorValor = MaiorValor(cores, nElementos);
    cout<< "N° de cores (sem refinamento): "<< cores[maiorValor] << endl;

    int ArrayAux[nElementos];

    for (int i = 1; i <= nElementos; i++) {
      ArrayAux[i]= cores[i];
    }

    int iMaiorCor = MaiorValor(ArrayAux, nElementos);

    cout << "Vertice/indice que possui a maior cor (sem refinamento): " << iMaiorCor << endl;

    int count = IndicesAdjacentes(Array, nElementos, iMaiorCor); //Verifica os vertices adjacentes ao indice de maior cor e retorna a quantidade de adjacentes a ele
    MovimentoVizinhanca(count, cores, iMaiorCor, Array);
<<<<<<< HEAD
    ExibirCores(ArrayAux, nElementos);
    iMaiorCor = MaiorValor(ArrayAux, nElementos);

    cout << "Vertice/indice maior cor (depois do refinamento): " << iMaiorCor << endl;
=======
   	ExibirCores(ArrayAux, nElementos);
    iMaiorCor = MaiorValor(ArrayAux, nElementos);

    cout << "Vertice/indice maior cor (depois do refinamento): " <<iMaiorCor << endl;
>>>>>>> e19e33c57202f15e70a0554704b385a93adc13e1

    return 0;
}
