int __fastcall emit_operand_subtree(c2_operand *op)

{
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  uint uVar3;
  
  uVar3 = 1 << (op->kind & 0x1f);
  if ((uVar3 & 0xffe) == 0) {
    op = (c2_operand *)emit_tree_as_tuples((c2_tuple *)op);
    if ((op->flags9 & 1) != 0) {
      op = (c2_operand *)op->tag;
    }
  }
  else {
    op->flags = op->flags & 0xef;
    if (((uVar3 & 6) != 0) && (op->sym->def != (c2_tuple *)0x0)) {
      emit_tree_as_tuples(op->sym->def);
      return (int)op;
    }
    if (((((uVar3 & 0x60) != 0) &&
         ((pcVar1 = op->base, pcVar1 == (c2_operand *)0x0 ||
          (((1 << (pcVar1->kind & 0x1f) & 6U) != 0 && (pcVar1->sym->def != (c2_tuple *)0x0)))))) &&
        ((pcVar2 = op->index, pcVar2 == (c2_operand *)0x0 ||
         (((1 << (pcVar2->kind & 0x1f) & 6U) != 0 && (pcVar2->sym->def != (c2_tuple *)0x0)))))) &&
       (pcVar1 != pcVar2)) {
      emit_tree_as_tuples(op->base->sym->def);
      return (int)op;
    }
  }
  return (int)op;
}

