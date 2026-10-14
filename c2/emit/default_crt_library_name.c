char * default_crt_library_name(void)

{
  if (g_opt_MD != 0) {
    return "MSVCRT";
  }
  if (g_opt_MT != 0) {
    return "LIBCMT";
  }
  if (g_opt_ML != 0) {
    return "LIBC";
  }
  if (g_opt_MDd != 0) {
    return "MSVCRTD";
  }
  if (g_opt_MTd != 0) {
    return "LIBCMTD";
  }
  return (char *)(-(uint)(g_opt_MLd != 0) & 0x107a5a54);
}

