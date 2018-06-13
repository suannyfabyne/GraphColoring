#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

const int MAX = 1000;
int nElementos; // sfafasfas
int cores[MAX];

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
      cout << "opa1" << endl;
      cout << "maiorGrau"<< maiorGrau << endl;
      Grau[maiorGrau] = 0;
      int menorCor = Verificar(Array, nElementos, maiorGrau);
      cout << "opa2" << endl;
      cores[maiorGrau] = menorCor;
      vertices--;
      cout << "vertices "<< vertices << endl;
      cout << "maiorGrau "<< maiorGrau << endl;
      cout << "cor " << cores[maiorGrau] << endl;
    }

}

int main() {
    ifstream file("instancia2.txt");
    string line;
    int Array[1000][1000] = {{0}};


    while(getline(file, line)) {
        string mark, edge;
        int int1, from, to;
        stringstream ss1(line);
        while(ss1 >> mark >> edge >> int1) {
           if(mark == "p") {
              Array[int1][int1];
              nElementos = int1;
               break;
           }
        }
        stringstream ss2(line);
        while(ss2 >> mark >> from >> to) {
            if(mark == "e"){
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
    for (int i = 1; i <= nElementos; ++i)
    {
       cout << i << "  " << cores[i] << endl;
    }

    int maiorValor;
    maiorValor = MaiorValor(cores, nElementos);
    cout<< "numero de cores: "<< cores[maiorValor] << endl;

    return 0;
}