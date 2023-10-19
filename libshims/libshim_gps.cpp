#include <iostream>
#include <sys/types.h>
#include <dlfcn.h>
#include <string.h>

//
// Return value for most GPS APIs.
//
#define MTK_GPS_SUCCESS    (0)

//
// This function is part of the main GPS controller.
// For some reason it seems to be used but not implemented.
// Provide a dummy stub that returns success regardless of
// the parameters that are passed on.
//
extern "C" int32_t mtk_gps_sys_agps_disaptcher_callback(uint16_t type, uint16_t length, char *data) {
    // This is supposed to be a callback from agent to dispatcher.
    // The third parameter holds the checksum(1) of 'PMTK_FS_REQ_MEAS'.
    // We don't really care about the dispatcher. Return success and
    // pretend everything's fine.
    return MTK_GPS_SUCCESS;
}

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
