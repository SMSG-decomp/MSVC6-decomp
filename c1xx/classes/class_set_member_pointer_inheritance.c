void __cdecl class_set_member_pointer_inheritance(int model)

{
  if (model == 3) {
    model = 4;
  }
  if (g_ptm_inheritance_model == 0) {
    g_ptm_inheritance_model = model;
    return;
  }
  if (g_ptm_inheritance_model != model) {
    diag_error(0x11d);
  }
  return;
}

