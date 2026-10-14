void __thiscall sym_attach_declspec_record(c1_symbol *key,uint *spec)

{
  c1_u8 *value;
  
  value = g_arenas[0].cur;
  if (spec == (uint *)0x0) {
    key->flags21 = key->flags21 & 0xbf;
    return;
  }
  g_arenas[0].cur = g_arenas[0].cur + 0x10;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  if (value != (c1_u8 *)0x0) {
    *(uint *)value = *spec;
    *(uint *)(value + 4) = spec[1];
    *(uint *)(value + 8) = spec[2];
    *(uint *)(value + 0xc) = spec[3];
    sym_attach_extra(key,value);
    return;
  }
  sym_attach_extra(key,(void *)0x0);
  return;
}

