#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

float train[][2] = {
    {0, 0},
    {1, 2},
    {2, 4},
    {3, 6},
    {4, 8},
};

#define train_count (sizeof(train)/sizeof(train[0]))

float rand_float(void) {
    return (float)rand() / (float)(RAND_MAX);
}

// this is the cost function
float cost(float w) {

    float result = 0.0f;
    for (size_t i=0; i<train_count; ++i){
        float x = train[i][0];
        float y = x*w;
        // printf("actual: %f, expected: %f\n", y, train[i][1]);
        float d = y - train[i][1];
        result += d*d;
    }
    result /= train_count;
    return result;
};

int main() {
    //srand(time(0)); 
    srand(69); 
    // y = x*w
    float w = rand_float()*10.0f; 

    float epsilon = 1e-3;
    printf("Cost error             w: %f\n", cost(w));
    printf("Cost error with eps weps: %f\n", cost(w - epsilon));
    printf("Cost error with eps weps: %f\n", cost(w - epsilon*2));

    return 0;
}
