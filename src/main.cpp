#include <cstddef>
#include <iostream>
#include <string>
#include <boost/program_options.hpp>
#include "MailAddress.hpp"
#include "Subdomain.hpp"

namespace bpo = boost::program_options;

int main(int argc, char* argv[])
{
  std::size_t length;
  bpo::options_description desc("options");
  desc.add_options()
    ("help",                                     "show help")
    ("length", bpo::value<std::size_t>(&length), "subdomain length")
    ("user",   bpo::value<std::string>(),        "user name")
    ("domain", bpo::value<std::string>(),        "domain name")
    ;

  bpo::variables_map vm;
  bpo::store(bpo::parse_command_line(argc, argv, desc), vm);
  bpo::notify(vm);

  if (vm.count("help")) {
    std::cerr << desc << std::endl;
    return 1;
  }

  std::string text;
  std::cin >> text;

  Subdomain subdomain(text, length);
  std::string hashedSubdomain = subdomain.get();

  std::cout << "hashed subdomain = " << hashedSubdomain << std::endl;

  if (vm.count("user") && vm.count("domain")) {
    MailAddress mailAddress(vm["user"].as<std::string>(), hashedSubdomain, vm["domain"].as<std::string>());

    std::cout << "mail address     = " << mailAddress.get() << std::endl;
  }

  return 0;
}
