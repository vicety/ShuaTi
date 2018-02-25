#ifndef HUMAN_H
#define HUMAN_H

#include<iostream>
using namespace std;

class Human{
	public:
		virtual void move() = 0;
		virtual Human attack() = 0;
		virtual ~Human();
	private:
		mutable money;
		mutable hp;
		mutable att;
		Human();
		Human&();
		Human& operator = (const Human&);
};
