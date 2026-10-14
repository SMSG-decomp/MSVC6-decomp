void __fastcall zi_layout_frame(c2_function *fn)

{
  zi_preallocate_eh_records();
  zi_home_remaining_locals();
  assign_temp_homes_in_reference_order(fn);
  if ((fn->fsym->u3e).label_flags == 0) {
    (fn->fsym->u3e).label_flags = 0x40;
    g_frame_cursor = g_frame_cursor + -0x40;
    return;
  }
  ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\stack.c",0x112);
}

