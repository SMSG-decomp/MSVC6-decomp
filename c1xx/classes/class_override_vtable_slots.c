void __cdecl
class_override_vtable_slots(int *fn_link,c1_vtable_record *rec,c1_symbol *cls,c1_u8 needs_vtordisp)

{
  char cVar1;
  c1_sym_link *base_fn;
  void *pvVar2;
  c1_vtable_slot *slot;
  int iVar3;
  
  iVar3 = 0;
  while( true ) {
    if (rec->nslots <= iVar3) {
      return;
    }
    slot = rec->slots + iVar3;
    iVar3 = iVar3 + 1;
    if (slot == (c1_vtable_slot *)0x0) break;
    base_fn = (c1_sym_link *)slot->member;
    if ((slot->flags & 4) != 0) {
      base_fn = *(c1_sym_link **)base_fn->position;
    }
    if (((fe_name *)*fn_link == base_fn->name) &&
       (cVar1 = class_check_override_return_type((c1_sym_link *)fn_link,base_fn,cls,'\0'),
       cVar1 != '\0')) {
      if ((slot->flags & 4) != 0) {
        class_vtable_slot_take_first_candidate(slot);
      }
      if ((*(byte *)(fn_link + 0xb) & 2) == 0) {
        *(byte *)(fn_link + 0xb) = *(byte *)(fn_link + 0xb) | 2;
        pvVar2 = (void *)class_vtable_vptr_offset(rec);
        sym_set_this_adjustment((c1_symbol *)(fn_link + -2),pvVar2);
        fn_link[7] = slot->member[7];
        *(undefined2 *)((int)fn_link + 0x22) = *(undefined2 *)((int)slot->member + 0x22);
      }
      slot->member = fn_link;
      if ((*(byte *)((int)fn_link + 0x2e) & 0x10) == 0) {
        pvVar2 = (void *)0x0;
      }
      else {
        pvVar2 = sym_this_adjustment((c1_symbol *)(fn_link + -2));
      }
      class_vtable_slot_path_set(&slot->path_offset,(int)pvVar2);
      *(byte *)&slot->flags = (needs_vtordisp & 1) << 3 | (byte)slot->flags & 0xf0;
    }
  }
  return;
}

