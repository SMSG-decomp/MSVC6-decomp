int __fastcall tuple_reads_sources(c2_tuple *t)

{
  c2_operand *pcVar1;
  int iVar2;
  
  if (t->op == 0x5f) {
    return 0;
  }
  if ((((t->op == 0x34) && (pcVar1 = t->src, pcVar1->kind == '\x01')) &&
      (pcVar1->next->kind == '\x01')) &&
     (((pcVar1->u18).reg == (pcVar1->next->u18).reg &&
      (iVar2 = is_register_candidate_home((pcVar1->u18).reg), iVar2 == 0)))) {
    return 0;
  }
  return 1;
}

