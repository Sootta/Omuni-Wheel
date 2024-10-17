#ifndef OMUNI
#define OMUNI

#include <Arduino.h>
#include <cmath>
#include <vector>

class Omuni 
{
    public:
        Omuni(int num){
            this->num = num;
            for(int i = 0; i < num; i++) {
                thita.push_back(M_PI * 2 / num * i);
                vec_cos.push_back(cos(this->thita[i]));
                vec_sin.push_back(sin(this->thita[i]));
            }
        }
        void calculate(int vector[], int vector_x, int vector_y) {
            for(int i = 0; i < this->num; i++) {
                vector[i] = vec_cos[i] * vector_x + vec_sin[i] * vector_y;
            }
        }
        void calculate(int vector[], int vector_x, int vector_y, int thita) {
            for(int i = 0; i < this->num; i++) {
                vector[i] = vec_cos[i] * vector_x + vec_sin[i] * vector_y + thita;
            }
        }
    private:
        int num;
        std::vector<double> vec_cos;
        std::vector<double> vec_sin;
        std::vector<double> thita;
};

#endif