void delayload_copy_iat(IMAGE_THUNK_DATA32 *pitdDst,IMAGE_THUNK_DATA32 *pitdSrc)

{
  IMAGE_THUNK_DATA32 *p;
  int count;
  uint *entry;
  
  count = 0;
  entry = pitdDst->Function;
  p = pitdDst;
  while (entry != (uint *)0x0) {
    p = p + 1;
    count = count + 1;
    entry = p->Function;
  }
  for (; count != 0; count = count + -1) {
    *pitdDst = *pitdSrc;
    pitdSrc = pitdSrc + 1;
    pitdDst = pitdDst + 1;
  }
  return;
}

