c1_type * __cdecl type_record_new_45f0(int void_ptr_flags,ushort modifier)

{
  c1_type *type;
  c1_u8 *list;
  ushort local_5c [2];
  int zero_58;
  ushort local_54 [2];
  int zero_50;
  c1_decl_record local_4c;
  
  list = g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 0x1c;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  if (list == (c1_u8 *)0x0) {
    list = (c1_u8 *)0x0;
  }
  else {
    list[0x10] = '\x04';
    list[0x11] = '\0';
    list[0x12] = '\0';
    list[0x13] = '\0';
    list[0x14] = '\0';
    list[0] = '\0';
    list[1] = '\0';
    list[2] = '\0';
    list[3] = '\0';
  }
  type = type_pointer_to((c1_u16)void_ptr_flags);
  param_list_add_compiler_formal(list,(void *)0x0,type);
  decl_record_init(&local_4c,g_type_void,g_default_decl_specifiers);
  local_5c[0] = 0;
  zero_58 = 0;
  local_54[0] = modifier;
  zero_50 = 0;
  decl_add_pointer_modifier(&local_4c,local_54,local_5c);
  decl_append_function_layer((int *)&local_4c,list);
  decl_finish_declarator(&local_4c);
  return local_4c.type;
}

