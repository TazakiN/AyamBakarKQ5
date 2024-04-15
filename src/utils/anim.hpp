#ifndef ANIM_HPP
#define ANIM_HPP

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <sstream>
#include <vector>
#include "pcolor.hpp"


string title1;

string code1;

string title2;

string code2;

string homeImage;

string homePage1;

string homePage2;

string welcome;

string peternak;

string peternak2;

string petani;

string petani2;

string walikota;

string walikota2;

void printLoadingAnimation();

void printAnimation(const string& frame1, const string& frame2, int numFrames, int delay);

#endif 
