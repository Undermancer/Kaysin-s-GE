#include <fmt/core.h>
#include <glad/glad.h>
#include <SDL3/SDL.h>
#include <imgui.h>
#include <imgui_impl_sdl3.h>
#include <imgui_impl_opengl3.h>


int main(int argc, char* argv[]) {
    // Intentamos inicializar el subsistema de video de SDL
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        // Si falla, usamos fmt para imprimir el error exacto que nos da SDL
        fmt::print("Error crítico: No se pudo inicializar SDL. {}\n", SDL_GetError());
        return -1;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8); 

    SDL_Window* window = SDL_CreateWindow("Kaysin's GE", 1280, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    SDL_GLContext context = SDL_GL_CreateContext(window);

    //contect ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable; // Habilitar Docking pedido en clase

    ImGui::StyleColorsDark();

    // Inicializar los backends de SDL3 y OpenGL3
    ImGui_ImplSDL3_InitForOpenGL(window, context);
    ImGui_ImplOpenGL3_Init("#version 460 core"); // Ajusta la versión según lo que uses

    // Variables de estado para los botones
    bool enable_depth_test = false;
    bool enable_cull_face = false;
    bool enable_wireframe = false;

    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        // error: no se cargó OpenGL
        fmt::print("Error crítico: No se pudo inicializar OpenGL.\n");
        return -1;
    }
    int version = gladLoadGLLoader(reinterpret_cast<GLADloadproc>(SDL_GL_GetProcAddress));
    // … check for errors
    if (version == 0)
        fmt::print("Error loading the glad library");

    fmt::print("Vendor: {}\n", reinterpret_cast<const char*>(glGetString(GL_VENDOR)));
    fmt::print("Renderer: {}\n", reinterpret_cast<const char*>(glGetString(GL_RENDERER)));
    fmt::print("OpenGL version supported {}\n", reinterpret_cast<const char*>(glGetString(GL_VERSION)));
    fmt::print("GLSL: {}\n", reinterpret_cast<const char*>(glGetString(GL_SHADING_LANGUAGE_VERSION)));

    // Si llegamos aquí, la tarjeta gráfica ha respondido bien
    fmt::print("SDL3 inicializado correctamente\n");
    fmt::print("OpenGL: {}\n", (const char*)glGetString(GL_VERSION));

    // Opciones globales 
    glClearDepth(1.0f); 

    // Transparencias
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 

    // Z-Buffer y Culling
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE); 

    // Viewport inicial (Asumiendo que tu ventana es 1280x720)
    glViewport(0, 0, 1280, 720); //[cite: 307, 343, 348]

    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT)
                running = false;
        }
        //PreUpdate
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //Dibuja la geometria

        //Dibuja el editor

        //Cambio de buffers y renderizado
        SDL_GL_SwapWindow(window);
    }

    // Apagamos SDL limpiamente para no dejar procesos colgados en Windows
    SDL_GL_DestroyContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}