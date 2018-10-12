#include "MailAddress.hpp"
#include <sstream>
#include <string>

MailAddress::MailAddress(const std::string& user, const std::string& subdomain, const std::string& domain)
  : user_(user)
  , subdomain_(subdomain)
  , domain_(domain)
{
}

std::string MailAddress::get(void) const
{
  std::ostringstream ss;

  ss << user_;
  ss << "@";
  ss << subdomain_;
  ss << ".";
  ss << domain_;

  return ss.str();
}
