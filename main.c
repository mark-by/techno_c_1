#include <stdio.h>
#include "weather.h"

int main() {
    weather_info smpl;
    smpl.temperature = 5;
    smpl.precipitation = 10;
    smpl.wind_speed = 25;
    print_weather_info(&smpl);
    return 0;
}
