c1_type * __cdecl sym_new_builtin_helper(ushort convention,c1_type *type)

{
  c1_u8 *params;
  ushort local_54;
  int zero_50;
  c1_decl_record local_4c;
  
  decl_record_init(&local_4c,type,g_default_decl_specifiers);
  params = g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 0x1c;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  if (params == (c1_u8 *)0x0) {
    params = (c1_u8 *)0x0;
  }
  else {
    params[0x10] = '\x05';
    params[0x11] = '\0';
    params[0x12] = '\0';
    params[0x13] = '\0';
    params[0x14] = '\0';
    params[0] = '\0';
    params[1] = '\0';
    params[2] = '\0';
    params[3] = '\0';
  }
  decl_append_function_layer((int *)&local_4c,params);
  local_54 = convention;
  zero_50 = 0;
  type_check_based_form(&local_4c,(c1_decl_modifier *)&stack0xffffffac);
  decl_finish_declarator(&local_4c);
  return local_4c.type;
}

