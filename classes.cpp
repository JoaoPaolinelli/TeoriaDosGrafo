
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <list>

using namespace std;

class Grafo{
    public:
    Grafo(string nome, int qtdVertice) {
        this->nome = nome;
        this->qtdVertice = qtdVertice;

        
        this->vertices = new list<Vertice>();

    }


    string nome;
    list <Vertice>  vertices;
    int qtdVertice;


};

class Aresta {

    Aresta(string verticeA, string verticeB) {
        this->peso =0;
        this->verticeA = verticeA;
        this->verticeB = verticeB;

    }

    int peso;
    
    string verticeA;
    string verticeB;

};

class Vertice{

    public:
    Vertice ();

    Vertice(string label) {
        this->label = label;
    }

    string label;
    list <Aresta> arestas;

    void setName(string label) {
        this->label = label;
    }


};

int countSplit(string qualquer, char whiteSpace ) {

    int contador = 0;

    for(int i=0; i < sizeof(qualquer) ; i++ ) {
        if(qualquer[i] == whiteSpace) {
            contador++;
        }
    }

    return contador;
}

string** makeSplit (string qualquer, char whiteSpace) {

    int numSplit = countSplit(qualquer, whiteSpace);


    string ** vetorSplit = new string * [numSplit+1];

    int posicaoAtual = 0;
    int size = qualquer.size();

    for(int i=0; i< size; i++) {
        vetorSplit[i] = new string[size];
    }




    for (int i = 0; i < size ; i++)

    {

        if(qualquer[i] == whiteSpace) {
            posicaoAtual++;
            // cout << endl;

        }else{
            vetorSplit[posicaoAtual][0] += qualquer[i];
            // cout << vetorSplit[posicaoAtual][0];
        }
    }

   
    return vetorSplit;
}

int main() {

   Grafo grafo ("JohnnyxD", 6);

   Vertice bolinhas[6];

    string * nomes = new string[6];
        nomes[0] = "A";
        nomes[1] = "B";
        nomes[2] = "C";
        nomes[3] = "D";
        nomes[4] = "E";
        nomes[5] = "F";

    for(int i=0; i < 6; i ++) {

        bolinhas[i].setName(nomes[i]);

        grafo.vertices.insert(bolinhas);

    }








    return 0;
}

