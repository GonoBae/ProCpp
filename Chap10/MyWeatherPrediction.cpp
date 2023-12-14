#include "MyWeatherPrediction.h"
#include <iostream>

using namespace std;

void MyWeatherPrediction::setCurrentTempCelsius(int temp)
{
    int fahrenheitTemp { convertCelsiusToFahrenheit(temp) };
    setCurrentTempFahrenheit(fahrenheitTemp);
}

int MyWeatherPrediction::getTomorrowTempCelsius() const
{
    int fahrenheitTemp { getTomorrowTempFahrenheit() };
    return convertFahrenheitToCelsius(fahrenheitTemp);
}

void MyWeatherPrediction::showResult() const
{
    cout << "Tomorrow will be " << getTomorrowTempCelsius() << "degrees Celsius (" << getTomorrowTempFahrenheit() << " degrees Fahrenheit)" << endl;
    cout << "Chance of rain is " << getChanceOfRain() * 100 << "%" << endl;
    if(getChanceOfRain() > 0.5) { cout << "Bring an umbrella!" << endl; }
}

std::string MyWeatherPrediction::getTemperature() const
{
    return WeatherPrediction::getTemperature() + "\u00B0F";
}