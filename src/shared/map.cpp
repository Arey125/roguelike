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

bool Map::intersectsWall(sf::Rect<float>& objRect)
{
    // определяем в каком чанке находится obj
    /* code */

    // проверяем, есть ли там соприкосновение

    return true;
}