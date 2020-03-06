#include "gtest/gtest.h"
#include <stdio.h>
#include <stdlib.h>

extern "C" {
#include "weather/weather.h"
}

TEST(InputTest, CorrectInput) {
    FILE * input = fopen("../../test/test_input", "r");
    if(!input) {
        printf("NOFILE\n");
    }
    ASSERT_FLOAT_EQ(100, input_number(input));
    ASSERT_FLOAT_EQ(200, input_number(input));
    ASSERT_FLOAT_EQ(300, input_number(input));
    ASSERT_FLOAT_EQ(45.5, input_number(input));
    ASSERT_FLOAT_EQ(55.5, input_number(input));
    ASSERT_FLOAT_EQ(65.5, input_number(input));
    ASSERT_FLOAT_EQ(10, input_number(input));
    ASSERT_FLOAT_EQ(20, input_number(input));
    ASSERT_FLOAT_EQ(30, input_number(input));
    ASSERT_FLOAT_EQ(100.5, input_number(input));
    ASSERT_FLOAT_EQ(125.5, input_number(input));
    ASSERT_FLOAT_EQ(135.5, input_number(input));
    fclose(input);
}
    
TEST(InputTest, IncorrectInput) {
    FILE * input = fopen("../../test/test_incorrect_input", "r");
    if(!input) {
        printf("NOFILE\n");
    }
    ASSERT_FLOAT_EQ(234234.4534534345, input_number(input));
    ASSERT_FLOAT_EQ(0, input_number(input));
    ASSERT_FLOAT_EQ(300, input_number(input));
    ASSERT_FLOAT_EQ(45.5, input_number(input));
    ASSERT_FLOAT_EQ(55.5, input_number(input));
    ASSERT_FLOAT_EQ(65.5, input_number(input));
    ASSERT_FLOAT_EQ(-934, input_number(input));
    ASSERT_FLOAT_EQ(0, input_number(input));
    ASSERT_FLOAT_EQ(30, input_number(input));
    ASSERT_FLOAT_EQ(0, input_number(input));
    ASSERT_FLOAT_EQ(12, input_number(input));
    ASSERT_FLOAT_EQ(0, input_number(input));
    fclose(input);
}

TEST(WeatherTest, CreateStruct) {
    float temperature = 5;
    float precipitation = 10;
    float wind_speed = 15;
    weather_info * ptr = create_struct_weather(temperature,
                                               precipitation,
                                               wind_speed);
    ASSERT_NE(ptr, nullptr);
    ASSERT_EQ(ptr->temperature, temperature);
    ASSERT_EQ(ptr->precipitation, precipitation);
    ASSERT_EQ(ptr->wind_speed, wind_speed);
    free(ptr);
}

TEST(WeatherTest, CreateStructsForWeek) {
    FILE * test_input = fopen("../../test/test_input", "r");
    FILE * out_file = fopen("out_file", "w");
    float numbers[21];
    weather_info * ptr = input_weather_info_for_week(test_input, out_file);
    fseek(test_input, 0, SEEK_SET);
    for (int i = 0; i < 21; i++) {
        fscanf(test_input, "%f", &(numbers[i]));
    }
    fclose(test_input);
    fclose(out_file);

    for (int i = 0; i < 7; i++) {
        ASSERT_FLOAT_EQ(numbers[i*3], ptr[i].temperature);
        ASSERT_FLOAT_EQ(numbers[i*3+1], ptr[i].precipitation);
        ASSERT_FLOAT_EQ(numbers[i*3+2], ptr[i].wind_speed);
    }
    free(ptr);
}

TEST(WeatherTest, MaxByTempForWeek) {
   FILE * test_input = fopen("../../test/test_input", "r");
   FILE * out_file = fopen("out_file", "w");
   weather_info * ptr = input_weather_info_for_week(test_input, out_file);
   fclose(test_input);
   fclose(out_file);

   weather_info * ans = max_by_temp_for_week(ptr);
   ASSERT_FLOAT_EQ(100.5, ans->temperature);
   ASSERT_FLOAT_EQ(125.5, ans->precipitation);
   ASSERT_FLOAT_EQ(135.5, ans->wind_speed);
   free(ptr);
}

TEST(WeatherTest, MinByTempForWeek) {
   FILE * test_input = fopen("../../test/test_input", "r");
   FILE * out_file = fopen("out_file", "w");
   weather_info * ptr = input_weather_info_for_week(test_input, out_file);
   fclose(test_input);
   fclose(out_file);

   weather_info * ans = min_by_temp_for_week(ptr);
   ASSERT_FLOAT_EQ(10, ans->temperature);
   ASSERT_FLOAT_EQ(20, ans->precipitation);
   ASSERT_FLOAT_EQ(30, ans->wind_speed);
   free(ptr);
}

TEST(WeatherTest, AverageInfoForWeek) {
   FILE * test_input = fopen("../../test/test_input", "r");
   FILE * out_file = fopen("out_file", "w");
   weather_info * ptr = input_weather_info_for_week(test_input, out_file);
   fclose(test_input);
   fclose(out_file);

   weather_info * ans = average_info_for_week(ptr);
   ASSERT_FLOAT_EQ(65.85714, ans->temperature);
   ASSERT_FLOAT_EQ(108, ans->precipitation);
   ASSERT_FLOAT_EQ(135.14285, ans->wind_speed);
   free(ptr);
}

TEST(WeatherTest, MaxByPrecipitationForWeek) {
   FILE * test_input = fopen("../../test/test_input", "r");
   FILE * out_file = fopen("out_file", "w");
   weather_info * ptr = input_weather_info_for_week(test_input, out_file);
   fclose(test_input);
   fclose(out_file);

   weather_info * ans = max_by_precip_for_week(ptr);
   ASSERT_FLOAT_EQ(100, ans->temperature);
   ASSERT_FLOAT_EQ(200, ans->precipitation);
   ASSERT_FLOAT_EQ(300, ans->wind_speed);
   free(ptr);
}


TEST(WeatherTest, MinByPrecipitationForWeek) {
   FILE * test_input = fopen("../../test/test_input", "r");
   FILE * out_file = fopen("out_file", "w");
   weather_info * ptr = input_weather_info_for_week(test_input, out_file);
   fclose(test_input);
   fclose(out_file);

   weather_info * ans = min_by_precip_for_week(ptr);
   ASSERT_FLOAT_EQ(10, ans->temperature);
   ASSERT_FLOAT_EQ(20, ans->precipitation);
   ASSERT_FLOAT_EQ(30, ans->wind_speed);
   free(ptr);
}
