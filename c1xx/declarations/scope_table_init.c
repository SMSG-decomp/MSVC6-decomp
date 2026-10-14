void __cdecl scope_table_init(void)

{
  g_scope_vector = symtab_record_new(0x640);
  if (g_scope_vector->count == g_scope_vector->capacity) {
    g_scope_vector = vector_grow_checked(g_scope_vector);
  }
  g_scope_vector->entries[(short)g_scope_vector->count] = (c1_symbol *)0x0;
  g_scope_vector->count = g_scope_vector->count + 1;
  return;
}

