/*
 * habitacion.h
 *
 *  Created on: 20 may 2024
 *      Author: GONZA
 */

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
	virtual ~habitacion();
	habitacion(const habitacion &other);
};

#endif /* HABITACION_H_ */
