#ifndef HABITACION_H_
#define HABITACION_H_

class habitacion {
private:
	int id;
	char* tipo;
	int capacidad;
	float precio;
	char* estado;
public:
	habitacion();
	habitacion(int id, char* tipo, int capacidad, float precio, char* estado);
	virtual ~habitacion();
	habitacion(const habitacion &h);

	int getId();
	char* getTipo();
	int getCapacidad();
	float getPrecio();
	char* getEstado();
	void getId(int id);
	void getTipo(char* tipo);
	void getCapacidad(int capacidad);
	void getPrecio(float precio);
	void getEstado(char* estado);
};

#endif /* HABITACION_H_ */
