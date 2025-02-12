#include <iostream> 
#include <vector>
#include <map>

#include "letra_existe.hpp"

//extern sinaliza para o compilador que a variável existe em outro arquivo e não será definida nesse
extern std::map<char, bool> chutou; 
extern std::vector<char> chutes_errados;

void chuta() {
    std::cout << "Seu chute: " << std::endl;
    char chute;
    std::cin >> chute;

    chutou[chute] = true;

    if(letra_existe(chute)) {
        std::cout << "Você acertou, seu chute está na palavra." << std::endl;
    } else {
        std::cout << "Você errou, seu chute não está na palavra." << std::endl;
        chutes_errados.push_back(chute); //adiciona ao final do vetor o chute dado
    }
    std::cout << std::endl;
}