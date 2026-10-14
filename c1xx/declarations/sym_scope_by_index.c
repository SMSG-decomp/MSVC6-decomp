c1_symbol * __thiscall sym_scope_by_index(c1_symbol *sym,int unused)

{
  return g_scope_vector->entries[(short)sym->scope_index];
}

