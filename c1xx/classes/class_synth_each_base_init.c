c1_u8 __cdecl class_synth_each_base_init(c1_symbol *member,int *count)

{
  if (((member->kind & 0x1f) == 0xf) && ((member->key_ref & 0x10000) == 0)) {
    class_synth_append_base_init(g_scope_vector->entries[(short)member->key_ref],count);
  }
  return '\x01';
}

