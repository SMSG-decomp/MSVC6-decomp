void __cdecl rtti_emit_base_class_array(int *item)

{
  ushort *puVar1;
  c1_symbol *sym;
  short sVar2;
  
  sym = (c1_symbol *)decl_begin_initialized_definition((c1_symbol *)*item);
  init_begin(sym,'\0');
  init_check_too_many_2();
  puVar1 = (ushort *)item[1];
  for (sVar2 = 0; (puVar1 != (ushort *)0x0 && ((int)sVar2 < (int)(uint)*puVar1)); sVar2 = sVar2 + 1)
  {
    init_emit_address_or_zero(*(int *)(*(int *)(puVar1 + 4) + sVar2 * 4));
  }
  init_pop_brace_level();
  init_finish(sym);
  return;
}

