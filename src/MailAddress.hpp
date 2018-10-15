#ifndef MAIL_ADDRESS_H
#define MAIL_ADDRESS_H

#include <string>

class MailAddress
{
public:
  MailAddress(const std::string& username, const std::string& subdomain, const std::string& maindomain);
  std::string get(void) const;

private:
  std::string username_;
  std::string subdomain_;
  std::string maindomain_;
};

#endif  // MAIL_ADDRESS_H
