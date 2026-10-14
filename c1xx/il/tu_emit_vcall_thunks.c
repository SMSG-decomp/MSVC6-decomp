void __cdecl tu_emit_vcall_thunks(void)

{
  c1_u8 cVar1;
  c1_symtab_iter local_14;
  
  if (g_vcall_thunk_table != (c1_symtab *)0x0) {
    symtab_iterator_init(&local_14,g_vcall_thunk_table);
    cVar1 = symtab_iterator_next(&local_14);
    while (cVar1 != '\0') {
      if (((c1_vcall_thunk_key *)local_14.key)->emitted == '\0') {
        ((c1_vcall_thunk_key *)local_14.key)->emitted = '\x01';
        func_emit_vcall_thunk_body(local_14.key,local_14.value);
      }
      cVar1 = symtab_iterator_next(&local_14);
    }
  }
  return;
}

