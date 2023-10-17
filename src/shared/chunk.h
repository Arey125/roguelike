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

    // пересекается ли объект со стенкой 
    bool intersectsWall(sf::Rect<float>& objRect, 
                        std::vector<sf::Vector2u>& idTails); 

    ~Chunk();

private:
    //
    void generation();

    // Размер чанка
    const unsigned int SIZE = 32; 

    // Квадраты внутри одного чанка
    std::vector <std::vector <bool>*> tiles;

    // Цвета квадратов
    std::vector <std::vector <sf::Color>*> colorTails;

    // Размер одного квадрата 
    const unsigned int sizeTail = 50;

    //  
    sf::RectangleShape shape;

    //
    double qNeighborhood(unsigned int idX, unsigned int idY);

    bool contact;
};


#endif //CHUNK_H
