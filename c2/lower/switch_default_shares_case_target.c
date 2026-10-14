int __fastcall
switch_default_shares_case_target(c2_switch_case_range *cases,c2_tuple *default_label)

{
  c2_symbol *pcVar1;
  c2_tuple *pcVar2;
  
  pcVar2 = tuple_next_real(default_label->next);
  if (pcVar2 != (c2_tuple *)0x0) {
    if (pcVar2->op == 0x18c) {
      pcVar2 = tuple_next_real(pcVar2);
    }
    if ((((pcVar2 != (c2_tuple *)0x0) && (pcVar2->kind == '\x11')) &&
        ((pcVar2->u20).cond_cells == (c2_cond_cell *)0x0)) && (pcVar2->op != 0x18b)) {
      pcVar1 = pcVar2->src->sym;
      for (; cases != (c2_switch_case_range *)0x0; cases = cases->next) {
        for (pcVar2 = tuple_next_real(cases->label); pcVar2 != (c2_tuple *)0x0;
            pcVar2 = tuple_next_real(pcVar2)) {
          if ((pcVar2->op != 0x1ab) || (pcVar2->next == (c2_tuple *)0x0)) {
            if ((((pcVar2 != (c2_tuple *)0x0) &&
                 ((pcVar2->kind == '\x11' && ((pcVar2->u20).cond_cells == (c2_cond_cell *)0x0)))) &&
                (pcVar2->op != 0x18b)) && (pcVar2->src->sym == pcVar1)) {
              return 1;
            }
            break;
          }
        }
      }
    }
  }
  return 0;
}

