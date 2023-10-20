#ifndef CHUNK_H
#define CHUNK_H

#include "SFML/Graphics.hpp"
#include <vector>

#include "tail.h"

class Chunk
{
public:
    Chunk(b2World& world, float Xo, float Yo);

    void update();
    void render(sf::RenderTarget &target);

    //
    static bool randBool(double pTrue = 0.5);

    ~Chunk();

private:
    //
    float Xo, Yo;

    //
    void generation(/*const b2World& world*/);

    //
    void setColorsTails();

    // Размер чанка
    const unsigned int SIZE = 32; 

    // Квадраты внутри одного чанка
    std::vector <std::vector <Tail*>*> tiles;

    // Размер одного квадрата 
    const unsigned int sizeTail = 50;

    //  
    sf::RectangleShape shape;

    //
    double qNeighborhood(unsigned int idX, unsigned int idY);

    bool contact;
};


#endif //CHUNK_H
