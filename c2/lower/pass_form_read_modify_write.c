void __fastcall pass_form_read_modify_write(c2_function *fn)

{
  ushort uVar1;
  c2_tuple *pcVar2;
  c2_symbol *pcVar3;
  c2_tuple *anchor;
  
  pcVar2 = fn->cfg->first->head;
  while (anchor = pcVar2, anchor != (c2_tuple *)0x0) {
    uVar1 = anchor->line;
    pcVar2 = anchor->next;
    if (uVar1 != 0) {
      g_current_line_abs = fn->line_base + (uint)uVar1;
      g_cur_line = uVar1;
    }
    if ((anchor->op == 0x15b) &&
       (((anchor->dst->kind != '\x01' || (pcVar3 = anchor->dst->sym, pcVar3->cls != '\x03')) ||
        (pcVar3->def == (c2_tuple *)0x0)))) {
      form_read_modify_write(anchor);
    }
  }
  return;
}

