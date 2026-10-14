void __fastcall bitfield_clone_tuple_tree(c2_tuple *t)

{
  c2_operand *pcVar1;
  c2_symbol *sym;
  c2_operand *new_op;
  
  pcVar1 = t->dst;
  if (((1 << (pcVar1->kind & 0x1f) & 6U) != 0) && (pcVar1->sym->def != (c2_tuple *)0x0)) {
    new_op = operand_new_temp(pcVar1->type);
    tuple_replace_dst(t,pcVar1,new_op);
    sym = new_op->sym;
    if (sym->storage->part_next == (c2_symbol *)0x0) {
      sym->def = t;
    }
    else {
      symbol_mark_overlapping_parts(sym,t);
    }
  }
  for (pcVar1 = t->src; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
    if ((pcVar1->flags9 & 1) == 0) {
      bitfield_clone_leaf(pcVar1);
    }
    else {
      bitfield_clone_tuple_tree((c2_tuple *)pcVar1);
    }
  }
  return;
}

