#ifndef SUBDOMAIN_H
#define SUBDOMAIN_H

#include <cstddef>
#include <string>

class Subdomain
{
public:
  Subdomain(const std::string& domain, std::size_t length);
  std::string get(void) const;

private:
  std::size_t length_;
  std::string domain_;
  std::size_t hash_;
  std::size_t total_;
};

#endif  // SUBDOMAIN_H
