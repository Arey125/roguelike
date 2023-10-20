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

void Map::generated(b2World& world)
{
    if (!generatedMap)
    {
        generatedMap = true;
        //world = &world_;

        chunk = new Chunk(world, 0.0, 0.0);
    }
    else
    {
        return;
    }
}

Map::Map()
{
    generatedMap = false;
}

void Map::render(sf::RenderTarget &target)
{
    chunk->render(target);
}