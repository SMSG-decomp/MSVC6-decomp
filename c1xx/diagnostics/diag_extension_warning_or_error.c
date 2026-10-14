void __cdecl diag_extension_warning_or_error(int warning,int error,...)

{
  if (g_ms_extensions != '\0') {
    diag_warning(4,warning);
    return;
  }
  diag_error_emit((short)error,&stack0x0000000c);
  return;
}

