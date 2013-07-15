#ifndef SAILFISH_SDL_WAYLAND_OPENGL_TEST_H
#define SAILFISH_SDL_WAYLAND_OPENGL_TEST_H

#include <SDL.h>
#include <stdio.h>

#include <list>

class TouchPoint {
    public:
        TouchPoint(int id, float x, float y) : id(id), x(x), y(y) {}

        int id;
        float x;
        float y;
};

typedef void (*touch_point_func)(TouchPoint *touch, void *user_data);

class SDL2TestApplication {
    public:
        SDL2TestApplication(int major, int minor);
        ~SDL2TestApplication();

        int run();

        virtual void initGL() = 0;
        virtual void resizeGL(int width, int height) = 0;
        virtual void renderGL() = 0;

        void for_each_touch(touch_point_func f, void *user_data);

    private:
        int m_major;
        int m_minor;
        SDL_Window *m_window;
        SDL_GLContext m_gl_context;
        std::list<TouchPoint*> m_touches;
};

#endif /* SAILFISH_SDL_WAYLAND_OPENGL_TEST_H */