#pragma once
#include "AppInstance.h"
 
namespace Fuse {
  extern AppInstance* CreateAppInstance();
}  

int main(int argc, char** argv) {   
  auto appInstance = Fuse::CreateAppInstance();
  appInstance->RunMainLoop();
  FUSE_DELETE(appInstance);
  return EXIT_SUCCESS;
}