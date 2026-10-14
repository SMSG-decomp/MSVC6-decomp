c1_vtable_record * __cdecl class_vtable_record_move_to_arena0(c1_vtable_record *src)

{
  c1_u8 *pcVar1;
  c1_vector *pcVar2;
  int iVar3;
  c1_vtable_record *pcVar4;
  c1_vtable_slot *pcVar5;
  int *piVar6;
  c1_u8 *pcVar7;
  
  pcVar1 = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 0x44;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  pcVar4 = src;
  piVar6 = (int *)pcVar1;
  for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar6 = pcVar4->kind;
    pcVar4 = (c1_vtable_record *)&pcVar4->table;
    piVar6 = piVar6 + 1;
  }
  pcVar2 = vector_copy_shallow_to_arena(src->for_classes,0);
  *(c1_vector **)(pcVar1 + 0x34) = pcVar2;
  pcVar7 = g_arenas[0].cur;
  if (0 < *(int *)(pcVar1 + 0x10)) {
    g_arenas[0].cur = g_arenas[0].cur + src->nslots * 0x10;
    if (g_arenas[0].end < g_arenas[0].cur) {
      arena_grow(g_arenas);
    }
    *(c1_u8 **)(pcVar1 + 0x18) = pcVar7;
    pcVar5 = src->slots;
    for (iVar3 = (src->nslots & 0xfffffffU) << 2; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(int **)pcVar7 = pcVar5->member;
      pcVar5 = (c1_vtable_slot *)&pcVar5->path_offset;
      pcVar7 = pcVar7 + 4;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *pcVar7 = *(c1_u8 *)&pcVar5->member;
      pcVar5 = (c1_vtable_slot *)((int)&pcVar5->member + 1);
      pcVar7 = pcVar7 + 1;
    }
  }
  class_vtable_record_free_slots(src);
  return (c1_vtable_record *)pcVar1;
}

