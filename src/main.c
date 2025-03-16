#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include "cpu.h"
#include "memory.h"

// Screen dimensions
#define SCREEN_WIDTH 160
#define SCREEN_HEIGHT 144
#define SCALE_FACTOR 3

// Game Boy screen color palette (shades of green)
const SDL_Color PALETTE[4] = {
    {155, 188, 15, 255},  // Lightest
    {139, 172, 15, 255},  // Light
    {48, 98, 48, 255},    // Dark
    {15, 56, 15, 255}     // Darkest
};

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *screen_texture;
    bool running;
} Emulator;

// Initialize SDL and create window
bool init_video(Emulator *emu) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL initialization failed: %s\n", SDL_GetError());
        return false;
    }

    emu->window = SDL_CreateWindow(
        "Game Boy Emulator",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH * SCALE_FACTOR,
        SCREEN_HEIGHT * SCALE_FACTOR,
        SDL_WINDOW_SHOWN
    );

    if (!emu->window) {
        printf("Window creation failed: %s\n", SDL_GetError());
        return false;
    }

    emu->renderer = SDL_CreateRenderer(
        emu->window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (!emu->renderer) {
        printf("Renderer creation failed: %s\n", SDL_GetError());
        return false;
    }

    emu->screen_texture = SDL_CreateTexture(
        emu->renderer,
        SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_STREAMING,
        SCREEN_WIDTH,
        SCREEN_HEIGHT
    );

    if (!emu->screen_texture) {
        printf("Texture creation failed: %s\n", SDL_GetError());
        return false;
    }

    return true;
}

// Clean up SDL resources
void cleanup(Emulator *emu) {
    if (emu->screen_texture) {
        SDL_DestroyTexture(emu->screen_texture);
    }
    if (emu->renderer) {
        SDL_DestroyRenderer(emu->renderer);
    }
    if (emu->window) {
        SDL_DestroyWindow(emu->window);
    }
    SDL_Quit();
}

// Handle input events
void handle_input(Emulator *emu) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                emu->running = false;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        emu->running = false;
                        break;
                    // Add more key handlers here for Game Boy buttons
                }
                break;
        }
    }
}

int main(int argc, char *argv[]) {
    Emulator emu = {0};
    CPU cpu = {0};
    Memory memory = {0};

    // Initialize emulator components
    if (!init_video(&emu)) {
        cleanup(&emu);
        return 1;
    }

    cpu_init(&cpu);
    memory_init(&memory);
    emu.running = true;

    // Main emulation loop
    while (emu.running) {
        // Handle input
        handle_input(&emu);

        // Emulate one CPU instruction
        int cycles = cpu_step(&cpu);

        // Update timers and other components based on cycles
        
        // Update graphics
        SDL_RenderClear(emu.renderer);
        SDL_RenderCopy(emu.renderer, emu.screen_texture, NULL, NULL);
        SDL_RenderPresent(emu.renderer);

        // TODO: Implement proper timing to match Game Boy's refresh rate (59.73 Hz)
    }

    // Cleanup
    cleanup(&emu);
    return 0;
} 