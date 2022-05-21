/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "includes.h"

void free_everything(kidiot_t *kidiot, char *buffer)
{
    if (buffer)
        free(buffer);
    free_double_tab(kidiot->first_floor);
    free_double_tab(kidiot->second_floor);
    free(kidiot->baby->bathtub);
    free(kidiot->baby->electric);
    free(kidiot->baby->oven);
    free(kidiot->baby->cactus);
    free(kidiot->baby->fridge);
    free(kidiot->tp);
    free(kidiot->baby);
    free(kidiot->mom);
    free(kidiot);
}

static void get_keys(int *keys)
{
    if (IsKeyDown(KEY_RIGHT)) keys[0] = 1;
    if (IsKeyDown(KEY_LEFT)) keys[1] = 1;
    if (IsKeyDown(KEY_UP)) keys[2] = 1;
    if (IsKeyDown(KEY_DOWN)) keys[3] = 1;
    if (IsKeyDown(KEY_ENTER)) keys[4];
    if (IsKeyDown(KEY_D)) keys[5] = 1;
    if (IsKeyDown(KEY_A)) keys[6] = 1;
    if (IsKeyDown(KEY_W)) keys[7] = 1;
    if (IsKeyDown(KEY_S)) keys[8] = 1;
    if (IsKeyDown(KEY_SPACE)) keys[9] = 1;
}

int args_invalid(int ac, char **av)
{
    if (ac == 2 && !strcmp(av[1], "-h")) {
        printf("%s[KIDIOT]%s\n\tBasically a 2D \"Who's your daddy\" ", Y, W);
        printf("coded in 2 days in C with the raylib.\n\tIt's an Epitech ");
        printf("GameJam (20/05/2022) project made by Dorian AYOUL and Xavier ");
        printf("TONNELLIER.\n\n%s[ARGUMENTS]%s\n\t-h\thelp\n\t[width] ", G, W);
        printf("[height] [framerate]\tstart the game with a valid screen ");
        printf("width/height/framerate\n\n%s[CONTROLS]%s\n\tBaby:\n\t", B, W);
        printf("Z\tgo up\n\tQ\tgo left\n\tS\tgo down\n\tD\tgo right\n\tSPACE");
        printf("\tinteract\n\n\tMom:\n\tUP ARROW\tgo up\n\tLEFT ARROW\tgo ");
        printf("left\n\tDOWN ARROW\tgo down\n\tRIGHT ARROW\tgo right\n\t");
        return printf("NUMPAD 0\tinteract\n\nCheck the readme for more info\n");
    }
    if (ac != 4)
        return fprintf(stderr, "%s[ERROR]%s Invalid number of args\n", R, W);
    for (size_t i = 1; i < 4; i++)
        for (size_t j = 0; av[i][j] != '\0'; j++)
            if (!isdigit(av[i][j]))
                return fprintf(stderr, "%s[ERROR]%s Invalid arg value\n", R, W);
    return 0;
}

void my_memset(int *keys, int i, int z)
{
    for (size_t i = 0; i != z; i++)
        keys[i] = 0;
}

void main_loop(kidiot_t *kidiot, char **buffer)
{
    int save_hp = kidiot->baby->hp;

    for (int keys[10] = {0}; !WindowShouldClose();) {
        get_keys(keys);
        kidiot->keys = keys;
        if (game_loop(kidiot, keys))
            break;
        BeginDrawing();
        ClearBackground(RAYWHITE);
        draw_map(kidiot);
        if (kidiot->baby->hp != save_hp) {
            free(*buffer);
            asprintf(buffer, "baby hp = %d", kidiot->baby->hp);
        }
        DrawText(*buffer, 10, 5, 20, LIGHTGRAY);
        EndDrawing();
        gest_clock(kidiot);
        for (size_t i = 0; i != 10; i++)
            keys[i] = 0;
    }
}

int main(int ac, char **av)
{
    int save_hp = 0;
    char *buffer = NULL;
    kidiot_t *kidiot;
    
    SetTraceLogLevel(LOG_NONE);
    if (args_invalid(ac, av))
        return 84;
    InitWindow(atoi(av[1]), atoi(av[2]), "Kidiot");
    kidiot = init_kidiot(read_map("map/first_floor.txt"), read_map("map/second_floor.txt"));
    SetTargetFPS(atoi(av[3]));
    asprintf(&buffer, "baby hp = %d", kidiot->baby->hp);
    main_loop(kidiot, &buffer);
    free_everything(kidiot, buffer);
    CloseWindow();
    return 0;
}