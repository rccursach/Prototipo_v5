#include "DummySensor.h"

Dummy::Dummy(float data_threshold, int buffer_size, int dummyness) : Sensor(data_threshold, buffer_size) {
	this.dummyness = dummyness;
}

float Dummy::readSensor() {
	return 5.0;
}

bool Dummy::initSensor() {
	/* hacer algo aquí*/
	return true;
}

bool Dummy::readData(byte* byte_array) {
	return false;
}