uint * __thiscall
il_emitter_browse_assign_entity_id(c1xx_il_emitter_browse *this,uint *out,uint entity)

{
  if ((byte)(entity >> 0x18) == g_browse_id_module_byte) {
    *out = entity;
    return out;
  }
  if ((entity & 0xffffff) == 0) {
    if (0x7ffffffe < g_next_entity_id) {
      diag_fatal_simple(0x37);
    }
    entity = entity ^ (g_next_entity_id ^ entity) & 0xffffff;
    g_next_entity_id = g_next_entity_id + 1;
  }
  *out = (uint)g_browse_id_module_byte << 0x18 | entity & 0xffffff;
  return out;
}

