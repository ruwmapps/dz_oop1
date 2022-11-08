#include <fstream>
#include <iostream>


void record_file(std::ofstream &file, int count_arr, int *&arr) {
    file << count_arr << std::endl;
    for (int j = 0; j < count_arr; ++j) {
        file << arr[j] << " ";
    }
    file << std::endl;
}

void *create_array(int *&arr, int count_arr, std::istream &file) {
    arr = new int[count_arr]();
    for (int i = 0; i < count_arr; ++i) {
        file >> arr[i];
    }
}

void delete_array(int *&arr) {
    delete[] arr;
    arr = nullptr;
}

void change_right(int *&arr, int count_arr, std::ofstream &file) {
    int temp = arr[0];
    for (int i = 0; i < (count_arr - 1); ++i) {
        arr[i] = arr[i + 1];
    }
    arr[(count_arr - 1)] = temp;

    record_file(file, count_arr, arr);
}

void change_left(int *&arr, int count_arr, std::ofstream &file) {
    int temp = arr[(count_arr - 1)];
    for (int i = count_arr; i > 0; --i) {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;

    record_file(file, count_arr, arr);
}

int main() {

    std::ifstream file("in.txt");
    if (!file) {
        std::cout << "Не найден файл для чтения";
        return 0;
    }


    std::ofstream file2;          // поток для записи
    file2.open("out.txt"); // окрываем файл для записи
    if (!file2.is_open()) {
        std::cout << "Не найден файл для записи";
        return 0;
    }


    int count_arr1 = 0;
    int count_arr2 = 0;

    int *arr1;
    int *arr2;

    file >> count_arr1;
    create_array(arr1, count_arr1, file);

    file >> count_arr2;
    create_array(arr2, count_arr2, file);

    file.close();

    change_left(arr2, count_arr2, file2);
    change_right(arr1, count_arr1, file2);

    file2.close();

    delete_array(arr1);
    delete_array(arr2);
    return 0;
}


