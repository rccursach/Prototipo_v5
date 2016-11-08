#include "Sensor.h"
/**
 * Constructor de la clase Sensor
 * param data_threshold : valor mínimo (variacion) para producir un cambio almacenable en las lecturas
 * param buffer_size : cantidad de registros almacenables antes de producir un envio (readData retornando true)
 */
Sensor::Sensor(float data_threshold, int buffer_size){
	// Inicializar parametros
	this->data_threshold = data_threshold;
	this->buffer_size = buffer_size;
	// inicializar valores de lecturas
	this->last_data = NULL;
	this->actual_data = NULL;
	// inicializar buffer de lecturas
	int l = sizeof(this->actual_data) * this->buffer_size;
	this->readings_array = new float[l];
	this->readings_array_index = 0;
}

/**
 * Realiza una lectura del sensor
 * param byte_array: recibe los datos de los sensores cuando |buffer_size| lecturas son alcanzadas
 * return bool: cuando buffer_size es alcanzado y las lecturas copiadas al byte_array retorna true 
 */
/*****
// ESTE METODO ES VIRTUAL Y SOLO PUEDE SER DEFINIDO EN LA CLASE HIJA
bool Sensor::readData(byte* byte_array) {
	return true;
}
*****/

/**
 * Devuelve verdadero si la diferencia de lecturas supera el umbral (data_threshold)
 * return bool : true si |actual_data - last_data| >= data_threshold
 */
bool Sensor::compareThreshold() {
	float d = (this->actual_data >= this->last_data) ? (this->actual_data - this->last_data) : (this->last_data - this->actual_data);
	return (d >= this->data_threshold);
}

/**
 * Interface publica para inicializar el sensor,
 * la implementacion interna de inicialización del sensor
 * debe ser definida en la clase derivada, en el metodo sensorInit() y debe retornar bool
 * si es inicializado con exito.
 */
bool Sensor::init() {
	bool child_init = this->initSensor();
	this->readSensor();
	this->last_data = (!this->last_data && !this->actual_data) ? this->actual_data : NULL;
	return child_init && this->last_data;
}
