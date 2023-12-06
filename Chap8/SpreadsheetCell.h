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
        void SetValue(double value);
        double getValue() const;

        void setString(std::string_view inString);
        std::string getString() const;
    private:
        std::string doubleToString(double value) const;
        double stringToDouble(std::string_view inString) const;
        double m_value { 0 };
};