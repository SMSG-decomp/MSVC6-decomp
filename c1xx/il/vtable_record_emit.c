void __cdecl vtable_record_emit(c1_vtable_record *rec,c1_symbol *cls)

{
  if (((rec->table->flags22 & 8) == 0) || (rec->alt_used != '\0')) {
    rec->emitted = '\x01';
    if ((rec->kind == 0) || (rec->kind == 2)) {
      vtable_record_make_slot_thunks(rec,cls);
    }
    if (rec->alt_table != (c1_symbol *)0x0) {
      vtable_record_write_data(rec,rec->alt_table,cls);
      return;
    }
    vtable_record_write_data(rec,rec->table,cls);
  }
  return;
}

