int __thiscall const_compare(c2_operand *k,uint32_t v,int hi)

{
  uint32_t uVar1;
  int iVar2;
  uint32_t uVar3;
  bool bVar4;
  uint64_t uVar5;
  
  uVar5 = const_normalize(k->type,v,hi);
  uVar3 = (uint32_t)(uVar5 >> 0x20);
  uVar1 = k->tag;
  if ((k->u18).reg == (c2_symbol *)uVar5) {
    iVar2 = uVar1 - uVar3;
    bVar4 = false;
    if (iVar2 == 0) {
      return 0;
    }
  }
  else {
    iVar2 = uVar1 - uVar3;
    bVar4 = uVar1 == uVar3;
  }
  if ((bVar4 || SBORROW4(uVar1,uVar3) != iVar2 < 0) &&
     ((SBORROW4(uVar1,uVar3) != iVar2 < 0 || ((k->u18).reg < (c2_symbol *)uVar5)))) {
    return -1;
  }
  return 1;
}

