#include <iostream>
#include <vector>

std::vector<float> insertion_sort(std::vector<float>& list);
void list_printer(const std::vector<float>& list);

int main() {
    std::vector<float> list {1, 9, 4.5, 10.6, 5.7, -4.5};

    insertion_sort(list);
    list_printer(list);

    return 0;
}

std::vector<float> insertion_sort(std::vector<float>& list) {
    int i, j;
    float pivot;

    for (i = 1; i < list.size(); i++) {
        pivot = list[i];
        j = i - 1;

        while (j >= 0 and list[j] > pivot) {  //Shifts elements to the right
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = pivot;    //Inserts the pivot in vague position
    }

    return list;
}

void list_printer(const std::vector<float>& list) {
    for (auto& i : list) {
        std::cout << i << " ";
    }
}
