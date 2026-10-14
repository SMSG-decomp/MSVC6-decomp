void __cdecl class_set_member_pointer_representation(char model)

{
  if (g_member_pointer_representation_fixed == '\0') {
    g_member_pointer_representation_fixed = '\x01';
    g_ptm_full_generality = model;
    return;
  }
  if (g_ptm_full_generality != model) {
    diag_error(0x11d);
  }
  return;
}

