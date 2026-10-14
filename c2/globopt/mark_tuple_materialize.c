void __fastcall mark_tuple_materialize(c2_tuple *t)

{
  ushort uVar1;
  uint32_t uVar2;
  c2_tuple *pcVar3;
  c2_operand *pcStack_4;
  
  uVar2 = t->op;
  if ((uVar2 != 0x15b) && (t->flags13 != '\x11')) {
    if (uVar2 == 0x162) {
      t->flags13 = '\x03';
    }
    else {
      pcStack_4 = (c2_operand *)t;
      if (uVar2 == 0x15f) {
        if ((((t->type & 0xf000) == 0x4000) && (uVar1 = t->src->type, (uVar1 & 0xf000) == 0x4000))
           && ((uVar1 & 0xfff) <= (t->type & 0xfff))) {
          t->flags13 = '\x03';
          if ((((1 << (t->dst->kind & 0x1f) & 6U) != 0) && (t->dst->sym->def != (c2_tuple *)0x0)) &&
             ((pcVar3 = find_next_use_of_dst(t,&pcStack_4), pcVar3 != (c2_tuple *)0x0 &&
              ((pcVar3->op == 0x15a &&
               (pcVar3 = find_next_use_of_dst(pcVar3,&pcStack_4), pcVar3->op == 0x184)))))) {
            t->flags13 = '\0';
          }
        }
      }
      else if (uVar2 == 0x15d) {
        if ((t->type & 0xf000) == 0x4000) {
          t->flags13 = '\x03';
        }
        if (((((1 << (t->dst->kind & 0x1f) & 6U) != 0) && (t->dst->sym->def != (c2_tuple *)0x0)) &&
            (pcVar3 = find_next_use_of_dst(t,&pcStack_4), pcVar3 != (c2_tuple *)0x0)) &&
           (pcVar3->op == 0x15a)) {
          t->flags13 = '\0';
        }
      }
      else if (uVar2 == 0x178) {
        t->src->sym->def->flags13 = '\x03';
      }
    }
    if (((t->type & 0xf000) == 0x4000) && (g_opt_basic != 0)) {
      t->flags13 = '\x03';
    }
  }
  return;
}

