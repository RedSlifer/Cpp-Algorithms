#include <iostream>
#include <ctime>

int main()
{
    const int NUMERO_CARTAS = 52;
    unsigned baralho[NUMERO_CARTAS], indice, i, auxiliar;
    std::string naipes[] = {"Espadas", "Copas", "Ouros", "Paus"};
    std::string cartas[] = {"As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Valete", "Rainha", "Rei"};

    //Inicializa as cartas
    for (i = 0; i < NUMERO_CARTAS; i++) {
        baralho[i] = i;
    }
    
    //Embaralha as cartas
    srand(time(0));
    for (i = 0; i < NUMERO_CARTAS; i++) {
        //Gera um índice aleatoriamente
        indice = rand() % NUMERO_CARTAS;
        auxiliar = baralho[i];
        baralho[i] = baralho[indice];
        baralho[indice] = auxiliar;
    }

    //Exibe as primeiras quatro cartas
    for  (i = 0; i < 4; i++) {
        std::cout << cartas[baralho[i] % 13] << " de " << naipes[baralho[i] / 13] << std::endl;
    }
    return 0;
}
