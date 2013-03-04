#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#include "hge_types.h"
#include "hge_engine.h"

/* HGE ENGINE */

void hgeEngine_Init(hgeEngine *e, float dt, float ft) {
	e->timestep.total_ticks = 0;
	e->timestep.frame_ticks = 0;
	e->timestep.accumulator = 0;

	memcpy((void *)&(e->timestep.delta_time), &(dt), sizeof(float));
	memcpy((void *)&(e->timestep.max_frame_time), &(ft), sizeof(float));

	e->is_active = hgeTrue;
}

hgeBool hgeEngine_IsActive(hgeEngine *e) {
	return e->is_active;
}

void hgeEngine_Quit(hgeEngine *e) {
	e->is_active = hgeFalse;
}

int hgeEngine_Tick(hgeEngine *e) {
	if(e->timestep.frame_ticks > 0) {
		return --(e->timestep.frame_ticks);
	}

	clock_t new_time = clock();
	double frame_time = (new_time - e->timestep.curr_time);
	if(new_time < e->timestep.curr_time) {
		frame_time = (((clock_t)(0) - e->timestep.curr_time) + new_time);
	}
	if(frame_time > e->timestep.max_frame_time) {
		frame_time = e->timestep.max_frame_time;
	}
	e->timestep.curr_time = new_time;

	e->timestep.accumulator += frame_time;
	e->timestep.frame_ticks = (e->timestep.accumulator / e->timestep.delta_time);
	e->timestep.total_ticks = e->timestep.frame_ticks;
	e->timestep.accumulator -= (e->timestep.frame_ticks * e->timestep.delta_time);

	return e->timestep.frame_ticks;
}

/* HGE ENGINE SERVER */

void hgeEngineServer_Init(hgeEngineServer *es, float dt, float ft) {
	hgeEngine_Init(&(es->base.engine), dt, ft);
}

/* HGE ENGINE CLIENT */
