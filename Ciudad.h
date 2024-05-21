#ifndef CLASES_PROVINCIA_H_
#define CLASES_PROVINCIA_H_

class Ciudad {
private:
	int id;
	char* nombre;
	int numHoteles;
public:
	Ciudad(int id, const char* nombre, int numHoteles);
	virtual ~Ciudad();
	const char* getNombre();
	int getId();
	int getNumHoteles();
	void setNombre(char*);
	void setId(int);
	void setNumHoteles(int);
	void imprimirCiudad();

};

#endif /* CLASES_PROVINCIA_H_ */
