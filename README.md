# Random Number Generator - Mersenne Twister
A random number generator implementation in `C++` using the Mersenne Twister


## Compiling the test files with the predefined scripts

The `scripts/` directory comes with some compilation scripts that run the source files in order to see if the functionality of the created classes work as intended.

However, the scripts fail to compile on MacOS Catalina if compiled with the `clang/clang++` compiler provided by Xcode. More precisely, if the `twister.sh` script was executed, which tried to compile and run the random number generator part of the project, then the following error would be thrown:

```bash
/twister.sh        
In file included from ../src/twister.cc:1:
In file included from ../src/../include/twister.hh:8:
In file included from /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/random:1637:
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/cmath:317:9: error: no member named
      'signbit' in the global namespace
using ::signbit;
      ~~^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/cmath:318:9: error: no member named
      'fpclassify' in the global namespace
using ::fpclassify;
      ~~^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/cmath:319:9: error: no member named
      'isfinite' in the global namespace; did you mean 'finite'?
using ::isfinite;
      ~~^
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.15.sdk/usr/include/math.h:749:12: note:
      'finite' declared here
extern int finite(double)
           ^
```

The random project contained the `random` and `math` header files, which apparently both have the `math.h` header file, that is not "properly" found by the compiler.

**Fix**: in order to fix this issue, an extra flag must be passed to the `clang++` compiler in the command line. Namely, this is the correct command in the script:

```bash
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk -std=c++17 ../src/twister.cc ../tests/twister_test.cc -o twister.out
```

> `-isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk` is just the extra flag passed, so that the correct SDK is pointed out to the clang compiler.

The command above uses a special CPP flag that points the compiler to the proer SDK, so that compilation process can be successfully finished. This is due to a problem with the math and random header.

___

Solution for this was found on [this](https://github.com/Homebrew/homebrew-core/issues/45061#issuecomment-541010787) issue.
