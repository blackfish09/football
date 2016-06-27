/// std ------------------------------------------------------------------------
#include <cstdio>
#include <ctime>
#include <cmath>
#include <cstdlib>

/// Deps -----------------------------------------------------------------------
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>


/// App headers ----------------------------------------------------------------
#include "../include/Application.h"
#include "../include/Status.h"

/// main() ---------------------------------------------------------------------
int
main(int argc, char *argv[])
{
  bfish::Status::fr_t _;

  // Init timer for user
  time_t start;
  time(&start);

  // Init SDL2 and start application loop
  SDL_SetMainReady();
  _ = bfish::Application::run(SDL_INIT_TIMER | SDL_INIT_AUDIO | \
			      SDL_INIT_VIDEO | SDL_INIT_EVENTS);

  // Show some messages
  int hrs, min, sec;
  printf("Application return code = %d (%s)\n", (int)_, bfish::Status::error_message[_]);
  sec = (int)ceil(difftime(time(NULL), start));
  hrs = sec / 3600;
  sec = (hrs == 0) ? sec : sec - hrs * 3600;
  min = sec / 60;
  sec = (min == 0) ? sec : sec - min * 60;
  printf("Application running for = %d hours, %d minutes, %d seconds\n",
	 hrs, min, sec);
  
  return (int)_;
}
