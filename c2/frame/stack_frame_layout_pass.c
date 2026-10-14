void __fastcall stack_frame_layout_pass(c2_function *fn)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = g_opt_edit_and_continue;
  bVar2 = g_opt_ZX == 0;
  fn->x28 = 0;
  if (bVar2) {
    if (iVar1 == 0) {
      if ((((g_opt_global == 0) || ((fn->fsym->attrs & 0x1000) != 0)) || (g_opt_dlp != 0)) ||
         (((fn->flags & 0x10000) != 0 && (g_opt_eh_enabled == 0)))) {
        assign_temp_homes_in_reference_order(fn);
      }
      else {
        pack_frame_locals(fn);
        if ((fn->flags & 0x10000) != 0) {
          assign_eh_object_homes();
        }
      }
    }
    else {
      zi_layout_frame(fn);
    }
  }
  else {
    if (iVar1 == 0) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\stack.c",0x75);
    }
    enc_layout_frame_reusing_locals(fn);
  }
  if ((fn->flags & 0x8000) != 0) {
    assign_nested_function_temp_homes(fn);
  }
  return;
}

