#pragma once

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Texture;

namespace game
{
    class SDLDevice
    {
    public:
        SDLDevice() = delete;
        SDLDevice(int width, int height);
        SDLDevice(const SDLDevice &other) = delete;
        SDLDevice &operator=(const SDLDevice &other) = delete;
        ~SDLDevice();

        /// The game loop
        void Run();

    private:
        SDL_Window *window;
        SDL_Renderer *renderer;

        double deltaTime;

        int width;
        int height;
    };

} // namespace game