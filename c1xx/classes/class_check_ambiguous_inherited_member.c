void __cdecl class_check_ambiguous_inherited_member(int sym2)

{
  ushort *puVar1;
  int iVar2;
  int *piVar3;
  char cVar4;
  int iVar5;
  c1_vtable_slot *slot;
  short sVar6;
  uint local_20;
  short vftable_index;
  int *local_18;
  uint local_14;
  short vbase_index;
  int local_c;
  int local_4;
  
  local_4 = 0;
  local_20 = *(uint *)(*(int *)(sym2 + 0x24) + 8);
  vftable_index = 0;
  local_14 = *(uint *)(*(int *)(sym2 + 0x24) + 0x10);
  vbase_index = 0;
  do {
    do {
      iVar5 = vector_iterator_next(&local_20);
      cVar4 = (char)iVar5;
      piVar3 = local_18;
      while (local_18 = piVar3, cVar4 == '\0') {
        iVar5 = vector_iterator_next(&local_14);
        if ((char)iVar5 == '\0') {
          return;
        }
        local_4 = local_c;
        local_20 = *(uint *)(local_c + 0x14);
        vftable_index = 0;
        iVar5 = vector_iterator_next(&local_20);
        piVar3 = local_18;
        cVar4 = (char)iVar5;
      }
    } while (*piVar3 != 2);
    iVar5 = 0;
    while (sVar6 = 0, iVar5 < piVar3[4]) {
      slot = (c1_vtable_slot *)(iVar5 * 0x10 + piVar3[6]);
      iVar5 = iVar5 + 1;
      if (slot == (c1_vtable_slot *)0x0) break;
      if ((slot->flags & 4) == 0) {
        if ((slot->flags & 2) != 0) {
          class_warn_dominance(0);
          return;
        }
      }
      else {
        puVar1 = (ushort *)slot->member;
        for (; (puVar1 != (ushort *)0x0 && ((int)sVar6 < (int)(uint)*puVar1)); sVar6 = sVar6 + 1) {
          iVar2 = *(int *)(*(int *)(puVar1 + 4) + sVar6 * 4);
          diag_error(0xfa,sym2,g_scope_vector->entries[*(short *)(iVar2 + -2)],iVar2 + -8);
        }
        class_vtable_slot_take_first_candidate(slot);
      }
    }
  } while( true );
}

