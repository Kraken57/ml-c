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

// to determine the number of rows in the train array
#define train_count (sizeof(train)/sizeof(train[0])) 

float rand_float(void) {
    return (float)rand() / (float)(RAND_MAX);
}

// this is the cost function
float cost(float w, float b) {

    float result = 0.0f;
    for (size_t i=0; i<train_count; ++i){
        float x = train[i][0];
        float y = x*w + b;
        // printf("actual: %f, expected: %f\n", y, train[i][1]);
        float d = y - train[i][1];
        result += d*d;
    }
    result /= train_count;
    return result;
};

int main() {
    srand(time(0)); 
    // srand(69); 
    // y = x*w
    float w = rand_float()*10.0f; 
    float b = rand_float()*5.0f; 

    float epsilon = 1e-3;
    float rate = 1e-3; //learning rate
    
    //derivative of cost function
    printf("Cost error before w: %f\n", cost(w, b));

    for(size_t i=0 ; i<500; ++i){

        float c = cost(w, b); 
        float dw = (cost(w + epsilon, b) - c)/epsilon;
        float db = (cost(w , b + epsilon) - c)/epsilon;
        w -= rate*dw;
        b -= rate*db;
       printf("Cost = %f, w = %f, b = %f\n", cost(w, b), w, b);
    }

    printf("----------------------------------------\n");
    printf("w: %f, b = %f\n", w, b);

    return 0;
}
