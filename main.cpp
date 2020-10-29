
#include "nfiqlib.h"
#include "wsqlib.h"
#include "thread"

int debug = 0;

int main() {

    int f1;
    auto err = convert_wsq("./image.jpegl");
    if (err != 0 ){
        return err;
    }
    f1 = nfiq("./image_12.wsq");

    printf("\n%d", f1);

    return 0;


}
