c1_type * __cdecl type_descriptor_copy_transient(c1_type *desc)

{
  uchar *puVar1;
  
  puVar1 = g_arenas[3].cur;
  g_arenas[3].cur = g_arenas[3].cur + 0x10;
  if (g_arenas[3].end < g_arenas[3].cur) {
    arena_grow(g_arenas + 3);
  }
  *(undefined4 *)puVar1 = *(undefined4 *)desc;
  *(c1_type **)(puVar1 + 4) = desc->base;
  *(c1_type_x08 *)(puVar1 + 8) = desc->extra;
  *(c1_u32 *)(puVar1 + 0xc) = desc->debug_index;
  return (c1_type *)puVar1;
}

