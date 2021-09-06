#include "struct.h"
#include "enum.h"
#include <ncurses.h>
#include <fmod/fmod.h>
#include <stdlib.h>

void init_colors(void)
{
    start_color();
    init_pair(EMPTY, COLOR_WHITE, COLOR_BLACK);
    init_pair(WALL, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(BOX, COLOR_BLACK, COLOR_YELLOW);
    init_pair(STORAGE, COLOR_RED, COLOR_BLACK);
    init_pair(PLAYER, COLOR_CYAN, COLOR_BLACK);
    init_pair(MENU_BORDER, COLOR_CYAN, COLOR_BLACK);
    init_pair(HIGHLIGHT, COLOR_MAGENTA, COLOR_BLACK);
}

void create_sound(map_i_t *map_i, char const *name, FMOD_MODE mode, FMOD_SOUND **sound)
{
    FMOD_RESULT result;

    result = FMOD_System_CreateSound(map_i->system, name, mode, 0, sound);
    if (result != FMOD_OK) {
        fprintf(stderr, "Cannot read %s\n", name);
        exit(84);
    }
}

void init_sound(map_i_t *map_i)
{
    FMOD_System_Create(&map_i->system);
    FMOD_System_Init(map_i->system, 5, FMOD_INIT_NORMAL, NULL);
    create_sound(map_i, "sounds/jojo.mp3", FMOD_2D | FMOD_CREATESTREAM | FMOD_LOOP_NORMAL, &map_i->music);
    create_sound(map_i, "sounds/coin.wav", FMOD_CREATESAMPLE, &map_i->click);
    create_sound(map_i, "sounds/ora.wav", FMOD_CREATESAMPLE, &map_i->box_placed);
    create_sound(map_i, "sounds/zawarudo.wav", FMOD_CREATESAMPLE, &map_i->pause_end);
    create_sound(map_i, "sounds/reset.wav", FMOD_CREATESAMPLE, &map_i->reset);
    FMOD_Sound_SetLoopCount(map_i->music, -1);
    FMOD_System_PlaySound(map_i->system, map_i->music, 0, 0, &map_i->chan_1);
    map_i->v_music = 0.1;
    FMOD_Channel_SetVolume(map_i->chan_1, map_i->v_music);
}