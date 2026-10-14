void __cdecl browse_record_finish_kind11(c1_browse_record *rec)

{
  rec->kind = '\x03';
  rec->sub_kind = '\x12';
  rec->attributes = 0;
  if ((byte)(rec->id >> 0x18) != g_browse_id_module_byte) {
    rec->id = rec->id & 0xff000000;
  }
  return;
}

