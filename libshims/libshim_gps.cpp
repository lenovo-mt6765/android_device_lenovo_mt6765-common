#include <iostream>
#include <sys/types.h>
#include <dlfcn.h>
#include <string.h>

extern "C" float mtk_flp_controller_get_current_acc() {
    return 1;
}

extern "C" int gfc_kernel_2gfc_hdlr() {
    return 0;
}

extern "C" int property_get(const char *key, char *value, const char *default_value) {
    if (strcmp("ro.build.type", key) == 0) {
      strcpy(value, "eng");
      return 3;
    }

    return ((int( * )(const char * , char *, const char * ))(dlsym((void * ) - 1, "property_get")))(key, value, default_value);
}
