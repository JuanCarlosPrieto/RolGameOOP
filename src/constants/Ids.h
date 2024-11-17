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

    const std::vector<std::pair<std::string,std::pair<int,int>>> objectsAvailable = {
        {"espada", {ObjectTypes::ATTACK, 5}},
        {"cuchillo", {ObjectTypes::ATTACK, 3}},
        {"hacha", {ObjectTypes::ATTACK, 6}},

        {"escudo", {ObjectTypes::DEFENSE, 3}},
        {"amuleto", {ObjectTypes::DEFENSE, 2}},
        {"bomba de humo", {ObjectTypes::PROTECTION, 4}},

        {"armadura", {ObjectTypes::PROTECTION,4}},
        {"pared magica", {ObjectTypes::PROTECTION,6}},

        {"libro", {ObjectTypes::WISDOM, 3}},
        {"orbe del entendimiento", {ObjectTypes::WISDOM, 5}}
    };

    const std::vector<std::string> npcNames = {
        "Kaelith", "Dravon", "Selphira", "Tharion", "Lyssandra",
        "Vorin", "Eryndor", "Zelvara", "Kaeric", "Nyxala",
        "Fenrick", "Asrion", "Valkira", "Torveth", "Lunessa",
        "Myrric", "Zarenth", "Phaedra", "Korrath", "Isylla",
        "Taryon", "Zyphira", "Orinthal", "Veylin", "Cassara",
        "Thyrex", "Morvath", "Lyrith", "Xandriel", "Arvok",
        "Syrris", "Valthor", "Nythera", "Drakar", "Selvyn",
        "Aelithra", "Korvyn", "Valindra", "Zarek", "Elyssan",
        "Pharok", "Rynella", "Tavros", "Sylvara", "Eryssa",
        "Thalric", "Caldrith", "Vorneth", "Myressa", "Jorven"
    };

    const std::vector<std::pair<std::string,std::pair<int,std::vector<std::string>>>> attacks = {
        {"golpe", {1, std::vector<std::string>()}},
        {"patada", {1, std::vector<std::string>()}},
        {"hachazo", {3, std::vector<std::string>({"hacha"})}},
        {"espadazo", {2, std::vector<std::string>({"espada"})}},
        {"cuchillazo", {2, std::vector<std::string>({"cuchillo"})}},
        {"combo bomba de humo / espada", {3, std::vector<std::string>({"espada", "bomba de humo"})}},
        {"combo bomba de humo / hacha", {4, std::vector<std::string>({"hacha", "bomba de humo"})}},
        {"combo bomba de humo / cuchillo", {3, std::vector<std::string>({"cuchillo", "bomba de humo"})}}
    };
}

#endif
