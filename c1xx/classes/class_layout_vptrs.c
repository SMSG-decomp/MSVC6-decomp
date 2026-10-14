void __cdecl class_layout_vptrs(c1_symbol *cls)

{
  class_reset_vtable_records(cls);
  class_add_vptr_members(cls);
  return;
}

