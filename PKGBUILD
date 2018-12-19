# Maintainer: Sandy Marko Knauer <smk@knasan.de>

pkgname=rrn
pkgver=0.0.1
_pkgver=
pkgrel=1
pkgdesc='recursive rename tool written in C++ and boost library'
arch=('x86_64')
license=('GPL3')
url='http://github.com/knasan/rrn'
makedepends=('gcc' 'boost-libs' 'cmake')
provides=('rrn')
source=("https://github.com/knasan/rrn/archive/${pkgver}.tar.gz")
sha256sums=('eb27468f5805272dde101d06a1f22912ea518e8ebe733194a4d52c0e685d6a21')

build() {
  cd "$srcdir/${pkgname}-${pkgver}"
  mkdir -p build
  cd build
  cmake -b ../
  make
}


package() {
  cd "$srcdir/${pkgname}-${pkgver}"
  cd build
  mkdir -p "$pkgdir/usr/bin/"
  install -m755 rrn "$pkgdir/usr/bin/"
}

