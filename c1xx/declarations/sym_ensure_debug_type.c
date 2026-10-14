int __cdecl sym_ensure_debug_type(c1_symbol *sym)

{
  c1_u32 cVar1;
  
  cVar1 = sym->type->debug_index;
  if (cVar1 == 0) {
    cVar1 = debug_type_record_class_forward(sym);
  }
  return cVar1;
}

