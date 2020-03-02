#ifndef _WEATHER_H_
#define _WEATHER_H_

<<<<<<< HEAD
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
=======
struct weather_info;

struct weather_info * average_info_for_week(const struct weather_info *const);

struct weather_info * max_by_temp_for_week(const struct weather_info *const);

struct weather_info * max_by_precip_for_week(const struct weather_info *const);

struct weather_info * min_by_temp_for_week(const struct weather_info *const);

struct weather_info * min_by_precip_for_week(const struct weather_info *const);
>>>>>>> 672f705b667ae81c6e76cdd031c35fbe9a02342f

#endif
