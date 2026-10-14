c1_type * __cdecl type_descriptor_copy_transient(c1_type *desc)

{
  c1_u8 *copy;
  
  copy = g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 0x10;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  *(undefined4 *)copy = *(undefined4 *)desc;
  *(c1_type **)(copy + 4) = desc->base;
  *(c1_type_extra *)(copy + 8) = desc->extra;
  *(c1_u32 *)(copy + 0xc) = desc->debug_index;
  return (c1_type *)copy;
}

