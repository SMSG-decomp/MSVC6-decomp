c2_operand * __fastcall find_src_overlapping_reg(c2_tuple *t,c2_symbol *reg)

{
  c2_operand *pcVar1;
  c2_symbol *src_reg;
  
  pcVar1 = t->src;
  do {
    if (pcVar1 == (c2_operand *)0x0) {
      return (c2_operand *)0x0;
    }
    if ((pcVar1->kind == '\x01') && (src_reg = (pcVar1->u18).reg, src_reg->storage == reg->storage))
    {
      if (src_reg == reg) {
        return pcVar1;
      }
      if ((src_reg->offset < reg->size + reg->offset) &&
         (reg->offset < src_reg->size + src_reg->offset)) {
        return pcVar1;
      }
    }
    pcVar1 = pcVar1->next;
  } while( true );
}

