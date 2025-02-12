#include <iostream>
#include <fstream>

#include "ler_arquivo.hpp"

std::vector<std::string> ler_arquivo() {
    std::ifstream arquivo;
    arquivo.open("./palavras.txt"); //abre o arquivo palavras.txt
    if(arquivo.is_open()) {

        int quantidade_palavras;
        arquivo >> quantidade_palavras; //coloca o primeiro item do arquivo na variável criada
    
        std::vector<std::string> palavras_do_arquivo;
    
        //laço de repetição para ler cada item do arquivo
        for(int i = 0; i < quantidade_palavras; i++) {
            std::string palavra_lida;
            arquivo >> palavra_lida;
            palavras_do_arquivo.push_back(palavra_lida);
    
        }
    
        arquivo.close();
        return palavras_do_arquivo;

    } else {
        std::cout << "Não foi possível acessar o banco de palavras." << std::endl;
        exit(0);
    }


}