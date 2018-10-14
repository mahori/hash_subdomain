#include "MailAddress.hpp"
#include <sstream>
#include <string>

using std::string;
using std::ostringstream;

MailAddress::MailAddress(const string& username, const string& subdomain, const string& domain)
  : username_(username)
  , subdomain_(subdomain)
  , domain_(domain)
{
}

string MailAddress::get(void) const
{
  ostringstream ss;

  ss << username_;
  ss << '@';
  ss << subdomain_;
  ss << '.';
  ss << domain_;

  return ss.str();
}
