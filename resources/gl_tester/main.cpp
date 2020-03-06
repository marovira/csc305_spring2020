#include <atlas/glx/Context.hpp>
#include <fmt/printf.h>

using namespace atlas;

void onError(int code, char const* message)
{
    fmt::print("error({}): {}\n", code, message);
}

void main()
{
    if (!glx::initializeGLFW(onError))
    {
        fmt::print("error: unable to initialize GLFW\n");
        std::abort();
    }

    glx::WindowSettings settings;
    settings.size  = {300, 300};
    settings.title = "OpenGL Tester";

    GLFWwindow* window = glx::createGLFWWindow(settings);
    if (!window)
    {
        fmt::print("error: unable to create window\n");
        std::abort();
    }

    glfwMakeContextCurrent(window);

    if (gl3wInit() != 0)
    {
        fmt::print("error: could not initialize OpenGL\n");
        std::abort();
    }

    if (gl3wIsSupported(4, 5) == 0 && gl3wIsSupported(4, 6) == 0)
    {
        fmt::print(
            "error: your graphics card does not support OpenGL 4.5 or 4.6\n");
        fmt::print("error: unable to access required OpenGL core functions\n");
        std::abort();
    }

    GLint major;
    GLint minor;
    glGetIntegerv(GL_MAJOR_VERSION, &major);
    glGetIntegerv(GL_MINOR_VERSION, &minor);
    fmt::print("Created OpenGL context {}.{}\n", major, minor);

    glx::destroyGLFWWindow(window);
    glx::terminateGLFW();
}
