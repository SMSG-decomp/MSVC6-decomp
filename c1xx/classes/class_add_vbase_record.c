void __cdecl
class_add_vbase_record
          (c1_vbase_vector *vbases,c1_vbase_record *rec,c1_symbol *cls,c1_symbol *base_entry)

{
  c1_u8 cVar1;
  char cVar2;
  c1_vbase_record *existing;
  int offset;
  c1_type *t;
  
  existing = class_find_base_record(rec->base,vbases);
  if (existing == (c1_vbase_record *)0x0) {
    cVar1 = class_vbase_needs_vtordisp(cls,rec->base);
    rec->needs_vtordisp = cVar1;
    cVar2 = class_vbase_needs_empty_gap(rec->base,cls);
    if ((cVar2 != '\0') || (rec->needs_vtordisp != '\0')) {
      t = type_int();
      class_check_member_array_size(t);
    }
    offset = class_check_zero_sized_array_member(rec->base);
    rec->offset = offset;
    class_vbase_record_rebase(rec,base_entry,offset);
    vector_push((c1_vector *)vbases,rec);
    return;
  }
  class_vbase_record_rebase(rec,base_entry,existing->offset);
  class_vbase_merge_vftable_slots(cls,existing,rec);
  class_vbase_record_free_slot_arrays(rec);
  return;
}

