#pragma once

using uint = unsigned int;
using byte = unsigned char;
using ulong = unsigned long;

class Bits
{
public:
  Bits();
  ~Bits();


public:
  static int Length(uint* value, int length);
  static int LeadingZeros(uint value);
  static int Compare(uint* left, int leftLength, uint right);
  static int Compare(uint* left, int leftLength, uint* right, int rightLength);
  static int Compare(uint* left, int leftLength, uint* right, int rightLength, int rightOffset);
  static uint* OnesComplement(uint* value, int length);
  static uint* TwosComplement(uint* value, int length);
  static byte* TwosComplement(byte* value, int length);
  static ulong Abs(long value);
  static uint  Abs(int value);
};

