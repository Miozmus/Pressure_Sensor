/*
 * Barometr.cpp
 *
 *  Created on: 6 maj 2022
 *      Author: Monika
 *      //tutaj definicje metod klasy
 */
#include "Barometr.h"
//#include "main.h"

void PressureSensor::init(I2C_HandleTypeDef hi2c,UART_HandleTypeDef huart)
{
	this->hi2c = hi2c;
	this -> huart = huart;

	//zeby zinicjalizowac czujnik najpierw trzeba go zresetowac
	HAL_StatusTypeDef status = check_sensor();
	if(status== HAL_OK)
	{
		const char msg[] = "Pressure sensor is OK. \r ";
		HAL_UART_Transmit(&this ->huart,(uint8_t*)msg,strlen(msg), 5000);
	}
	else if(status == HAL_BUSY)
	{
		const char msg[] ="Pressure sensor is busy. \r";
		HAL_UART_Transmit(&this ->huart,(uint8_t*)msg,strlen(msg), 5000);
	}
	else if(status == HAL_TIMEOUT)
	{
		const char msg[] ="Connection is timed out... \r";
		HAL_UART_Transmit(&this ->huart,(uint8_t*)msg,strlen(msg), 5000);
	}
	else if(status == HAL_ERROR)
	{
		const char msg[] ="Something is wrong with pressure sensor!!!\n\r";
		HAL_UART_Transmit(&this ->huart,(uint8_t*)msg,strlen(msg), 5000);
	}
	else
	{
		const char msg[] ="I don't know what's going on. \r";
		HAL_UART_Transmit(&this ->huart,(uint8_t*)msg,strlen(msg), 5000);
	}

}

HAL_StatusTypeDef PressureSensor::check_sensor()
{
	HAL_StatusTypeDef status;
	uint8_t command[1];
	command[0] = RESET_Sensor;
	status=HAL_I2C_Master_Transmit(&this->hi2c, I2C_address, command,1, 5000);
	//status=HAL_I2C_Master_Transmit(&this->hi2c, I2C_address, (uint8_t*)0x1E,1, 100);
	return status;
}

void PressureSensor::send_data_UART()
{
	//kod do wysylania danych przez UART
	//const char message[] = "The pressure measurement is: %d", pressure;
	//HAL_UART_Transmit(&this -> huart,(uint8_t*)msg,strlen(msg), 5000);
}

void PressureSensor::send_data()
{

}

void PressureSensor::receive_data()
{
	//HAL_I2C_Master_Receive(&this->hi2c, I2C_address, data_tab,2, 5000);
}
double PressureSensor::return_pressure()
{
	return this->pressure;
}
void PressureSensor::measure()
{
	//wysyla odpowiednia komende do czujnika aby wykonal pomiar
	this->pressure = HAL_I2C_Master_Transmit(&this->hi2c, I2C_address, Read_PROM_Sensor,1, 100);
}





