void close_il_files(void)

{
  if (g_exp_il_file != (FILE *)0x0) {
    fclose(g_exp_il_file);
  }
  if (g_sym_il_file != (FILE *)0x0) {
    fclose(g_sym_il_file);
  }
  if (g_pch_exp_il_file != (FILE *)0x0) {
    fclose(g_pch_exp_il_file);
  }
  if (g_pch_sym_il_file != (FILE *)0x0) {
    fclose(g_pch_sym_il_file);
  }
  fclose(g_init_il_file);
  g_backend_state = 4;
  return;
}

