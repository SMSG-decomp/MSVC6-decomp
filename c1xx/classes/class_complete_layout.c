void __cdecl class_complete_layout(c1_symbol *cls)

{
  char cVar1;
  
  class_reset_previous_vbase();
  class_merge_direct_base_records(cls);
  class_set_size(cls);
  class_assign_vbase_table_slots(cls);
  class_assign_vftable_slots(cls);
  class_check_ambiguous_inherited_member((int)cls);
  class_disambiguate_vtable_names(cls);
  class_copy_layout_records_to_arena0(cls);
  cVar1 = class_vtables_have_pure_virtual(cls);
  ((cls->detail).cls)->layout_flags3b = ((cls->detail).cls)->layout_flags3b & 0x7f | cVar1 << 7;
  return;
}

