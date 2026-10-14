void __fastcall cv_emit_lf_symbol(uint32_t n)

{
  if ((g_opt_incremental != 0) && (g_incr_object_not_reusable == 0)) {
    coff_fill_slots_default(g_coff_line_symbol_slot,3);
  }
  coff_add_symbol(".lf",(uint16_t)_g_coff_cur_code_section,'e',n & 0xffff,0,0);
  return;
}

