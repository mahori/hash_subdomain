#include "MailAddress.hpp"
#include <sstream>
#include <string>

using namespace std;

MailAddress::MailAddress(const string& username, const string& subdomain, const string& maindomain)
  : username_(username)
  , subdomain_(subdomain)
  , maindomain_(maindomain)
{
}

string MailAddress::get(void) const
{
  ostringstream ss;

  ss << username_;
  ss << '@';
  ss << subdomain_;
  ss << '.';
  ss << maindomain_;

  return ss.str();
}
