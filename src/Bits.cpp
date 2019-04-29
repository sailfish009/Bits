#include "Bits.h"



Bits::Bits()
{
}


Bits::~Bits()
{
}

int Bits::Length(uint* value, int length)
{
  while (length > 0 && value[length - 1] == 0) --length;
  return length;
}

int Bits::LeadingZeros(uint value)
{
  if (value == 0) return 32;

  int count = 0;

  if ((value & 0xFFFF0000) == 0)
  {
    count += 16;
    value <<= 16;
  }

  if ((value & 0xFF000000) == 0)
  {
    count += 8;
    value <<= 8;
  }

  if ((value & 0xF0000000) == 0)
  {
    count += 4;
    value <<= 4;
  }

  if ((value & 0xC0000000) == 0)
  {
    count += 2;
    value <<= 2;
  }

  if ((value & 0x80000000) == 0)
  {
    count += 1;
  }

  return count;
}


int Bits::Compare(uint* left, int leftLength, uint right)
{
  if (leftLength == 0)
  {
    if (right == 0) return 0;
    return -1;
  }

  if (leftLength > 1) return 1;
  if (left[0] < right) return -1;
  if (left[0] > right) return 1;
  return 0;
}

int Bits::Compare(uint* left, int leftLength, uint* right, int rightLength)
{
  if (leftLength < rightLength) return -1;
  if (leftLength > rightLength) return 1;

  for (int i = leftLength - 1; i >= 0; --i)
  {
    if (left[i] < right[i]) return -1;
    if (left[i] > right[i]) return 1;
  }
  return 0;
}

int Bits::Compare(uint* left, int leftLength, uint* right, int rightLength, int rightOffset)
{
  if (leftLength < rightLength + rightOffset) return -1;
  if (leftLength > rightLength + rightOffset) return 1;

  for (int i = leftLength - 1; i >= rightOffset; --i)
  {
    if (left[i] < right[i - rightOffset]) return -1;
    if (left[i] > right[i - rightOffset]) return 1;
  }

  for (int i = rightOffset - 1; i >= 0; --i)
  {
    if (left[i] < 0) return -1;
    if (left[i] > 0) return 1;
  }
  return 0;
}

uint* Bits::OnesComplement(uint* value, int length)
{
  if (length == 0) return new uint[1] {0xFFFFFFFF};

  uint *result = new uint[length];

  for (int i = 0; i < length; ++i)
    result[i] = ~value[i];

  return result;
}

uint* Bits::TwosComplement(uint* value, int length)
{
  uint *result = new uint[length];

  auto carry = 1UL;

  for (int i = 0; i < length; ++i)
  {
    auto digit = (uint)~value[i] + carry;
    result[i] = (uint)digit;
    carry = digit >> 32;
  }

  if (carry != 0)
  {
    result = new uint[length + 1];
    result[length] = 1;
  }

  return result;
}

byte* Bits::TwosComplement(byte* value, int length)
{
  auto result = new byte[length];

  auto carry = 1U;

  for (int i = 0; i < length; ++i)
  {
    auto digit = (byte)~value[i] + carry;
    result[i] = (byte)digit;
    carry = digit >> 8;
  }

  if (carry != 0)
  {
    result = new byte[length + 1];
    result[length] = 1;
  }

  return result;
}

ulong Bits::Abs(long value)
{
  auto mask = (ulong)(value >> 63);
  return ((ulong)value^mask) - mask;
}

uint Bits::Abs(int value)
{
  auto mask = (uint)(value >> 31);
  return ((uint)value^mask) - mask;
}
