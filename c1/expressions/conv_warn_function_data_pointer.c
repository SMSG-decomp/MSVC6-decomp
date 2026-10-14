void conv_warn_function_data_pointer(void)

{
  if (g_ms_extensions != '\0') {
    diag_warning(4,0x98);
    return;
  }
  diag_warning(1,0x99);
  return;
}

