#include <Fuse3D.h>

Fuse::AppInstance* Fuse::CreateAppInstance() {
  auto runtimeApp = new Fuse::AppInstance();
  return runtimeApp;
}
