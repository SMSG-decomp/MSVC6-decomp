uint __thiscall il_emitter_browse_entity_id(c1_il_emitter_browse *this,c1_symbol *sym)

{
  uint uVar1;
  
  uVar1 = sym->entity;
  if ((byte)(uVar1 >> 0x18) != g_browse_id_module_byte) {
    browse_add_record(0x19,sym);
    uVar1 = sym->entity;
  }
  return uVar1 & 0xffffff;
}

