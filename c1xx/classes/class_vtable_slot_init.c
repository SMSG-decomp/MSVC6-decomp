void __cdecl class_vtable_slot_init(c1_vtable_slot *slot,int *fn_link)

{
  slot->member = fn_link;
  class_vtable_slot_path_set(&slot->path_offset,0);
  *(byte *)&slot->flags = (byte)slot->flags & 0xf0;
  return;
}

