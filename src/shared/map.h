#ifndef MAP_H
#define MAP_H

#include "chunk.h"

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

#include <map>

class Map {
public:
    static Map* Instance();

    void generated(b2World& world, const b2Vec2& posPlayer);

    void render(sf::RenderTarget &target, const b2Vec2& posPlayer);

protected:
    Map(/*, int sid_Map*/);

private:
    void Pos_to_id_chunk(const b2Vec2& pos, int& idX, int& idY);

    void genChunk(b2World& world, int idX, int idY);

    // Единственный экземляр класса
    static Map* instance;

    // Текущее кол-во чанков по ширине/длине
    unsigned long int WIDTH;
    unsigned long int LENGTH;

    std::map<int, std::map<int, Chunk*>> chunks;
};


#endif //MAP_H
