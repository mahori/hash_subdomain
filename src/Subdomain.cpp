#include "Subdomain.hpp"

#include <cstddef>
#include <memory>
#include <string>
#include "Utils.hpp"

#ifdef MAHORI_TEST
#include "../test/MockHash.hpp"
#else
#include "../src/Hash.hpp"
#endif

template <class T>
Subdomain<T>::Subdomain(std::size_t length, std::shared_ptr<T> hash, const std::string& domain)
  : length_(length)
  , hash_(hash)
  , domain_(domain)
{
}

template <class T>
std::string Subdomain<T>::get(void) const
{
  if (length_) {
    std::size_t hash_size  = hash_->size();
    std::size_t hash_value = hash_->hash(domain_);

    return ::get_alphabets(hash_size, hash_value);
  } else {
    return "";
  }
}

#ifdef MAHORI_TEST
template class Subdomain<MockHash>;
#else
template class Subdomain<Hash>;
#endif
