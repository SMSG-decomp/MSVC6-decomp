int __cdecl type_debug_member_function_index(c1_symbol *sym)

{
  c1_type *type;
  void *pvVar1;
  
  type = sym->type;
  if ((*(byte *)((int)&sym->tail + 10) & 0x10) == 0) {
    pvVar1 = (void *)type->debug_index;
  }
  else {
    pvVar1 = symtab_15ec_lookup_by_id(sym);
  }
  if (pvVar1 == (void *)0x0) {
    if ((*(byte *)((int)&sym->tail + 10) & 0x10) != 0) {
      pvVar1 = sym_this_adjustment(sym);
      pvVar1 = (void *)debug_type_record_mfunction(type,(uint)pvVar1);
      symtab_15ec_insert_by_id(sym,pvVar1);
      return (int)pvVar1;
    }
    pvVar1 = (void *)debug_type_record_mfunction(type,0);
    type->debug_index = (c1_u32)pvVar1;
  }
  return (int)pvVar1;
}

