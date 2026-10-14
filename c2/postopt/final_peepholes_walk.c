void __fastcall final_peepholes_walk(c2_function *fn)

{
  ushort uVar1;
  c2_tuple *pcVar2;
  c2_tuple *pcVar3;
  c2_operand *pcVar4;
  c2_tuple *t;
  
  pcVar2 = fn->cfg->last->end;
  t = fn->cfg->first->head->next;
  do {
    if (t == pcVar2) {
      return;
    }
    pcVar3 = t->next;
    if ((t->flags & 1) != 0) {
      uVar1 = t->line;
      if (uVar1 != 0) {
        g_current_line_abs = fn->line_base + (uint)uVar1;
        g_cur_line = uVar1;
      }
      switch(*(undefined1 *)((int)&switchD_10775f72::switchdataD_10775fbc + (uint)t->kind)) {
      case 0:
        pcVar4 = t->dst;
        if ((((pcVar4 == (c2_operand *)0x0) || ((1 << (pcVar4->kind & 0x1f) & 6U) == 0)) ||
            (pcVar4->sym->def == (c2_tuple *)0x0)) ||
           ((pcVar4->next != (c2_operand *)0x0 && (pcVar4->next->type != 0x8000))))
        goto switchD_10775f72_caseD_1;
        break;
      case 1:
switchD_10775f72_caseD_1:
        widen_partial_register_def(t,(c2_symbol *)0x0);
      }
    }
    t = pcVar3;
  } while( true );
}

