c2_operand * __fastcall find_dst_clobbering_reg(c2_tuple *t,c2_symbol *reg)

{
  c2_operand *pcVar1;
  c2_symbol *pcVar2;
  uint32_t uVar3;
  c2_symbol *dst_reg;
  
  pcVar1 = t->dst;
  pcVar2 = reg->storage;
  do {
    if (pcVar1 == (c2_operand *)0x0) {
      return (c2_operand *)0x0;
    }
    if (pcVar1->kind == '\x01') {
      dst_reg = (pcVar1->u18).reg;
      if (dst_reg->storage == pcVar2) {
        if (dst_reg == reg) {
          return pcVar1;
        }
        if ((dst_reg->offset < reg->size + reg->offset) &&
           (reg->offset < dst_reg->size + dst_reg->offset)) {
          return pcVar1;
        }
      }
    }
    else if ((pcVar1->kind == '\n') &&
            (uVar3 = bitset_test((c2_bitset *)pcVar1->sym,pcVar2->id), uVar3 != 0)) {
      return pcVar1;
    }
    pcVar1 = pcVar1->next;
  } while( true );
}

