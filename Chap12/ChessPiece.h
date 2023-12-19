// #include "GamePiece.h"

class ChessPiece : public GamePiece
{
    public:
        std::unique_ptr<GamePiece> clone() const override
        {
            return std::make_unique<ChessPiece>(*this);
        }
};