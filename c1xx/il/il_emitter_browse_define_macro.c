void __thiscall il_emitter_browse_define_macro(c1xx_il_emitter_browse *this,fe_macro *macro)

{
  if ((byte)(macro->def->browse_id >> 0x18) != g_browse_id_module_byte) {
    browse_add_record(0x13,(int *)macro);
  }
  return;
}

