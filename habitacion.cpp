#include "habitacion.h"
#include <string.h>
#include <iostream>

using namespace std;

habitacion::habitacion()
{
	this->id = 0;
	this->tipo = NULL;
	this->capacidad = 0;
	this->precio = 0;
	this->estado = NULL;
}

habitacion::habitacion(int id, char* tipo, int capacidad, float precio, char* estado)
{
	this->id = id;
	this->tipo = new char(strlen(tipo) + 1);
	strcpy(this->tipo, tipo);
	this->capacidad = capacidad;
	this->precio = precio;
	this->estado = new char(strlen(estado) + 1);
	strcpy(this->estado, estado);
}

habitacion::habitacion(const habitacion &h)
{
	this->id = h.id;
	this->tipo = new char(strlen(h.tipo) + 1);
	strcpy(this->tipo, h.tipo);
	this->capacidad = h.capacidad;
	this->precio = h.precio;
	this->estado = new char(strlen(h.estado) + 1);
	strcpy(this->estado, h.estado);
}

int habitacion::getId(){
	return this->id;
}

char* habitacion::getTipo(){
	char* resultado = new char(strlen(this->tipo) + 1);
	strcpy(resultado, this->tipo);
	return resultado;
}

int habitacion::getCapacidad(){
	return this->capacidad;
}

float habitacion::getPrecio(){
	return this->precio;
}

char* habitacion::getEstado(){
	char* resultado = new char(strlen(this->estado) + 1);
	strcpy(resultado, this->estado);
	return resultado;
}

void habitacion::getId(int id){
	this->id = id;
}

void habitacion::getTipo(char* tipo){
	this->tipo = new char(strlen(tipo) + 1);
	strcpy(this->tipo, tipo);
}

void habitacion::getCapacidad(int capacidad){
	this->capacidad = capacidad;
}

void habitacion::getPrecio(float precio){
	this->precio = precio;
}

void habitacion::getEstado(char* estado){
	this->estado = new char(strlen(estado) + 1);
	strcpy(this->estado, estado);
}

habitacion::~habitacion() {
	delete[] this->tipo;
	delete[] this->estado;
}

