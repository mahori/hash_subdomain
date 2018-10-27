#include <algorithm>
#include <cstddef>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
#include "Hash.hpp"
#include "MailAddress.hpp"
#include "ProgramOptions.hpp"
#include "Subdomain.hpp"
#include "Utils.hpp"

using namespace std;

int main(int argc, char* argv[])
{
  bool   hasHelp;
  string helpLines;
  size_t length;
  string user;
  string domain;

  vector<const char*> args(argc);
  copy_n(argv, argc, args.begin());

  try {
    ProgramOptions po(args);
    hasHelp   = po.hasHelp();
    helpLines = po.helpLines();
    length    = po.length();
    user      = po.user();
    domain    = po.domain();
  }
  catch (invalid_argument& e) {
    cerr << "invalid argument: " << e.what() << endl;
    return 1;
  }

  if (hasHelp) {
    cerr << helpLines << endl;
    return 1;
  }

  string text;
  cin >> text;

  auto hash_size = ::hash_size(length);
  auto hash = make_shared<Hash>(hash_size);

  Subdomain<Hash> sd(length, hash, text);
  auto subdomain = sd.get();
  cout << "hashed subdomain = " << subdomain << endl;

  if (!user.empty() && !domain.empty()) {
    MailAddress ma(user, subdomain, domain);
    cout << "mail address     = " << ma.get() << endl;
  }

  return 0;
}
