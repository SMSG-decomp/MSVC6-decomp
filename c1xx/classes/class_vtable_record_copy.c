c1_vtable_record * __cdecl class_vtable_record_copy(c1_vtable_record *src,int unused)

{
  c1_u8 *pcVar1;
  c1_vector *pcVar2;
  c1_vtable_slot *slots;
  int iVar3;
  c1_vtable_record *pcVar4;
  c1_vtable_slot *pcVar5;
  int *piVar6;
  
  pcVar1 = g_arenas[3].cur;
  g_arenas[3].cur = g_arenas[3].cur + 0x44;
  if (g_arenas[3].end < g_arenas[3].cur) {
    arena_grow(g_arenas + 3);
  }
  pcVar4 = src;
  piVar6 = (int *)pcVar1;
  for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar6 = pcVar4->kind;
    pcVar4 = (c1_vtable_record *)&pcVar4->table;
    piVar6 = piVar6 + 1;
  }
  pcVar1[0x38] = '\0';
  pcVar2 = vector_copy_shallow(src->for_classes,0);
  *(c1_vector **)(pcVar1 + 0x34) = pcVar2;
  if (0 < *(int *)(pcVar1 + 0x10)) {
    slots = mem_xmalloc(src->capacity << 4);
    *(c1_vtable_slot **)(pcVar1 + 0x18) = slots;
    pcVar5 = src->slots;
    for (iVar3 = (src->nslots & 0xfffffffU) << 2; iVar3 != 0; iVar3 = iVar3 + -1) {
      slots->member = pcVar5->member;
      pcVar5 = (c1_vtable_slot *)&pcVar5->path_offset;
      slots = (c1_vtable_slot *)&slots->path_offset;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)&slots->member = *(undefined1 *)&pcVar5->member;
      pcVar5 = (c1_vtable_slot *)((int)&pcVar5->member + 1);
      slots = (c1_vtable_slot *)((int)&slots->member + 1);
    }
  }
  return (c1_vtable_record *)pcVar1;
}

