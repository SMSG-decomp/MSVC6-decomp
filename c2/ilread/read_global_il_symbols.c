void read_global_il_symbols(void)

{
  g_il_stream = g_glo_il_file;
  read_function_symbols((c2_function *)0x0);
  fclose(g_glo_il_file);
  return;
}

