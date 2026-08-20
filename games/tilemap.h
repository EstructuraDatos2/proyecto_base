#ifndef TILEMAP_H
#define TILEMAP_H

#include "entity.h"
typedef struct {
    int width;
    int height;

    char** tiles;
} TileMap;

TileMap tilemap_create(int width, int height);

TileMap tilemap_load(const char* path);

int tilemap_is_walkable(TileMap* map, int x, int y);

int tilemap_entity_is_walkable(TileMap* map, Entity* entity, int newX, int newY);

void tilemap_destroy(TileMap* map);

#endif