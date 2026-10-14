c1_type * __cdecl type_new_function_returning(ushort convention,c1_type *type)

{
  int *params;
  ushort local_40 [2];
  uint form_position;
  c1_type_declarator local_38;
  
  decl_init_declarator_over_type(&local_38,type,&g_empty_specifier_words);
  params = (int *)g_arenas[3].cur;
  g_arenas[3].cur = g_arenas[3].cur + 0xc;
  if (g_arenas[3].end < g_arenas[3].cur) {
    arena_grow(g_arenas + 3);
  }
  if (params == (int *)0x0) {
    params = (int *)0x0;
  }
  else {
    *(uchar *)((int)params + 4) = '\x01';
    *(uchar *)((int)params + 5) = '\0';
    *(uchar *)((int)params + 6) = '\0';
    *(uchar *)((int)params + 7) = '\0';
    *(uchar *)((int)params + 8) = '\0';
    *(uchar *)((int)params + 0) = '\0';
    *(uchar *)((int)params + 1) = '\0';
    *(uchar *)((int)params + 2) = '\0';
    *(uchar *)((int)params + 3) = '\0';
  }
  decl_append_function_layer(&local_38,params);
  local_40[0] = convention;
  form_position = 0;
  type_check_based_form(&local_38,(uint *)local_40);
  decl_finish_declarator(&local_38);
  return local_38.type;
}

