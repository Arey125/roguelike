#include "chunk.h"

#include <box2d/box2d.h>

Chunk::Chunk(b2World& world, float X, float Y): Xo(X), Yo(Y)
{
    // Инициализация случайных тайлов
    bool isWay = false;
    for (int i=0; i<SIZE; i++)
    {
        tiles.push_back(new std::vector <Tail*>);
        for (int j=0; j<SIZE; j++)
        {
            isWay = randBool(0.8);
            tiles[i]->push_back(new Tail(world, Xo + (j*sizeTail), Yo + (i*sizeTail), isWay));
        }
    }

    this->generation(/*world*/);

    // Присваивание цвета в зависимости от карты
    setColorsTails();

    shape.setSize(sf::Vector2f(sizeTail, sizeTail));
}

void Chunk::setColorsTails()
{
    bool isWall;
    sf::Color colorTail;
    for (int idX = 0; idX < SIZE; idX++)
    {
        for (int idY = 0; idY < SIZE; idY++)
        {
            //
            isWall = !tiles[idX]->at(idY)->getIsWay();

            if (isWall) colorTail = sf::Color::Black;
            else colorTail = sf::Color::Green;
            tiles[idX]->at(idY)->setColor(colorTail);
        }
    }
}

void Chunk::generation(/*const b2World& world*/)
{
    int idX;
    int idY;

    bool v;

    for (int i = 0; i < 1800; i++)
    {
        idX = rand()%SIZE;
        idY = rand()%SIZE;

        /*Правила клеточного автомата*/ 
        // 1)
        if (qNeighborhood(idX, idY) >= 0.5) tiles.at(idX)->at(idY)->setIsWay(true);
        // 2)
        if (qNeighborhood(idX, idY) < 0.25) tiles.at(idX)->at(idY)->setIsWay(false);

    }
}

void Chunk::update()
{

}

void Chunk::render(sf::RenderTarget &target)
{
    for (int idX = 0; idX < SIZE; idX++)
    {
        for (int idY = 0; idY < SIZE; idY++)
        {
            /*
            shape.setFillColor(tiles[idX]->at(idY)->getColor());
            shape.setPosition(Xo + (idY * sizeTail), Yo + (idX * sizeTail));
            target.draw(shape);*/

            target.draw(tiles.at(idX)->at(idY)->getShape());
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
            if (tiles.at(idX - 1)->at(idY)->getIsWay()) quotient += 0.15;
            if (tiles.at(idX + 1)->at(idY)->getIsWay()) quotient += 0.15;
            if (tiles.at(idX)->at(idY - 1)->getIsWay()) quotient += 0.15;
            if (tiles.at(idX)->at(idY + 1)->getIsWay()) quotient += 0.15;

            if (tiles.at(idX + 1)->at(idY + 1)->getIsWay()) quotient += 0.1;
            if (tiles.at(idX - 1)->at(idY - 1)->getIsWay()) quotient += 0.1;
            if (tiles.at(idX - 1)->at(idY + 1)->getIsWay()) quotient += 0.1;
            if (tiles.at(idX + 1)->at(idY - 1)->getIsWay()) quotient += 0.1;

        }
    else{
        quotient += 0.1; // Чтоб по краям чанка не всегда были стены

        if (idX > 0)
            if (tiles.at(idX - 1)->at(idY)->getIsWay()) quotient += 0.15;

        if (idX != SIZE - 1)
            if (tiles.at(idX + 1)->at(idY)->getIsWay()) quotient += 0.15;

        if (idY > 0)
            if (tiles.at(idX)->at(idY - 1)->getIsWay()) quotient += 0.15;

        if (idY != SIZE - 1)
            if (tiles.at(idX)->at(idY + 1)->getIsWay()) quotient += 0.15;
        }

    return quotient;
}

Chunk::~Chunk()
{
    // Очистка контнеров tiles и colorTiles
}