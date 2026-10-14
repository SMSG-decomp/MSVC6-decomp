uint32_t __fastcall decide_tree_substitution(c2_tuple *t,c2_operand *use_opnd)

{
  c2_operand *op;
  c2_symbol *pcVar1;
  int iVar2;
  uint32_t uVar3;
  
  op = t->dst;
  iVar2 = node_has_side_effects((c2_node *)t);
  if (((iVar2 == 0) &&
      ((((op->kind != '\x01' || (op->sym->cls != '\x03')) || (op->sym->def == (c2_tuple *)0x0)) ||
       (uVar3 = temp_operand_piece_mismatch(op), uVar3 == 0)))) &&
     (iVar2 = g_disable_tree_substitution, t->kind != '\x12')) {
    t->flags12 = '\x02';
    if ((((iVar2 == 0) && ((t->type & 0xf000) != 0x5000)) && (op->next == (c2_operand *)0x0)) &&
       ((((1 << (op->kind & 0x1f) & 6U) == 0 || (pcVar1 = op->sym, pcVar1->def == (c2_tuple *)0x0))
        || ((pcVar1->storage == pcVar1 ||
            ((use_opnd != (c2_operand *)0x0 && ((use_opnd->type & 0xfff) <= (op->type & 0xfff)))))))
       )) {
      switch(t->op) {
      case 0x15b:
      case 0x162:
      case 0x178:
      case 400:
        break;
      default:
        return 0;
      }
    }
  }
  else {
    t->flags12 = '\x01';
  }
  return 1;
}

