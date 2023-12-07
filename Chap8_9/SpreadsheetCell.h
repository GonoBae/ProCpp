#include <string>
#include <string_view>

class SpreadsheetCell
{
    public:
        SpreadsheetCell() = default;
        SpreadsheetCell(double initialValue);
        SpreadsheetCell(std::string_view initialValue);
        SpreadsheetCell(const SpreadsheetCell& src);
        SpreadsheetCell& operator=(const SpreadsheetCell& rhs);
        ~SpreadsheetCell();
        void Set(double value);
        double getValue() const;

        void set(std::string_view inString);
        std::string getString() const;
    private:
        double m_value { 0 };
        mutable size_t m_numAccesses { 0 };
        // Chapter9.3 static method
        static std::string doubleToString(double value);
        static double stringToDouble(std::string_view inString);
};