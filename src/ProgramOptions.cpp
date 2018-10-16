#include "ProgramOptions.hpp"
#include <cstddef>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

using std::vector;
using invalid_argument = std::invalid_argument;
using ostringstream    = std::ostringstream;
using size_t           = std::size_t;
using string           = std::string;

const char* const kHelpKey   = "help";
const char* const kLengthKey = "length";
const char* const kDomainKey = "domain";
const char* const kUserKey   = "user";

ProgramOptions::ProgramOptions(const vector<const char*>& args)
  : hasHelp_(false)
  , helpLines_()
  , length_(0)
  , user_()
  , domain_()

{
  po::options_description desc("options");
  desc.add_options()
    (kHelpKey,                                                  "show help")
    (kLengthKey, po::value<size_t>(&length_)->default_value(1), "subdomain length")
    (kUserKey,   po::value<string>(),                           "user name")
    (kDomainKey, po::value<string>(),                           "domain name")
    ;

  po::variables_map vm;
  try {
    po::store(po::parse_command_line(args.size(), args.data(), desc), vm);
  }
  catch (po::invalid_option_value& e) {
    throw invalid_argument(e.what());
  }
  po::notify(vm);

  hasHelp_ = (vm.count(kHelpKey) > 0);

  if (hasHelp_) {
    ostringstream ss;
    ss << desc;
    helpLines_ = ss.str();
  }

  if (vm.count(kUserKey)) {
    user_ = vm[kUserKey].as<string>();
  }

  if (vm.count(kDomainKey)) {
    domain_ = vm[kDomainKey].as<string>();
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
