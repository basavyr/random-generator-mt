#include "../include/twister.hh"

//Create a seed to be feed into the mersenne twiser
//Random device generates entropy from the system's OS or the actual compiler implementation of std::random_device
static std::random_device rd;

//Debug only: generates a constant seed
//! by having a constant seed, the PNRG - Mersenne Twister will always generate the same sequence
static constexpr int seed = 1137;

//* Create the PNRG - Mersenne Twister implementation which is feeded by the random device.
static std::mt19937 mersenne{seed};

//returns an integer number with the help of a uniform distribution
int generate_int_number(int left, int right, std::mt19937 &mt)
{
    std::uniform_int_distribution<int> int_dist(left, right);
    auto int_num = int_dist(mt);
    return static_cast<int>(int_num);
}

twister::Random::Random(int l, int r)
{
    left = l;
    right = r;
}

twister::Random::~Random()
{
    //?improves time performance if destructs the random device
    // rd.~random_device(); //! doesn't work since the use of smart pointers cancels out the randomness
}

int twister::Random::get_random()
{
    return generate_int_number(left, right, mersenne);
}