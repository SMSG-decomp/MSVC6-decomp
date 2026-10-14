void __fastcall
ra_pressure_split_candidates(c2_list_cell *cuts,c2_bitset *pressure,c2_live_range *picked)

{
  c2_bitset *a;
  c2_tuple *t;
  c2_bitset *a_00;
  c2_list_cell *pcVar1;
  c2_bitset *bs;
  uint32_t uVar2;
  c2_live_range *pcVar3;
  int iVar4;
  c2_operand *op;
  c2_bitset *dst;
  c2_bitset *dst_00;
  c2_block *b;
  c2_list_cell *pcVar5;
  
  bs = bitset_new(6);
  uVar2 = bitset_iter_next(pressure);
  while (pcVar1 = cuts, uVar2 != 0xffffffff) {
    pcVar3 = live_range_from_id(uVar2);
    if ((pcVar3->sym->cls != '\r') && (0 < pcVar3->weight)) {
      bitset_set(bs,uVar2);
    }
    uVar2 = bitset_iter_next((c2_bitset *)0x0);
  }
  for (; pcVar1 != (c2_list_cell *)0x0; pcVar1 = pcVar1->next) {
    t = (pcVar1->u04).tuple;
    if (t != (c2_tuple *)0x0) {
      a_00 = (t->next->u14).regs;
      iVar4 = bitset_intersects(a_00,bs);
      if (((iVar4 != 0) && (t->flags12 == '\x01')) &&
         (op = ra_find_rewritable_reg_source(t,picked), op != (c2_operand *)0x0)) {
        dst = bitset_clone(a_00);
        bitset_and(dst,bs);
        dst_00 = bitset_new(6);
        pcVar5 = cuts;
        do {
          if (((pcVar5->u04).tuple != (c2_tuple *)0x0) && (pcVar5 != pcVar1)) {
            a = (t->next->u14).regs;
            iVar4 = bitset_intersects(a,dst);
            if (iVar4 != 0) {
              bitset_or(dst_00,a);
            }
          }
          pcVar5 = pcVar5->next;
        } while (pcVar5 != (c2_list_cell *)0x0);
        bitset_and(dst_00,dst);
        pcVar3 = (op->u18).range;
        if ((dst_00->chunks == (c2_bitset_chunk *)0x0) || (pcVar3->weight < 1)) {
          bitset_andnot(a_00,dst);
          bitset_andnot(dst,dst_00);
          bitset_andnot(pressure,dst);
          uVar2 = pcVar3->id;
          t->flags12 = '\0';
          bitset_set(a_00,uVar2);
          bitset_set(pressure,uVar2);
          b = tuple_get_block_nonnull(t);
          if (b->loop != (c2_loop *)0x0) {
            split_mark_symbol_in_chain(b->loop,op->sym);
          }
          if ((op->flags11 & 0x80) != 0) {
            add_reference_saving(t,pcVar3,b);
          }
          operand_make_sym(op);
          op->rank = pcVar3->id;
          pcVar3->flags5 = pcVar3->flags5 | 8;
        }
        bitset_free(dst);
        bitset_free(dst_00);
      }
    }
  }
  bitset_free(bs);
  return;
}

