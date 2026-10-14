void __cdecl class_find_special_members(c1_symbol *cls)

{
  class_walk_members_matching(cls,g_name_scalar_deleting_dtor);
  if ((cls->flags22 & 4) != 0) {
    class_walk_members_matching(cls,g_name_vector_deleting_dtor);
  }
  return;
}

