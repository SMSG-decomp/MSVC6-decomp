c1_vector * __cdecl eh_collect_catchable_types(ushort *type,int flag)

{
  c1_u8 *rec;
  ushort uVar1;
  c1_vector *v;
  c1_catchable_type *pcVar2;
  uint *puVar3;
  
  g_catchable_type_table = symtab_new(0x10,5,0,0,'\x01','\x01');
  v = vector_new(0,5);
  rec = g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 0x44;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  pcVar2 = eh_catchable_type_init((c1_catchable_type *)rec,(c1_type *)type,(char)flag);
  puVar3 = eh_next_catchable_type((uint *)pcVar2,flag);
  pcVar2 = (c1_catchable_type *)g_arenas[5].cur;
  while (g_arenas[5].cur = (c1_u8 *)pcVar2, puVar3 != (uint *)0x0) {
    vector_push(v,puVar3);
    puVar3 = eh_next_catchable_type(puVar3,flag);
    pcVar2 = (c1_catchable_type *)g_arenas[5].cur;
  }
  if (((char)*type < '\0') && ((uVar1 = *type & 0x8f, uVar1 == 0x86 || (uVar1 == 0x82)))) {
    g_arenas[5].cur = (c1_u8 *)(pcVar2 + 1);
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    pcVar2 = eh_catchable_type_init(pcVar2,PTR_104d152c,(char)flag);
    for (puVar3 = eh_next_catchable_type((uint *)pcVar2,flag); puVar3 != (uint *)0x0;
        puVar3 = eh_next_catchable_type(puVar3,flag)) {
      vector_push(v,puVar3);
    }
  }
  return v;
}

