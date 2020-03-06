#include "weather/weather.h"
#include "input/input.h"
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

weather_info  * create_struct_weather(float temp, float precip, float wind_speed) {
    weather_info * temporary = (weather_info *)malloc(sizeof(weather_info));
    if (!temporary) {
        return NULL;
    }
    temporary->temperature = temp;
    temporary->precipitation = precip;
    temporary->wind_speed = wind_speed;
    return temporary;
}

weather_info * average_info_for_week(const weather_info *const days) {
    if (!days) {
        return NULL;
    }
    float avg_temp = 0;
    float avg_precip = 0;
    float avg_wind_speed = 0;
    for (int i = 0; i < 7; i++) {
        if (!(days + i)) {
            return NULL;
        }
        avg_temp += days[i].temperature;
        avg_precip += days[i].precipitation;
        avg_wind_speed += days[i].wind_speed;
    }
    avg_temp /= 7;
    avg_precip /= 7;
    avg_wind_speed /= 7;
    return create_struct_weather(avg_temp, avg_precip, avg_wind_speed);
}

weather_info * max_by_temp_for_week(const weather_info *const days) {
    if (!days) {
        return NULL;
    }

    int number_of_max_day = 0;
    float max_temperature = days->temperature;
    for (int i = 1; i < 7; i++) {
        if (!(days + i)) {
            return NULL;
        }
        if (days[i].temperature > max_temperature) {
            max_temperature = days[i].temperature;
            number_of_max_day = i;
        }
    }
    return create_struct_weather(max_temperature,
                                 days[number_of_max_day].precipitation,
                                 days[number_of_max_day].wind_speed);
}

weather_info * min_by_temp_for_week(const weather_info *const days) {
    if (!days) {
        return NULL;
    }

    int number_of_min_day = 0;
    float min_temperature = days->temperature;
    for (int i = 1; i < 7; i++) {
        if (!(days + i)) {
            return NULL;
        }
        if (days[i].temperature < min_temperature) {
            min_temperature = days[i].temperature;
            number_of_min_day = i;
        }
    }
    return create_struct_weather(min_temperature,
                                 days[number_of_min_day].precipitation,
                                 days[number_of_min_day].wind_speed);
}

weather_info * max_by_precip_for_week(const weather_info *const days) {
    if (!days) {
        return NULL;
    }

    int number_of_max_day = 0;
    float max_precipitation = days->precipitation;
    for (int i = 1; i < 7; i++) {
        if (!(days + i)) {
            return NULL;
        }
        if (days[i].precipitation > max_precipitation) {
            max_precipitation = days[i].precipitation;
            number_of_max_day = i;
        }
    }
    return create_struct_weather(days[number_of_max_day].temperature,
                                 max_precipitation,
                                 days[number_of_max_day].wind_speed);
}

weather_info * min_by_precip_for_week(const weather_info *const days) {
    if (!days) {
        return NULL;
    }

    int number_of_min_day = 0;
    float min_precipitation = days->precipitation;
    for (int i = 1; i < 7; i++) {
        if (!(days + i)) {
            return NULL;
        }
        if (days[i].precipitation < min_precipitation) {
            min_precipitation = days[i].precipitation;
            number_of_min_day = i;
        }
    }
    return create_struct_weather(days[number_of_min_day].temperature,
                                 min_precipitation,
                                 days[number_of_min_day].wind_speed);
}

void print_weather_info(FILE * out, const weather_info *const day) {
    fprintf(out, "Temperature: %f\nPrecipitation: %f\nWind speed: %f\n", day->temperature,
                                                                         day->precipitation,
                                                                         day->wind_speed);
}

void input_weather_info(FILE * in, FILE * out, weather_info * day) {
    float temp;
    errno = 0;
    fprintf(out, "Input temperature: ");
    temp = input_float(in, stderr);
    if (!errno) {
        day->temperature = temp;
    } else {
        return;
    }
    fprintf(out, "Input precipitation: ");
    errno = 0;
    temp = input_float(in, stderr);
    if (!errno) {
        day->precipitation = temp;
    } else {
        return;
    }
    fprintf(out, "Input wind speed: ");
    errno = 0;
    temp = input_float(in, stderr);
    if (!errno) {
        day->wind_speed = temp;
    } else {
        return;
    }
}


weather_info * input_weather_info_for_week(FILE * in, FILE * out) {
    weather_info * days = (weather_info *)malloc(sizeof(weather_info)*7);
    for (int i = 0; i < 7; i++) {
        fprintf(out, "DAY %d:\n", (i + 1));
        errno  = 0;
        input_weather_info(in, out, days + i);
        if (errno) {
            i--;
        }
    }
    printf("\n");
    return days;
}
