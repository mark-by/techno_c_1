#ifndef _WEATHER_H_
#define _WEATHER_H_

typedef struct weather_info {
    float temperature;
    float precipitation;
    float wind_speed;
} weather_info;

weather_info * create_struct_weather(float, float, float);

weather_info * average_info_for_week(const weather_info *const);

weather_info * max_by_temp_for_week(const weather_info *const);

weather_info * max_by_precip_for_week(const weather_info *const);

weather_info * min_by_temp_for_week(const weather_info *const);

weather_info * min_by_precip_for_week(const weather_info *const);

void print_weather_info(const weather_info *const);

#endif
