#include <iostream>
#include <fstream>
using namespace std;

struct ImageInfo {
    int width;
    int height;
    char type[10];
};

int main() {
    ImageInfo img1{1600, 900, "PNG"};
    ImageInfo img2{2560, 1440, "JPEG"};
    ImageInfo img3{3840, 2160, "WEBP"};

    ofstream file("image_data.bin", ios::binary);

    if (!file) {
        cout << "File could not be opened for writing." << endl;
        return 1;
    }

    file.write(reinterpret_cast<const char*>(&img1), sizeof(ImageInfo));
    file.write(reinterpret_cast<const char*>(&img2), sizeof(ImageInfo));
    file.write(reinterpret_cast<const char*>(&img3), sizeof(ImageInfo));

    file.close();

    ifstream input("image_data.bin", ios::binary);

    if (!input) {
        cout << "File could not be opened for reading." << endl;
        return 1;
    }

    ImageInfo image;
    int count = 1;

    cout << "===== IMAGE INFORMATION =====" << endl;

    while (input.read(reinterpret_cast<char*>(&image), sizeof(ImageInfo))) {
        cout << "Image " << count++ << ": "
             << image.width << " x "
             << image.height
             << " | Format: " << image.type << endl;
    }

    input.close();

    return 0;
}