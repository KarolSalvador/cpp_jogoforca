#include <iostream> //entrada e saida de dados
#include <string> //biblioteca para suportar strings
#include <map> // inclui biblioteca do map
using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";
map<char, bool> chutou;

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

    cout << "***************************************" << endl;
    cout << "*           JOGO DA FORCA             *" << endl;
    cout << "***************************************" << endl;
    cout << endl;

    bool nao_acertou = true;
    bool nao_enforcou = true;

    while(nao_acertou && nao_enforcou) {
        for(char letra : PALAVRA_SECRETA) {
            if(chutou[letra]) {
                cout << letra << " ";

            } else {
                cout << "_ ";
            }
        }
        cout << endl;

        cout << "Seu chute: " << endl;
        char chute;
        cin >> chute;

        chutou[chute] = true;

        if(letra_existe(chute)) {
            cout << "Voc� acertou, seu chute est� na palavra." << endl;
        } else {
            cout << "Voc� errou, seu chute n�o est� na palavra." << endl;
        }
    }

}