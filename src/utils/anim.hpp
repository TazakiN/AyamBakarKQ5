#ifndef ANIM_HPP
#define ANIM_HPP

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <sstream>
#include <vector>
#include "pcolor.hpp"


extern string title1;

extern string code1;

extern string title2;

extern string code2;

extern string homeImage;

extern string homePage1;

extern string homePage2;

extern string welcome;

extern string peternak;

extern string peternak2;

extern string petani;

extern string petani2;

extern string walikota;

extern string walikota2;

void printLoadingAnimation();

void printAnimation(const string& frame1, const string& frame2, int numFrames, int delay);


#endif 
