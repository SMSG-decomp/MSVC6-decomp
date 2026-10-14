int __cdecl debug_emit_class_type(c1_symbol *sym)

{
  int iVar1;
  
  if ((g_debug_types_in_pdb == '\0') || ((((sym->detail).cls)->flags3f & 8) == 0)) {
    debug_type_record_class_full(sym);
  }
  iVar1 = debug_type_record_class_forward(sym);
  return iVar1;
}

