class Sensor {
private:
	float data_threshold;
	int buffer_size;
	float last_data; 		// valor lectura anterior
	float actual_data; 	// valor ultima lectura ( |actual_data - last_data| >= data_threshold )
	// los siguientes dos atributos, son el array de lecturas y su indice
	// el largo del array de lecturas sera (sizeof(this.actual_data) * this.buffer_size)
	float* readings_array;
	int readings_array_index;
	
	bool compareThreshold();
	virtual float readSensor();
	virtual bool initSensor();
public:
	Sensor(float data_threshold, int buffer_size);
	virtual bool init() final;
	virtual bool readData(byte* byte_array);
};