#include <cstddef>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include "Hash.hpp"
#include "MailAddress.hpp"
#include "ProgramOptions.hpp"
#include "Subdomain.hpp"

int main(int argc, char* argv[])
{
  bool hasHelp;
  std::string helpLines;
  std::size_t length;
  std::string user;
  std::string domain;

  try {
    ProgramOptions po(argc, argv);

    hasHelp = po.hasHelp();
    helpLines = po.helpLines();
    length = po.length();
    user = po.user();
    domain = po.domain();
  }
  catch (std::invalid_argument& e) {
    std::cerr << "Invalid argument: " << e.what() << std::endl;
    return 1;
  }

  if (hasHelp) {
    std::cerr << helpLines << std::endl;
    return 1;
  }

  std::string text;
  std::cin >> text;

  std::shared_ptr<Hash> hash = std::make_shared<Hash>();

  Subdomain<Hash> subdomain(hash, text, length);
  std::string hashedSubdomain = subdomain.get();

  std::cout << "hashed subdomain = " << hashedSubdomain << std::endl;

  if (!user.empty() && !domain.empty()) {
    MailAddress ma(user, hashedSubdomain, domain);

    std::cout << "mail address     = " << ma.get() << std::endl;
  }

  return 0;
}
