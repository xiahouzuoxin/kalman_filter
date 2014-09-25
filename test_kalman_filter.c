/*
 * FileName : test_kalman_filter.c
 * Author   : xiahouzuoxin @163.com
 * Version  : v1.0
 * Date     : 2014/9/25 8:34:29
 * Brief    : 
 * 
 * Copyright (C) MICL,USTB
 */
#include <stdio.h>
#include "kalman_filter.h" 
//#include "fixed_test1.h"
//#include "fixed_test2.h"
#include "free_test07.h"

int main(void)
{
    int i = 0;
    kalman1_state state1;
    float *data = NULL;
    int data_len = 0;
    float out1 = 0;
    /* For 2 Dimension */
    kalman2_state state2;
    float init_x[2];
    float init_p[2][2] = {{10e-6,0}, {0,10e-6}};
    float out2 = 0;

    data = x1;
    data_len = sizeof(x1)/sizeof(float);
    // 1 dimension
    kalman1_init(&state1, data[1], 5e2);
    // 2 dimension
    init_x[0] = data[0];
    init_x[1] = data[1] - data[0];
    kalman2_init(&state2, init_x, init_p);
    printf("%d %d %d\n", data, data_len-2, data_len-2);
    for (i=2; i<data_len; i++) {  // Filter start from 2
        printf("%.2f", data[i]);      // Original data
        /* 1 dimension */
        out1 = kalman1_filter(&state1, data[i]);
        printf(" %.2f", out1);  // Filter result
        /* 2 dimension */
        out2 = kalman2_filter(&state2, data[i]);
        printf(" %.2f\n", out2);  // Filter result
    }

    data = x2;
    data_len = sizeof(x2)/sizeof(float);
    // 1 dimension
    kalman1_init(&state1, data[1], 5e2);
    // 2 dimension
    init_x[0] = data[0];
    init_x[1] = data[1] - data[0];
    kalman2_init(&state2, init_x, init_p);
    printf("%d %d %d\n", data, data_len-2, data_len-2);
    for (i=2; i<data_len; i++) {  // Filter start from 2
        printf("%.2f", data[i]);      // Original data
        /* 1 dimension */
        out1 = kalman1_filter(&state1, data[i]);
        printf(" %.2f", out1);  // Filter result
        /* 2 dimension */
        out2 = kalman2_filter(&state2, data[i]);
        printf(" %.2f\n", out2);  // Filter result
    }

    return 0;
}

