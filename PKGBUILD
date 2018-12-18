# Maintainer: Sandy Marko Knauer <smk@knasan.de>

pkgname=rrn
pkgver=0.0.1
_pkgver=
pkgrel=1
pkgdesc='recursive rename tool written in C++ and boost library'
arch=('x86_64')
license=('GPL3')
url='http://github.com/knasan/rrn'
makedepends=('git' 'gcc' 'boost-libs' 'cmake')
provides=('rrn')
source=('git://github.com/knasan/rrn.git')
#depends=('')
#optdepends=('')
sha256sums=('SKIP')
_gitname='rrn'


build() {
  cd "$srcdir/$_gitname"
  mkdir -p build
  cd build
  cmake -b ../
  make
}


package() {
  cd "$srcdir/$_gitname"
  cd build
  mkdir -p "$pkgdir/usr/bin/"
  install -m755 rrn "$pkgdir/usr/bin/"
}

