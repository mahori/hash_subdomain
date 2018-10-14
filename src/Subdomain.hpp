#ifndef SUBDOMAIN_H
#define SUBDOMAIN_H

#include <cstddef>
#include <memory>
#include <string>

class Hash;

class Subdomain
{
public:
  Subdomain(std::shared_ptr<Hash> hash, const std::string& domain, std::size_t length);

  std::string get(void) const;

private:
  std::shared_ptr<Hash> hash_;
  std::size_t length_;
  std::string domain_;
};

#endif  // SUBDOMAIN_H
