int __fastcall sink_common_tail_pair(c2_tuple *jmp,c2_tuple *kept_jmp)

{
  c2_tuple *pos;
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  c2_fe_symbol *label_sym;
  c2_tuple *t;
  c2_tuple *from_before;
  c2_tuple *to_before;
  int local_10;
  
  bVar1 = false;
  if ((((jmp->op != 0) && (jmp->op < 0x144)) && (kept_jmp->op != 0)) && (kept_jmp->op < 0x144)) {
    bVar2 = false;
    bVar3 = false;
    local_10 = 0;
    from_before = jmp;
    to_before = kept_jmp;
    while( true ) {
      from_before = from_before->prev;
      to_before = to_before->prev;
      if (((!bVar2) &&
          (((from_before->kind == '\x0e' ||
            ((from_before->kind == '\x11' &&
             (((from_before->u20).cond_cells != (c2_cond_cell *)0x0 || (from_before->op == 0x18b))))
            )) && (bVar2 = true, bVar1)))) && (bVar3)) {
        cross_jump_fix_labels(from_before,jmp,to_before,kept_jmp,0,0);
        bVar1 = false;
      }
      if (from_before->kind == '\x1a') {
        bVar1 = true;
        do {
          from_before = from_before->prev;
        } while (from_before->kind == '\x1a');
      }
      if (to_before->kind == '\x1a') {
        bVar3 = true;
        do {
          to_before = to_before->prev;
        } while (to_before->kind == '\x1a');
      }
      if (((from_before == kept_jmp) || (to_before == jmp)) ||
         (iVar4 = tuples_equal(from_before,to_before), iVar4 == 0)) break;
      local_10 = local_10 + 1;
    }
    if (local_10 != 0) {
      if (bVar1) {
        cross_jump_fix_labels(from_before,jmp,to_before,kept_jmp,0,1);
      }
      t = to_before->next;
      pos = *(c2_tuple **)((int)&jmp->src->sym->u30 + 2);
      if (t->kind != '\x1a') {
        label_sym = label_symbol_new();
        t = tuple_new_label(label_sym);
        tuple_insert_before(pos,t);
      }
      tuple_move_range(pos,to_before->next,kept_jmp->prev);
      tuple_range_free(from_before->next,jmp);
      tuple_retarget(jmp,(c2_node *)t,0);
      tuple_retarget(kept_jmp,(c2_node *)t,0);
      return 1;
    }
  }
  return 0;
}

