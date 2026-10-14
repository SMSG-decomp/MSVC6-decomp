int __fastcall switch_jump_table_size(int ncases,uint32_t span)

{
  uint uVar1;
  
  uVar1 = span + (g_opt_favor_speed != 0) + 7 + ncases * 4;
  if (0x1fffffff < span) {
    return 0x1fffffff;
  }
  if (span * 4 < uVar1) {
    uVar1 = span * 4;
  }
  return uVar1 + 0xb;
}

