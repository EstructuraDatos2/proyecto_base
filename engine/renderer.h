#ifndef RENDERER_H
#define RENDERER_H

#include "../games/entity.h"
#include "../games/tilemap.h"

#define SCREEN_WIDTH 20
#define SCREEN_HEIGHT 10

void renderer_init(int width, int height);

void renderer_clear();

void renderer_draw_char(int x, int y, char c);

void renderer_draw_text(int x, int y, const char* text);

void renderer_draw_entity(Entity* entity);

void renderer_draw_map(TileMap* map);

void renderer_present();

void renderer_set_viewport(int x, int y);

void renderer_shutdown();

#endif