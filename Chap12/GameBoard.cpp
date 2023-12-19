#include "GameBoard.h"
#include <stdexcept>
#include <iostream>
#include <string>
#include <utility>

GameBoard::GameBoard(size_t width, size_t height)
    : m_width { width }, m_height { height }
{
    m_cells.resize(m_width);
    for(auto& column : m_cells)
    {
        column.resize(m_height);
    }
}

GameBoard::GameBoard(const GameBoard& src)
    : GameBoard { src.m_width, src.m_height }
{
    for(size_t i {0}; i < m_width; i++)
    {
        for(size_t j {0}; j < m_height; j++)
        {
            if(src.m_cells[i][j])
            {
                m_cells[i][j] = src.m_cells[i][j]->clone();
            }
        }
    }
}

void GameBoard::verifyCoordinate(size_t x, size_t y) const
{
    if(x >= m_width)
    {
        std::string str;
        str += x;
        str += " must be less than ";
        str += m_width;
        throw std::out_of_range { str };
    }
    if(y >= m_height)
    {
        std::string str;
        str += y;
        str += " must be less than ";
        str += m_height;
        throw std::out_of_range { str };
    }
}

void GameBoard::swap(GameBoard& other) noexcept
{
    std::swap(m_width, other.m_width);
    std::swap(m_height, other.m_height);
    std::swap(m_cells, other.m_cells);
}

void swap(GameBoard& first, GameBoard& second) noexcept
{
    first.swap(second);
}

GameBoard& GameBoard::operator=(const GameBoard& rhs)
{
    GameBoard temp { rhs };
    swap(temp);
    return *this;
}

const std::unique_ptr<GamePiece>& GameBoard::at(size_t x, size_t y) const
{
    verifyCoordinate(x, y);
    return m_cells[x][y];
}

std::unique_ptr<GamePiece>& GameBoard::at(size_t x, size_t y)
{
    return const_cast<std::unique_ptr<GamePiece>&>(std::as_const(*this).at(x, y));
}