c1_u8 __cdecl class_synth_each_base_assign(c1_symbol *member)

{
  if (((member->kind & 0x1f) == 0xf) && ((member->key_ref & 0x10000) == 0)) {
    class_synth_append_base_assign(g_scope_vector->entries[(short)member->key_ref]);
  }
  return '\x01';
}

