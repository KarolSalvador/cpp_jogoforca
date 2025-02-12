#include <iostream> //entrada e saida de dados
#include <string> //biblioteca para suportar strings
#include <map> // inclui biblioteca do map
#include <vector> // inclui biblioteca de vetores
#include <fstream>
#include<ctime>
#include <cstdlib>

#include "nao_acertou.hpp"
#include "letra_existe.hpp"
#include "nao_enforcou.hpp"
#include "imprime_abertura.hpp"
#include "imprime_erros.hpp"
#include "imprime_palavra.hpp"
#include "chuta.hpp"
#include "ler_arquivo.hpp"
#include "sorteia_palavra.hpp"
#include "salva_arquivo.hpp"
#include "adiciona_palavra.hpp"

using namespace std;

string palavra_secreta;
map<char, bool> chutou;
vector<char> chutes_errados;

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
    cout << "A palavra secreta era: " << palavra_secreta << endl;
    cout << endl;
    
    if(nao_acertou()) {
        cout << "Você perdeu! Tente novamente!" << endl;
    } else {
        cout << "Parabéns! Você ganhou." << endl;
        cout << "Você deseja adicionar uma nova palavra ao banco? (S/N)" << endl;
        char resposta;
        cin >> resposta;
        if(resposta == 'S') {
            adiciona_palavra();
        }
    }

}