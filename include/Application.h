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
  static fr_t compiled_version(SDL_version* ver);
  static fr_t linked_version(SDL_version* ver);
  static fr_t run(const u32 flags);
  static fr_t err(const char* msg);
  
 private:
  static fr_t init(const u32 flags);




 private:
  Application(void) = delete;
  virtual ~Application(void) = delete;
  Application(const Application& app) = delete;
  Application& operator=(const Application& app) = delete;
  Application(const Application&& app) = delete;
  Application& operator=(const Application&& app) = delete;
  
};


#endif
