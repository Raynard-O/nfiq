
#include <iostream>
#include "ms_func.h"
#include "thread"
#include <atomic>
#include <chrono>
#include <unistd.h>
int debug = 0;


int fgp;
int imageQtest;
char *test = "../testb.jpeg";

using namespace std;

int main() {
    char *MODE;
    int f1, f2, f3, f4;
            f1 = ms_imagequality("./image_02.wsq");
            f2 = ms_imagequality("./image_03.wsq");
            f3 = ms_imagequality("./image_04.wsq");
            f4 = ms_imagequality("./image_05.wsq");



    return 0;


}
