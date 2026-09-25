#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "renderer.h"

static int screenWidth;
static int screenHeight;

static char* screen;
static char* outputBuffer;
static int outputSize;

static int viewportX = 0;
static int viewportY = 0;

void renderer_init(int *width, int *height) {
    screenWidth = *width;
    screenHeight = *height;

    screen = malloc(screenWidth * screenHeight);
    outputSize = (screenWidth + 1) * screenHeight;
    outputBuffer = malloc(outputSize);
}

void renderer_clear() {
    memset(screen, ' ', screenWidth * screenHeight);
}

void renderer_draw_char(int x, int y, char c) {
    if (x < 0 || x >= screenWidth) return;
    if (y < 0 || y >= screenHeight) return;

    screen[y * screenWidth + x] = c;
}

void renderer_present() {
    printf("\x1b[H");

    for (int y = 0; y < screenHeight; y++) {
        memcpy(
            &outputBuffer[y * (screenWidth + 1)],
            &screen[y * screenWidth],
            screenWidth
        );

        outputBuffer[y * (screenWidth + 1) + screenWidth] = '\n';
    }

    fwrite(outputBuffer, sizeof(char), outputSize, stdout);
}

void renderer_set_viewport(int x, int y) {
    viewportX = x;
    viewportY = y;
}

void renderer_draw_entity(Entity* entity) {
    for(int y=0; y < entity->height; y++) {
        for(int x=0; x < entity->width; x++) {
            renderer_draw_char(
                viewportX + entity->x + x,
                viewportY + entity->y + y,
                entity->sprite
            );
        }
    }
}

void renderer_draw_map(TileMap* map) {
    for(int y=0; y < map->height; y++) {
        for(int x=0; x < map->width; x++) {
            if (map->tiles[y][x] != ' ') renderer_draw_char(viewportX + x, viewportY + y, map->tiles[y][x]);
        }
    }
}

void renderer_draw_text(int x, int y, const char* text) {
    int i = 0;

    while(text[i] != '\0') {
        renderer_draw_char(x + i, y, text[i]);
        i++;
    }
}

void renderer_shutdown() {
    free(outputBuffer);
    free(screen);
}