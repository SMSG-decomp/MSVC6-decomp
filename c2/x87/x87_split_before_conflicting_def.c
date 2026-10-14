int __fastcall x87_split_before_conflicting_def(c2_symbol *reg,c2_tuple *t)

{
  c2_operand *pcVar1;
  c2_block *pcVar2;
  c2_bitset *bs;
  c2_tuple *t_00;
  
  if ((t->flags & 1) != 0) {
    while (pcVar1 = find_src_reg_operand(reg,t), pcVar1 == (c2_operand *)0x0) {
      do {
        t = t->prev;
      } while ((t->flags & 1) == 0);
    }
    t_00 = t->prev;
    if ((t_00->flags & 1) != 0) {
      while (((t_00->flags13 != '\0' || (t_00->op == 0x163)) || (t_00->op == 0x164))) {
        pcVar1 = t_00->dst;
        if ((((pcVar1 != (c2_operand *)0x0) && ((pcVar1->type & 0xf000) == 0x4000)) &&
            ((pcVar1->kind == '\x01' &&
             ((((pcVar1->u18).reg)->cls == '\x02' && (t_00->op != 0x163)))))) &&
           ((pcVar1->u18).reg != reg)) {
          pcVar2 = tuple_get_block_nonnull(t_00);
          pcVar2->flags = pcVar2->flags | 0x40000;
          bs = bitset_new(6);
          bitset_set(bs,reg->id);
          insert_split_marker_after_spill(t,bs);
          insert_split_marker_after_spill(t->prev,bs);
          bitset_free(bs);
          return 1;
        }
        t_00 = t_00->prev;
        if ((t_00->flags & 1) == 0) {
          return 0;
        }
      }
    }
  }
  return 0;
}

