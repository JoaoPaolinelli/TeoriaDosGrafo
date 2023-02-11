
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

    string nome_completo = "A B C D E F";
    
    string ** vetorString = makeSplit(nome_completo, ' ');

    int sizeString = countSplit(nome_completo, ' ' );


    
    cout << "Teste split" << endl;

    for(int i=0; i < sizeString+1; i++) {

        cout <<  vetorString[i][0] << endl;
    }


    vetorString[0][0] = "B";
    vetorString[0][1] = "C";
    vetorString[0][2] = "D";

    vetorString[1][0] = "F";
    vetorString[1][1] = "G";
    vetorString[1][2] = "H"; 



     for(int i=0; i < sizeString+1; i++) {

         for(int j=0; j < sizeString+1; j++) {

        cout <<  vetorString[i][0] << endl;
    }
    }




    return 0;
}

