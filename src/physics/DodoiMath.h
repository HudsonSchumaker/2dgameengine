/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "../include/Common.h"

class DodoiMath {

    static double root(double n) {
        double x = n / 2;
        for (int i = 0; i < 1000; i++) {
            double x_new = x - (x * x - n) / (2 * x);
            if (fabs(x_new - x) < 0.000001) {
            return x_new;
            }
            x = x_new;
        }
        return x;
    }

    static float root(float n) {
        float x = n / 2;
        for (int i = 0; i < 1000; i++) {
            float x_new = x - (x * x - n) / (2 * x);
            if (fabs(x_new - x) < 0.000001) {
                return x_new;
            }
            x = x_new;
         }
        return x;
    }

    static int root(int n) {
        int x = n / 2;
        for (int i = 0; i < 1000; i++) {
            int x_new = x - (x * x - n) / (2 * x);
            if (x_new == x) {
                return x;
            }
            x = x_new;
        }
        return x;
    }
};
