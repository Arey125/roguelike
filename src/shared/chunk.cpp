#include "chunk.h"

#include <box2d/box2d.h>

Chunk::Chunk()
{
    // Инициализация случайных квадратов
    for (int i=0; i<SIZE; i++)
    {
        squares.push_back(new std::vector <bool>);
        for (int j=0; j<SIZE; j++)
        {
            squares[i]->push_back(randBool());
        }
    }

    this->generation();

    shapeWall = new sf::RectangleShape(sf::Vector2f(sizeShare, sizeShare));
    shapeWall->setFillColor(sf::Color(0, 0, 0));

    shapeTrail = new sf::RectangleShape(sf::Vector2f(sizeShare, sizeShare));
    shapeTrail->setFillColor(sf::Color(0, 255, 0));
}

void Chunk::generation()
{
    int idX;
    int idY;

    bool v;

    for (int i = 0; i < 800; i++)
    {
        idX = rand()%SIZE;
        idY = rand()%SIZE;

        // Правила клеточного автомата
        if (qNeighborhood(idX, idY) >= 0.5) squares.at(idX)->at(idY) = true;
        if (qNeighborhood(idX, idY) < 0.25) squares.at(idX)->at(idY) = false;

    }
}

void Chunk::update()
{

}

void Chunk::render(sf::RenderTarget &target)
{
    int Xo = 0;
    int Yo = 0;

    sf::RectangleShape* shape;

    for (int idX = 0; idX < SIZE; idX++)
    {
        for (int idY = 0; idY < SIZE; idY++)
        {
            if (squares.at(idX)->at(idY))
            {
                shape = shapeTrail;
            }
            else
            {
                shape = shapeWall;
            }

            shape->setPosition(Xo + (idY * sizeShare), Yo + (idX * sizeShare));
            target.draw(*shape);
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
            if (squares.at(idX - 1)->at(idY)) quotient += 0.15;
            if (squares.at(idX + 1)->at(idY)) quotient += 0.15;
            if (squares.at(idX)->at(idY - 1)) quotient += 0.15;
            if (squares.at(idX)->at(idY + 1)) quotient += 0.15;

            if (squares.at(idX + 1)->at(idY + 1)) quotient += 0.1;
            if (squares.at(idX - 1)->at(idY - 1)) quotient += 0.1;
            if (squares.at(idX - 1)->at(idY + 1)) quotient += 0.1;
            if (squares.at(idX + 1)->at(idY - 1)) quotient += 0.1;

        }
    else{
        quotient += 0.1; // Чтоб по краям чанка не всегда были стены

        if (idX > 0)
            if (squares.at(idX - 1)->at(idY)) quotient += 0.15;

        if (idX != SIZE - 1)
            if (squares.at(idX + 1)->at(idY)) quotient += 0.15;

        if (idY > 0)
            if (squares.at(idX)->at(idY - 1)) quotient += 0.15;

        if (idY != SIZE - 1)
            if (squares.at(idX)->at(idY + 1)) quotient += 0.15;
        }

    return quotient;
}

Chunk::~Chunk()
{
    delete shapeWall;
    delete shapeTrail;
}