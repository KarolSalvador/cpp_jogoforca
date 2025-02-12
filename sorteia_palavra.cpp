#include <vector>
#include <string>
#include <ctime>

#include "ler_arquivo.hpp"

extern std::string palavra_secreta;

void sorteia_palavra() {
    std::vector<std::string> palavras = ler_arquivo(); //pega a lista de palavras do arquivo que consta na função

    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();

    palavra_secreta = palavras[indice_sorteado];

}