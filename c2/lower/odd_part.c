int __fastcall odd_part(int n)

{
  do {
    n = n / 2;
  } while ((n & 1U) == 0);
  return n;
}

