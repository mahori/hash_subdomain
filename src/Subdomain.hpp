#ifndef SUBDOMAIN_H
#define SUBDOMAIN_H

#include <cmath>
#include <cstddef>
#include <memory>
#include <string>
#include "Utils.hpp"

template <typename Hash>
class Subdomain
{
public:
  Subdomain(std::shared_ptr<Hash> hash, const std::string& domain, std::size_t length)
    : hash_(hash)
    , domain_(domain)
    , length_(length)
  {
  }

  std::string get(void) const
  {
    if (length_) {
      std::size_t total = std::pow(26, length_);
      std::size_t hash = hash_->hash(domain_, total);

      return ::get_subdomain(hash, total);
    } else {
      return "";
    }
  }

private:
  std::shared_ptr<Hash> hash_;
  std::size_t length_;
  std::string domain_;
};

#endif  // SUBDOMAIN_H
