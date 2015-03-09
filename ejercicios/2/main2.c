#include "gestor_tareas.h"

int main(void){


	struct tarea *t1, *t2;
	struct gestor_tareas *gt;
	char buffer[4000];

	t1 = curso_tarea_alloc();

	curso_tarea_attr_set_str(t1, CURSO_TAREA_ATTR_NOMBRE_TAREA, "Mixturas MCMC");
	curso_tarea_attr_set_str(t1, CURSO_TAREA_ATTR_DESC_TAREA, "Ahora en C!");
	curso_tarea_attr_set_u32(t1, CURSO_TAREA_ATTR_ID, 0);
	curso_tarea_attr_set_str(t1, CURSO_TAREA_ATTR_USUARIO, "Jose");
	curso_tarea_attr_set_u32(t1, CURSO_TAREA_ATTR_PRIORIDAD, 1);

	t2 = curso_tarea_alloc();

	curso_tarea_attr_set_str(t2, CURSO_TAREA_ATTR_NOMBRE_TAREA, "Machine Learning");
	curso_tarea_attr_set_str(t2, CURSO_TAREA_ATTR_DESC_TAREA, "En Python");
	curso_tarea_attr_set_u32(t2, CURSO_TAREA_ATTR_ID, 1);
	curso_tarea_attr_set_str(t2, CURSO_TAREA_ATTR_USUARIO, "Pepe");
	curso_tarea_attr_set_u32(t2, CURSO_TAREA_ATTR_PRIORIDAD, 2);

	gt = curso_gestor_tareas_alloc();

	curso_gestor_tareas_set_tarea(gt, CURSO_GESTOR_TAREAS_ATTR_TAREA, t1);
	curso_gestor_tareas_set_tarea(gt, CURSO_GESTOR_TAREAS_ATTR_TAREA, t2);

	curso_gestor_tareas_snprintf(buffer, sizeof(buffer), gt);
	printf("%s\n", buffer);

	curso_gestor_tareas_free(gt);


	return 0;
}