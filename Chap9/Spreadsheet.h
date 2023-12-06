#include "../Chap8/SpreadsheetCell.h"

class Spreadsheet
{
    public:
        Spreadsheet(size_t width, size_t height);
        void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
        SpreadsheetCell& getCellAt(size_t x, size_t y);

        Spreadsheet(const Spreadsheet& src);
        Spreadsheet& operator=(const Spreadsheet& rhs);
        ~Spreadsheet();

        Spreadsheet(Spreadsheet&& src) noexcept;
        Spreadsheet& operator=(Spreadsheet&& rhs) noexcept;

        void swap(Spreadsheet& other) noexcept;
    private:
        void cleanup() noexcept;
        void moveFrom(Spreadsheet& src) noexcept;

        bool inRange(size_t value, size_t upper) const;
        void verifyCoordinate(size_t x, size_t y) const;
        size_t m_width { 0 };
        size_t m_height { 0 };
        SpreadsheetCell** m_cells { nullptr };
};
void swap(Spreadsheet& first, Spreadsheet& second) noexcept;