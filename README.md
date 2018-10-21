# hash_subdomain

[![Build Status](https://travis-ci.org/mahori/hash_subdomain.svg?branch=master)](https://travis-ci.org/mahori/hash_subdomain)

以下の勉強のために作ったプログラムです．
* [Standard C++ Library](http://www.cplusplus.com/reference/) - `std::hash`
* [Boost C++ Libraries](https://www.boost.org/) - [Program Options](https://www.boost.org/doc/libs/release/libs/program_options/)
* [CMake](https://cmake.org/)
* [Google Test](https://github.com/google/googletest)
  * [Google Test](https://github.com/google/googletest/tree/master/googletest)
  * [Google Mock](https://github.com/google/googletest/tree/master/googlemock)
* [Travis CI](https://travis-ci.org/)

相手先のドメインごとにサブドメインを使いわけたいとき`examplecom`や`exampleorg`といったわかりやすいサブドメインを用意することもできますが，もう少しわかりにくいサブドメインをつくりたいときにこのプログラムを使います．

| 相手先ドメイン   | サブドメイン   |
|------------------|----------------|
| `example.com`    | `ajt`          |
| `example.org`    | `zgw`          |
| `example.net`    | `tbz`          |

このプログラムに与える`--length`オプションによって以下のようなサブドメインを作ることができます．

| `--length` | サブドメイン     | 種類    |
|------------|------------------|---------|
| 2          | `aa` 〜 `zz`     | 676     |
| 3          | `aaa` 〜 `zzz`   | 17,576  |
| 4          | `aaaa` 〜 `zzzz` | 456,976 |

## Build
```sh
$ mkdir build
$ cd build
$ cmake ..
$ make
```

## Usage
```sh
$ echo 'text to hash' \
    | hash_subdomain \
        --length <subdomain length> \
        --user <user name> \
        --domain <domain name>
```
`--user`と`--domain`は省略可能です．

## Example
```sh
$ echo 'example.com' | hash_subdomain --length 3 --user foo --domain example.org
hashed subdomain = ajt
mail address     = foo@ajt.example.org
```
```sh
$ echo 'example.net' | hash_subdomain --length 2
hashed subdomain = bz
```

## Note
* `std::hash`でハッシュ値を求めたあと剰余演算をしていますので一様になっている保証はありません．
