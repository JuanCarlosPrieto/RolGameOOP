#include <iostream>
#include "./utils/GameUtils.h"

int main() {
    int level = 1;

    presentGame();
    Character* player = createPlayer();

    while (level <= 10) {
        int option;
        std::cout<<"Proximo enfrentamiento (nivel "<<level<<")"<<std::endl;
        std::cout<<"1. Enfrentarse a un rival estandar para mejorar habilidades"<<std::endl;
        std::cout<<"2. Enfrentarse al proximo jefe para subir de nivel"<<std::endl;
        std::cout<<"> ";
        std::cin>>option;
        if (option == 1) {
            Character* npc = createNPC(level - 1);
            play(player, npc);
        }
        else if (option == 2) {
            Character* npc = createNPC(level);
            play(player, npc, level);
        }
        else {
            system("cls");
            std::cout<<"Selecciona una opcion valida!"<<std::endl;
        }
    }

    std::cout<<"Bravo, terminaste el juego"<<std::endl;
    return 0;
}