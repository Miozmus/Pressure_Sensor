/*
 * Barometr.h
 *
 *  Created on: 6 maj 2022
 *      Author: Monika
 *      Tutaj wstawic definicje klasy i nazwy metod
 */
#include "main.h"
#include "string.h"

//Użycie ostrych nawiasów <...> informuje kompilator, aby przeszukiwał domyślne ścieżki, w których znajdują się pliki nagłówkowe.
//Użycie "..." informuje kompilator, że plik nagłówkowy ma być poszukiwany tylko i wyłącznie względem aktualnego katalogu, w którym znajduje się nasz projekt

#ifndef SRC_BAROMETR_H_
//Instrukcja preprocesora, która sprawdza czy zmienna preprocesora o podanej nazwie istnieje.
//Jeśli zmienna preprocesora nie istnieje to wszystkie instrukcje, które się znajdują poniżej #ifndef,
//zostaną wykonane. Jeśli natomiast zmienna będzie istniała, kompilator pominie wszystkie instrukcje
//jakie znajdują się pomiędzy słowami preprocesora #ifndef, a #endif.

#define SRC_BAROMETR_H_

#endif /* SRC_BAROMETR_H_ */

#define I2C_address (uint16_t) 0xEC //0x76
//#define SDA_pin I2C2_SDA
//#define SCL_pin I2C2_SCL

//komendy czujnika
#define RESET_Sensor 0x1E
#define Read_PROM_Sensor (uint8_t*)0xA0

class PressureSensor
{
	double pressure, address;
	int data_tab[16]; //tablica odbierajaca dane
	I2C_HandleTypeDef hi2c;
	UART_HandleTypeDef huart;

public:
	void init(I2C_HandleTypeDef hi2c, UART_HandleTypeDef huart);//konstruktor klasy sluzacy do zainicjalizowania i uruchomienia czujnika

	HAL_StatusTypeDef check_sensor();

	void measure();//funkcja do robienia pomiarow cisnienia

	double return_pressure();

	void send_data_UART();

	void send_data();

	void receive_data();

};

