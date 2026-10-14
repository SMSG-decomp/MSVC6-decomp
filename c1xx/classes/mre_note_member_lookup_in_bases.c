void __cdecl mre_note_member_lookup_in_bases(c1_symbol *cls,void *name)

{
  c1_vbase_vector *pcVar1;
  char cVar2;
  c1_symbol *pcVar3;
  byte bVar4;
  short sVar5;
  short sVar6;
  int *piVar7;
  c1_vbase_vector *pcVar8;
  int *piVar9;
  c1_vbase_vector *local_18;
  int *local_14;
  int *local_10;
  int *local_c;
  
  mre_note_member_use(g_minimal_rebuild_tracker,cls,name);
  class_member_iter_init((c1_member_iter *)&local_18,&cls->name,4);
  piVar9 = local_14;
  piVar7 = local_c;
  do {
    while( true ) {
      local_c = piVar7;
      local_10 = local_c;
      piVar7 = local_c;
      if (local_c == (int *)0x0) goto LAB_104abe82;
      if ((piVar9 == (int *)0x0) ||
         (piVar7 = (int *)piVar9[1], piVar9 = piVar7, local_14 = piVar7, piVar7 == (int *)0x0)) {
        piVar7 = (int *)0x0;
      }
      if ((*(byte *)(local_c + -2) & 0x1f) == 3) break;
      if (((g_compile_flags_cc & 0x100000) == 0) ||
         (((*(byte *)(local_c + -2) & 0x1f) != 0xf || ((*(byte *)((int)local_c + 0x12) & 2) == 0))))
      {
        if ((*(byte *)(local_c + -2) & 0x1f) != 0xf) goto LAB_104abe82;
        bVar4 = *(byte *)((int)local_c + 0x12) & 2;
        if (bVar4 == 0) {
          pcVar3 = g_scope_vector->entries[(short)local_c[4]];
        }
        else {
          pcVar3 = (c1_symbol *)0x0;
        }
        if ((((pcVar3->detail).cls)->flags3e & 0x40) == 0) {
          if (bVar4 == 0) {
            piVar9 = local_c + 4;
            local_c = piVar7;
            mre_note_member_lookup_in_bases(g_scope_vector->entries[(short)*piVar9],name);
            piVar9 = local_14;
            piVar7 = local_c;
          }
          else {
            local_c = piVar7;
            mre_note_member_lookup_in_bases((c1_symbol *)0x0,name);
            piVar9 = local_14;
            piVar7 = local_c;
          }
        }
      }
    }
  } while (((void *)*local_c == g_name_vbptr) || ((void *)*local_c == g_name_vfptr));
LAB_104abe82:
  local_c = piVar7;
  pcVar1 = ((cls->detail).cls)->vbases;
  if (pcVar1 == (c1_vbase_vector *)0x0) {
    pcVar8 = local_18;
    sVar5 = (short)local_14;
  }
  else {
    pcVar8 = pcVar1;
    sVar5 = 0;
  }
  while (((pcVar1 != (c1_vbase_vector *)0x0 && (pcVar8 != (c1_vbase_vector *)0x0)) &&
         ((int)sVar5 < (int)(uint)pcVar8->count))) {
    sVar6 = sVar5 + 1;
    pcVar3 = pcVar8->data[sVar5]->base;
    cVar2 = class_has_direct_base(cls,pcVar3);
    sVar5 = sVar6;
    if ((cVar2 == '\0') && ((((pcVar3->detail).cls)->flags3e & 0x40) == 0)) {
      mre_note_member_lookup_in_bases(pcVar3,name);
    }
  }
  return;
}

