int __fastcall function_is_inline_candidate(c2_fe_symbol *f,int forced)

{
  uint uVar1;
  
  uVar1 = f->fn_flags;
  if ((((uVar1 & 0x40) != 0) &&
      (((forced != 0 || ((uVar1 & 0x2080) != 0)) && ((f->attrs & 0x1400) == 0)))) &&
     ((uVar1 & 0x200) == 0)) {
    return 1;
  }
  return 0;
}

