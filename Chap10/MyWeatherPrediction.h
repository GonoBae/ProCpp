#include "WeatherPrediction.h"

class MyWeatherPrediction : public WeatherPrediction
{
    private:
        static int convertCelsiusToFahrenheit(int celsius);
        static int convertFahrenheitToCelsius(int fahrenheit);
        
    public:
        virtual void setCurrentTempCelsius(int temp);
        virtual int getTomorrowTempCelsius() const;

        void showResult() const override;
        std::string getTemperature() const override;
};