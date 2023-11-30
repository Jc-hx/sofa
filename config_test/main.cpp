#include <iostream>
#include <dlfcn.h> // Header for dynamic linking

typedef void (*InitSofaConfig)();

int main() {
    void* lib = dlopen("./libSofa.Config.so", RTLD_LAZY);

    if (!lib) {
        std::cerr << "Error loading library: " << dlerror() << std::endl;
        return 1;
    }

    InitSofaConfig initFunc = reinterpret_cast<InitSofaConfig>(dlsym(lib, "initSofaConfig"));

    if (!initFunc) {
        std::cerr << "Error locating initSofaConfig function: " << dlerror() << std::endl;
        dlclose(lib);
        return 1;
    }

    initFunc();

    dlclose(lib);

    return 0;
}
