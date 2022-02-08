#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "snake_utils.h"
#include "state.h"

/* Helper function definitions */
static char get_board_at(game_state_t* state, int x, int y);
static void set_board_at(game_state_t* state, int x, int y, char ch);
static bool is_tail(char c);
static bool is_snake(char c);
static char body_to_tail(char c);
static int incr_x(char c);
static int incr_y(char c);
static void find_head(game_state_t* state, int snum);
static char next_square(game_state_t* state, int snum);
static void update_tail(game_state_t* state, int snum);
static void update_head(game_state_t* state, int snum);

/* Helper function to get a character from the board (already implemented for you). */
static char get_board_at(game_state_t* state, int x, int y) {
  return state->board[y][x];
}

/* Helper function to set a character on the board (already implemented for you). */
static void set_board_at(game_state_t* state, int x, int y, char ch) {
  state->board[y][x] = ch;
}

/* Task 1 */
game_state_t* create_default_state() {
  game_state_t *game = malloc(sizeof(game_state_t));
  if (game == NULL) {
    perror("Malloc failed\n");
  }
  game->x_size = 14;
  game->y_size = 10;
  game->board = malloc((game->y_size) * sizeof(char*));
  if (game->board == NULL) {
    perror("Malloc failed\n");
  }
  for (int i = 0; i < game->y_size; i++) {
    game->board[i] = malloc((game->x_size + 1) * sizeof(char));
    char *line = game->board[i];
    if (line == NULL) {
      perror("Malloc failed\n");
    }
    if (i == 0 || i == game->y_size - 1) {
      strcpy(line, "##############");
    } else if (i == 2) {
      strcpy(line, "#        *   #");
    } else if (i == 4) {
      strcpy(line, "#   d>       #");
    } else {
      strcpy(line, "#            #");
    }
  }
  game->num_snakes = 1;
  game->snakes = malloc((game->num_snakes) * sizeof(snake_t));
  if (game->snakes == NULL) {
    perror("Malloc failed\n");
  }
  snake_t *s = game->snakes;
  s->tail_x = 4;
  s->tail_y = 4;
  s->head_x = 5;
  s->head_y = 4;
  s->live = true;
  return game;
}

/* Task 2 */
void free_state(game_state_t* state) {
  for(int i = 0; i < state->y_size; i++) {
    free(state->board[i]);
  }
  free(state->board);
  free(state->snakes); //TODO: MIGHT have to change this in the case of more than one snake?
  free(state);
  return;
}

/* Task 3 */
void print_board(game_state_t* state, FILE* fp) { 
  for (int i = 0; i < state->y_size; i++) {
    fprintf(fp, "%s", state->board[i]);
    fprintf(fp, "%c", '\n');
  }
  return;
}

/* Saves the current state into filename (already implemented for you). */
void save_board(game_state_t* state, char* filename) {
  FILE* f = fopen(filename, "w");
  print_board(state, f);
  fclose(f);
}

/* Task 4.1 */
static bool is_tail(char c) {
  // TODO: Implement this function.
  return !(c == '\0') && strchr("wasd", c);
}

static bool is_snake(char c) {
  // TODO: Implement this function.
  return !(c == '\0') && strchr("wasd^<>vx", c);
}

static char body_to_tail(char c) {
  // TODO: Check that c is in ^<>v
  if(c == '^') {
    return 'w';
  } else if (c == '<') {
    return 'a';
  } else if (c == '>') {
    return 'd';
  } else if (c == 'v') {
    return 's';
  }
  return '?';
}

static int incr_x(char c) {
  if (c == '\0') {
    return 0;
  }
  if (strchr(">d", c)) {
    return 1;
  }
  else if (strchr("<a", c)) {
    return -1;
  }
  else return 0;
}

static int incr_y(char c) {
  if (c == '\0') {
    return 0;
  }
  if (strchr("vs", c)) {
    return 1;
  }
  else if (strchr("^w", c)) {
    return -1;
  }
  else return 0;
}

/* Task 4.2 */
static char next_square(game_state_t* state, int snum) {
  snake_t snek = state->snakes[snum];
  char head = get_board_at(state, snek.head_x, snek.head_y);
  int next_x = snek.head_x + incr_x(head);
  int next_y = snek.head_y + incr_y(head);
  return get_board_at(state, next_x, next_y);
}

/* Task 4.3 */
static void update_head(game_state_t* state, int snum) {
  snake_t *snek = &state->snakes[snum];
  char head = get_board_at(state, snek->head_x, snek->head_y);
  snek->head_x += incr_x(head);
  snek->head_y += incr_y(head);
  set_board_at(state, snek->head_x, snek->head_y, head);
}

/* Task 4.4 */
static void update_tail(game_state_t* state, int snum) {
  // TODO: Implement this function.
  return;
}

/* Task 4.5 */
void update_state(game_state_t* state, int (*add_food)(game_state_t* state)) {
  // TODO: Implement this function.
  return;
}

/* Task 5 */
game_state_t* load_board(char* filename) {
  // TODO: Implement this function.
  return NULL;
}

/* Task 6.1 */
static void find_head(game_state_t* state, int snum) {
  // TODO: Implement this function.
  return;
}

/* Task 6.2 */
game_state_t* initialize_snakes(game_state_t* state) {
  // TODO: Implement this function.
  return NULL;
}
