c1_vbase_record * __cdecl class_vbase_record_move_to_arena(c1_vbase_record *src,int arena)

{
  c1_vbase_record *pcVar1;
  c1_vtable_vector *pcVar2;
  c1_arena *a;
  int iVar3;
  c1_vbase_record *pcVar4;
  c1_vtable_vector **ppcVar5;
  c1_vbase_record *pcVar6;
  
  a = g_arenas + arena;
  pcVar1 = (c1_vbase_record *)a->cur;
  pcVar4 = (c1_vbase_record *)g_arenas[arena].end;
  a->cur = (c1_u8 *)(pcVar1 + 1);
  if (pcVar4 < pcVar1 + 1) {
    arena_grow(a);
  }
  pcVar4 = src;
  pcVar6 = pcVar1;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    pcVar6->base = pcVar4->base;
    pcVar4 = (c1_vbase_record *)&pcVar4->offset;
    pcVar6 = (c1_vbase_record *)&pcVar6->offset;
  }
  ppcVar5 = &pcVar1->vftables;
  iVar3 = 2;
  do {
    pcVar2 = (c1_vtable_vector *)
             vector_copy(*(c1_vector **)(((int)src - (int)pcVar1) + (int)ppcVar5),arena,
                         class_vtable_record_move_to_arena0);
    *ppcVar5 = pcVar2;
    ppcVar5 = ppcVar5 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return pcVar1;
}

