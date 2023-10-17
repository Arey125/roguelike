#ifndef CHUNK_H
#define CHUNK_H

#include "SFML/Graphics.hpp"
#include <vector>

class Chunk
{
public:
    Chunk();

    void update();
    void render(sf::RenderTarget &target);

    //
    static bool randBool(double pTrue = 0.5);

    ~Chunk();

private:
    //
    void generation();

    // Размер чанка
    const unsigned int SIZE = 16; 

    // Квадраты внутри одного чанка
    std::vector <std::vector <bool>*> squares;

    // Размер одного квадрата 
    const unsigned int sizeShare = 50;

    //  
    sf::RectangleShape* shapeWall;
    sf::RectangleShape* shapeTrail;

    double qNeighborhood(unsigned int idX, unsigned int idY);
};


#endif //CHUNK_H
