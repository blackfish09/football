#ifndef INCLUDE__APPLICATION_H
#define INCLUDE__APPLICATION_H

#include <SDL2/SDL.h>

#include "Status.h"
#include "types.h"

namespace bfish
{
  class Application;
}

using fr_t = typename bfish::Status::fr_t;

/**
 * \brief Used to create window, handle messages
   */
class bfish::Application {
 public:
  static fr_t run(u32 flags);
  static fr_t err(const char* msg);
 private:
  Application() = delete;
  virtual ~Application() = delete;
  Application(const Application& app) = delete;
  Application& operator=(const Application& app) = delete;
  Application(const Application&& app) = delete;
  Application& operator=(const Application&& app) = delete;
  
  static fr_t init(u32 flags);
};


#endif
