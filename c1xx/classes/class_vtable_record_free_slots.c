void __cdecl class_vtable_record_free_slots(c1_vtable_record *rec)

{
  if (0 < rec->nslots) {
    mem_free(rec->slots);
  }
  return;
}

