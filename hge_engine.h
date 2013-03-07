#ifndef HGE_ENGINE_H
#define HGE_ENGINE_H

#include <time.h>

#include "hge_types.h"

/* ENGINE
 * Engine base struct, manages the fixed timestep
 */
typedef struct hgeEngine {
	hgeBool is_active;
	struct {
		clock_t curr_time;
		unsigned int total_ticks, frame_ticks;
		double accumulator;
		const float delta_time, max_frame_time;
	} timestep;
} hgeEngine;

void	hgeEngine_Init(hgeEngine *this, float dt, float ft);
hgeBool	hgeEngine_IsActive(hgeEngine *this);
void	hgeEngine_Quit(hgeEngine *this);
int		hgeEngine_Tick(hgeEngine *this);

/* ENGINE SERVER
 * manages game logic, accepts inputs from EngineClient
 */
typedef struct hgeEngineServer {
	union {
		hgeEngine engine;
	} base;
} hgeEngineServer;

void	hgeEngineServer_Init(hgeEngineServer *this, float dt, float ft);
void	hgeEngineServer_UpdateState(hgeEngineServer *this);

/* ENGINE CLIENT
 * manages input & rendering, sends input to EngineServer
 */
typedef struct hgeEngineClient {
	union {
		hgeEngine engine;
	} base;
} hgeEngineClient;

#endif//HGE_ENGINE_H