#include "Spreadsheet.h"
#include <stdexcept>
#include <iostream>
#include <utility>

using namespace std;

Spreadsheet::Spreadsheet(size_t width, size_t height)
    : m_width { width }, m_height { height }
{
    cout << "Normal constructor" << endl;
    m_cells = new SpreadsheetCell*[m_width];
    for(size_t i { 0 }; i < m_width; i++)
    {
        m_cells[i] = new SpreadsheetCell[m_height];
    }
}

Spreadsheet::Spreadsheet(const Spreadsheet& src)
    : Spreadsheet { src.m_width, src.m_height }
{
    cout << "Copy constructor" << endl;
    for(size_t i {0}; i < m_width; i++)
    {
        for(size_t j {0}; j < m_height; j++)
        {
            m_cells[i][j] = src.m_cells[i][j];
        }
    }
}

Spreadsheet::Spreadsheet(Spreadsheet&& src) noexcept
{
    cout << "Move constructor" << endl;
    BBB::swap(*this, src);
}

Spreadsheet& Spreadsheet::operator=(Spreadsheet&& rhs) noexcept
{
    cout << "Move assignment operator" << endl;
    BBB::swap(*this, rhs);
    return *this;
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
{
    cout << "Copy assignment operator" << endl;
    Spreadsheet temp { rhs };
    swap(temp);
    return *this;
}

Spreadsheet::~Spreadsheet()
{
    for(size_t i { 0 }; i < m_width; i++)
    {
        delete[] m_cells[i];
    }
    delete[] m_cells;
    m_cells = nullptr;
}

void Spreadsheet::setCellAt(size_t x, size_t y, const SpreadsheetCell& cell)
{
    verifyCoordinate(x, y);
    m_cells[x][y] = cell;
}

SpreadsheetCell& Spreadsheet::getCellAt(size_t x, size_t y)
{
    verifyCoordinate(x, y);
    return m_cells[x][y];
}

void Spreadsheet::verifyCoordinate(size_t x, size_t y) const
{
    if(x >= m_width)
    {
        throw out_of_range { to_string(x) + " must be less than " + to_string(m_width) };
    }
    if(y >= m_height)
    {
        throw out_of_range { to_string(y) + " must be less than " + to_string(m_height) }; 
    }
}

void Spreadsheet::swap(Spreadsheet& other) noexcept
{
    std::swap(m_width, other.m_width);
    std::swap(m_height, other.m_height);
    std::swap(m_cells, other.m_cells);
}

void BBB::swap(Spreadsheet& first, Spreadsheet& second) noexcept
{
    first.swap(second);
}

void Spreadsheet::cleanup() noexcept
{
    for(size_t i { 0 }; i < m_width; i++)
    {
        delete[] m_cells[i];
    }
    delete[] m_cells;
    m_cells = nullptr;
    m_width = m_height = 0;
}

void Spreadsheet::moveFrom(Spreadsheet& src) noexcept
{
    // // 데이터에 대한 얕은 복제
    // m_width = src.m_width;
    // m_height = src.m_height;
    // m_cells = src.m_cells;

    // // 소유권 이전되었기 때문에 소스 객체 리셋
    // src.m_width = src.m_height = 0;
    // src.m_cells = nullptr;

    // 기존값을 새 값으로 교체한 후 기존 값을 리턴
    m_width = exchange(src.m_width, 0);
    m_height = exchange(src.m_height, 0);
    m_cells = exchange(src.m_cells, nullptr);
}