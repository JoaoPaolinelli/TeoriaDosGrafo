#include <iostream>
#include <string>

using namespace std;


void printMatriz(int numVertice ,int ** matriz);

int ** incluirAresta(int ** matriz);
int ** removerAresta(int ** matriz);

int ** criarMatriz(int numVertice);

int calcularDistancia(int numVertice, int ** matriz);

string descobrirVizinhos(char distanciaB, int numVertice, int ** matriz, int vertice);

int transformarLetraToPosicao(char posicao);

string recursivoVizinho(char distanciaB, string vizinhos, int ** matriz, int numVertice, int posicaoAtual);

int getGrauVertice(int numVertice, int ** matriz);

int  getComponentes(string vertices , int ** matriz);

string  identificarVertices(int numVertice, int ** matriz);


int main (){


    int numVertice;

    cout << "Num de vertices: ";
    cin >> numVertice;
    cout << endl;

    int ** matriz = criarMatriz(numVertice);

    printMatriz(numVertice, matriz);

    matriz = incluirAresta(matriz);
    printMatriz(numVertice, matriz);

    string vertices = identificarVertices(numVertice, matriz);

    int number = getComponentes(vertices, matriz);


    //matriz = removerAresta(matriz);
    //printMatriz(numVertice,matriz);

    // int distancia =  calcularDistancia(numVertice, matriz);

    // int grauVertice = getGrauVertice(numVertice,matriz);
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

    
    cout << "Distancia = " << vizinhos.size() -1 << endl;

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

        cout <<"Vizinhos encontrados: " << vizinhos << endl;

    }else {
        for (int i = linhaAtual; i < numVertices; i++)
        {

            switch (linhaAtual)
            {
                //A
                case 0:
                    if(matriz[linhaAtual][i+1] == 1) {
                        vizinhos += "A";
                        vizinhos = recursivoVizinho(distanciaB, vizinhos, matriz, numVertices, linhaAtual+1);
                    }
                break;

                //B
                case 1:
                    if(matriz[linhaAtual][i+1] == 1) {
                            vizinhos += "B";
                            vizinhos= recursivoVizinho(distanciaB, vizinhos, matriz, numVertices, linhaAtual+1);
                    }
                break;

                //C
                case 2:
                    if(matriz[linhaAtual][i+1] == 1) {
                        vizinhos += "C";
                        vizinhos= recursivoVizinho(distanciaB, vizinhos, matriz, numVertices, linhaAtual+1);
                    } 
                break;

                //D
                case 3:
                    if(matriz[linhaAtual][i+1] == 1) {
                        vizinhos += "D";
                        vizinhos= recursivoVizinho(distanciaB, vizinhos, matriz, numVertices, linhaAtual+1);
                
                    } 
                break;
                
                //E
                case 4:
                    if(matriz[linhaAtual][i-1] == 1) {
                        vizinhos += "E";
                        vizinhos= recursivoVizinho(distanciaB, vizinhos, matriz, numVertices, linhaAtual+1);
                    } 
                break;
                
                default: cout << "\n\n\n\nErro de execucao\n\n\n\t\t\t" << endl; break;
            }  
        }
    } 

    return vizinhos;
}

int getGrauVertice(int numVertice, int ** matriz) {

    int qtdGrau = 0; char vertice;

    cout << "[Grau] Insira o vertice desejado: ";
    cin >> vertice;
    cout << endl;

    int coordenada = transformarLetraToPosicao(vertice);
    int * posicoes = new int[2];

    if(coordenada == 0) {
        posicoes[0] = 0;
        posicoes[1] = 0;
    }else {
        posicoes[0] = to_string(coordenada)[0];
        posicoes[1] = to_string(coordenada)[1];
    }
   
    int valor = to_string(coordenada)[1];

    string a; a += to_string(coordenada)[1];

    for (int i = 0; i <= numVertice; i++) { 

        if(matriz[stoi(a)][i] == 1){
            qtdGrau++;
        }
    }

    cout << "[Grau] Vertice: " << vertice << " = " << qtdGrau << endl;
    return qtdGrau;

}


string  identificarVertices(int numVertice, int ** matriz) {

    int coluna =0;
    string * vertices = new string[numVertice];
    string letras;
    
    for(int i=0; i < numVertice; i++) {
        for(int j=0; j < numVertice; j++) {
            if(matriz[j][i] == 1) {
                if(i == 0) { letras += "A "; }
                if(i == 1) { letras += "B "; }
                if(i == 2) { letras += "C "; }
                if(i == 3) { letras += "D "; }
                if(i == 4) { letras += "E "; }
            }
        }
    }

    cout << "Vertices: " << letras << endl;

    return letras;
   
}

int  getComponentes(string vertices ,int ** matriz) {


    string newVertices;
    char first = ' ';
    char second = 'a';
    newVertices = vertices.replace(vertices.begin(), vertices.end(), second, first);

    cout << "Novos vertices: " << newVertices << endl;
    
    return 0;

}