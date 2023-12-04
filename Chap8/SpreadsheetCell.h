#include <string>
#include <string_view>

class SpreadsheetCell
{
    public:
        void SetValue(double value);
        double getValue() const;

        void setString(std::string_view inString);
        std::string getString() const;
    private:
        std::string doubleToString(double value) const;
        double stringToDouble(std::string_view inString) const;
        double m_value { 0 };
};