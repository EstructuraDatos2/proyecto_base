#include "level1_scene.h"
#include "level2_scene.h"

#include "../../../engine/renderer.h"
#include "../../../engine/input.h"
#include "../../../engine/engine.h"

#include "../../tilemap.h"
#include "../../entity.h"

static TileMap map;
static Entity player = { 5, 5, 1, 1, '@' };

// PROTOTIPOS
void level1_init();
void level1_update();
void level1_render();
void level1_destroy();
int verifyDoor(int x, int y);

Scene level1Scene = {
    level1_init,
    level1_update,
    level1_render,
    level1_destroy,
};

void level1_init() {
    map = tilemap_load("games/dungeon/maps/level1.txt");
}

void level1_update() {
    int nextX = player.x;
    int nextY = player.y;

    if(key_down(KEY_W)) nextY--;
    if(key_down(KEY_S)) nextY++;
    if(key_down(KEY_A)) nextX--;
    if(key_down(KEY_D)) nextX++;

    // Verifica las colisiones con tiles de pared (#)
    if(tilemap_entity_is_walkable(&map, &player, nextX, nextY)) {
        if(map.tiles[nextY][nextX] == 'D' && nextX == 27 && nextY == 6) {
            engine_set_scene(&level2Scene);
            return;
        }
            
        player.x = nextX;
        player.y = nextY;
    }

    if(key_down(KEY_ESCAPE)) engine_stop();
}

void level1_render() {
    renderer_set_viewport(1, 2);
    renderer_draw_text(8, 0, "FRONT YARD");
    renderer_draw_map(&map);
    renderer_draw_entity(&player);
    renderer_draw_text(1, 14, "HP: 100");
}

void level1_destroy() {
    tilemap_destroy(&map);
}