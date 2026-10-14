byte __cdecl class_path_step_same_vbase_indices(c1_keyed_cell *cell)

{
  byte bVar1;
  c1_symbol *other;
  
  other = cell->key->sym;
  if ((other->kind & 0x1f) != 4) {
    other = g_scope_vector->entries[(short)other->key_ref];
  }
  bVar1 = class_vbase_indices_match(g_scope_vector->entries[(short)cell->sym->key_ref],other);
  return bVar1;
}

