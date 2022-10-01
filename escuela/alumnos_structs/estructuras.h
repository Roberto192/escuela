#define MAX_MATRICULA 12
#define MAX_NOMBRE 50
#define MAX_APELLIDO 30
#define MAX_CARRERA 10
#define MAX_EDAD 3


struct ALUMNO{

	char matricula[MAX_MATRICULA];
	char nombre[MAX_NOMBRE];
	char apellidoPaterno[MAX_APELLIDO];
	char apellidoMaterno[MAX_APELLIDO];
	char carrera[MAX_CARRERA];

	int edad;

};

typedef struct ALUMNO alumno;