#ifndef MAP_H
#define MAP_H

#include "chunk.h"

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class Map {
public:
    static Map* Instance();

    void generated(b2World& world);

    void render(sf::RenderTarget &target);

protected:
    Map(/*, int sid_Map*/);

private:
    //
    bool generatedMap;

    // Единственный экземляр класса
    static Map* instance;

    // Текущее кол-во чанков по ширине/длине
    unsigned long int WIDTH;
    unsigned long int LENGTH;

    // Пока вся карта это один чанк!
    Chunk* chunk;
};


#endif //MAP_H
