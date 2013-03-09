#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#include "hge_common.h"
#include "hge_engine.h"

/* HGE ENGINE */

void hgeEngine_Init(hgeEngine *self, float dt, float ft) {
	self->timestep.total_ticks = 0;
	self->timestep.frame_ticks = 0;
	self->timestep.accumulator = 0;

	memcpy((void *)&(self->timestep.delta_time), &(dt), sizeof(float));
	memcpy((void *)&(self->timestep.max_frame_time), &(ft), sizeof(float));

	self->is_active = hgeTrue;
}

hgeBool hgeEngine_IsActive(hgeEngine *self) {
	return self->is_active;
}

void hgeEngine_Quit(hgeEngine *self) {
	self->is_active = hgeFalse;
}

int hgeEngine_Tick(hgeEngine *self) {
	clock_t new_time = clock();
	double frame_time = (new_time - self->timestep.curr_time);

	if(self->timestep.frame_ticks > 0) {
		return --(self->timestep.frame_ticks);
	}

	if(new_time < self->timestep.curr_time) {
		frame_time = (((clock_t)(0) - self->timestep.curr_time) + new_time);
	}
	if(frame_time > self->timestep.max_frame_time) {
		frame_time = self->timestep.max_frame_time;
	}
	self->timestep.curr_time = new_time;

	self->timestep.accumulator += frame_time;
	self->timestep.frame_ticks = (self->timestep.accumulator / self->timestep.delta_time);
	self->timestep.total_ticks = self->timestep.frame_ticks;
	self->timestep.accumulator -= (self->timestep.frame_ticks * self->timestep.delta_time);

	return self->timestep.frame_ticks;
}

/* HGE ENGINE SERVER */

void hgeEngineServer_Init(hgeEngineServer *self, float dt, float ft) {
	hgeEngine_Init(&(self->base.engine), dt, ft);
}

/* HGE ENGINE CLIENT */
