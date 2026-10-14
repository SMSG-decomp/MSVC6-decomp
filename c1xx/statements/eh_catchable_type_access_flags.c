uint __cdecl eh_catchable_type_access_flags(c1_catchable_type *ct,char no_members)

{
  c1_type *pcVar1;
  char cVar2;
  c1_symbol *pcVar3;
  c1_keyed_list *pcVar4;
  uint uVar5;
  
  uVar5 = 0;
  if ((ct->flags & 0xd) != 0) {
    if (ct->path == (int *)0x0) {
      eh_catchable_type_path((int *)ct);
    }
    pcVar1 = ct->type;
    cVar2 = (char)pcVar1->code;
    while (cVar2 < '\0') {
      pcVar1 = pcVar1->base;
      cVar2 = (char)pcVar1->code;
    }
    if ((pcVar1->code & 0x300) == 0) {
      pcVar3 = (c1_symbol *)0x0;
    }
    else {
      pcVar3 = (pcVar1->extra).cls;
    }
    pcVar3 = (c1_symbol *)sym_new_overload_set_record((c1_keyed_list *)ct->path,pcVar3->name,5);
    cVar2 = access_check_member_path(pcVar3);
    if (cVar2 == '\0') {
      uVar5 = 0x400;
    }
    if ((no_members == '\0') && ((ct->flags & 9) != 0)) {
      tree_list_arena_set(5);
      pcVar4 = tree_new_list_cell((c1_keyed_list *)0x0,*ct->path,ct->copy_ctor);
      tree_list_arena_restore();
      pcVar3 = (c1_symbol *)sym_new_overload_set_record(pcVar4,ct->copy_ctor->name,5);
      cVar2 = access_check_member_path(pcVar3);
      if (cVar2 == '\0') {
        uVar5 = uVar5 | 0x800;
      }
      if ((((ct->cls->detail).cls)->implicit_state41 & 4) != 0) {
        ct->copy_ctor = (c1_symbol *)0x0;
      }
      if (ct->dtor != (c1_symbol *)0x0) {
        tree_list_arena_set(5);
        pcVar4 = tree_new_list_cell((c1_keyed_list *)0x0,*ct->path,ct->dtor);
        tree_list_arena_restore();
        pcVar3 = (c1_symbol *)sym_new_overload_set_record(pcVar4,ct->dtor->name,5);
        cVar2 = access_check_member_path(pcVar3);
        if (cVar2 == '\0') {
          uVar5 = uVar5 | 0x20;
        }
      }
    }
    return uVar5;
  }
  return 0;
}

