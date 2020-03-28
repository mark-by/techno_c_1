#include <stdio.h>
#include <stdlib.h>
#include "weather/weather.h"

int main() {
    weather_info * days = input_weather_info_for_week(stdin, stdout);

    weather_info * day = min_by_precip_for_week(days);
    printf("DAY WITH MINIMAL PRECIPITATION:\n");
    print_weather_info(stdout, day);
    free(day);
    
    day = max_by_precip_for_week(days);
    printf("DAY WITH MAXIMAL PRECIPITATION:\n");
    print_weather_info(stdout, day);
    free(day);
     
    day = min_by_temp_for_week(days);
    printf("DAY WITH MINIMAL TEMPERATURE:\n");
    print_weather_info(stdout, day);
    free(day);
     
    day = max_by_temp_for_week(days);
    printf("DAY WITH MAXIMAL TEMPERATURE:\n");
    print_weather_info(stdout, day);
    free(day);
     
    day = average_info_for_week(days);
    printf("AVERAGE INFO FOR WEEK:\n");
    print_weather_info(stdout, day);
    free(day);
    
    free(days);
    return 0;
}
