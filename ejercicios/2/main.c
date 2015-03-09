#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "tarea.h"
#include <stdbool.h>

int main(void)
{
	struct tarea *t1;
	char buffer[400];

	t1 = curso_tarea_alloc();

	curso_tarea_attr_set_str(t1, CURSO_TAREA_ATTR_NOMBRE_TAREA, "Mixturas MCMC");
	curso_tarea_attr_set_str(t1, CURSO_TAREA_ATTR_DESC_TAREA, "Ahora en C!");
	curso_tarea_attr_set_u32(t1, CURSO_TAREA_ATTR_ID, 0);
	curso_tarea_attr_set_str(t1, CURSO_TAREA_ATTR_USUARIO, "Jose");
	curso_tarea_attr_set_u32(t1, CURSO_TAREA_ATTR_PRIORIDAD, 1);

	curso_tarea_snprintf(buffer, sizeof(buffer), t1);
	printf("%s\n", buffer);

	curso_tarea_free(t1);

	return 0;
}