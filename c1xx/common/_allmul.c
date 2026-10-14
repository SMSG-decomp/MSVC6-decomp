longlong _allmul(uint a_lo,int a_hi,uint b_lo,int b_hi)

{
  if (b_hi == 0 && a_hi == 0) {
    return (ulonglong)a_lo * (ulonglong)b_lo;
  }
  return CONCAT44((int)((ulonglong)a_lo * (ulonglong)b_lo >> 0x20) + a_hi * b_lo + a_lo * b_hi,
                  (int)((ulonglong)a_lo * (ulonglong)b_lo));
}

