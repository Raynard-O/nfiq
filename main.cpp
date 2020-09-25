
#include "nfiqlib.h"
#include "thread"

int debug = 0;

int main() {

    int f1;
    f1 = nfiq("./image_02.wsq");

    printf("\n%d", f1);

    return 0;


}
