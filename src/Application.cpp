#include "../include/Application.h"

using fr_t = typename bfish::Status::fr_t;


fr_t
bfish::Application::init(u32 flags)
{
  fr_t _ = Status::BF_OK;
  
  if (SDL_Init(flags) != 0)
    _ = Status::BF_INIT;
  
  return _;
}


fr_t
bfish::Application::run(u32 flags)
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
