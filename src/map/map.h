#ifndef MAP_H
#define MAP_H

#include "shared/chunk.h"

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

#include <map>

class Map {
public:
    Map(/*, int sidMap*/);

    void generated(b2World& world, const b2Vec2& posPlayer);
    void render(sf::RenderTarget &target, const b2Vec2& posPlayer);

private:
    void posToIdChunk(const b2Vec2& pos, int& idX, int& idY);

    void genChunk(b2World& world, int idX, int idY);

    // Текущее кол-во чанков по ширине/длине
    unsigned long int WIDTH;
    unsigned long int LENGTH;

    std::map<int, std::map<int, Chunk*>> chunks;
};


#endif //MAP_H
