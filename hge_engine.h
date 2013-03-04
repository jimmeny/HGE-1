#ifndef HGE_ENGINE_H
#define HGE_ENGINE_H

#include <time.h>

#include "hge_types.h"

typedef struct hgeEngine {
	hgeBool is_active;
	struct {
		clock_t curr_time;
		unsigned int total_ticks, frame_ticks;
		double accumulator;
		const float delta_time, max_frame_time;
	} timestep;
} hgeEngine;

void	hgeEngine_Init(hgeEngine *e, float dt, float ft);
hgeBool	hgeEngine_IsActive(hgeEngine *e);
void	hgeEngine_Quit(hgeEngine *e);
int		hgeEngine_Tick(hgeEngine *e);

/* ENGINE SERVER */
typedef struct hgeEngineServer {
	union {
		hgeEngine engine;
	} base;
} hgeEngineServer;

void	hgeEngineServer_Init(hgeEngineServer *es, float dt, float ft);
void	hgeEngineServer_UpdateState(hgeEngineServer *es);

/* ENGINE CLIENT */
typedef struct hgeEngineClient {
	union {
		hgeEngine engine;
	} base;
} hgeEngineClient;

#endif//HGE_ENGINE_H