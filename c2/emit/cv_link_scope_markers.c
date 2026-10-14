void __fastcall cv_link_scope_markers(c2_function *fn)

{
  c2_tuple *pcVar1;
  c2_symbol *pcVar2;
  c2_symbol *pcVar3;
  
  pcVar3 = (c2_symbol *)0x0;
  pcVar2 = (c2_symbol *)fn->cv_scopes->next;
  for (pcVar1 = fn->cfg->first->head; pcVar1 != (c2_tuple *)0x0; pcVar1 = pcVar1->next) {
    if (pcVar1->op == 0x1b4) {
      if (pcVar1->flags12 == '\0') {
        pcVar2 = ((c2_operand *)pcVar2)->sym;
        pcVar1->src = (c2_operand *)pcVar2;
        *(c2_symbol **)&pcVar2->type = pcVar3;
        pcVar3 = pcVar2;
      }
    }
    else if ((pcVar1->op == 0x1b5) && (pcVar1->flags12 == '\0')) {
      pcVar1->src = (c2_operand *)pcVar3;
      pcVar3 = *(c2_symbol **)&pcVar3->type;
    }
  }
  return;
}

