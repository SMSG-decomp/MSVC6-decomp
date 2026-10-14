void __cdecl class_vbtable_slot_init(c1_vtable_slot *slot,c1_symbol *cls,c1_symbol *vbase)

{
  slot->path_offset = (int)vbase;
  slot->member = (int *)((cls->detail).cls)->vbptr_offset;
  return;
}

