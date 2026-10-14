void __fastcall note_symbol_referenced(c2_fe_symbol *s)

{
  c2_list_cell *pcVar1;
  
  if (((g_opt_incremental != 0) && (s->last_referrer != g_cur_func_sym)) &&
     (g_cur_func_sym != (c2_fe_symbol *)0x0)) {
    incremental_record_dependency(s);
  }
  if ((s->flags31 & 5) == 0) {
    s->flags31 = s->flags31 | 4;
    pcVar1 = arena_alloc(1,8);
    (pcVar1->u04).fe = s;
    pcVar1->next = g_referenced_symbol_list;
    g_referenced_symbol_list = pcVar1;
  }
  return;
}

