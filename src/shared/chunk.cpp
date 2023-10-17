#include "chunk.h"

#include <box2d/box2d.h>

Chunk::Chunk()
{
    // Инициализация случайных тайлов
    bool isWall = false;
    for (int i=0; i<SIZE; i++)
    {
        tiles.push_back(new std::vector <bool>);
        colorTails.push_back(new std::vector <sf::Color>);
        for (int j=0; j<SIZE; j++)
        {
            isWall = randBool();
            tiles[i]->push_back(isWall);
        }
    }

    this->generation();

    // Присваивание цвета в зависимости от типа тайла
    bool isWall;
    sf::Color colorTail;
    for (int idX = 0; idX < SIZE; idX++)
    {
        for (int idY = 0; idY < SIZE; idY++)
        {
            //
            isWall = !tiles[idX]->at(idY);

            if (isWall) colorTail = sf::Color::Black;
            else colorTail = sf::Color::Green;
            colorTails[idX]->push_back(colorTail);
        }
    }

    shape.setSize(sf::Vector2f(sizeTail, sizeTail));
}

void Chunk::generation()
{
    int idX;
    int idY;

    bool v;

    for (int i = 0; i < 2800; i++)
    {
        idX = rand()%SIZE;
        idY = rand()%SIZE;

        /*Правила клеточного автомата*/ 
        // 1)
        if (qNeighborhood(idX, idY) >= 0.5) tiles.at(idX)->at(idY) = true;
        // 2)
        if (qNeighborhood(idX, idY) < 0.25) tiles.at(idX)->at(idY) = false;

    }
}

void Chunk::update()
{

}

void Chunk::render(sf::RenderTarget &target)
{
    int Xo = 0;
    int Yo = 0;

    for (int idX = 0; idX < SIZE; idX++)
    {
        for (int idY = 0; idY < SIZE; idY++)
        {
            shape.setFillColor(colorTails[idX]->at(idY));
            shape.setPosition(Xo + (idY * sizeTail), Yo + (idX * sizeTail));
            target.draw(shape);
        }
    }
}

bool Chunk::randBool(double pTrue)
{
    return pTrue > (double (rand() % 1000) / 1000);
}

double Chunk::qNeighborhood(unsigned int idX, unsigned int idY)
{
    double quotient = 0.0;

    if (idX > 0 & idX != SIZE - 1 &
        idY > 0 & idY != SIZE - 1)
        {
            if (tiles.at(idX - 1)->at(idY)) quotient += 0.15;
            if (tiles.at(idX + 1)->at(idY)) quotient += 0.15;
            if (tiles.at(idX)->at(idY - 1)) quotient += 0.15;
            if (tiles.at(idX)->at(idY + 1)) quotient += 0.15;

            if (tiles.at(idX + 1)->at(idY + 1)) quotient += 0.1;
            if (tiles.at(idX - 1)->at(idY - 1)) quotient += 0.1;
            if (tiles.at(idX - 1)->at(idY + 1)) quotient += 0.1;
            if (tiles.at(idX + 1)->at(idY - 1)) quotient += 0.1;

        }
    else{
        quotient += 0.1; // Чтоб по краям чанка не всегда были стены

        if (idX > 0)
            if (tiles.at(idX - 1)->at(idY)) quotient += 0.15;

        if (idX != SIZE - 1)
            if (tiles.at(idX + 1)->at(idY)) quotient += 0.15;

        if (idY > 0)
            if (tiles.at(idX)->at(idY - 1)) quotient += 0.15;

        if (idY != SIZE - 1)
            if (tiles.at(idX)->at(idY + 1)) quotient += 0.15;
        }

    return quotient;
}

bool Chunk::intersectsWall(sf::Rect<float>& objRect, 
                           std::vector<sf::Vector2u>& idTails)
{
    sf::Vector2 pos = objRect.getPosition();
    sf::Vector2f size = objRect.getSize();

    sf::Vector2u idLastTail;

    unsigned int idX, idY;

    idX = pos.x / sizeTail;
    idY = pos.y / sizeTail;
    if (!tiles.at(idX)->at(idY))
    {     
        idLastTail.x = idX;
        idLastTail.y = idY;
        idTails.push_back(idLastTail);
    }

    idX = (pos.x + size.x) / sizeTail;
    idY = (pos.y) / sizeTail;
    if (!tiles.at(idX)->at(idY))
    {
        idLastTail.x = idX;
        idLastTail.y = idY;
        idTails.push_back(idLastTail);
    }

    idX = (pos.x) / sizeTail;
    idY = (pos.y + size.y) / sizeTail;
    if (!tiles.at(idX)->at(idY))
    {
        idLastTail.x = idX;
        idLastTail.y = idY;
        idTails.push_back(idLastTail);
    }

    idX = (pos.x + size.x) / sizeTail;
    idY = (pos.y + size.y) / sizeTail;
    if (!tiles.at(idX)->at(idY))
    {
        idLastTail.x = idX;
        idLastTail.y = idY;
        idTails.push_back(idLastTail);
    }
    
    return idTails.size() > 0;
}

Chunk::~Chunk()
{
    // Очистка контнеров tiles и colorTiles
}