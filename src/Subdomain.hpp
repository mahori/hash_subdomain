#ifndef SUBDOMAIN_H
#define SUBDOMAIN_H

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
      std::size_t hash_size = hash_->size();
      std::size_t hash_value = hash_->hash(domain_);

      return ::get_alphabets(hash_size, hash_value);
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
