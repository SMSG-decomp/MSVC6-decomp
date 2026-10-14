int __fastcall switch_default_is_unreachable(c2_switch_case_range *cases)

{
  c2_tuple *pcVar1;
  c2_operand *pcVar2;
  
  if (((g_opt_global != 0) && (pcVar1 = cases->label->next, pcVar1 != (c2_tuple *)0x0)) &&
     (pcVar1->op == 0x1ab)) {
    for (pcVar1 = (pcVar1->u20).tuples; pcVar1 != (c2_tuple *)0x0; pcVar1 = pcVar1->next) {
      if (((pcVar1->op == 0x1ac) && (pcVar2 = pcVar1->src, pcVar2->kind == '\a')) &&
         ((pcVar2->u18).lo == 0 && pcVar2->tag == 0)) {
        return 1;
      }
    }
  }
  return 0;
}

