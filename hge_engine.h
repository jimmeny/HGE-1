#ifndef HGE_ENGINE_H
#define HGE_ENGINE_H

#include <time.h>

#include "hge_common.h"
#include "hge_window.h"

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

void	hgeEngine_Init(hgeEngine *self, float dt, float ft);
hgeBool	hgeEngine_IsActive(hgeEngine *self);
void	hgeEngine_Quit(hgeEngine *self);
int		hgeEngine_Tick(hgeEngine *self);

/* ENGINE SERVER
 * manages game logic, accepts inputs from EngineClient
 */
typedef struct hgeEngineServer {
	union {
		hgeEngine engine;
	} base;
} hgeEngineServer;

void	hgeEngineServer_Init(hgeEngineServer *self, float dt, float ft);
void	hgeEngineServer_UpdateState(hgeEngineServer *self);

/* ENGINE CLIENT
 * manages input & rendering, sends input to EngineServer
 */
typedef struct hgeEngineClient {
	union {
		hgeEngine engine;
	} base;
	hgeWindow *window;
} hgeEngineClient;

void	hgeEngineClient_Init(hgeEngineClient *self);

#endif//HGE_ENGINE_H