#include "../include/safety_display.h"
#include <stdio.h>
#include <GLFW/glfw3.h> // Standard OpenGL Window library

// LLR-GRAPHICS-003: Driver must initialize and flag invalid display bounds
bool init_display_driver(SafetyDisplayDriver* driver, int w, int h) {
    driver->width = w;
    driver->height = h;
    driver->error_count = 0;

    // BUG SIMULATION: Safety-critical screens cannot accept zero boundaries
    if (w <= 0 || h <= 0) {
        driver->error_count++;
        driver->is_window_active = false;
        return false; 
    }

    driver->is_window_active = true;
    return true;
}

// Renders a basic, high-visibility orange hazard triangle
void render_safety_triangle(SafetyDisplayDriver* driver) {
    if (!driver->is_window_active) return;

    // Standard legacy OpenGL to render a basic triangle shape in the window
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.5f, 0.0f); // Alert Orange
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
    glEnd();
}
