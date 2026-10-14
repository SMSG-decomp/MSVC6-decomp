void __cdecl browse_record_set_symbol(c1_browse_record *rec,c1_symbol *sym)

{
  rec->id = sym->entity;
  if (rec->name == (char *)0x0) {
    rec->name = sym->name->text;
    rec->name_record = sym->name;
  }
  return;
}

