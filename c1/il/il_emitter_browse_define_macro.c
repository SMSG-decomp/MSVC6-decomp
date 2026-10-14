void __thiscall il_emitter_browse_define_macro(c1_il_emitter_browse *this,uint **macro)

{
  if ((byte)(*macro[1] >> 0x18) != g_browse_id_module_byte) {
    browse_add_record(0x13,(c1_symbol *)macro);
  }
  return;
}

