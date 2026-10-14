int __fastcall reader_value_has_side_effects(c2_operand *op)

{
  c2_tuple *n;
  c2_operand *pcVar1;
  int iVar2;
  uint32_t uVar3;
  
  if (op->kind == '\x06') {
    op = op->base;
  }
  n = op->sym->def;
  iVar2 = node_has_side_effects((c2_node *)n);
  if (iVar2 != 0) {
    return 1;
  }
  for (pcVar1 = n->dst; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
    if ((((1 << (pcVar1->kind & 0x1f) & 6U) != 0) && (pcVar1->sym->def != (c2_tuple *)0x0)) &&
       (uVar3 = temp_operand_piece_mismatch(pcVar1), uVar3 != 0)) {
      return 1;
    }
  }
  pcVar1 = n->src;
  do {
    if (pcVar1 == (c2_operand *)0x0) {
      return 0;
    }
    if (((1 << (pcVar1->kind & 0x1f) & 6U) == 0) || (pcVar1->sym->def == (c2_tuple *)0x0)) {
      if ((pcVar1->kind == 2) && ((pcVar1->sym->flags7 & 1) != 0)) {
        return 1;
      }
    }
    else {
      uVar3 = temp_operand_piece_mismatch(pcVar1);
      if (uVar3 != 0) {
        return 1;
      }
      iVar2 = reader_value_has_side_effects(pcVar1);
      if (iVar2 != 0) {
        return 1;
      }
    }
    pcVar1 = pcVar1->next;
  } while( true );
}

