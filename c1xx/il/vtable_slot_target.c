c1_symbol * __cdecl vtable_slot_target(c1_vtable_slot *slot,c1_symbol *cls,c1_vtable_record *rec)

{
  int *piVar1;
  int delta;
  int iVar2;
  c1_symbol *pcVar3;
  int kind;
  
  piVar1 = slot->member;
  pcVar3 = (c1_symbol *)(piVar1 + -2);
  delta = vtable_slot_this_delta(slot,cls,rec);
  if ((*(byte *)((int)piVar1 + -7) & 0x20) == 0x20) {
    pcVar3 = (c1_symbol *)
             class_find_vector_deleting_dtor
                       ((c1_type *)
                        **(undefined4 **)
                          ((-(uint)((*(byte *)piVar1[3] & 0x80) != 0) & (uint)piVar1[3]) + 8));
  }
  if ((delta == 0) && ((slot->flags & 8) == 0)) {
    return pcVar3;
  }
  kind = (-(uint)((slot->flags & 8) != 0) & 3) + 1;
  if ((slot->flags & 8) != 0) {
    iVar2 = type_int_size();
    pcVar3 = adjustor_thunk_lookup_or_new(kind,pcVar3,delta,-(iVar2 + rec->off20));
    return pcVar3;
  }
  pcVar3 = adjustor_thunk_lookup_or_new(kind,pcVar3,delta,0);
  return pcVar3;
}

