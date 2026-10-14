uint __cdecl
fold_check_subtract_overflow(uint a_lo,int a_hi,uint b_lo,int b_hi,int is_unsigned,uint size)

{
  uint uVar1;
  
  if ((is_unsigned == 0) && (-1 < b_hi != -1 < a_hi)) {
    uVar1 = fold_add_overflows(a_lo,a_hi,-b_lo,-(b_hi + (uint)(b_lo != 0)),0,size);
    return uVar1;
  }
  return 0;
}

