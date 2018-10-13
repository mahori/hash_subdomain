#include <iostream>
#include <string>
#include "MailAddress.hpp"
#include "ProgramOptions.hpp"
#include "Subdomain.hpp"

int main(int argc, char* argv[])
{
  ProgramOptions po(argc, argv);

  if (po.hasHelp()) {
    std::cerr << po.helpLines() << std::endl;
    return 1;
  }

  std::string text;
  std::cin >> text;

  Subdomain subdomain(text, po.length());
  std::string hashedSubdomain = subdomain.get();

  std::cout << "hashed subdomain = " << hashedSubdomain << std::endl;

  std::string user(po.user());
  std::string domain(po.domain());

  if (!user.empty() && !domain.empty()) {
    MailAddress ma(user, hashedSubdomain, domain);

    std::cout << "mail address     = " << ma.get() << std::endl;
  }

  return 0;
}
