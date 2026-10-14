longlong __allmul(uint32_t a_lo,int32_t a_hi,uint32_t b_lo,int32_t b_hi)

{
  if (b_hi == 0 && a_hi == 0) {
    return (ulonglong)a_lo * (ulonglong)b_lo;
  }
  return CONCAT44((int)((ulonglong)a_lo * (ulonglong)b_lo >> 0x20) + a_hi * b_lo + a_lo * b_hi,
                  (int)((ulonglong)a_lo * (ulonglong)b_lo));
}

