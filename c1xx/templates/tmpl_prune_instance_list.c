void __cdecl tmpl_prune_instance_list(c1_symbol *sym)

{
  c1_type *pcVar1;
  
  if ((g_c9il_mode == '\0') && ((sym->key_ref & 0xfffffff8) == 0)) {
    il_symbol_key_assign(sym);
  }
  pcVar1 = type_chain_rebuild(sym->type,type_is_not_array,type_strip_cv,0);
  sym->type = pcVar1;
  return;
}

