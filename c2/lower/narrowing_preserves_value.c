int __fastcall narrowing_preserves_value(c2_tuple *t,uint32_t size)

{
  c2_operand *k;
  uint8_t uVar1;
  uint uVar2;
  int iVar3;
  c2_tuple *t_00;
  int iVar4;
  c2_operand *local_4;
  
  uVar2 = t->type & 0xfff;
  if (uVar2 != size) {
    k = t->src->next;
    if (k->kind != '\a') {
      return 0;
    }
    local_4 = (c2_operand *)t;
    iVar3 = const_leading_zero_bits(k);
    iVar4 = (uVar2 - size) * 8;
    if (iVar3 < iVar4) {
      return 0;
    }
    t_00 = find_next_use_of_dst(t,&local_4);
    uVar1 = x86_fixed_reg_class(t_00);
    if (((uVar1 != '\x01') && (uVar1 != '\x02')) && (iVar3 < iVar4 + 1)) {
      return 0;
    }
  }
  return 1;
}

