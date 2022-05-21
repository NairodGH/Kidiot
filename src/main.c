/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "include.h"

static void get_keys(int *keys)
{
    if (IsKeyPressed(KEY_RIGHT)) keys[0] = 1;
    if (IsKeyPressed(KEY_LEFT)) keys[1] = 1;
    if (IsKeyPressed(KEY_UP)) keys[2] = 1;
    if (IsKeyPressed(KEY_DOWN)) keys[3] = 1;
    if (IsKeyPressed(KEY_RIGHT) && IsKeyPressed(KEY_UP)) keys[4] = 1;
    if (IsKeyPressed(KEY_RIGHT) && IsKeyPressed(KEY_DOWN)) keys[5] = 1;
    if (IsKeyPressed(KEY_LEFT) && IsKeyPressed(KEY_UP)) keys[6] = 1;
    if (IsKeyPressed(KEY_LEFT) && IsKeyPressed(KEY_DOWN)) keys[7] = 1;
    if (IsKeyPressed(KEY_ENTER)) keys[8];
    if (IsKeyPressed(KEY_D)) keys[9] = 1;
    if (IsKeyPressed(KEY_A)) keys[10] = 1;
    if (IsKeyPressed(KEY_W)) keys[11] = 1;
    if (IsKeyPressed(KEY_S)) keys[12] = 1;
    if (IsKeyPressed(KEY_D) && IsKeyPressed(KEY_Z)) keys[13] = 1;
    if (IsKeyPressed(KEY_D) && IsKeyPressed(KEY_S)) keys[14] = 1;
    if (IsKeyPressed(KEY_Q) && IsKeyPressed(KEY_Z)) keys[15] = 1;
    if (IsKeyPressed(KEY_Q) && IsKeyPressed(KEY_S)) keys[16] = 1;
    if (IsKeyPressed(KEY_SPACE)) keys[17] = 1;
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
        keys[i] = z;
}

int main(int ac, char **av)
{
    char **floor_1 = read_map("map/first_floor.txt");
    char **floor_2 = read_map("map/second_floor.txt");
    char *buffer = NULL;
    entity_t *players = init_entity(floor_1, floor_2);
    
    SetTraceLogLevel(LOG_NONE);
    if (args_invalid(ac, av))
        return 84;
    InitWindow(atoi(av[1]), atoi(av[2]), "Kidiot");
    SetTargetFPS(atoi(av[3]));
    for (int keys[18] = {0}; !WindowShouldClose(); my_memset(keys, 0, 18)) {
        get_keys(keys);
        if (game_loop(players, keys))
            break;
        BeginDrawing();
        ClearBackground(RAYWHITE);
        draw_map(players);
        asprintf(&buffer, "baby hp = %d", players->baby->hp);
        DrawText(buffer, 10, 5, 20, LIGHTGRAY);
        EndDrawing();
        free(buffer);
    }
    free_double_tab(floor_1);
    free_double_tab(floor_2);
    free(players);
    CloseWindow();
    return 0;
}