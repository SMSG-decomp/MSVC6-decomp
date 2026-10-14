c1_ovl_candidate * __cdecl
ovl_resolve_call(c1_symbol *set,c1_node *object,c1_node *args,int argc,int *template_args,byte flags
                )

{
  c1_symbol *sym;
  char cVar1;
  c1_ovl_candidate *pcVar2;
  int iVar3;
  c1_symbol *pcVar4;
  c1_ovl_resolution res;
  
  if (argc < 0) {
    return (c1_ovl_candidate *)0x0;
  }
  ovl_resolution_begin(&res,set,args,argc,template_args,flags);
  if (res.failed != '\0') {
    return (c1_ovl_candidate *)0x0;
  }
  cVar1 = ovl_prune_candidates_by_arity(&res,args);
  if (cVar1 == '\0') {
    return (c1_ovl_candidate *)0x0;
  }
  cVar1 = ovl_match_arguments(&res,object);
  if (cVar1 == '\0') {
    return (c1_ovl_candidate *)0x0;
  }
  pcVar2 = (c1_ovl_candidate *)ovl_unique_candidate((int)&res);
  if ((pcVar2 == (c1_ovl_candidate *)0x0) &&
     (pcVar2 = (c1_ovl_candidate *)
               ovl_select_best_candidate(&res,(byte *)0x0,ovl_resolve_call_no_best),
     pcVar2 == (c1_ovl_candidate *)0x0)) {
    pcVar2 = (c1_ovl_candidate *)ovl_resolve_call_fail_exit((int *)0x0);
    return pcVar2;
  }
  sym = pcVar2->function;
  pcVar4 = sym;
  if ((*(byte *)((int)&sym->tail + 9) & 0x40) == 0) {
    pcVar4 = pcVar2->alias;
    if (pcVar2->alias == (c1_symbol *)0x0) {
      pcVar4 = sym;
    }
  }
  else if (((sym->flags2 & 4) == 0) && ((flags & 8) == 0)) {
    iVar3 = (*g_idb->vtbl->idb_note_first_use)(g_idb);
    if (iVar3 == 0) {
      diag_fatal(0x49,"..\\Cxx\\dymto.c",0x186c);
    }
    if (pcVar2->deduction == (c1_tmpl_deduction *)0x0) {
      tmpl_work_queue_add(sym,(int *)0x0);
    }
    else {
      tmpl_work_queue_add(sym,(int *)pcVar2->deduction);
    }
  }
  if (((flags & 1) != 0) && (g_browse_file != (char *)0x0)) {
    (*g_il_emitter->vtbl->reference_symbol)((int)pcVar4);
  }
  return pcVar2;
}

