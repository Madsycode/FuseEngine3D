#include <Fuse3D.h>

Fuse::AppInstance* Fuse::CreateAppInstance() {
  auto editorApp = new Fuse::AppInstance();
  return editorApp;
}