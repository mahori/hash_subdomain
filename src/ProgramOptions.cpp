#include "ProgramOptions.hpp"
#include <cstddef>
#include <stdexcept>
#include <string>
#include <sstream>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

ProgramOptions::ProgramOptions(int argc, char** argv)
  : hasHelp_(false)
  , helpLines_()
  , length_(0)
  , user_()
  , domain_()

{
  po::options_description desc("options");

  desc.add_options()
    ("help",                                                       "show help")
    ("length", po::value<std::size_t>(&length_)->default_value(1), "subdomain length")
    ("user",   po::value<std::string>(),                           "user name")
    ("domain", po::value<std::string>(),                           "domain name")
    ;

  po::variables_map vm;
  try {
    po::store(po::parse_command_line(argc, argv, desc), vm);
  }
  catch (boost::program_options::invalid_option_value& e) {
    throw std::invalid_argument(e.what());
  }

  po::notify(vm);

  hasHelp_ = (vm.count("help") > 0);

  if (hasHelp_) {
    std::ostringstream ss;
    ss << desc;
    helpLines_ = ss.str();
  }

  if (vm.count("user")) {
    user_ = vm["user"].as<std::string>();
  }

  if (vm.count("domain")) {
    domain_ = vm["domain"].as<std::string>();
  }
}

ProgramOptions::~ProgramOptions(void)
{
}

bool ProgramOptions::hasHelp(void) const
{
  return hasHelp_;
}

std::string ProgramOptions::helpLines(void) const
{
  return helpLines_;
}

std::size_t ProgramOptions::length(void) const
{
  return length_;
}

std::string ProgramOptions::user(void) const
{
  return user_;
}

std::string ProgramOptions::domain(void) const
{
  return domain_;
}
