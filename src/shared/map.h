#ifndef MAP_H
#define MAP_H

#include "chunk.h"

class Map {
public:
    static Map* Instance();

    void render(sf::RenderTarget &target);

    // Узнать касается ли прямоугольник препядствия на карте
    bool intersectsWall(sf::Rect<float>& objRect); 

protected:
    Map(/* int sid_Map*/);

private:
    // Единственный экземляр класса
    static Map* instance;

    // Текущее кол-во чанков по ширине/длине
    unsigned long int WIDTH;
    unsigned long int LENGTH;

    // Пока вся карта это один чанк!
    Chunk* chunk;
};


#endif //MAP_H
