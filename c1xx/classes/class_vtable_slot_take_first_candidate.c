void __cdecl class_vtable_slot_take_first_candidate(c1_vtable_slot *slot)

{
  slot->member = *(int **)slot->member[2];
  *(byte *)&slot->flags = (byte)slot->flags & 0xfb;
  return;
}

