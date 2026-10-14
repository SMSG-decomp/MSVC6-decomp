char __cdecl pch_check_options(char quiet)

{
  uint uVar1;
  
  if (g_opt_Gr != g_pch_option_block_read.opt_Gr) {
    if (quiet != '\0') {
      return '\0';
    }
    diag_warning(1,0x28c,0x18a);
  }
  if (g_opt_Gz != g_pch_option_block_read.opt_Gz) {
    if (quiet != '\0') {
      return '\0';
    }
    diag_warning(1,0x28c,0x19a);
  }
  if (g_opt_Gd != g_pch_option_block_read.opt_Gd) {
    if (quiet != '\0') {
      return '\0';
    }
    diag_warning(1,0x28c,0x19b);
  }
  if ((g_opt_Jd != g_pch_option_block_read.opt_Jd) ||
     (g_opt_J_unsigned_char != g_pch_option_block_read.opt_J_unsigned_char)) {
    if (quiet != '\0') {
      return '\0';
    }
    diag_warning(1,0x28c,0x18b);
  }
  if (g_opt_vmb != g_pch_option_block_read.opt_vmb) {
    if (quiet != '\0') {
      return '\0';
    }
    diag_warning(1,0x28c,0x18c);
  }
  if (g_opt_vmg != g_pch_option_block_read.opt_vmg) {
    if (quiet != '\0') {
      return '\0';
    }
    diag_warning(1,0x28c,0x18d);
  }
  if (((g_opt_vms != g_pch_option_block_read.opt_vms) ||
      (g_opt_vmm != g_pch_option_block_read.opt_vmm)) ||
     (g_opt_vmv != g_pch_option_block_read.opt_vmv)) {
    if (quiet != '\0') {
      return '\0';
    }
    diag_warning(1,0x28c,0x18e);
  }
  if (g_opt_vd != g_pch_option_block_read.opt_vd) {
    if (quiet != '\0') {
      return '\0';
    }
    diag_warning(1,0x28c,399);
  }
  if (g_opt_MD != g_pch_option_block_read.opt_MD) {
    if (quiet != '\0') {
      return '\0';
    }
    diag_warning(1,0x28c,400);
  }
  uVar1 = il_function_option_word();
  if (g_pch_option_block_read.optimize_word != uVar1) {
    if (quiet != '\0') {
      return '\0';
    }
    diag_warning(1,0x28d,0x192);
  }
  if (g_opt_Zi != g_pch_option_block_read.opt_Zi) {
    if (quiet != '\0') {
      return '\0';
    }
    if ((g_opt_Zi != '\0') && (g_pch_option_block_read.opt_Zi == '\0')) {
      diag_warning(1,0x28a);
    }
  }
  if ((g_opt_browse_info != g_pch_option_block_read.browse_info) ||
     (g_browse_full != g_pch_option_block_read.browse_full)) {
    if (quiet != '\0') {
      return '\0';
    }
    if (((g_opt_browse_info != '\0') && (g_pch_option_block_read.browse_info == '\0')) ||
       (g_browse_full != g_pch_option_block_read.browse_full)) {
      diag_warning(1,0x28c,0x194);
      g_browse_file = (char *)0x0;
      g_opt_browse_info = '\0';
    }
  }
  if (g_pch_option_block_read.opt_Gi != g_incremental) {
    if (quiet != '\0') {
      return '\0';
    }
    diag_error(0x357,"/Gi");
  }
  return '\x01';
}

