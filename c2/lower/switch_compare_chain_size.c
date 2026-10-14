int __fastcall switch_compare_chain_size(c2_switch_case_range *cases,int ncases)

{
  uint32_t uVar1;
  int iVar2;
  int iVar3;
  int local_4;
  
  iVar3 = 0;
  local_4 = ncases;
  if (ncases == 0) {
    return 0;
  }
  do {
    uVar1 = (uint32_t)(char)cases->first;
    if ((uVar1 != cases->first) || (iVar2 = 3, (int)uVar1 >> 0x1f != cases->first_high)) {
      iVar2 = 6;
    }
    iVar3 = iVar2 + 3 + iVar3;
    if ((cases->first != cases->last) || (cases->first_high != cases->last_high)) {
      uVar1 = (uint32_t)(char)cases->last;
      if ((uVar1 != cases->last) || (iVar2 = 3, (int)uVar1 >> 0x1f != cases->last_high)) {
        iVar2 = 6;
      }
      iVar3 = iVar2 + 3 + iVar3;
    }
    cases = cases->next;
    local_4 = local_4 + -1;
  } while (local_4 != 0);
  return iVar3;
}

