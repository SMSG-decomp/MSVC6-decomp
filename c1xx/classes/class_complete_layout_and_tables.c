void __cdecl class_complete_layout_and_tables(c1_symbol *cls)

{
  class_complete_layout(cls);
  class_declare_vtable_symbols(cls);
  return;
}

