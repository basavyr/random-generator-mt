/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk -std=c++17 ../src/twister.cc ../tests/twister_test.cc -o twister.out
# the command above uses a special CPP flag that points the compiler to the proer SDK, so that compilation process can be successfully finished.
# this is due to a problem with the math and random header
# /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ -std=c++17 ../src/twister.cc ../tests/twister_test.cc -o twister.out
./twister.out