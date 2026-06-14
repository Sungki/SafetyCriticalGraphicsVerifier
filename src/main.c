#include "../include/safety_display.h"
#include <GLFW/glfw3.h>

int main() {
    if (!glfwInit()) return -1;

    // Set up a standard 800x600 window
    GLFWwindow* window = glfwCreateWindow(800, 600, "Aversan Critical Display POC", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    SafetyDisplayDriver driver;
    init_display_driver(&driver, 800, 600);

    // Simple Render Loop
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // Run the driver logic to draw the asset inside the active window
        render_safety_triangle(&driver);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
