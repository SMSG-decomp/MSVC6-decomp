void __fastcall ovl_add_deduced_specializations(c1_ovl_resolution *res)

{
  c1_symbol *pcVar1;
  char cVar2;
  c1_symbol_vector_iter local_c;
  
  vector_iterator_init(&local_c,res->specializations);
  cVar2 = vector_iter_next((int *)&local_c);
  pcVar1 = local_c.current;
  while (cVar2 != '\0') {
    local_c.current = pcVar1;
    ovl_add_candidate_entry(res,*(c1_symbol **)&pcVar1->flags4,(c1_symbol *)0x0);
    res->tail->deduction = (c1_tmpl_deduction *)pcVar1;
    cVar2 = vector_iter_next((int *)&local_c);
    pcVar1 = local_c.current;
  }
  return;
}

