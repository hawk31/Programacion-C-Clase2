#include "gestor_tareas.h"

int main(void){


	struct tarea *t1, *t2, *t3;
	struct gestor_tareas *gt;
	char buffer[4000];

	t1 = curso_tarea_alloc();

	curso_tarea_attr_set_str(t1, CURSO_TAREA_ATTR_NOMBRE_TAREA, "Mixturas MCMC");
	curso_tarea_attr_set_str(t1, CURSO_TAREA_ATTR_DESC_TAREA, "Ahora en C!");
	curso_tarea_attr_set_u32(t1, CURSO_TAREA_ATTR_ID, 0);
	curso_tarea_attr_set_str(t1, CURSO_TAREA_ATTR_USUARIO, "Jose");
	curso_tarea_attr_set_u32(t1, CURSO_TAREA_ATTR_PRIORIDAD, 2);

	t2 = curso_tarea_alloc();

	curso_tarea_attr_set_str(t2, CURSO_TAREA_ATTR_NOMBRE_TAREA, "Machine Learning");
	curso_tarea_attr_set_str(t2, CURSO_TAREA_ATTR_DESC_TAREA, "En Python");
	curso_tarea_attr_set_u32(t2, CURSO_TAREA_ATTR_ID, 1);
	curso_tarea_attr_set_str(t2, CURSO_TAREA_ATTR_USUARIO, "Pepe");
	curso_tarea_attr_set_u32(t2, CURSO_TAREA_ATTR_PRIORIDAD, 0);

	t3 = curso_tarea_alloc();

	curso_tarea_attr_set_str(t3, CURSO_TAREA_ATTR_NOMBRE_TAREA, "Automated Planning");
	curso_tarea_attr_set_str(t3, CURSO_TAREA_ATTR_DESC_TAREA, "Sin implementacion");
	curso_tarea_attr_set_u32(t3, CURSO_TAREA_ATTR_ID, 2);
	curso_tarea_attr_set_str(t3, CURSO_TAREA_ATTR_USUARIO, "Juan");
	curso_tarea_attr_set_u32(t3, CURSO_TAREA_ATTR_PRIORIDAD, 3);

	gt = curso_gestor_tareas_alloc();

	curso_gestor_tareas_set_tarea(gt, CURSO_GESTOR_TAREAS_ATTR_TAREA, t1);
	curso_gestor_tareas_set_tarea(gt, CURSO_GESTOR_TAREAS_ATTR_TAREA, t2);
	curso_gestor_tareas_set_tarea(gt, CURSO_GESTOR_TAREAS_ATTR_TAREA, t3);

	/*curso_gestor_tareas_snprintf(buffer, sizeof(buffer), gt);*/
	/*printf("%s\n", buffer);*/
	/*printf("%d\n", curso_tarea_attr_get_u32(curso_gestor_tareas_attr_get_tarea(gt, CURSO_GESTOR_TAREAS_ATTR_TAREA , 0), CURSO_TAREA_ATTR_PRIORIDAD));*/
	/*curso_tarea_attr_get_u32(curso_gestor_tareas_attr_get_tarea(gt, CURSO_GESTOR_TAREAS_ATTR_TAREA , 0), CURSO_TAREA_ATTR_PRIORIDAD) */

	/* Asumimos que prioridad es un entero de 0 a 5 */

	struct gestor_tareas *gtordenado;
	struct tarea *tar;
	gtordenado = curso_gestor_tareas_alloc();
	uint32_t pri=0;
	int i;
	uint32_t prisac;
	tar = curso_tarea_alloc();

	/* Este bucle es tan ineficiente que mata gatitos */
	/* Pero por probar... */

	/* Ordenando tareas por prioridad */

	for (pri=0;pri<=5;pri++)
	{
		for(i=0;i<3;i++){ /* Mejorar: llamar a num_tareas */
			tar = curso_gestor_tareas_attr_get_tarea(gt, CURSO_GESTOR_TAREAS_ATTR_TAREA , i);
			prisac = curso_tarea_attr_get_u32(curso_gestor_tareas_attr_get_tarea(gt, CURSO_GESTOR_TAREAS_ATTR_TAREA , i), CURSO_TAREA_ATTR_PRIORIDAD);
			if(prisac == pri){
				curso_gestor_tareas_set_tarea(gtordenado, CURSO_GESTOR_TAREAS_ATTR_TAREA, tar);
			}
		}
	}

	curso_gestor_tareas_snprintf(buffer, sizeof(buffer), gtordenado);
	printf("%s\n", buffer);


	/*curso_gestor_tareas_free(gt); Aqui mete segmentation fault*/
	curso_gestor_tareas_free(gtordenado);


	return 0;
}