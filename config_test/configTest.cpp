#include <iostream>

// Function declaration from the shared object file
extern "C" {
    void initSofaConfig();
}

int main() {
    std::cout << "Testing generated .so file.\n";
    initSofaConfig();
    return 0;
}
