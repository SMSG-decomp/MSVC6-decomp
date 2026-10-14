c1_symbol * __fastcall class_member_iter_base_class(c1_member_iter *iter)

{
  if ((*(byte *)((int)iter->current + 0x12) & 2) != 0) {
    return (c1_symbol *)0x0;
  }
  return g_scope_vector->entries[*(short *)((int)iter->current + 0x10)];
}

