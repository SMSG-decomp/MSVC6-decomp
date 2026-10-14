void __fastcall coff_note_inline_debug_function(uint32_t id)

{
  c2_fe_symbol *pcVar1;
  
  if ((g_opt_debug_info != 0) || (g_opt_line_numbers != 0)) {
    pcVar1 = fe_symbol_lookup_id(id);
    if ((pcVar1 != (c2_fe_symbol *)0x0) &&
       (((pcVar1->cls == '\x04' && ((pcVar1->storage & 0x4000) != 0)) &&
        ((pcVar1->u4a).function.exp_offset != 0)))) {
      g_incr_rebuild_line_info = 1;
    }
  }
  return;
}

