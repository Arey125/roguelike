#include "map.h"

Map* Map::instance = nullptr;

Map* Map::Instance()
{
    if (instance == nullptr)
    {
        instance = new Map;
    }

    return instance;
}

Map::Map()
{
    chunk = new Chunk;
}

void Map::render(sf::RenderTarget &target)
{
    chunk->render(target);
}