void __cdecl init_finish_variable_fragment(c1_symbol *sym)

{
  int iVar1;
  int iVar2;
  
  if (PTR_1066b8ec == (c1_type *)0x0) {
    sym->detail = (void *)0x0;
  }
  else {
    iVar1 = type_size(PTR_1066b8ec);
    iVar2 = init_unsized_array_count();
    sym->detail = (void *)(iVar1 * iVar2);
  }
  PTR_1066b8ec = (c1_type *)0x0;
  init_end_record(sym);
  if (g_il_block_level != '\0') {
    sym->key_ref = sym->key_ref & 0xfffffff8;
  }
  g_init_symbol = (c1_symbol *)0x0;
  return;
}

