#ifndef _WEATHER_H_
#define _WEATHER_H_

struct weather_info;

struct weather_info * average_info_for_week(const struct weather_info *const);

struct weather_info * max_by_temp_for_week(const struct weather_info *const);

struct weather_info * max_by_precip_for_week(const struct weather_info *const);

struct weather_info * min_by_temp_for_week(const struct weather_info *const);

struct weather_info * min_by_precip_for_week(const struct weather_info *const);

#endif
