int __fastcall switch_dec_chain_profitable(c2_switch_case_range *cases,int ncases,uint16_t type)

{
  uint32_t uVar1;
  ushort uVar2;
  int iVar3;
  uint32_t uVar4;
  int local_4;
  
  uVar4 = 0;
  local_4 = 0;
  if (g_opt_global == 0) {
    return 0;
  }
  uVar2 = type & 0xfff;
  _type = ncases;
  if (uVar2 < 5) {
    while( true ) {
      if (_type == 0) {
        return (uint)(0 < local_4);
      }
      _type = _type + -1;
      uVar1 = cases->first;
      if ((((uVar1 != cases->last) || (cases->first_high != cases->last_high)) ||
          (cases->first_high != (int)uVar1 >> 0x1f)) || ((int)uVar1 < (int)uVar4)) break;
      iVar3 = uVar1 - uVar4;
      if ((iVar3 == 1) || (iVar3 == 2)) {
        local_4 = local_4 + 1;
      }
      if ((uVar1 != (int)(char)cases->first) && ((char)iVar3 == iVar3)) {
        local_4 = local_4 + 1;
      }
      cases = cases->next;
      uVar4 = uVar1;
    }
  }
  return 0;
}

