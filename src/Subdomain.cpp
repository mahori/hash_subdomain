#include "Subdomain.hpp"
#include <cmath>
#include <cstddef>
#include <memory>
#include <string>
#include "Hash.hpp"

constexpr char kCharacters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                                'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                                'u', 'v', 'w', 'x', 'y', 'z'};
constexpr std::size_t kSize = sizeof(kCharacters) / sizeof(char);

namespace
{

std::string get_character(std::size_t value, std::size_t current)
{
  current /= kSize;

  if (current < kSize) {
    return std::string(1, kCharacters[value]);
  }

  std::string s(1, kCharacters[value/current]);
  s += get_character(value % current, current);

  return s;
}

std::string get_subdomain(std::size_t hash, std::size_t total)
{
  return get_character(hash, total);
}

}  // anonymous namespace

Subdomain::Subdomain(std::shared_ptr<Hash> hash, const std::string& domain, std::size_t length)
  : hash_(hash)
  , domain_(domain)
  , length_(length)
{
}

std::string Subdomain::get(void) const
{
  if (length_) {
    std::size_t total = pow(kSize, length_);
    hash_->setMax(total);
    std::size_t hash = hash_->hash(domain_);

    return get_subdomain(hash, total);
  } else {
    return "";
  }
}
