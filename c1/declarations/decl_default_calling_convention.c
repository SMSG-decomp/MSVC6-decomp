int decl_default_calling_convention(c1_type *type)

{
  if ((type->flags & 0x8000) != 0) {
    if ((g_opt_Gr != '\0') || (g_opt_Gc != '\0')) {
      diag_warning(2,0x60,0x25,0x6a);
    }
    return 1;
  }
  if (g_opt_Gr != '\0') {
    return 3;
  }
  if (g_opt_Gz == 0) {
    return (g_opt_Gc != '\0') + 1;
  }
  return 5;
}

