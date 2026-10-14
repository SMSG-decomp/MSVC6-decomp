void __thiscall decl_record_set_conversion_type(c1_decl_record *rec,c1xx_decl_specifiers *spec)

{
  byte bVar1;
  
  bVar1 = rec->flags | 0x20;
  rec->flags = bVar1;
  rec->flags = spec->spec[0] >> 3 & 1 | bVar1;
  rec->spec_type = spec->type;
  return;
}

