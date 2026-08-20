#include "level2_scene.h"
#include "level1_scene.h"

#include "../../../engine/renderer.h"
#include "../../../engine/input.h"
#include "../../../engine/engine.h"

#include "../../tilemap.h"

static TileMap map;
static Entity player = { 1, 6, 1, 1, '@' };

// PROTOTIPOS
void level2_init();
void level2_update();
void level2_render();
void level2_destroy();

Scene level2Scene = {
    level2_init,
    level2_update,
    level2_render,
    level2_destroy,
};

void level2_init() {
    map = tilemap_load("games/dungeon/maps/level2.txt");
}

void level2_update() {
    int nextX = player.x;
    int nextY = player.y;

    if(key_down(KEY_W)) nextY--;
    if(key_down(KEY_S)) nextY++;
    if(key_down(KEY_A)) nextX--;
    if(key_down(KEY_D)) nextX++;

    // Verifica las colisiones con tiles de pared (#)
    if(tilemap_entity_is_walkable(&map, &player, nextX, nextY)) {
        if(map.tiles[nextY][nextX] == 'D' && nextX == 0 && nextY == 6) {
            engine_set_scene(&level1Scene);
            return;
        }

        player.x = nextX;
        player.y = nextY;
    }

    if(key_down(KEY_ESCAPE)) engine_stop();
}

void level2_render() {
    renderer_set_viewport(1, 2);
    renderer_draw_text(8, 0, "FIRST FLOOR");
    renderer_draw_map(&map);
    renderer_draw_entity(&player);
    renderer_draw_text(1, 14, "HP: 100");
}

void level2_destroy() {
    tilemap_destroy(&map);
}