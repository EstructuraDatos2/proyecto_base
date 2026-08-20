#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tilemap.h"

TileMap tilemap_create(int width, int height) {
    TileMap map;

    map.width = width;
    map.height = height;

    map.tiles = malloc(sizeof(char*) * height);

    for(int y = 0; y < height; y++) {
        map.tiles[y] = malloc(sizeof(char) * width);

        for(int x = 0; x < width; x++) {
            if(
                y == 0 ||
                y == height - 1 ||
                x == 0 ||
                x == width - 1
            ) {
                map.tiles[y][x] = '#';
            }
            else {
                map.tiles[y][x] = ' ';
            }
        }
    }

    return map;
}

TileMap tilemap_load(const char* path) {
    FILE* file = fopen(path, "r");

    if(file == NULL) {
        printf("Error loading map: %s\n", path);

        return tilemap_create(1, 1);
    }

    char line[256];

    int width = 0;
    int height = 0;

    while(fgets(line, sizeof(line), file)) {
        int len = strlen(line);

        if(line[len - 1] == '\n') {
            len--;
        }

        if(len > width) {
            width = len;
        }

        height++;
    }

    rewind(file);

    TileMap map = tilemap_create(width, height);

    int y = 0;

    while(fgets(line, sizeof(line), file)) {
        int len = strlen(line);

        if(line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;
        }

        for(int x = 0; x < width; x++) {
            if(x < len) {
                map.tiles[y][x] = line[x];
            }
            else {
                map.tiles[y][x] = ' ';
            }
        }
        y++;
    }

    fclose(file);
    return map;
}

int tilemap_is_walkable(TileMap* map, int x, int y) {
    if (x < 0 || x > map->width) {
        return 0;
    }

    if (y < 0 || y > map->height) {
        return 0;
    }

    if (map->tiles[y][x] == '#') {
        return 0;
    } 

    return 1;
}

int tilemap_entity_is_walkable(TileMap* map, Entity* entity, int newX, int newY) {
    for(int y=0; y < entity->height; y++) {
        for(int x=0; x < entity->width; x++) {
            int tileX = newX + x;
            int tileY = newY + y;

            if (!tilemap_is_walkable(map, tileX, tileY)) return 0;
        }
    }
    return 1;
}

void tilemap_destroy(TileMap* map) {
    for(int y = 0; y < map->height; y++) {
        free(map->tiles[y]);
    }

    free(map->tiles);
}