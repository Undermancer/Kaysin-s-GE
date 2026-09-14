#include <fmt/core.h>
#include <SDL3/SDL.h>

int main(int argc, char* argv[]) {
    // Intentamos inicializar el subsistema de video de SDL
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        // Si falla, usamos fmt para imprimir el error exacto que nos da SDL
        fmt::print("Error crítico: No se pudo inicializar SDL. {}\n", SDL_GetError());
        return -1;
    }

    // Si llegamos aquí, la tarjeta gráfica ha respondido bien
    fmt::print("¡SDL3 inicializado correctamente! El motor gráfico respira...\n");

    // Apagamos SDL limpiamente para no dejar procesos colgados en Windows
    SDL_Quit();
    return 0;
}