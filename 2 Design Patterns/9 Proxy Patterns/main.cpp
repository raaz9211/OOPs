#include "ImageProxy.hpp"

int main() {
    ImageProxy image("example.jpg");
    std::cout << "[Client] Proxy created.\n";
    std::cout << "[Client] Now displaying image:\n";
    image.display();  // This will load the image from disk and display it

    std::cout << "[Client] Displaying image again:\n";
    image.display();  // This will not load the image again, just display it
    return 0;
}