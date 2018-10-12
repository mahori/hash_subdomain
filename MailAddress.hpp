#ifndef MAIL_ADDRESS_H
#define MAIL_ADDRESS_H

#include <string>

class MailAddress
{
public:
  MailAddress(const std::string& user, const std::string& subdomain, const std::string& domain);
  std::string get(void) const;

private:
  std::string user_;
  std::string subdomain_;
  std::string domain_;
};

#endif  // MAIL_ADDRESS_H
