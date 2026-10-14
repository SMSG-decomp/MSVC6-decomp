void __fastcall
emit_fpo_header(c2_fe_symbol *fsym,uint32_t off_start,uint32_t proc_size,uint32_t locals_dwords,
               uint16_t params_dwords,uint8_t prolog_size,uint8_t saved_regs,uint8_t has_seh,
               int non_fpo_frame,uint8_t ebp_allocated)

{
  uint32_t fpo_off_start;
  uint32_t fpo_proc_size;
  uint32_t fpo_locals_dwords;
  uint16_t fpo_params_dwords;
  uint8_t fpo_prolog_size;
  uint8_t fpo_bits;
  
  if ((g_opt_object_path != (char *)0x0) && (g_emit_coff_object != 0)) {
    (*g_hook_pad_section)(g_coff_fpo_section);
    fpo_locals_dwords = locals_dwords;
    fpo_proc_size = proc_size;
    fpo_prolog_size = prolog_size;
    fpo_params_dwords = params_dwords;
    fpo_bits = (((-(non_fpo_frame != 0) & 3U) << 2 | ebp_allocated) << 1 | has_seh) << 3 |
               saved_regs;
    fpo_off_start = off_start;
    (*g_writer_write_bytes_hook)(&fpo_off_start,0x10);
    (*g_hook_add_reloc_type7)(-0x10,fsym);
    g_coff_fpo_section->offset = g_coff_fpo_section->offset + 0x10;
  }
  return;
}

