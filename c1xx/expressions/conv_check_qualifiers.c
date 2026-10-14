int __cdecl conv_check_qualifiers(uint op,uint target_quals,uint source_quals,int rank_flag)

{
  bool bVar1;
  
  if ((((target_quals ^ source_quals) & 0x3e0) != 0) && ((source_quals & 0x3e0) != 0)) {
    bVar1 = false;
    if (((target_quals & 0x40) == 0) && ((source_quals & 0x40) != 0)) {
      diag_error(0x10c,op,0x30);
      bVar1 = true;
    }
    if (((target_quals & 0x20) == 0) && ((source_quals & 0x20) != 0)) {
      diag_error(0x10c,op,0x2f);
      return 0;
    }
    if (bVar1) {
      return 0;
    }
  }
  return 2 - (uint)(rank_flag != 0);
}

