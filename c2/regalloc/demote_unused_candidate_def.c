void __fastcall demote_unused_candidate_def(c2_function *fn,c2_symbol *sym,c2_tuple *where)

{
  ushort uVar1;
  c2_alias_sym_info *pcVar2;
  c2_tuple *pcVar3;
  c2_operand *pcVar4;
  int iVar5;
  c2_tuple *t;
  c2_operand *old;
  
  pcVar2 = (sym->u30).alias_info;
  t = (c2_tuple *)pcVar2->points_to;
  if (t->op == 0x163) {
    old = (c2_operand *)where;
    for (pcVar3 = t->next; pcVar3 != (c2_tuple *)0x0; pcVar3 = pcVar3->next) {
      for (old = pcVar3->src; old != (c2_operand *)0x0; old = old->next) {
        if ((old->kind == '\x01') &&
           ((old->sym == sym || ((c2_symbol *)(old->sym->u34).refs == sym)))) goto LAB_107177bd;
      }
    }
LAB_107177bd:
    if (pcVar3 == where) {
      return;
    }
    tuple_unlink_free(t);
    t = pcVar3;
  }
  else {
    pcVar4 = t->dst;
    old = pcVar4;
    while ((old != (c2_operand *)0x0 &&
           ((old->kind != '\x01' ||
            ((old->sym != sym && ((c2_symbol *)(old->sym->u34).refs != sym))))))) {
      old = old->next;
    }
    if ((old->flags & 0xf) != 0) {
      return;
    }
    pcVar2->classes = (c2_alias_class_cache *)((int)&pcVar2->classes[-1].size + 3);
    if (((((sym->cls == '\x03') && (sym->def == (c2_tuple *)0x0)) &&
         (sym->storage->part_next == (c2_symbol *)0x0)) &&
        ((old == pcVar4 && ((old->type & 0xf000) != 0x4000)))) &&
       ((old->next == (c2_operand *)0x0 &&
        (((sym->flags6 & 2) == 0 && (iVar5 = def_has_unshared_sources(t), iVar5 != 0)))))) {
      tuple_unlink_free(t);
      return;
    }
  }
  uVar1 = t->line;
  if (uVar1 != 0) {
    g_current_line_abs = fn->line_base + (uint)uVar1;
    g_cur_line = uVar1;
  }
  if (sym->cls != '\r') {
    operand_make_sym(old);
    if ((old->type & 0xf000) != 0x4000) {
      if ((old->flags & 0x20) != 0) {
        tuple_legalize_mem_operands(t);
        return;
      }
      legalize_machine_tuple(t);
    }
    return;
  }
  tuple_replace_src_with_base_copy(t,old,sym);
  return;
}

