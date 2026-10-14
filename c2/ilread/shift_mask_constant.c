uint64_t __fastcall shift_mask_constant(c2_tuple *t)

{
  uint8_t count;
  int64_t iVar1;
  uint64_t uVar2;
  
  count = (uint8_t)(t->src->next->u18).lo;
  if (t->op != 0x171) {
    iVar1 = allshl(count,-1,0xffffffff);
    uVar2 = const_normalize(t->type,(uint32_t)iVar1,(int32_t)((ulonglong)iVar1 >> 0x20));
    return uVar2;
  }
  uVar2 = const_normalize(t->type & 0xfff | 0x2000,0xffffffff,-1);
  uVar2 = aullshr(count,(uint32_t)(uVar2 >> 0x20),(uint32_t)uVar2);
  return uVar2;
}

