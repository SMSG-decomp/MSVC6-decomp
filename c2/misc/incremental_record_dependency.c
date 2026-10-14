void __fastcall incremental_record_dependency(c2_fe_symbol *s)

{
  uint32_t id;
  int iVar1;
  int iVar2;
  c2_init *pcVar3;
  c2_fe_symbol *pcVar4;
  c2_incr_id_cell *pcVar5;
  c2_incr_id_cell *pcVar6;
  bool bVar7;
  
  id = s->id;
  iVar2 = coff_is_known_global_id(id);
  iVar1 = g_incr_skip_known_globals;
  if (((iVar2 == 0) || (g_incr_skip_known_globals == 0)) &&
     (bVar7 = s != g_cur_func_sym, s->last_referrer = g_cur_func_sym, bVar7)) {
    if (s->cls == '\x01') {
      if (iVar2 == 0) {
        if ((s->attrs & 0x480) == 0) {
          return;
        }
        if ((s->storage & 0x1000) == 0) {
          pcVar3 = (s->u32).inits;
          g_incr_skip_known_globals = 0;
          if (pcVar3 == (c2_init *)0x0) {
            pcVar3 = data_def_find_by_id(id);
            (s->u32).inits = pcVar3;
            if (pcVar3 == (c2_init *)0x0) {
              g_incr_skip_known_globals = iVar1;
              return;
            }
          }
          for (pcVar3 = pcVar3->next; pcVar3 != (c2_init *)0x0; pcVar3 = pcVar3->next) {
            if ((pcVar3->kind == 2) &&
               (pcVar4 = fe_symbol_lookup_id((pcVar3->u08).address.target_id),
               pcVar4->last_referrer != g_cur_func_sym)) {
              incremental_record_dependency(pcVar4);
            }
          }
          g_incr_skip_known_globals = iVar1;
          return;
        }
        return;
      }
    }
    else if (s->cls == '\x04') {
      if (((s->storage & 0x8000) != 0) &&
         (pcVar4 = fe_symbol_lookup_id((s->u4a).function.exp_offset),
         pcVar4->last_referrer != g_cur_func_sym)) {
        incremental_record_dependency(pcVar4);
      }
    }
    else if (iVar2 == 0) {
      return;
    }
    pcVar5 = arena_alloc(0,8);
    pcVar4 = g_cur_func_sym;
    pcVar5->sym_id = id;
    pcVar6 = pcVar4->incr->symbol_deps;
    pcVar4->incr->symbol_deps = pcVar5;
    pcVar5->next = pcVar6;
    pcVar4 = fe_scope_lookup_id(&g_global_scope,id);
    pcVar6 = g_incr_unknown_symbol_ids;
    if (pcVar4 == (c2_fe_symbol *)0x0) {
      for (; pcVar6 != (c2_incr_id_cell *)0x0; pcVar6 = pcVar6->next) {
        if (pcVar6->sym_id == id) {
          if (pcVar6 != (c2_incr_id_cell *)0x0) {
            return;
          }
          break;
        }
      }
      pcVar6 = arena_alloc(0,8);
      pcVar6->sym_id = id;
      pcVar6->next = g_incr_unknown_symbol_ids;
      g_incr_unknown_symbol_ids = pcVar6;
    }
  }
  return;
}

