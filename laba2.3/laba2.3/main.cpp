#include <iostream>
#include "Player.h"
#include "Lootbox.h"

int main()
{
    srand(time(NULL));

    Item sword{ "Sword","Rare","Sharp blade" };
    Item potion{ "Potion","Common","Healing potion" };
    Item armor{ "Armor","Epic","Heavy armor" };

    std::vector<Item> items = { sword,potion,armor };

    Lootbox box("Starter Box", items);

    Player player("Hero", 10, 10, {});

    box.info();

    player.openLootbox(box);
    player.openLootbox(box);

    player.info();

    return 0;
}