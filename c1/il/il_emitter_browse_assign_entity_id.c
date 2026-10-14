void __thiscall il_emitter_browse_assign_entity_id(c1_il_emitter_browse *this,uint *out_id,uint id)

{
  if ((byte)(id >> 0x18) == g_browse_id_module_byte) {
    *out_id = id;
    return;
  }
  if ((id & 0xffffff) == 0) {
    if (0x7ffffffe < g_next_entity_id) {
      diag_fatal_simple(0x37);
    }
    id = id ^ (g_next_entity_id ^ id) & 0xffffff;
    g_next_entity_id = g_next_entity_id + 1;
  }
  *out_id = (uint)g_browse_id_module_byte << 0x18 | id & 0xffffff;
  return;
}

