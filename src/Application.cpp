#include "../include/Application.h"

using fr_t = typename bfish::Status::fr_t;

/// PUBLIC ---------------------------------------------------------------------
fr_t
bfish::Application::compiled_version(SDL_version* ver)
{
  fr_t _ = Status::BF_OK;
  
  SDL_VERSION(ver);
  
  return _;
}


fr_t
bfish::Application::linked_version(SDL_version* ver)
{
  fr_t _ = Status::BF_OK;

  SDL_GetVersion(ver);
  
  return _;
}


fr_t
bfish::Application::run(const u32 flags)
{
  fr_t _ = Status::BF_OK;

  // Init
  _ = Application::init(flags);
  if (Status::BF_OK != _) {
    Application::err(Status::error_message[_]);
    goto exit;
  }

  // Do stuff

  // Event loop
  SDL_Event event;
  bool want_quit;
  want_quit = false;
  while (!want_quit) {
    SDL_WaitEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
      want_quit = true;
      break;
    }
  }
  
  // Quit
 exit:
  return _;
}


fr_t
bfish::Application::err(const char* msg)
{
  fr_t _ = Status::BF_OK;
  if (msg == NULL)
    printf("%s\n", SDL_GetError());
  else 
    printf(msg, "\n%s\n", SDL_GetError());
  
  return _;
}



/// PRIVATE --------------------------------------------------------------------
fr_t
bfish::Application::init(const u32 flags)
{
  fr_t _ = Status::BF_OK;
  
  if (SDL_Init(flags) != 0)
    _ = Status::BF_INIT;
  
  return _;
}
