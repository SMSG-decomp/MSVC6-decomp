void __cdecl tu_emit_pending_table_15d0(void)

{
  c1_u8 cVar1;
  c1_symtab_iter local_14;
  
  if (g_pointer_pair_table != (c1_symtab *)0x0) {
    symtab_iterator_init(&local_14,g_pointer_pair_table);
    cVar1 = symtab_iterator_next(&local_14);
    while (cVar1 != '\0') {
      if (((c1_vbase_map_key *)local_14.key)->emitted == '\0') {
        ((c1_vbase_map_key *)local_14.key)->emitted = '\x01';
        class_build_vbase_index_map(local_14.key,local_14.value);
      }
      cVar1 = symtab_iterator_next(&local_14);
    }
  }
  return;
}

