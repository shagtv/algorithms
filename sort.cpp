#include <iostream>

void printArray(int array[], int n) {
	for (int i = 0; i < n; i++) {
                std::cout << array[i] << ", ";
        }
	std::cout << std::endl;
};

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int array[], int n) {
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n- i -1; j++)
			if (array[j] > array[j + 1])
				swap(&array[j], &array[j + 1]);
};

void selectionSort(int array[], int n) {
    int i, j, min_i;
	for (int i = 0; i < n - 1; i++) {
	    min_i = i;
		for (int j = i + 1; j < n; j++)
			if (array[j] < array[min_i])
				min_i = j;
		swap(&array[i], &array[min_i]);
	}
};

int main (int argc, char** argv) {
	if (argc < 3) {
		std::cout << "Enter sort type and int list" << std::endl;
		return 1;
	}

	int n = argc - 2;
	int array[n];

	for (int i = 2; i < argc; i++) {
		array[i - 2] = atoi(argv[i]);
	}

	std::cout << "Input: ";
	printArray(array, n);

	if (strcmp(argv[1], "selection")) {
	    selectionSort(array, n);
    } else if (strcmp(argv[1], "bubble")) {
        bubbleSort(array, n);
    }

	std::cout << "Sorted: ";
	printArray(array, n);
	
	return 0;
}

