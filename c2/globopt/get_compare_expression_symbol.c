c2_symbol * __fastcall
get_compare_expression_symbol(uint32_t op,uint16_t type,c2_operand *a,c2_operand *b)

{
  c2_symbol *pcVar1;
  uint32_t bucket;
  c2_cse_expr *pcVar2;
  uint uVar3;
  c2_bitset *pcVar4;
  c2_symbol *pcVar5;
  c2_symbol *pcVar6;
  
  cse_set_key_operands(2,a,b);
  bucket = hash_expression(op,type);
  pcVar2 = cse_lookup(bucket,op,type);
  if (pcVar2 != (c2_cse_expr *)0x0) {
    return pcVar2->sym;
  }
  pcVar2 = cse_insert(bucket,op,type);
  pcVar1 = pcVar2->sym;
  uVar3 = 1 << (a->kind & 0x1f);
  if ((uVar3 & 6) == 0) {
    if ((uVar3 & 0x60) == 0) {
      pcVar5 = (c2_symbol *)0x0;
    }
    else {
      pcVar5 = (a->u18).reg;
    }
  }
  else {
    pcVar5 = a->sym;
  }
  uVar3 = 1 << (b->kind & 0x1f);
  if ((uVar3 & 6) == 0) {
    if ((uVar3 & 0x60) == 0) {
      pcVar6 = (c2_symbol *)0x0;
    }
    else {
      pcVar6 = (b->u18).reg;
    }
  }
  else {
    pcVar6 = b->sym;
  }
  if (pcVar5 != (c2_symbol *)0x0) {
    if (pcVar5->kills == (c2_bitset *)0x0) {
      pcVar4 = bitset_new(0xd);
      pcVar5->kills = pcVar4;
    }
    bitset_set(pcVar5->kills,pcVar1->id);
  }
  if (pcVar6 != (c2_symbol *)0x0) {
    if (pcVar6->kills == (c2_bitset *)0x0) {
      pcVar4 = bitset_new(0xd);
      pcVar6->kills = pcVar4;
    }
    bitset_set(pcVar6->kills,pcVar1->id);
  }
  return pcVar1;
}

