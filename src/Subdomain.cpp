#include "Subdomain.hpp"

#include <cstddef>
#include <memory>
#include <string>
#include "Utils.hpp"

using namespace std;

template <class T>
Subdomain<T>::Subdomain(size_t length, shared_ptr<T> hash, const string& domain)
  : length_(length)
  , hash_(hash)
  , domain_(domain)
{
}

template <class T>
string Subdomain<T>::get(void) const
{
  if (length_) {
    auto hash_size  = hash_->size();
    auto hash_value = hash_->hash(domain_);

    return ::get_alphabets(hash_size, hash_value);
  } else {
    return "";
  }
}

#ifdef MAHORI_TEST
#include "../test/MockHash.hpp"
template class Subdomain<MockHash>;
#else
#include "../src/Hash.hpp"
template class Subdomain<Hash>;
#endif
