#include "../include/Status.h"

const char* bfish::Status::error_message[] = {
    "Success",
    "BF_EXCEPTION_LOW_BOUND",
    "Error while initialize SDL2!",
    "BF_WARNING_LOW_BOUND",
    "BF_CRITICAL_LOW_BOUND"
};

bool bfish::is_successful(Status::fr_t r)
{
  return (r == Status::BF_OK);
}


bool bfish::is_warning(Status::fr_t r) {
  return (r > Status::BF_WARNING) && (r < Status::BF_CRITICAL);
}


bool bfish::is_critical(Status::fr_t r) {
  return (r > Status::BF_CRITICAL);
}
