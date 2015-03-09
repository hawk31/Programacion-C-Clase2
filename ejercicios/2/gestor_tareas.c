#include "gestor_tareas.h"
#include <string.h>
#include <stdlib.h>

struct gestor_tareas {
	struct tarea *tareas[10];
	uint32_t num_tareas;

	uint32_t flags;
};

struct gestor_tareas *curso_gestor_tareas_alloc(void)
{
	return (struct gestor_tareas *)malloc(sizeof(struct gestor_tareas));
}

void curso_gestor_tareas_free(struct gestor_tareas *gt)
{
	int i;

	for(i=0; i< gt->num_tareas; i++){
		curso_tarea_free(gt->tareas[i]);
	}

	xfree(gt);
}

void curso_gestor_tareas_attr_unset_tarea(struct gestor_tareas *gt,
	uint32_t pos)
	{
		if(pos > 0 && pos > gt->num_tareas)
			return;
		gt->num_tareas--;
		curso_tarea_free(gt->tareas[pos]);
	}

static void curso_gestor_tareas_set_data(struct gestor_tareas *gt,
	uint16_t attr, const void *data)
{
	if(attr > CURSO_GESTOR_TAREAS_ATTR_MAX)
		return;
	switch(attr){
	case CURSO_GESTOR_TAREAS_ATTR_TAREA:
		if(gt->num_tareas > 10){
			printf("No queda espacio para tareas\n");
			break;
		}

		gt->tareas[gt->num_tareas] = (struct tarea *)data;
		gt->num_tareas++;
		break;
	}

	gt -> flags |= (1 << attr);
}

void curso_gestor_tareas_set_tarea(struct gestor_tareas *gt,
	uint16_t attr, struct tarea *data)
{
	curso_gestor_tareas_set_data(gt, attr, data);
}

/* Pueden faltar algunas cosas de strings y u32 */

const void *curso_gestor_tareas_attr_get_data(struct gestor_tareas *gt,
	uint16_t attr, uint32_t pos)
{
	if(!(gt->flags & (1 << attr)))
		return NULL;

	switch(attr){
		case CURSO_GESTOR_TAREAS_ATTR_NUM_TAREAS:
			return &gt->num_tareas;
		case CURSO_GESTOR_TAREAS_ATTR_TAREA:
			return gt->tareas[pos];
	}
	return NULL;
}

struct tarea *curso_gestor_tareas_attr_get_tarea(struct gestor_tareas *gt,
					         uint16_t attr, uint32_t pos)
{
	return (struct tarea *)curso_gestor_tareas_attr_get_data(gt, attr,
								 pos);
}

/* Faltan algunos get str y get u32, pero creo que no hacen falta */

int curso_gestor_tareas_snprintf(char *buffer, size_t size,
	struct gestor_tareas *gt)
{
	int i, ret = 0;

	for(i=0; i<gt->num_tareas; i++){
		ret += curso_tarea_snprintf(buffer + ret, size - ret, gt->tareas[i]);
		ret += snprintf(buffer + ret, size - ret, "\n");		
	}

	
}