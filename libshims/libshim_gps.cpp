#include <iostream>

extern "C" float mtk_flp_controller_get_current_acc() {
    return 1;
}

extern "C" int gfc_kernel_2gfc_hdlr() {
    return 0;
}
