#pragma once

namespace Fuse {
  struct FUSE_API AppInstance {

    FUSE_INLINE AppInstance() {
      // Initialize glfw
      if (!glfwInit()) { 
        FUSE_FATAL("glfwInit() failed!"); 
      }
  
      // Creating window
      this->_appWindow = glfwCreateWindow(1280, 720, "FuseEngine3D", NULL, NULL);

      // Check validity
      if (!this->_appWindow) { 
        glfwTerminate();
        FUSE_FATAL("glfwCreateWindow() failed!"); 
      }
    }

    FUSE_INLINE ~AppInstance() {
      glfwTerminate();
    }

    FUSE_INLINE void RunMainLoop() {
      while(!glfwWindowShouldClose(this->_appWindow)) {
        glfwPollEvents();
        glfwSwapBuffers(this->_appWindow);
      }
    }

  private:
    GLFWwindow* _appWindow = NULL;
  };
}