#include <fstream>
#include <iostream>
#include <windows.h>

void print_array(int *arr, int rows) {
        for (int j = 0; j < rows; ++j) {
                std::cout << arr[j] << "\t";
        }
}

void *create_array(int *&arr, int count_arr,std::istream &file){
    arr = new int[count_arr]();
    for(int i = 0; i < count_arr; ++i){
        file >> arr[i];
    }
}

void delete_array(int *&arr) {
    delete[] arr;
    arr = nullptr;
}

void change_right(int *&arr, int count_arr) {
    int temp = arr[0];
    for(int i = 0; i < (count_arr - 1); ++i){
        arr[i] = arr[i + 1];
    }
    arr[(count_arr-1)] = temp;
}

void change_left(int *&arr, int count_arr) {
    int temp = arr[(count_arr-1)];
    for(int i = count_arr; i > 0; --i){
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    std::ifstream file("in.txt");
    if (!file) {
        std::cout << "Не найден файл";
        return 0;
    }
    int count_arr1 = 0;
    int count_arr2 = 0;

    int *arr1;
    int *arr2;

    file >> count_arr1;
    create_array(arr1, count_arr1,file);

    file >> count_arr2;
    create_array(arr2, count_arr2,file);

    file.close();

    print_array(arr1,count_arr1);
    std::cout << "\n";
    print_array(arr2,count_arr2);
    std::cout << std::endl;

    change_right(arr1,count_arr1);
    change_left(arr2,count_arr2);

    print_array(arr1,count_arr1);
    std::cout << "\n";
    print_array(arr2,count_arr2);
    std::cout << std::endl;

    delete_array(arr1);
    delete_array(arr2);
    return 0;
}

