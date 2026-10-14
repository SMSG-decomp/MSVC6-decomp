void __cdecl pch_relocate_vbase_record(c1_vbase_record *rec)

{
  pch_relocate_slot_once(&g_pch_image,(uint *)rec);
  pch_relocate_slot_once(&g_pch_image,(uint *)&rec->vftables);
  pch_relocate_slot_once(&g_pch_image,(uint *)&rec->vbtables);
  pch_relocate_slot_once(&g_pch_image,(uint *)&rec->member);
  pch_mark_vector_slots((c1_vector *)rec->vftables,pch_mark_vtable_record);
  pch_mark_vector_slots((c1_vector *)rec->vbtables,pch_mark_vtable_record);
  return;
}

