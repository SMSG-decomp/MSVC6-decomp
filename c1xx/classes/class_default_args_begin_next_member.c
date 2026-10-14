void __cdecl class_default_args_begin_next_member(void)

{
  c1_symbol *fn;
  c1_deferred_body_list *pcVar1;
  c1_u8 *rec;
  
  rec = g_arenas[3].cur;
  pcVar1 = g_deferred_member_bodies;
  if ((g_deferred_member_bodies->cursor == (c1_deferred_body *)0x0) ||
     (fn = g_deferred_member_bodies->cursor->fn, fn == (c1_symbol *)0x0)) {
    g_deferred_member_bodies->cursor = (c1_deferred_body *)0x0;
    pcVar1->first = (c1_deferred_body *)0x0;
    if (g_deferred_member_bodies->outer == (c1_deferred_body_list *)0x0) {
      g_deferred_member_bodies = (c1_deferred_body_list *)0x0;
      return;
    }
  }
  else {
    g_arenas[3].cur = g_arenas[3].cur + 0x24;
    if (g_arenas[3].end < g_arenas[3].cur) {
      arena_grow(g_arenas + 3);
    }
    if (rec != (c1_u8 *)0x0) {
      g_default_argument_parse_stack =
           class_default_args_parse_init((c1_deferred_parse *)rec,fn,g_default_argument_parse_stack)
      ;
      return;
    }
    g_default_argument_parse_stack = (c1_deferred_parse *)0x0;
  }
  return;
}

