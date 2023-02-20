#include <string>

#define SDL_MAIN_HANDLED
#include <SDL.h>

#include "sdl_device.h"

namespace game
{
    SDLDevice::SDLDevice(int width, int height) : deltaTime(0), width(width), height(height)
    {
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER) != 0)
        {
            SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        }

        window = SDL_CreateWindow("SDL is active!", 100, 100, width, height, 0);
        if (!window)
        {
            SDL_Log("Unable to create window: %s", SDL_GetError());
            SDL_Quit();
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (!renderer)
        {
            SDL_Log("Unable to create renderer: %s", SDL_GetError());
            SDL_DestroyWindow(window);
        }
    }

    SDLDevice::~SDLDevice()
    {
        if (renderer)
        {
            SDL_DestroyRenderer(renderer);
        }

        if (window)
        {
            SDL_DestroyWindow(window);
        }

        if (SDL_WasInit(0) != 0)
        {
            SDL_Quit();
        }
    }

    void SDLDevice::Run()
    {
        int running = 1;

        uint64_t frequency = SDL_GetPerformanceFrequency();
        uint64_t prev_time = 0;

        while (running)
        {
            uint64_t current_time = SDL_GetPerformanceCounter();
            deltaTime = (double)(current_time - prev_time) / (double)frequency;
            prev_time = current_time;

            SDL_SetWindowTitle(window, std::to_string(deltaTime).c_str());

            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    running = 0;
                }

                SDL_PumpEvents();

                SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
                SDL_RenderClear(renderer);

                SDL_RenderPresent(renderer);
            }
        }
    }

} // namespace game

using namespace game;

int main(int argc, char **argv)
{
    SDLDevice device(1280, 720);

    device.Run();

    return 0;
}