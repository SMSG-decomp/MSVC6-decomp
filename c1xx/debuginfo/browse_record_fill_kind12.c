void __cdecl browse_record_fill_kind12(c1xx_browse_record *rec,fe_macro *macro)

{
  if ((byte)(macro->def->browse_id >> 0x18) == g_browse_id_module_byte) {
    rec->kind = '\x04';
    rec->entity = macro->def->browse_id;
    return;
  }
  browse_record_finish_kind13(rec,macro);
  *(byte *)&rec->attributes = (byte)rec->attributes | 0x20;
  return;
}

