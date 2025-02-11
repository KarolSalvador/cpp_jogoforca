#include <iostream> //entrada e saida de dados
#include <string> //biblioteca para suportar strings
#include <map> // inclui biblioteca do map
#include <vector> // inclui biblioteca de vetores
using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";
map<char, bool> chutou;
vector<char> chutes_errados;

void imprime_abertura() {
    cout << "***************************************" << endl;
    cout << "*           JOGO DA FORCA             *" << endl;
    cout << "***************************************" << endl;
    cout << endl;
}

bool letra_existe(char chute) {
    for(char letra : PALAVRA_SECRETA) {
        if(chute == letra) {
            return true;
        }
    }
    return false;
}

bool nao_acertou() {
    for(char letra : PALAVRA_SECRETA) {
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
    for(char letra : PALAVRA_SECRETA) {
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
        cout << "Você acertou, seu chute está na palavra." << endl;
    } else {
        cout << "Você errou, seu chute não está na palavra." << endl;
        chutes_errados.push_back(chute); //adiciona ao final do vetor o chute dado
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    imprime_abertura();

    while(nao_acertou() && nao_enforcou()) {
        imprime_erros();

        imprime_palavra();

        chuta();
    }

    cout << "Fim de jogo!" << endl;
    
    if(nao_acertou()) {
        cout << "Você perdeu! Tente novamente!" << endl;
    } else {
        cout << "Parabéns! Você ganhou." << endl;
    }
    cout << "A palavra secreta era: " << PALAVRA_SECRETA << endl;
    cout << endl;

}