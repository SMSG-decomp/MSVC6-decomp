void __cdecl pragma_component_set_name_references(fe_name *name)

{
  if (g_emitter_suspend->browse_on == '\x01') {
    name->flags = name->flags & 0xffdfffff;
    return;
  }
  name->flags = name->flags | 0x200000;
  return;
}

