#include <iostream>
#include <string>

using namespace std;


void printMatriz(int numVertice ,int ** matriz);

int ** incluirAresta(int ** matriz);
int ** removerAresta(int ** matriz);

int ** criarMatriz(int numVertice);

int calcularDistancia(int numVertice, int ** matriz);

string descobrirVizinhos(char distanciaB, int numVertice, int ** matriz, int vertice);

int transformarLetraToPosicao(int posicao);

string recursivoVizinho(char distanciaB, string vizinhos, int ** matriz, int numVertice, int posicaoAtual);



int main (){


    int numVertice;

    cout << "Num de vertices: ";
    cin >> numVertice;
    cout << endl;


    int ** matriz = criarMatriz(numVertice);

    printMatriz(numVertice, matriz);

    matriz = incluirAresta(matriz);
    printMatriz(numVertice, matriz);

    //matriz = removerAresta(matriz);
    //printMatriz(numVertice,matriz);

    int distancia =  calcularDistancia(numVertice, matriz);

}

void printMatriz(int numVertice , int ** matriz) {

    cout << "\nPrint da matriz: " << endl;

    for(int i=0; i < numVertice; i++) {
        for(int j=0; j < numVertice; j++) {
           cout << matriz[i][j] << " ";

        }
        cout << endl;
    }
}

int ** incluirAresta(int ** matriz) {

    int qtdAresta;
    cout << "Qtd de aresta: ";
    cin >> qtdAresta;
    cout << endl;

    int pontoA, pontoB;

    cout << "Seleciona as arestas desejadas: " << endl;
    for(int i=0; i< qtdAresta; i++) {
        cout << "Aresta: ";
        cin >> pontoA;
        cout << endl;

        cout << "Conecta: ";
        cin >> pontoB;
        cout << endl;

        matriz[pontoA][pontoB] = 1;
        matriz[pontoB][pontoA] = 1;

    }
    return matriz;

}
int ** removerAresta(int ** matriz) {

    int numLinha, numColuna;

    cout << "[Remover] Linha: ";
    cin >> numLinha;
    cout << endl;

    cout << "[Remover] Coluna: ";
    cin >> numColuna;
    cout << endl;

    matriz[numLinha][numColuna] = 0;
    matriz[numColuna][numLinha] = 0;

    return matriz;

}

int ** criarMatriz(int numVertice) {

     int ** matriz = new int *[numVertice];

    for(int i=0; i< numVertice; i++) {
        matriz[i] = new int[numVertice];
    }

    for(int i=0; i < numVertice; i++) {
        for(int j=0; j < numVertice; j++) {
            matriz[i][j] = 0;
        }
    }

    return matriz;
}

int transformarLetraToPosicao(char letra) {

     switch (letra)
    {
    case 'A':
        return 00;

        break;
    case 'B':
        return 11;

        break;
    case 'C':
        return 22;

        break;
    case 'D':
        return 33;

        break;
    
    case 'E': 
        return 44;
        
        break;

    case 'F': return 55;

        break;

    
    default:
        return 'Z';
        break;
    }

}

int calcularDistancia(int numVertice,int ** matriz) {

    char distanciaA, distanciaB;
    cout << "[Distancia] Vertice inicial: ";
    cin >> distanciaA;
    cout << endl;

    cout << "[Distancia] Vertice final: ";
    cin >> distanciaB;
    cout << endl;

    string vizinhos = descobrirVizinhos(distanciaB,numVertice, matriz, transformarLetraToPosicao(distanciaA));

    cout << "Distancia = " << vizinhos << endl;

}

string descobrirVizinhos(char distanciaB, int numVertice, int ** matriz, int vizinho) {

    int posicaoA = vizinho;
    int linha =0;

    string vizinhos;

    switch (posicaoA)
    {
    case 00:
        linha = 0;
        break;
    
    case 11:
        linha = 1;
        break;

    case 22:
        linha =2;
        break;

    case 33:
        linha =3;
        break;

    case 44:
        linha =4;
        break;

    case 55:
        linha =5;
        break;

    default:
        break;
    }

    int posicaoAtual = linha;

    vizinhos = recursivoVizinho(distanciaB, vizinhos, matriz,numVertice, posicaoAtual);
    

    cout << "Vizinhos de A: " << vizinhos << endl;

    return vizinhos;

}

string recursivoVizinho(char distanciaB ,string vizinhos, int **matriz,  int numVertices, int posicaoAtual ) {

    int linhaAtual = posicaoAtual;

    if(vizinhos.find(distanciaB) != string::npos) {

            cout <<"GOT IT" << endl;
            cout << vizinhos << endl;
            return vizinhos;

    }else {
        for (int i = linhaAtual; i < numVertices; i++)
        {
            //A
            if(linhaAtual == 0) {
                if(matriz[linhaAtual][i+1] == 1) {
                    vizinhos += "A";
                    vizinhos = recursivoVizinho(distanciaB, vizinhos, matriz, numVertices, linhaAtual+1);
                    continue;
                }
            }
            
            //B
            if(linhaAtual == 1) {

                if(matriz[linhaAtual][i+1] == 1) {
                    vizinhos += "B";
                    vizinhos= recursivoVizinho(distanciaB, vizinhos, matriz, numVertices, linhaAtual+1);
                    continue;
                }

            }

            //C
            if(linhaAtual == 2) {
                if(matriz[linhaAtual][i+1] == 1) {
                    vizinhos += "C";
                    vizinhos= recursivoVizinho(distanciaB, vizinhos, matriz, numVertices, linhaAtual+1);
                    continue;
                } 
            }

            //D
            if(linhaAtual == 3) {
                if(matriz[linhaAtual][i+1] == 1) {
                vizinhos += "D";
                    vizinhos= recursivoVizinho(distanciaB, vizinhos, matriz, numVertices, linhaAtual+1);
                    continue;
                } 
            }

            //E
            if(linhaAtual == 4) {
                if(matriz[linhaAtual][i-1] == 1) {
                    vizinhos += "E";
                    vizinhos= recursivoVizinho(distanciaB, vizinhos, matriz, numVertices, linhaAtual+1);
                    continue;
                } 
            }
        }
        return vizinhos;
        
        
    } 
    return vizinhos;
}