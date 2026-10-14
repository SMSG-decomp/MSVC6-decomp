char __cdecl pragma_pointers_to_members_default(int *model_out)

{
  if (g_ptm_full_generality != '\0') {
    if (g_ptm_inheritance_model == 0) {
      class_set_member_pointer_inheritance(3);
      diag_warning(1,0x9e,g_member_pointer_model_names[g_ptm_inheritance_model]);
    }
    *model_out = g_ptm_inheritance_model;
    return '\x01';
  }
  if (g_ptm_inheritance_model != 0) {
    diag_warning(1,0x9e,g_member_pointer_model_names[g_ptm_inheritance_model]);
    g_ptm_full_generality = '\x01';
    g_member_pointer_representation_fixed = '\x01';
    *model_out = g_ptm_inheritance_model;
    return '\x01';
  }
  if (g_opt_vmg == '\0') {
    return '\0';
  }
  if (g_opt_vms != '\0') {
    *model_out = 1;
    return '\x01';
  }
  *model_out = (-(uint)(g_opt_vmm != '\0') & 0xfffffffe) + 4;
  return '\x01';
}

