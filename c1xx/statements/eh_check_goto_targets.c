void __cdecl eh_check_goto_targets(void)

{
  c1_flow_state *from_rec;
  c1_flow_state *to_rec;
  c1_node *n;
  
  for (from_rec = (c1_flow_state *)g_pending_goto_list; from_rec != (c1_flow_state *)0x0;
      from_rec = (c1_flow_state *)from_rec->word18) {
    to_rec = stmt_find_label_flow_state(from_rec->subject);
    if (to_rec != (c1_flow_state *)0x0) {
      label_emit_definition((c1_node *)from_rec->word14);
      g_compile_flags_c8 = g_compile_flags_c8 | 0x8000;
      eh_scope_setjmp_guard(from_rec,to_rec,2);
      n = tree_new_symbol_ref(from_rec->subject,'\0');
      il_emit_tuple(0x3a,n);
      g_compile_flags_c8 = g_compile_flags_c8 & 0xfffe7fff;
    }
  }
  return;
}

