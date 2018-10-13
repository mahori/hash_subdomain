#include "MailAddress.hpp"
#include <sstream>
#include <string>

MailAddress::MailAddress(const std::string& username, const std::string& subdomain, const std::string& domain)
  : username_(username)
  , subdomain_(subdomain)
  , domain_(domain)
{
}

std::string MailAddress::get(void) const
{
  std::ostringstream ss;

  ss << username_;
  ss << "@";
  ss << subdomain_;
  ss << ".";
  ss << domain_;

  return ss.str();
}
