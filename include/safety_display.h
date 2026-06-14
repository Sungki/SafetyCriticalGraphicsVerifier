#ifndef SAFETY_DISPLAY_H
#define SAFETY_DISPLAY_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int width;
    int height;
    bool is_window_active;
    unsigned int error_count;
} SafetyDisplayDriver;

// Core driver functions
bool init_display_driver(SafetyDisplayDriver* driver, int w, int h);
void render_safety_triangle(SafetyDisplayDriver* driver);

#ifdef __cplusplus
}
#endif

#endif
