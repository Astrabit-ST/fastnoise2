require 'mkmf'
have_library("c++") or have_library("stdc++")
have_library("fastnoise")
$CXXFLAGS = ($CXXFLAGS || "") + " -O2 -Wall "
create_makefile('fastnoise2')
