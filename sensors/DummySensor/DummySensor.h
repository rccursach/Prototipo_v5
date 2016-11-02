#include "../Sensor.h"
/**
incluir headers de otras libs de
los sensores de los que depende esta clase.

NO UTILIZAR FUNCIONES DE ARDUINO/WIRING
como Serial.print(), etc
Eso se realizará en el archivo .ino
**/


class Dummy : public Sensor {
private:
	//definir variables propias de este sensor aquí;
	int dummyness;
public:
	Dummy(float data_threshold, int buffer_size, int dummyness);
};