#include "map.h"

#include <iostream>

Map::Map()
{
    
}

void Map::generated(b2World& world, const b2Vec2& posPlayer)
{
    int idX, idY;
    posToIdChunk(posPlayer, idX, idY);

    genChunk(world, idX, idY);

    genChunk(world, idX-1, idY-1);
    genChunk(world, idX-1, idY+1);
    genChunk(world, idX+1, idY-1);
    genChunk(world, idX+1, idY+1);

    genChunk(world, idX-1, idY);
    genChunk(world, idX+1, idY);
    genChunk(world, idX, idY-1);
    genChunk(world, idX, idY+1);
  
}

void Map::genChunk(b2World& world, int idX, int idY)
{
    float sizeChunk = Chunk::getSize();

    if (!chunks.contains(idX))
    {
        chunks[idX][idY] = new Chunk(world, 
                                    (float) idX * sizeChunk, 
                                    (float) idY * sizeChunk); 
    }
    else
    {
        if (!chunks[idX].contains(idY))
        {
            chunks[idX][idY] = new Chunk(world, 
                                        (float) idX * sizeChunk, 
                                        (float) idY * sizeChunk); 
        }
    }
}

void Map::posToIdChunk(const b2Vec2& pos, int& idX, int& idY)
{
    idX = pos.x / int(Chunk::getSize());
    idY = pos.y / int(Chunk::getSize());

    if (pos.x < 0) idX -= 1;
    if (pos.y < 0) idY -= 1;
}

void Map::render(sf::RenderTarget &target, const b2Vec2& posPlayer)
{
    int idX, idY;
    posToIdChunk(posPlayer, idX, idY);

    chunks[idX][idY]->render(target);

    chunks[idX-1][idY]->render(target);
    chunks[idX+1][idY]->render(target);
    chunks[idX][idY-1]->render(target);
    chunks[idX][idY+1]->render(target); 

    chunks[idX-1][idY-1]->render(target);
    chunks[idX-1][idY+1]->render(target);
    chunks[idX+1][idY-1]->render(target);
    chunks[idX+1][idY+1]->render(target); 
}