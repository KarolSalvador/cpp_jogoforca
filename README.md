# 🎯 Jogo da Forca - C++

Seja bem-vindo ao **Jogo da Forca**! Este é um jogo clássico onde você precisa adivinhar a palavra secreta antes de cometer 5 erros. O jogo sorteia palavras de um banco e permite adicionar novas palavras ao final.

---

## 📌 Como jogar
1. O jogo sorteia uma palavra secreta.
2. Você deve tentar adivinhar a palavra chutando letras.
3. Se errar 5 vezes, você perde.
4. Se acertar todas as letras antes dos 5 erros, você vence!
5. No final, há a opção de adicionar novas palavras ao banco de dados.

---

## 🚀 Funcionalidades
✅ Sorteio de palavras aleatórias a partir de um arquivo externo (`palavras.txt`).
✅ Exibição de letras acertadas e erradas.
✅ Sistema de erros limitado a 5 tentativas.
✅ Possibilidade de adicionar novas palavras ao banco de palavras.
✅ Interface amigável no terminal.

---

## 🛠️ Requisitos
🔹 Compilador C++ (g++ recomendado)
🔹 Arquivo `palavras.txt` na mesma pasta do código

---

## 📂 Estrutura do projeto
```
📂 JogoDaForca
 ├── forca.cpp  # Código-fonte principal
 ├── palavras.txt  # Banco de palavras
 ├── README.md  # Este arquivo 😃
```

📌 O arquivo `palavras.txt` deve conter a seguinte estrutura:
```
5
MELANCIA
BANANA
CEREJA
LARANJA
MORANGO
```
A primeira linha indica a quantidade de palavras, e as demais são as palavras disponíveis para o jogo.

---

## ▶️ Como executar

1️⃣ **Compilar o código:**
```sh
g++ forca.cpp -o forca
```

2️⃣ **Executar o jogo:**
```sh
./forca
```

---

## 📌 Exemplo de Jogo
```
***************************************
*           JOGO DA FORCA             *
***************************************

Chutes errados: A E I
_ _ L A _ C I A

Seu chute: M
Você acertou, seu chute está na palavra.

Chutes errados: A E I
M E L A _ C I A

...

Parabéns! Você ganhou.
A palavra secreta era: MELANCIA
Você deseja adicionar uma nova palavra ao banco? (S/N)
```

---

## 📌 Melhorias Futuras 🚀
🔹 Suporte a acentos
🔹 Interface gráfica
🔹 Níveis de dificuldade
🔹 Multiplayer

Sinta-se à vontade para contribuir e aprimorar o jogo! 🎉

