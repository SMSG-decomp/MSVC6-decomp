c1_vtable_record * __cdecl
class_vtable_record_new(int kind,c1_symbol *cls,int vptr_offset,c1_symbol *vptr_member)

{
  c1_u8 *pcVar1;
  c1_vector *pcVar2;
  
  pcVar1 = g_arenas[3].cur;
  g_arenas[3].cur = g_arenas[3].cur + 0x44;
  if (g_arenas[3].end < g_arenas[3].cur) {
    arena_grow(g_arenas + 3);
  }
  *(int *)pcVar1 = kind;
  pcVar2 = vector_new(1,0);
  *(c1_vector **)(pcVar1 + 0x34) = pcVar2;
  *(c1_symbol **)(pcVar1 + 8) = vptr_member;
  *(c1_symbol **)(pcVar1 + 0x30) = cls;
  *(int *)(pcVar1 + 0x20) = vptr_offset;
  pcVar1[0xc] = ' ';
  pcVar1[0xd] = '\0';
  return (c1_vtable_record *)pcVar1;
}

