#include <iostream> //entrada e saida de dados
#include <string> //biblioteca para suportar strings
#include <map> // inclui biblioteca do map
#include <vector> // inclui biblioteca de vetores
#include <fstream>
#include<ctime>
#include <cstdlib>

using namespace std;

string palavra_secreta = "MELANCIA";
map<char, bool> chutou;
vector<char> chutes_errados;

void imprime_abertura() {
    cout << "***************************************" << endl;
    cout << "*           JOGO DA FORCA             *" << endl;
    cout << "***************************************" << endl;
    cout << endl;
}

bool letra_existe(char chute) {
    for(char letra : palavra_secreta) {
        if(chute == letra) {
            return true;
        }
    }
    return false;
}

bool nao_acertou() {
    for(char letra : palavra_secreta) {
        if(!chutou[letra]) {
            return true;
        }        
    }
    return false;
}

bool nao_enforcou() {
    return chutes_errados.size() < 5;
}

void imprime_erros() {
    cout << "Chutes errados: ";
    for(char letra : chutes_errados) {
        cout << letra << " ";
    }
    cout << endl;
}

void imprime_palavra() {
    for(char letra : palavra_secreta) {
        if(chutou[letra]) {
            cout << letra << " ";

        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

void chuta() {
    cout << "Seu chute: " << endl;
    char chute;
    cin >> chute;

    chutou[chute] = true;

    if(letra_existe(chute)) {
        cout << "Voc� acertou, seu chute est� na palavra." << endl;
    } else {
        cout << "Voc� errou, seu chute n�o est� na palavra." << endl;
        chutes_errados.push_back(chute); //adiciona ao final do vetor o chute dado
    }
    cout << endl;
}

vector<string> ler_arquivo() {
    ifstream arquivo;
    arquivo.open("../palavras.txt"); //abre o arquivo palavras.txt
    if(arquivo.is_open()) {

        int quantidade_palavras;
        arquivo >> quantidade_palavras; //coloca o primeiro item do arquivo na vari�vel criada
    
        vector<string> palavras_do_arquivo;
    
        //la�o de repeti��o para ler cada item do arquivo
        for(int i = 0; i < quantidade_palavras; i++) {
            string palavra_lida;
            arquivo >> palavra_lida;
            palavras_do_arquivo.push_back(palavra_lida);
    
        }
    
        arquivo.close();
        return palavras_do_arquivo;
        
    } else {
        cout << "N�o foi poss�vel acessar o banco de palavras." << endl;
        exit(0);
    }


}

void sorteia_palavra() {
    vector<string> palavras = ler_arquivo(); //pega a lista de palavras do arquivo que consta na fun��o

    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();

    palavra_secreta = palavras[indice_sorteado];

}

int main() {
    setlocale(LC_ALL, "Portuguese");

    imprime_abertura();

    ler_arquivo();

    sorteia_palavra();

    while(nao_acertou() && nao_enforcou()) {
        imprime_erros();

        imprime_palavra();

        chuta();
    }

    cout << "Fim de jogo!" << endl;
    
    if(nao_acertou()) {
        cout << "Voc� perdeu! Tente novamente!" << endl;
    } else {
        cout << "Parab�ns! Voc� ganhou." << endl;
    }
    cout << "A palavra secreta era: " << palavra_secreta << endl;
    cout << endl;

}