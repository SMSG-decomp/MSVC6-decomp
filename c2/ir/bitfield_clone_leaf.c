void __fastcall bitfield_clone_leaf(c2_operand *op)

{
  uint16_t uVar1;
  c2_tuple *n;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  c2_node *pcVar4;
  c2_symbol *pcVar5;
  
  if (((((1 << (op->kind & 0x1f) & 0x60U) != 0) &&
       ((pcVar2 = op->base, pcVar2 == (c2_operand *)0x0 ||
        (((1 << (pcVar2->kind & 0x1f) & 6U) != 0 && (pcVar2->sym->def != (c2_tuple *)0x0)))))) &&
      ((pcVar3 = op->index, pcVar3 == (c2_operand *)0x0 ||
       (((1 << (pcVar3->kind & 0x1f) & 6U) != 0 && (pcVar3->sym->def != (c2_tuple *)0x0)))))) &&
     (pcVar2 != pcVar3)) {
    op = pcVar2;
  }
  if ((1 << (op->kind & 0x1f) & 6U) != 0) {
    pcVar5 = op->sym;
    n = pcVar5->def;
    if (n != (c2_tuple *)0x0) {
      pcVar4 = bitfield_clone_tree((c2_node *)n);
      pcVar4 = node_clone((c2_node *)pcVar4[1].rank_or_prev);
      pcVar5 = symbol_get_part((c2_symbol *)pcVar4[1].op,op->type,op->type & 0xfff,pcVar5->offset);
      uVar1 = pcVar4->type;
      op->sym = pcVar5;
      (op->u18).reg = pcVar5;
      op->type = uVar1;
    }
  }
  return;
}

