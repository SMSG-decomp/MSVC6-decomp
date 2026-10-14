c1_ovl_resolution * __thiscall
ovl_resolution_begin
          (c1_ovl_resolution *res,c1_symbol *set,c1_node *args,c1_u32 nargs,int *template_args,
          byte flags)

{
  c1_symbol *pcVar1;
  c1_ovl_candidate *cand;
  byte bVar2;
  char cVar3;
  int iVar4;
  c1_deferred_action *action;
  c1_symbol_vector_iter local_c;
  
  ovl_resolution_init(res,set,nargs,1,flags);
  pcVar1 = res->set;
  res->args = args;
  (res->extra).right = (c1_node *)template_args;
  bVar2 = pcVar1->kind & 0x1f;
  if ((bVar2 == 8) ||
     (((bVar2 == 0x1a &&
       (iVar4 = sym_is_member_function_via_alias(*(c1_symbol **)pcVar1->type), (char)iVar4 != '\0'))
      || ((pcVar1->kind & 0x1f) == 0x11)))) {
    res->nargs = res->nargs + 1;
  }
  if ((res->set->name->flags & 0x8000000) != 0) {
    ovl_collect_template_candidates(res,res->set);
  }
  iVar4 = ovl_count_nontemplate_functions(res->set);
  res->count = iVar4;
  if (res->specializations != (c1_symbol_vector *)0x0) {
    vector_iterator_init(&local_c,res->specializations);
    cVar3 = vector_iter_next((int *)&local_c);
    while (cVar3 != '\0') {
      res->count = res->count + 1;
      cVar3 = vector_iter_next((int *)&local_c);
    }
  }
  if (res->count == 0) {
    res->failed = '\x01';
    if (g_deferred_actions_head == (c1_deferred_action *)0x0) {
      return res;
    }
    if ((res->flags & 1) == 0) {
      return res;
    }
    action = g_deferred_actions_head;
    if (g_tmpl_deduction_depth < 1) {
      do {
        (**action->vtbl)();
        action = action->next;
      } while (action != (c1_deferred_action *)0x0);
    }
  }
  else {
    ovl_candidates_alloc(res);
    ovl_add_candidates(res,res->set,(c1_symbol *)0x0);
    if (res->specializations != (c1_symbol_vector *)0x0) {
      ovl_add_deduced_specializations(res);
      vector_release((int)res->specializations);
    }
    res->live = res->count;
    res->head = res->candidates;
    if ((res->flags & 4) != 0) {
      ovl_set_failure_reason(res,0,0);
      for (cand = res->head; cand != (c1_ovl_candidate *)0x0; cand = cand->next) {
        if (((cand->function->flags23 & 8) != 0) &&
           (cVar3 = ovl_candidate_remove(res,cand,(c1_node *)0x0), cVar3 != '\0')) {
          res->failed = '\x01';
          return res;
        }
      }
    }
  }
  g_deferred_actions_tail = (c1_deferred_action *)0x0;
  g_deferred_actions_head = (c1_deferred_action *)0x0;
  return res;
}

