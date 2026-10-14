void __fastcall tuple_free_src_defs(c2_tuple *t)

{
  c2_operand *pcVar1;
  
  for (pcVar1 = t->src; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
    if (pcVar1->kind != '\v') {
      tuple_unlink_free(pcVar1->sym->def);
    }
  }
  return;
}

