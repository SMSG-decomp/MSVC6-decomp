void __fastcall mark_tree_materialize(c2_tuple *t)

{
  ushort uVar1;
  c2_operand *pcVar2;
  uint32_t uVar3;
  c2_tuple *pcVar4;
  
  for (pcVar2 = t->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
    if (((1 << (pcVar2->kind & 0x1f) & 6U) != 0) &&
       (pcVar4 = pcVar2->sym->def, pcVar4 != (c2_tuple *)0x0)) {
      mark_tree_materialize(pcVar4);
    }
  }
  uVar3 = t->op;
  if ((uVar3 != 0x15b) && (t->flags13 != '\x11')) {
    if (uVar3 == 0x162) {
      t->flags13 = '\x03';
    }
    else if (uVar3 == 0x15f) {
      if ((((t->type & 0xf000) == 0x4000) && (uVar1 = t->src->type, (uVar1 & 0xf000) == 0x4000)) &&
         ((uVar1 & 0xfff) <= (t->type & 0xfff))) {
        t->flags13 = '\x03';
        if ((((1 << (t->dst->kind & 0x1f) & 6U) != 0) && (t->dst->sym->def != (c2_tuple *)0x0)) &&
           ((pcVar4 = find_next_use_of_dst(t,(c2_operand **)&stack0xfffffffc),
            pcVar4 != (c2_tuple *)0x0 &&
            ((pcVar4->op == 0x15a &&
             (pcVar4 = find_next_use_of_dst(pcVar4,(c2_operand **)&stack0xfffffffc),
             pcVar4->op == 0x184)))))) {
          t->flags13 = '\0';
        }
      }
    }
    else if (uVar3 == 0x15d) {
      if ((t->type & 0xf000) == 0x4000) {
        t->flags13 = '\x03';
      }
      if (((((1 << (t->dst->kind & 0x1f) & 6U) != 0) && (t->dst->sym->def != (c2_tuple *)0x0)) &&
          (pcVar4 = find_next_use_of_dst(t,(c2_operand **)&stack0xfffffffc),
          pcVar4 != (c2_tuple *)0x0)) && (pcVar4->op == 0x15a)) {
        t->flags13 = '\0';
      }
    }
    else if (uVar3 == 0x178) {
      t->src->sym->def->flags13 = '\x03';
    }
    if (((t->type & 0xf000) == 0x4000) && (g_opt_basic != 0)) {
      t->flags13 = '\x03';
    }
  }
  return;
}

