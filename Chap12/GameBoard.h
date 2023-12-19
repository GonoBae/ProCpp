#include <stdlib.h>
#include <vector>
#include "GamePiece.h"

class GameBoard
{
    public:
        explicit GameBoard(size_t width = DefaultWidth, size_t height = DefaultHeight);
        GameBoard(const GameBoard& src); // 복제 생성자
        virtual ~GameBoard() = default; // 가상 디폴트 소멸자
        GameBoard& operator=(const GameBoard& rhs); // 대입 연산자

        // 이동 생성자와 대입 연산자를 명시적으로 디폴트로 지정한다.
        GameBoard(GameBoard& src) = default;
        GameBoard& operator=(GameBoard&& src) = default;

        std::unique_ptr<GamePiece>& at(size_t x, size_t y);
        const std::unique_ptr<GamePiece>& at(size_t x, size_t y) const;

        size_t getHeight() const { return m_height; }
        size_t getWidth() const { return m_width; }

        static const size_t DefaultWidth { 10 };
        static const size_t DefaultHeight { 10 };

        void swap(GameBoard& other) noexcept;
    private:
        void verifyCoordinate(size_t x, size_t y) const;
        std::vector<std::vector<std::unique_ptr<GamePiece>>> m_cells;
        size_t m_width { 0 }, m_height { 0 };
};
void swap(GameBoard& first, GameBoard& second) noexcept;