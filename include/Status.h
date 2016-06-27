#ifndef INCLUDE__STATUS_H
#define INCLUDE__STATUS_H

namespace bfish
{
  class Status;
}

class bfish::Status
{
 public:
  typedef enum {
    BF_OK = 0,
    BF_EXCEPTION,
    BF_INIT,

    BF_WARNING,

    BF_CRITICAL,
    BF_HIGHBOUND
  } fr_t;

  static const char *error_message[BF_HIGHBOUND];




 private:
  Status(void) = delete;
  virtual ~Status(void) = delete;
  Status(const Status&) = delete;
  Status& operator=(const Status&) = delete;
  Status(const Status&&) = delete;
  Status& operator=(const Status&&) = delete;
};

namespace bfish
{
  bool is_successful(Status::fr_t r);
  bool is_warning(Status::fr_t r);
  bool is_critical(Status::fr_t r);  
}

#endif
