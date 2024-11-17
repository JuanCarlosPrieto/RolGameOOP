#ifndef IDS_H
#define IDS_H

namespace Ids {
    enum CharacterTypes {
        REGENERATOR = 1,
        ROGUE = 2,
        TANK = 3,
        WARRIOR = 4
    };

    enum ObjectTypes {
        ATTACK = 1,
        DEFENSE = 2,
        PROTECTION = 3,
        WISDOM = 4
    };

    std::vector<std::tuple<std::string,int,int>> objectsAvailable = {
        std::make_tuple("espada", ObjectTypes::ATTACK, 5),
        std::make_tuple("cuchillo", ObjectTypes::ATTACK, 3),
        std::make_tuple("hacha", ObjectTypes::ATTACK, 6),

        std::make_tuple("escudo", ObjectTypes::DEFENSE, 3),
        std::make_tuple("amuleto", ObjectTypes::DEFENSE, 2),
        std::make_tuple("bomba de humo", ObjectTypes::PROTECTION, 4),

        std::make_tuple("armadura", ObjectTypes::PROTECTION,4),
        std::make_tuple("pared magica", ObjectTypes::PROTECTION,6),

        std::make_tuple("libro", ObjectTypes::WISDOM, 3),
        std::make_tuple("orbe del entendimiento", ObjectTypes::WISDOM, 5)
    };
}

#endif
