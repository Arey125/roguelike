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

    //
    static unsigned int getSize();

    ~Chunk();

private:

    //
    float Xo, Yo;

    //
    void generation(/*const b2World& world*/);

    //
    void setColorsTails();

    // Размер одного квадрата (тайла)
    static const unsigned int sizeTail = 50;

    // Размер чанка
    static const unsigned int tSIZE = 16; // в тайлах
    static const unsigned int pSIZE = sizeTail * tSIZE; // в пикселях

    // Квадраты внутри одного чанка
    std::vector <std::vector <Tail*>*> tiles;

    

    //  
    sf::RectangleShape shape;

    //
    double qNeighborhood(unsigned int idX, unsigned int idY);

    bool contact;
};


#endif //CHUNK_H
