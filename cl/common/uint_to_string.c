int __cdecl uint_to_string(uint v,char *out,uint radix)

{
  uchar *p;
  uchar digits [36];
  int n;
  
  n = 0;
  digits[0] = '\0';
  p = digits + 1;
  do {
    _mbccpy(p,(uchar *)(s_hex_digits + v % radix));
    p = _mbsinc(p);
    v = v / radix;
  } while (v != 0);
  while( true ) {
    p = _mbsdec(digits,p);
    _mbccpy((uchar *)out,p);
    out = (char *)_mbsinc((uchar *)out);
    if (*p == '\0') break;
    n = n + 1;
  }
  return n;
}

