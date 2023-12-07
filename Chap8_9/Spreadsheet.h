#include "SpreadsheetCell.h"

class SpreadsheetApplication { };

class Spreadsheet
{
    public:
        Spreadsheet(size_t width, size_t height, const SpreadsheetApplication& theApp);
        void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
        SpreadsheetCell& getCellAt(size_t x, size_t y);
        const SpreadsheetCell& getCellAt(size_t x, size_t y) const;

        Spreadsheet(const Spreadsheet& src);
        Spreadsheet& operator=(const Spreadsheet& rhs);
        ~Spreadsheet();

        Spreadsheet(Spreadsheet&& src) noexcept; // 이동 생성자
        Spreadsheet& operator=(Spreadsheet&& rhs) noexcept; // 이동 대입 연산자

        void swap(Spreadsheet& other) noexcept;

        // Chap9-4
        size_t getId() const;

        const size_t MaxHeight { 100 };
        const size_t MaxWidth { 100 };

        

    private:
        void cleanup() noexcept;
        void moveFrom(Spreadsheet& src) noexcept;

        bool inRange(size_t value, size_t upper) const;
        void verifyCoordinate(size_t x, size_t y) const;
        size_t m_width { 0 };
        size_t m_height { 0 };
        SpreadsheetCell** m_cells { nullptr };
        static size_t ms_counter;
        const size_t m_id { 0 };

        const SpreadsheetApplication& m_theApp;

        
};
namespace BBB
{
    void swap(Spreadsheet& first, Spreadsheet& second) noexcept;
}