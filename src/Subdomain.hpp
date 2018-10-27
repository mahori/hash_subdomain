#ifndef SUBDOMAIN_H
#define SUBDOMAIN_H

#include <cstddef>
#include <memory>
#include <string>

template <class T>
class Subdomain
{
public:
  Subdomain(std::size_t length, std::shared_ptr<T> hash, const std::string& domain);

  std::string get(void) const;

private:
  std::size_t        length_;
  std::shared_ptr<T> hash_;
  std::string        domain_;
};

#endif  // SUBDOMAIN_H
