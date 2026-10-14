int __cdecl debug_is_vbase_or_scalar_deleting_dtor(c1_symbol *sym)

{
  if ((sym->name != g_name_vbase_dtor) && (sym->name != g_name_scalar_deleting_dtor)) {
    return 0;
  }
  return 1;
}

