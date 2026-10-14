void __fastcall lower_pending_arg_copies(c2_tuple *t)

{
  uint8_t uVar1;
  c2_operand *pcVar2;
  c2_tuple *t_00;
  
  if (t->kind == '\x0e') {
    pcVar2 = t->src->next;
  }
  else {
    pcVar2 = t->src;
  }
  for (; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
    uVar1 = pcVar2->kind;
    if ((((((uVar1 != '\v') && (uVar1 != '\n')) && ((pcVar2->flags & 0x20) == 0)) &&
         ((uVar1 != '\x01' || (pcVar2->sym->cls != '\x01')))) &&
        ((t_00 = pcVar2->sym->def, t_00 != (c2_tuple *)0x0 &&
         ((t_00->op == 0x15a || (t_00->op == 0x16a)))))) && ((t_00->type & 0xf000) != 0x4000)) {
      lower_tuple(t_00);
    }
  }
  return;
}

