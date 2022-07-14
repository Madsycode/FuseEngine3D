#pragma once

namespace Fuse {
  struct FUSE_API AppInstance {
    FUSE_INLINE void RunMainLoop() {
      while(true) {
        FUSE_INFO("this is a info!");
      }
    }
  };
}