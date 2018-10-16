#ifndef SUBDOMAIN_H
#define SUBDOMAIN_H

#include <cstddef>
#include <memory>
#include <string>
#include "Utils.hpp"

template <class Hash>
class Subdomain
{
public:
  Subdomain(std::size_t length, std::shared_ptr<Hash> hash, const std::string& domain)
    : length_(length)
    , hash_(hash)
    , domain_(domain)
  {
  }

  std::string get(void) const
  {
    if (length_) {
      std::size_t hash_size  = hash_->size();
      std::size_t hash_value = hash_->hash(domain_);

      return ::get_alphabets(hash_size, hash_value);
    } else {
      return "";
    }
  }

private:
  std::size_t           length_;
  std::shared_ptr<Hash> hash_;
  std::string           domain_;
};

#endif  // SUBDOMAIN_H
