# integer array API

    1- init first make an object of the Struct Array then send its address to the init function with the  initial required size
            typedef struct Array
            {
                int *arr;
                int length;
                int size;
            } Array;
            Array *array;
            init(array, 5);
        this will initialize the integer array with the required size and length 0
        abd every not filled slot(index) is initialized with INT_MIN
