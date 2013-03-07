#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#include "hge_types.h"
#include "hge_engine.h"

/* HGE ENGINE */

void hgeEngine_Init(hgeEngine *this, float dt, float ft) {
	this->timestep.total_ticks = 0;
	this->timestep.frame_ticks = 0;
	this->timestep.accumulator = 0;

	memcpy((void *)&(this->timestep.delta_time), &(dt), sizeof(float));
	memcpy((void *)&(this->timestep.max_frame_time), &(ft), sizeof(float));

	this->is_active = hgeTrue;
}

hgeBool hgeEngine_IsActive(hgeEngine *this) {
	return this->is_active;
}

void hgeEngine_Quit(hgeEngine *this) {
	this->is_active = hgeFalse;
}

int hgeEngine_Tick(hgeEngine *this) {
	if(this->timestep.frame_ticks > 0) {
		return --(this->timestep.frame_ticks);
	}

	clock_t new_time = clock();
	double frame_time = (new_time - this->timestep.curr_time);
	if(new_time < this->timestep.curr_time) {
		frame_time = (((clock_t)(0) - this->timestep.curr_time) + new_time);
	}
	if(frame_time > this->timestep.max_frame_time) {
		frame_time = this->timestep.max_frame_time;
	}
	this->timestep.curr_time = new_time;

	this->timestep.accumulator += frame_time;
	this->timestep.frame_ticks = (this->timestep.accumulator / this->timestep.delta_time);
	this->timestep.total_ticks = this->timestep.frame_ticks;
	this->timestep.accumulator -= (this->timestep.frame_ticks * this->timestep.delta_time);

	return this->timestep.frame_ticks;
}

/* HGE ENGINE SERVER */

void hgeEngineServer_Init(hgeEngineServer *this, float dt, float ft) {
	hgeEngine_Init(&(this->base.engine), dt, ft);
}

/* HGE ENGINE CLIENT */
