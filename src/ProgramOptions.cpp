#include "ProgramOptions.hpp"
#include <cstddef>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

using namespace std;

const char* const k_help_key   = "help";
const char* const k_length_key = "length";
const char* const k_domain_key = "domain";
const char* const k_user_key   = "user";

ProgramOptions::ProgramOptions(const vector<const char*>& args)
  : hasHelp_(false)
  , helpLines_()
  , length_(0)
  , user_()
  , domain_()

{
  po::options_description desc("options");
  desc.add_options()
    (k_help_key,                                                  "show help")
    (k_length_key, po::value<size_t>(&length_)->default_value(1), "subdomain length")
    (k_user_key,   po::value<string>(),                           "user name")
    (k_domain_key, po::value<string>(),                           "domain name")
    ;

  po::variables_map vm;
  try {
    po::store(po::parse_command_line(args.size(), args.data(), desc), vm);
  }
  catch (po::invalid_option_value& e) {
    throw invalid_argument(e.what());
  }
  po::notify(vm);

  hasHelp_ = (vm.count(k_help_key) > 0);
  if (hasHelp_) {
    ostringstream ss;
    ss << desc;
    helpLines_ = ss.str();
  }

  if (vm.count(k_user_key)) {
    user_ = vm[k_user_key].as<string>();
  }

  if (vm.count(k_domain_key)) {
    domain_ = vm[k_domain_key].as<string>();
  }
}

bool ProgramOptions::hasHelp(void) const
{
  return hasHelp_;
}

string ProgramOptions::helpLines(void) const
{
  return helpLines_;
}

size_t ProgramOptions::length(void) const
{
  return length_;
}

string ProgramOptions::user(void) const
{
  return user_;
}

string ProgramOptions::domain(void) const
{
  return domain_;
}
