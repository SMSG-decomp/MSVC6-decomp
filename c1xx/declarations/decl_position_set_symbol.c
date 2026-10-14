void __cdecl decl_position_set_symbol(c1xx_browse_record *rec,c1_symbol *sym)

{
  rec->entity = sym->entity;
  if (rec->name == (char *)0x0) {
    rec->flags = rec->flags & 0xfd;
    rec->name = sym->name->text;
    rec->name_record = sym->name;
  }
  return;
}

