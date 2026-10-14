int __fastcall shift_by_constant_to_mul(c2_tuple *t)

{
  ushort type;
  c2_operand *pcVar1;
  int64_t iVar2;
  uint64_t uVar3;
  
  pcVar1 = t->src->next;
  if ((t->op == 0x171) && (pcVar1->kind == '\a')) {
    type = t->type;
    if (((int)pcVar1->tag < 1) &&
       (((int)pcVar1->tag < 0 || ((pcVar1->u18).reg < (c2_symbol *)((type & 0xfff) << 3))))) {
      iVar2 = allshl((uint8_t)(pcVar1->u18).lo,0,1);
    }
    else {
      iVar2 = 0;
    }
    uVar3 = const_normalize(type,(uint32_t)iVar2,(int32_t)((ulonglong)iVar2 >> 0x20));
    (pcVar1->u18).lo = (uint32_t)uVar3;
    pcVar1->type = type;
    pcVar1->tag = (uint32_t)(uVar3 >> 0x20);
    t->op = 0x16f;
    return 1;
  }
  return 0;
}

