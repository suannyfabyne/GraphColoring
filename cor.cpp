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
<<<<<<< HEAD
}


=======

}
>>>>>>> 37fc08b1d3f6842aeff94e007f72106e697b020f

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
<<<<<<< HEAD
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
=======
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
>>>>>>> 37fc08b1d3f6842aeff94e007f72106e697b020f
    }

}

<<<<<<< HEAD

=======
>>>>>>> 37fc08b1d3f6842aeff94e007f72106e697b020f
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
<<<<<<< HEAD
       //cout << i << "  " << cores[i] << endl;
=======
       cout << i << "  " << cores[i] << endl;
>>>>>>> 37fc08b1d3f6842aeff94e007f72106e697b020f
    }

    int maiorValor;
    maiorValor = MaiorValor(cores, nElementos);
    cout<< "numero de cores: "<< cores[maiorValor] << endl;

<<<<<<< HEAD
    int ArrayAux[nElementos];

    for (int i = 1; i <= nElementos; i++)
    {
      ArrayAux[i]= cores[i];
    }

    int iMaiorCor = MaiorValor(ArrayAux, nElementos);

    cout << "indice maior cor: " <<iMaiorCor << endl;

    int auxAdj[nElementos];
    int count;

    for (int i = 1; i <= nElementos; i++)//4656546
    { 

      if (Array[iMaiorCor][i] == 1)
      {
          count++;
          auxAdj[count] = i;
      }
    }

    int count2 =1;

    while(count > 0 && cores[iMaiorCor] == ArrayAux[iMaiorCor]){

      ArrayAux[iMaiorCor] = 0;
      ArrayAux[auxAdj[count2]] = 0;

      int menorCor2 = Verificar(Array, nElementos, iMaiorCor);
      ArrayAux[iMaiorCor] = menorCor2;

      cout << "indice menor cor: " << menorCor2 << endl;
      //cout << "dfjggsdfkgsdflsdgf" << ArrayAux[216] << endl;
      int menorCor3 = Verificar(Array, nElementos, auxAdj[count2]);
      ArrayAux[auxAdj[count2]] = menorCor3;
      cout << "indice menor cor: " << menorCor3 << " do adjacente "<< count2 << endl;

      count2++;
      count--;
    }

   for (int i = 1; i <= nElementos; ++i)
    {
       //cout << i << "  " << ArrayAux[i] << endl;
    }

    iMaiorCor = MaiorValor(ArrayAux, nElementos);

    cout << "indice maior cor: " <<iMaiorCor << endl;

=======
>>>>>>> 37fc08b1d3f6842aeff94e007f72106e697b020f
    return 0;
}