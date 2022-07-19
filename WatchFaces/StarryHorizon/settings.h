#ifndef SETTINGS_H
#define SETTINGS_H

//Weather Settings
#define CITY_ID "1277333" // Bengaluru https://openweathermap.org/current#cityid
#define OPENWEATHERMAP_APIKEY "2c4caaf6ff8eb7658dc62b63431b3755" //use your own API key :)
#define OPENWEATHERMAP_URL "http://api.openweathermap.org/data/2.5/weather?id=" //open weather api
#define TEMP_UNIT "metric" // metric = Celsius , imperial = Fahrenheit
#define TEMP_LANG "en"
#define WEATHER_UPDATE_INTERVAL 30 // must be greater than 5, measured in minutes
//NTP Settings
#define NTP_SERVER "pool.ntp.org"
#define GMT_OFFSET_SEC 19800 // 3600 x 5.5 for India Standard Time
#define DST_OFFSET_SEC 3600

watchySettings settings{
    CITY_ID,
    OPENWEATHERMAP_APIKEY,
    OPENWEATHERMAP_URL,
    TEMP_UNIT,
    TEMP_LANG,
    WEATHER_UPDATE_INTERVAL,
    NTP_SERVER,
    GMT_OFFSET_SEC,
    DST_OFFSET_SEC
};

#endif