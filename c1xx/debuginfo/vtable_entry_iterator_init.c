void __cdecl vtable_entry_iterator_init(c1_vtable_slot_iter *it,c1_vtable_record *table)

{
  it->table = table;
  it->index = 0;
  return;
}

