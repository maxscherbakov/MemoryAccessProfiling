#include <iostream>
#include <chrono>

#define ROWS 10000
#define COLUMNS 10000

void vertical_read(int* &matrix) {
    int item;
    for (size_t x = 0; x < ROWS; ++x) {
        for (size_t y = 0; y < COLUMNS; ++y) {
            item = matrix[y * COLUMNS + x];
        }
    }
}


void horizontal_read(int* &matrix) {
    int item;
    for (size_t y = 0; y < COLUMNS; ++y) {
        for (size_t x = 0; x < ROWS; ++x) {
            item = matrix[y * COLUMNS + x];
        }
    }
}

int main() {
    int* matrix = (int*)malloc(COLUMNS * ROWS * sizeof(int));

    for (int x = 0; x < ROWS; ++x) {
        for (int y = 0; y < COLUMNS; ++y) {
            matrix[y * COLUMNS + x] = 1;
        }
    }

    auto start_horithontal_timer = std::chrono::high_resolution_clock::now();

    horizontal_read(matrix);

    auto start_vertical_timer = std::chrono::high_resolution_clock::now();


    vertical_read(matrix);

    auto end = std::chrono::high_resolution_clock::now();
    auto horithontal_time = std::chrono::duration_cast<std::chrono::milliseconds>(
        start_vertical_timer - start_horithontal_timer);
    auto vertical_time = std::chrono::duration_cast<std::chrono::milliseconds>(
        end - start_vertical_timer);

    std::cout << "Time for horithontal read: ";
    std::cout << horithontal_time.count() << std::endl;
    std::cout << "Time for vertical read: ";
    std::cout << vertical_time.count() << std::endl;


    // Freeing memory
    free(matrix);

    return 0;
}
// Results:
// Time for horithontal read: 115
// Time for vertical read: 527
