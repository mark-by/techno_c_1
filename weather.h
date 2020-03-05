#ifndef _WEATHER_H_
#define _WEATHER_H_
#include <stdio.h>

typedef struct weather_info {
    float temperature;
    float precipitation;
    float wind_speed;
} weather_info;

//Размещает в памяти структуру и инициализирует ее аргументами
//temp - температура, precip - осадки, wind_speed - скорость ветра
//Функция возварщает указатель на структуру, либо NULL, в случае
//ошибки malloc
weather_info * create_struct_weather(float, float, float);

//Принимает массив days из структур weather_info
//для 7 элементов считает среднее значение precipitation,
//temperature, wind_speed
//Возвращает указатель на новую стркутуру (созданную с помощью
//create_struct_weather) или NULL
weather_info * average_info_for_week(const weather_info *const);

//Принимает массив days из структур weather_info
//среди 7 элементов ищет максимальный день по температуре
//Возвращает указатель на новую стркутуру (созданную с помощью
//create_struct_weather) или NULL
weather_info * max_by_temp_for_week(const weather_info *const);

//Принимает массив days из структур weather_info
//среди 7 элементов ищет максимальный день по осадкам 
//Возвращает указатель на новую стркутуру (созданную с помощью
//create_struct_weather) или NULL
weather_info * max_by_precip_for_week(const weather_info *const);

//Принимает массив days из структур weather_info
//среди 7 элементов ищет минимальный день по температуре
//Возвращает указатель на новую стркутуру (созданную с помощью
//create_struct_weather) или NULL
weather_info * min_by_temp_for_week(const weather_info *const);

//Принимает массив days из структур weather_info
//среди 7 элементов ищет минимальный день по осадкам 
//Возвращает указатель на новую стркутуру (созданную с помощью
//create_struct_weather) или NULL
weather_info * min_by_precip_for_week(const weather_info *const);

//Печатает структуру weather_info
void print_weather_info(const weather_info *const);

//Просит пользователя ввести данные через stdin для каждого
//поля структуры для полученной структуры day.
//Изменяет полученную структуру
void input_weather_info(FILE * in, weather_info *);

//Создает массив из 7 структур weather_info
//Заполняет каждую с помощью input_weather_info
//Возвращает указатель на массив или NULL в случае неудачи
weather_info * input_weather_info_for_week(FILE * in);

#endif
