#include <iostream> //entrada e saida de dados
#include <string> //biblioteca para suportar strings
using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";

bool letra_existe(char chute) {
    for(char letra : PALAVRA_SECRETA) {
        if(chute == letra) {
            return true;
        }
    }
    return false;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    bool nao_acertou = true;
    bool nao_enforcou = true;

    while(nao_acertou && nao_enforcou) {
        char chute;

        cin >> chute;

        if(letra_existe(chute)) {
            cout << "Você acertou, seu chute está na palavra." << endl;
        } else {
            cout << "Você errou, seu chute não está na palavra." << endl;
        }
    }

}