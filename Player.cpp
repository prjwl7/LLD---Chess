#include "Player.h"

namespace Chess
{
    Player::Player(ColorType color, std::string name)
    {
        this->color = color;
        this->name = name;
        this->currentMove = nullptr;
    }
    Move *Player::getMove()
    {
        return currentMove;
    }
    void Player::setMove(Move *move)
    {
        this->currentMove = move;
    }
}