int32_t __fastcall fold_copy_into_next_use(c2_tuple *t)

{
  c2_operand *new_op;
  c2_symbol *pcVar1;
  c2_tuple *t_00;
  c2_operand *old;
  c2_symbol *sym;
  c2_tuple *pcVar2;
  int iVar3;
  c2_operand *pcVar4;
  
  pcVar4 = t->src;
  if ((((pcVar4->kind == '\x01') && (new_op = t->dst, (1 << (new_op->kind & 0x1f) & 6U) != 0)) &&
      ((pcVar1 = new_op->sym, (pcVar1->u18).expr != (c2_cse_expr *)0x0 ||
       (pcVar1->def != (c2_tuple *)0x0)))) && (t_00 = pcVar4->sym->def, t_00 != (c2_tuple *)0x0)) {
    if ((pcVar1->def == (c2_tuple *)0x0) &&
       (pcVar2 = tuple_prev_real_before_boundary(t), t_00 != pcVar2)) {
      return 0;
    }
    iVar3 = types_compatible(t->type,t_00->type);
    if ((iVar3 != 0) && (t_00->kind == '\f')) {
      old = t_00->dst;
      pcVar1 = old->sym;
      if ((pcVar1 == (old->u18).reg) && ((pcVar4->sym == pcVar1 && (pcVar1->storage == pcVar1)))) {
        pcVar4 = tuple_replace_dst(t_00,old,new_op);
        sym = pcVar4->sym;
        if (sym->def != (c2_tuple *)0x0) {
          if (sym->storage->part_next == (c2_symbol *)0x0) {
            sym->def = t_00;
          }
          else {
            symbol_mark_overlapping_parts(sym,t_00);
          }
        }
        operand_set_type(pcVar4,t_00->type);
        tuple_delete(t);
        symbol_free_chain(pcVar1);
        return 1;
      }
    }
  }
  return 0;
}

