#include <SDL2/SDL.h>

int main(int argc, char* argv[]) {
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Graphics Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1080, 700, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    int i;

    for (i = 0; i <= 250; i++) {
        SDL_Delay(20);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 1, 102, 80, 255);
        SDL_Rect rect = { 400, 300 - i, 200, 100 };
        SDL_RenderFillRect(renderer, &rect);

        SDL_SetRenderDrawColor(renderer, 235, 24, 50, 255);
        SDL_RenderDrawLine(renderer, 385, 30, 385, 600);
        SDL_RenderDrawLine(renderer, 0, 600, 1080, 600);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
